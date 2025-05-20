#include <PulseSensorPlayground.h>

const int PulseWire = A0;
const int LED13 = 13;
int Threshold = 550;
PulseSensorPlayground pulseSensor;
 
//  [1](https://arduino-kit.ru/blogs/blog/project_24)
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <MPU6050.h>
//----------------------
#include "TM1637Display.h" //avishorp
TM1637Display display(3, 2);  // CLC, DIO

//----------------------------
#include <LiquidCrystal.h>

int sensor = A0;
int dig_out;
float millivolt;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // устанавливает контакты для взаимодействия с LCD
//----------------------------

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
MPU6050 mpu;
int Signal;     
void puls(){
    Signal = analogRead(PulseWire); // чтение данных с сенсора 
    Serial.println(Signal); 
    if (Signal > Threshold){ 
        Serial.println("Жив");
    } else {
        Serial.println("Не совсем Жив");
    } 
    delay(10); 
}

//ослеживани воды
// void boda(){

// }


void vivod(int a){
    display.showNumberDec(a, true, 1, 0);  // 1___
  
}



int kPin[2]={0,0};
int k[2]={0,0};
int k_s= sizeof(k)/sizeof(k[0]);


void knop(int a){
  if (digitalRead(kPin[a])==0){
    k[a]==1;
  }
}


void reset(){ 
 for (int a=1; a<k_s; a++){
    k[a]=0;
  }
}
void setup() {
  //----------
  // инициализация
  // Serial.println("Initializing I2C devices...");
  // accelgyro.initialize();
  // delay(100);  
  //----------pulse sensor
   pinMode(LED13, OUTPUT);
  Serial.begin(9600);
//-----------
    // if (!accel.begin()) {
    //     Serial.println("No ADXL345 detected");
    //     while (1);
    // }
    // mpu.initialize();
  //----------
// display.setBrightness(4);  // яркость от 0 до 7, true/false
//   display.clear();
  //----------------
     int s=0;
  //----------------
}


void loop() {  // Задание на включение разделителя
  puls();
//   //тригеры
//   knop();
//   for (a=1; a<#k; a++){
//     if (k[a]==1){
//        s=1+a
//     }
//   }


// // реакции


// //   0. сон
//   if s==0 (){

//   }
//  // 1. сбор данных
//   if s==1 (){
//      puls();

//   }
// //  2.пульс
//   if s==2 (){
     
//   }
//   //  3. ВОда
//   if s==2 (){
     
//   }
//  // 4. вывод данных на дисплей
//   if s==3 (){

//   }
//  //5. разряжен
//   if s==4 (){

//   }
}


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 



