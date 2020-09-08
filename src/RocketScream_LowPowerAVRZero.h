#ifndef RocketScream_LowPowerAVRZero_h
#define RocketScream_LowPowerAVRZero_h

#include "Arduino.h"

class RocketScream_LowPowerAVRZeroClass
{
	public:
	  void idle(void);
      void standby(void);
	  void powerDown(void);
	  void disablePinISC(uint8_t pin);
	  void enablePinISC(uint8_t pin);
    
	private:
      void sleep(void);
};

extern RocketScream_LowPowerAVRZeroClass LowPower;

#endif
