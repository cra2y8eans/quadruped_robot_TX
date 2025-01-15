#pragma once

#include <arduino.h>

class millisDelay {
private:
  int _delayTime;
  unsigned long previousMillis;
public:
  millisDelay();
  ~millisDelay();
  void interval(void (*ptr)(), int delaytime);
};

millisDelay::millisDelay() {}
millisDelay::~millisDelay() {}

void millisDelay::interval(void (*ptr)(), int delaytime) {
  _delayTime = delaytime;
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis) > _delayTime) {
    ptr();
    previousMillis = currentMillis;
  }
}