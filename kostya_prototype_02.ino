#include <PulseSensorPlayground.h>

const int PulseWire = A0;
const int LED13 = 13;
int Threshold = 550;
PulseSensorPlayground pulseSensor;
 
 [1](https://arduino-kit.ru/blogs/blog/project_24)
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;




//пособности ослеживани пульса
void puls(){
  int myBPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat()) {
    Serial.println("Heartbeat detected!");
    Serial.print("BPM: ");
    Serial.println(myBPM);
  }
  delay(20);
}

//ослеживани шагов 
void shag(){
  // чтение значений гироскопа и акселерометра
  accelgyro.getMotion6  
}
//ослеживани воды
void boda(){

}

void zaryad(){

}

void puls(){
}

void pressre(){
}

void setup() {
  //----------
  Wire.begin();
  Serial.begin(38400);
  // инициализация
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();
  delay(100);  
  //----------pulse sensor
   pinMode(LED13, OUTPUT);
  Serial.begin(9600);
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13);
  pulseSensor.setThreshold(Threshold);
  if (pulseSensor.begin()) {
    Serial.println("Pulse sensor started successfully.");
  }
  //----------
}

void loop() {
  // чтение значений гироскопа и акселерометра
  accelgyro.getMotion6ode here, to run repeatedly:

}
