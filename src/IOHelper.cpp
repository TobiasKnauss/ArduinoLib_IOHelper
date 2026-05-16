#include "Arduino.h"
#include "IOHelper.h"

//--------------------------------------------------------------------
uint8_t getPinMode (uint8_t i_Pin)
{
  // from https://forum.arduino.cc/t/check-current-pinmode/232140/4
	uint8_t bitMask = digitalPinToBitMask (i_Pin);
	uint8_t port    = digitalPinToPort    (i_Pin);
	volatile uint8_t *portMode, *portOut;

	if (port == NOT_A_PIN)       return UNKNOWN_PIN;
  if (bitMask == 0)            return UNKNOWN_PIN;
  if (bitMask & (bitMask - 1)) return UNKNOWN_PIN;

	portMode = portModeRegister   (port);
	portOut  = portOutputRegister (port);

  if (*portMode & bitMask)
    return OUTPUT;
  if (*portOut & bitMask)  // portMode bit is false here
    return INPUT_PULLUP;
  return INPUT;
}

//--------------------------------------------------------------------
const __FlashStringHelper* getPinModeName (uint8_t i_Value)
{
  switch (i_Value)
  {
  case INPUT:         return F("INPUT");
  case INPUT_PULLUP:  return F("INPUT_PULLUP");
  case OUTPUT:        return F("OUTPUT");
  default:            return F("UNKNOWN");
  }
}

//--------------------------------------------------------------------
const __FlashStringHelper* getText_HighLow (bool i_Value)
{
  return i_Value
       ? F("HIGH")
       : F("LOW");
}

//--------------------------------------------------------------------
const __FlashStringHelper* getText_OnOff (bool i_Value)
{
  return i_Value
       ? F("ON")
       : F("OFF");
}

//--------------------------------------------------------------------
bool isPinModeValid (uint8_t i_Mode)
{
  return i_Mode == INPUT
      || i_Mode == INPUT_PULLUP
      || i_Mode == OUTPUT;
}

//--------------------------------------------------------------------
void setPinMode (uint8_t i_Pin, uint8_t i_Mode)
{
  pinMode (i_Pin, i_Mode);
}
