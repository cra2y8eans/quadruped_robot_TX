#include "batteryReading.hpp"
#include "intervalByMillis.hpp"
#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <esp_now.h>
#include <esp_wifi.h>

// cc:8d:a2:91:2d:7a

int L1_in_1         = 14; // 高电平顺时针转动（往上抬）
int L1_in_2         = 13; // 高电平逆时针
int L1_position_pin = 9;  // 站立中值123 顺时针（往上抬）读数增加
int L1_stand_val;
int L1_pwm_channel1 = 0;
int L1_pwm_channel2 = 1;

void setup() {
  pinMode(15, OUTPUT);
  pinMode(L1_in_1, OUTPUT);
  pinMode(L1_in_2, OUTPUT);
  Serial.begin(115200);
  analogReadResolution(8);
  L1_stand_val = analogRead(L1_position_pin);
}

void loop() {
  int currentPosition = analogRead(L1_position_pin);

  //   if (currentPosition < (L1_stand_val + 20)) {
  //     analogWrite(L1_in_1, 200);
  //     analogWrite(L1_in_2, 0);
  //   } else {
  //     analogWrite(L1_in_1, 255);
  //     analogWrite(L1_in_2, 255);
  //   }
  //   delay(500);
  //   if (currentPosition > (L1_stand_val - 20)) {
  //     analogWrite(L1_in_1, 0);
  //     analogWrite(L1_in_2, 200);
  //   } else {
  //     analogWrite(L1_in_1, 255);
  //     analogWrite(L1_in_2, 255);
  //   }
  //   delay(500);
  //   while (analogRead(L1_position_pin) != L1_stand_val) {
  //     if (analogRead(L1_position_pin) < L1_stand_val) {
  //       digitalWrite(L1_in_1, HIGH);
  //       digitalWrite(L1_in_2, LOW);
  //     } else if (analogRead(L1_position_pin) > L1_stand_val) {
  //       digitalWrite(L1_in_1, LOW);
  //       digitalWrite(L1_in_2, HIGH);
  //     } else {
  //       digitalWrite(L1_in_1, HIGH);
  //       digitalWrite(L1_in_2, HIGH);
  //     }
  //   }
  //   delay(1000);

  //   digitalWrite(15, HIGH);
  //   delay(500);
  //   digitalWrite(15, LOW);
  //   delay(500);
  //   while (currentPosition < (L1_stand_val + 20)) {
  //     digitalWrite(15, HIGH);
  //     analogWrite(L1_in_1, 200);
  //     analogWrite(L1_in_2, 0);
  //     currentPosition = analogRead(L1_position_pin);
  //   }
  //   digitalWrite(15, LOW);
  //   delay(500);
  //   digitalWrite(15, HIGH);
  //   delay(500);
  //     analogWrite(L1_in_1, 255);
  //     analogWrite(L1_in_2, 255);
  //   while (currentPosition > (L1_stand_val - 20)) {
  //     analogWrite(L1_in_1, 0);
  //     analogWrite(L1_in_2, 200);
  //     currentPosition = analogRead(L1_position_pin);
  //   }
  //     analogWrite(L1_in_1, 255);
  //     analogWrite(L1_in_2, 255);

  while (currentPosition < (L1_stand_val + 30)) {
    // digitalWrite(15, HIGH);
    digitalWrite(L1_in_1, 1);
    digitalWrite(L1_in_2, 0);
    currentPosition = analogRead(L1_position_pin);
  }
  digitalWrite(L1_in_1, 1);
  digitalWrite(L1_in_2, 1);
  delay(500);
  //   digitalWrite(15, LOW);
  while (currentPosition > (L1_stand_val - 30)) {
    // digitalWrite(15, HIGH);
    digitalWrite(L1_in_1, 0);
    digitalWrite(L1_in_2, 1);
    currentPosition = analogRead(L1_position_pin);
  }
  digitalWrite(L1_in_1, 1);
  digitalWrite(L1_in_2, 1);
    delay(500);
// Serial.println(analogRead(L1_position_pin));
}
