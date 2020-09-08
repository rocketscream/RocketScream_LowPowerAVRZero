#include <RocketScream_LowPowerAVRZero.h>

/* Example on a 32-pin ATMega4808, LED on pin D7 */
const uint8_t unusedPins[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 
                              14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
void setup() 
{
  uint8_t index;
  
  /* Ensure unused pins are not floating */
  for (index = 0; index < sizeof(unusedPins); index++)
  {
    pinMode(unusedPins[index], INPUT_PULLUP);
    LowPower.disablePinISC(unusedPins[index]);
  }
  
  /* LED is connected to D7 */
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  LowPower.powerDown();
}

void loop() 
{

}
