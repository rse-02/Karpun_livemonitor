#include <TM1637Display.h>

#define CLK 2
#define DIO 3
#define BUTTON_PIN 4
#define PULSE_PIN A0

TM1637Display display(CLK, DIO);

const int threshold = 410; // Порог для определения удара (подкорректировано)
int pulseValue = 0;

unsigned long lastBeatTime = 0;
unsigned long interval = 0;
int bpm = 0;

bool buttonPressed = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // кнопка с подтяжкой
  display.setBrightness(0x0f);
  display.clear();
  Serial.begin(9600);
}

void loop() {
  buttonPressed = (digitalRead(BUTTON_PIN) == LOW); // кнопка нажата

  if (buttonPressed) {
    pulseValue = analogRead(PULSE_PIN);
    Serial.println(pulseValue);
    // Простая детекция пика (в момент превышения порога)
    if (pulseValue > threshold) {
      unsigned long currentTime = millis();

      // Убедимся, что между ударами прошло минимум 500 мс (чтобы избежать дребезга)
      if (currentTime - lastBeatTime > 500) {
        interval = currentTime - lastBeatTime;
        lastBeatTime = currentTime;

        bpm = 60000 / interval; // Вычисляем bpm
        Serial.print("PulseValue: ");
        Serial.print(pulseValue);
        Serial.print(" BPM: ");
        Serial.println(bpm);
      }
    }

    // Отображаем bpm, если в разумном диапазоне
    if (bpm > 30 && bpm < 200) {
      display.showNumberDec(bpm, false); // false — без двоеточия
    } else {
      display.showNumberDec(0, false);
    }
  } else {
    display.clear();
  }

  delay(50);
}
