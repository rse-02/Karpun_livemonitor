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

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <MPU6050.h>
//----------------------
#include "TM1637.h"  // Подключаем библиотеку для работы с модулем
int8_t DispMSG = {1, 2, 3, 4};  // Настройка символов для последующего вывода на дисплей

// Определяем пины для подключения к плате Arduino
#define CLK 3
#define DIO 2

// Создаём объект класса TM1637, в качестве параметров
// передаём номера пинов подключения
TM1637 tm1637(CLK, DIO)
//----------------------------
#include <LiquidCrystal.h>

int sensor = A0;
int dig_out;
float millivolt;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // устанавливает контакты для взаимодействия с LCD
//----------------------------

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
MPU6050 mpu;

void puls(){
  int myBPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat()) {
    Serial.println("Heartbeat detected!");
    Serial.print("BPM: ");
    Serial.println(myBPM);
  }
  delay(20);
}

//ослеживани воды
void boda(){

}


void vivod(){
tm1637.point(true);
  //Выводим массив на дисплей
  tm1637.display(DispMSG);   dig_out = analogRead(sensor);  // считывает входное напряжение
    millivolt = (dig_out * 4.882);  // конвертирует значение в милливольты
    lcd.setCursor(0,0);
    lcd.print("Pressure Sensor");  // выводит текст «Pressure Sensor»
    lcd.setCursor(0,1);
    lcd.print(millivolt);  // выводит входное напряжение
    lcd.setCursor(9,1);
    lcd.print("mV");  // выводит формат значения (милливольты)
    delay(300);  // задержка 300 мс
    lcd.clear();  // очищает экран
}
  //Задержка
  delay(1000);
  //Задание на выключение разделителя
  tm1637.point(false);
  //Выводим массив на дисплей
  tm1637.display(DispMSG);
  //Задержка
  delay(1000);

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
  Serial.begin(9600)
//-----------
    Serial.begin(9600);
    if (!accel.begin()) {
        Serial.println("No ADXL345 detected");
        while (1);
    }
    mpu.initialize();
  //----------
tm1637.init();
  //Установка яркости горения сегментов
  tm1637.set(BRIGHT_TYPICAL);
  //----------------
  void setup() {
    pinMode(sensor,INPUT);  // устанавливает A0 как вход
    lcd.begin(16, 2);  // инициализирует LCD
  //----------------
}


void loop() {  // Задание на включение разделителя

}