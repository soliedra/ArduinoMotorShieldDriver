#include "Arduino.h"
#include "ArduinoMotorShieldDriver.h"

ArduinoMotorShieldDriver::ArduinoMotorShieldDriver(uint8_t pin_dir_channelA, uint8_t pin_dir_channelB, uint8_t pin_pwm_output_channelA, uint8_t pin_pwm_output_channelB)
{
	_pin_pwm_output_channelA = pin_pwm_output_channelA;
	_pin_pwm_output_channelB = pin_pwm_output_channelB;
	_pin_dir_channelA = pin_dir_channelA;
	_pin_dir_channelB = pin_dir_channelB;

	//Direction and PWM output
	pinMode(_pin_dir_channelA, OUTPUT);
	pinMode(_pin_dir_channelB, OUTPUT);
	pinMode(_pin_pwm_output_channelA, OUTPUT);
	pinMode(_pin_pwm_output_channelB, OUTPUT);	
}
	
void ArduinoMotorShieldDriver::writePWM(int pwmSpeed)
{
	// Pick direction
	if (pwmSpeed < 0)
	{
		digitalWrite(_pin_dir_channelA, HIGH);
		digitalWrite(_pin_dir_channelB, HIGH);
		
		// set PWM outputs
		analogWrite(_pin_pwm_output_channelA, -pwmSpeed);
		analogWrite(_pin_pwm_output_channelB, -pwmSpeed);
	}
	else
	{
		digitalWrite(_pin_dir_channelA, LOW);
		digitalWrite(_pin_dir_channelB, LOW);
		
		// set PWM outputs
		analogWrite(_pin_pwm_output_channelA, pwmSpeed);
		analogWrite(_pin_pwm_output_channelB, pwmSpeed);
		
	}		
}	
