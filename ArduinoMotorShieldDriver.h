#ifndef AduinoMotorShieldDriver_h
#define AduinoMotorShieldDriver_h

#include "Arduino.h"
#include <MotorDriver.h>

class ArduinoMotorShieldDriver : public MotorDriver
{
	public:
		ArduinoMotorShieldDriver(uint8_t pin_dir_channelA = 12, uint8_t pin_dir_channelB = 13, uint8_t pin_pwm_output_channelA = 5,uint8_t pin_pwm_output_channelB = 11);
		void writePWM(int pwmSpeed);
		
	private:	
		uint8_t _pin_pwm_output_channelA, _pin_pwm_output_channelB, _pin_dir_channelA, _pin_dir_channelB;
};
#endif
