# Dispensador de Alimento para Mascotas

Este proyecto consiste en un código en Arduino para controlar un dispensador de alimento para mascotas. El dispensador se activa automáticamente en un horario predefinido para servir la comida a la mascota.

## Dependencias

El código utiliza las siguientes librerías:

- Wire.h: Librería para el módulo RTC (Real Time Clock).
- Servo.h: Librería para controlar el ServoMotor.
- RTClib.h: Librería para el RTC DS1307.
- Adafruit_I2CDevice.h: Librería complementaria para el módulo I2C.
- LiquidCrystal_I2C.h: Librería para controlar el LCD mediante I2C.

## Configuración

Antes de utilizar el código, asegúrate de seguir los siguientes pasos:

1. Conecta correctamente los componentes, incluyendo el módulo RTC, el ServoMotor y el LCD.
2. Ajusta la variable `feedHour` con la hora en la que deseas que el dispensador se active.
3. Ajusta la variable `feedMin` con el minuto en el que deseas que el dispensador se active.

## Funcionamiento

El código utiliza el módulo RTC para obtener la hora actual y compara con la hora configurada en `feedHour` y `feedMin`. Cuando se alcanza el horario predefinido, se activa el dispensador de alimentos.

Durante la activación, el ServoMotor se desplaza en dos posiciones para dispensar la comida en tres ocasiones. Luego, se desactiva el ServoMotor.

La hora actual y la hora programada para la alimentación se muestran en el LCD.

## Contribución

Si tienes alguna mejora o sugerencia para este proyecto, siéntete libre de contribuir abriendo un issue o enviando un pull request.

## Documentacion del proyecto

Drive: https://drive.google.com/file/d/1EHNUMb8-uUNfCT90x-n5Cfk5UFFqeANq/view?usp=sharing


¡Gracias por utilizar el Dispensador de Alimento para Mascotas!
