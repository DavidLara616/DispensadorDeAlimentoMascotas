#include <Wire.h> //incluimos libreria para RTC
#include <Servo.h> //incluimos libreria para ServoMotor
#include "RTClib.h" //incluimos libreria para RTC
#include <Adafruit_I2CDevice.h> //incluimos libreria complementaria para el modulo I2C
#include <LiquidCrystal_I2C.h> //incluimos libreria para LCD

RTC_DS1307 rtc; //definimos el modelo del modulo a usar
int meca; // declaramos variable para ciclo de activacion
LiquidCrystal_I2C lcd(0x27,16,2);

Servo myservo; //declaramos el servo

DateTime now; 
byte hour, minute;
String h,m;

int feedHour = 13; //hora para activar el Dispensador
int feedMin = 44; //minuto para Activar dispensador
boolean foodTime = true; //variable para controlar la activacion del dispensador

void setup(){
  Wire.begin();
  rtc.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop(){
  now = rtc.now();
  printTime(now);
  
  if ((feedHour == now.hour()) && (feedMin == now.minute()) && foodTime){
    feed(); //rutina para activar dispensador
  }

 /* Se utiliza 'foodTime' para que la comida no se sirva dos veces si la rutina no de alimentacion  
     finaliza en menos de un minuto **/
  if(feedMin != now.minute()){
    foodTime = true;
  }
}

void feed(){
  lcd.clear(); //se limpia la terminal
  lcd.setCursor(0,0); //se escribe en la linea cero y columna cero
  lcd.print("Sirviendo comida");

  myservo.attach(9); //conexion del ServoMotor

  //ciclo para ejecutar tres veces el mecanismo
  for (meca = 1; meca <= 3; meca++ ){ 
    // Desplazamos a la posición 45º
    myservo.write(45);
    delay(1000);  // Esperamos 1 segundo
    
    // Desplazamos a la posición 3º
    myservo.write(3);
    delay(1000);  // Esperamos 1 segundo

  }
   myservo.detach(); //Desconexion del ServoMotor
   foodTime = false; //Se cambia la variable de foodtime
}

void printTime(DateTime t){
  //imprimir hora actual
  lcd.setCursor(0, 0);
  lcd.print("H. Actual: ");
  hour = t.hour();
  if (hour < 10){
    h = "0" + String(hour);
  }else{
    h = String(hour);
  }
  lcd.print(h);
  lcd.print(':');
  minute = t.minute();
  if (minute < 10) {
    m = "0" + String(minute);
  }else{
    m = String(minute);
  }
  lcd.print(m);

//cuando se activa el dispensador
  lcd.setCursor(0, 1);
  lcd.print("H. Comida: ");
  if (feedHour < 10){
    h = "0" + String(feedHour);
  }else{
    h = String(feedHour);
  }
  lcd.print(h);
  lcd.print(':');
  if (feedMin < 10){
    m = "0" + String(feedMin);
  }else{
    m = String(feedMin);
  }
  lcd.print(m);
}
