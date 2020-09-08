#include <avr/io.h>
#include <avr/sleep.h>
#include "RocketScream_LowPowerAVRZero.h"

/*! \brief Put MCU into idle mode.
 *
 */
void RocketScream_LowPowerAVRZeroClass::idle(void)
{
  set_sleep_mode(SLEEP_MODE_IDLE);    
  sleep();     
}

/*! \brief Put MCU into standby mode.
 *
 */
void RocketScream_LowPowerAVRZeroClass::standby(void)
{
  set_sleep_mode(SLEEP_MODE_STANDBY);
  sleep();
}

/*! \brief Put MCU into power down mode.
 *
 */
void RocketScream_LowPowerAVRZeroClass::powerDown(void)
{
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep();
}

/*! \brief Enable sleep mode.
 *
 */
void RocketScream_LowPowerAVRZeroClass::sleep(void)
{
  cli();
  sleep_enable();
  sei();
  sleep_cpu(); 
}

/*! \brief Disable pin ISC.
 *
 */
void RocketScream_LowPowerAVRZeroClass::disablePinISC(uint8_t pin)
{
  PORT_t *port = digitalPinToPortStruct(pin);
  /* Get bit position for getting pin ctrl reg */
  uint8_t bit_pos = digitalPinToBitPosition(pin);

  /* Calculate where pin control register is */
  volatile uint8_t *pin_ctrl_reg = getPINnCTRLregister(port, bit_pos);

  /* Disable ISC */
  *pin_ctrl_reg = PORT_ISC_INPUT_DISABLE_gc;
}

/*! \brief Enable pin ISC.
 *
 */
void RocketScream_LowPowerAVRZeroClass::enablePinISC(uint8_t pin)
{
  PORT_t *port = digitalPinToPortStruct(pin);
  /* Get bit position for getting pin ctrl reg */
  uint8_t bit_pos = digitalPinToBitPosition(pin);

  /* Calculate where pin control register is */
  volatile uint8_t *pin_ctrl_reg = getPINnCTRLregister(port, bit_pos);
  
  /* Default configuration is enable ISC without interrupt */
  *pin_ctrl_reg = PORT_ISC_INTDISABLE_gc;
}

RocketScream_LowPowerAVRZeroClass LowPower;

