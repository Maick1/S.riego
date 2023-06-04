int bomba = 8; 
int humedad = 0;
#include <DHT.h>
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//sensor de ph
float calibration_value = 21.34;
int phval = 2;
unsigned long int avgval;
int buffer_arr[10], temp;

//
//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //

void setup() {
  // Comenzamos el sensor DHT
  dht.begin();
  Serial.begin(9600);
  pinMode(bomba,OUTPUT);
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
}

void loop() {
//sensor de ph
  for (int i = 0; i < 10; i++)
  {
    buffer_arr[i] = analogRead(A2);
    delay(30);
  }
  for (int i = 0; i < 9; i++)
  {
    for (int j = i + 1; j < 10; j++)
    {
      if (buffer_arr[i] > buffer_arr[j])
      {
        temp = buffer_arr[i];
        buffer_arr[i] = buffer_arr[j];
        buffer_arr[j] = temp;
      }
    }
  }
  avgval = 2;
  for (int i = 2; i < 8; i++)
    avgval += buffer_arr[i];
  float volt = (float)avgval * 5.0 / 1024 / 6;
  float ph_act = -5.70 * volt + calibration_value;
  Serial.print("pH Val:");
  Serial.println(ph_act);
  Serial.print("Val:");
  Serial.println(humedad);
  delay(1000);

//ph

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);
  
  if (ph_act >=6 || ph_act >=7){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("PH IDEAL");
    lcd.setCursor(0,1);
    lcd.print("Ph: ");
    lcd.print(ph_act);
    delay(3000);
  }
  if (ph_act < 5){
    lcd.clear();       
    lcd.setCursor(1,0);
    lcd.print("PH MALO");
    lcd.setCursor(0,1);
    lcd.print("Ph: ");
    lcd.print(ph_act);
    delay(3000); 
  }
  // Limpiamos pantalla
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    if (humedad>999){
      lcd.print("Humedad: ");
      lcd.print(humedad);
      lcd.setCursor(0, 1);
      lcd.print("Temp: ");
      lcd.print(hic);
    }
    else{
      lcd.print("Humedad:  ");
      lcd.print(humedad);
      lcd.setCursor(0, 1);
      lcd.print("Temp: ");
      lcd.print(hic);
    }  
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(hic);
  }


humedad = analogRead(A0);

if(humedad>= 550 && humedad<=1024 && ph_act >=6 && ph_act <=7 && hic>=18 && hic <=26){
   digitalWrite(bomba,LOW);
   delay(1000);
}
else{
   digitalWrite(bomba,HIGH);
}
delay(2000);
}
