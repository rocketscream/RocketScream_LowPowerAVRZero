#include <RocketScream_LowPowerAVRZero.h>
#include <RocketScream_RTCAVRZero.h>

/* Example on a 32-pin ATMega4808, LED on pin D7, using internal ULP OSC32K */
const uint8_t unusedPins[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13,
                              14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
                              
void setup()
{
  uint8_t index;

  for (index = 0; index < sizeof(unusedPins); index++)
  {
    pinMode(unusedPins[index], INPUT_PULLUP);
    LowPower.disablePinISC(unusedPins[index]);
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  /* true: external 32.768 kHz crystal */
  /* false: internal 32.768 kHz ULP oscillator */
  RTCAVRZero.begin(false);
  /* Time in seconds, true: repeat, false: once */
  RTCAVRZero.enableAlarm(5, true);
  RTCAVRZero.attachInterrupt(toggle);  
}

void loop()
{
  /* RTC works down to standby mode only. In power down, PIT is required */
  LowPower.standby();
}

void toggle(void)
{
  digitalWrite(LED_BUILTIN, CHANGE);
}
