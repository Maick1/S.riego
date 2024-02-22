# Sistema de Riego Automático con Arduino

Este proyecto implementa un sistema de riego automático utilizando Arduino para controlar el suministro de agua a las plantas de forma automatizada.

## Descripción del Proyecto

El sistema de riego automático está diseñado para mantener las plantas adecuadamente hidratadas sin la necesidad de intervención manual. Utiliza un sensor de humedad del suelo para detectar cuándo las plantas necesitan agua y activa una bomba de agua para suministrarla.

## Componentes Necesarios

- Arduino (puede ser Arduino Uno, Arduino Nano, etc.)
- Sensor de humedad del suelo
- Bomba de agua
- Relé
- Módulo de reloj en tiempo real (RTC) opcional para programar horarios de riego
- Cables y resistencias

## Diagrama de Conexión

![image](https://github.com/Maick1/S.riego/assets/86171053/53a66bf5-9a79-49aa-b8b1-ebc0216cd4ae)


## Instrucciones de Montaje

1. Conecta el sensor de humedad del suelo al Arduino.
2. Conecta la bomba de agua al relé y luego al Arduino.
3. Si estás utilizando un módulo RTC, conéctalo al Arduino.
4. Asegúrate de que todos los componentes estén correctamente alimentados.

## Código Fuente

El código fuente del proyecto se encuentra en el archivo `riego_automatico.ino`. Abre este archivo en el IDE de Arduino y cárgalo en tu placa Arduino.

## Uso

1. Coloca el sensor de humedad del suelo en la maceta de la planta que deseas regar.
2. Enciende el sistema.
3. El sistema monitoreará continuamente la humedad del suelo y activará la bomba de agua cuando sea necesario.
4. Si estás utilizando un módulo RTC, puedes programar horarios específicos para el riego.

## Contribuciones

¡Las contribuciones son bienvenidas! Si deseas mejorar este proyecto de sistema de riego automático, no dudes en enviar un pull request.

## Contacto

Si tienes alguna pregunta o sugerencia, no dudes en contactarme:

- Email: mtomalaz@unemi.edu.ec


¡Espero que encuentres útil este proyecto!

---
