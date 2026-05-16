#ifndef IOHelper_h
#define IOHelper_h

#include <Arduino.h>

#define UNKNOWN_PIN 0xFF

uint8_t getPinMode (uint8_t i_Pin);

const __FlashStringHelper* getPinModeName (uint8_t i_Value);

const __FlashStringHelper* getText_HighLow (bool i_Value);
const __FlashStringHelper* getText_OnOff (bool i_Value);

bool    isPinModeValid (uint8_t i_Mode);

void    setPinMode (uint8_t i_Pin, uint8_t i_Mode);

#endif
