#include <RocketScream_LowPowerAVRZero.h>

/* Example on a 32-pin ATMega4808, LED on pin D7 */
const uint8_t unusedPins[] = {0, 1, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 
                              14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
volatile bool awake = false;

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
  pinMode(2, INPUT_PULLUP);
  digitalWrite(LED_BUILTIN, LOW);
  
  /* Only asynchronous input pin can be used as wake up source during power */
  /* down. Pin D2, D6, D14, D16, D18, D22 on 32-pin ATMega4808 */
  attachInterrupt(2, wakeUp, LOW);
}

void loop() 
{
  LowPower.powerDown();
  if (awake)
  {
    awake = false;
    digitalWrite(LED_BUILTIN, CHANGE);
  }
}

void wakeUp(void)
{
  awake = true;	
}
