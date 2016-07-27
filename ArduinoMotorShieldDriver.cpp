#include "Arduino.h"
#include "ArduinoMotorShieldDriver.h"

ArduinoMotorShieldDriver::ArduinoMotorShieldDriver(uint8_t pin_dir_channelA, uint8_t pin_dir_channelB, uint8_t pin_pwm_output_channelA, uint8_t pin_pwm_output_channelB, uint8_t pin_brake_channelA, uint8_t pin_brake_channelB, uint8_t pin_current_channelA,uint8_t pin_current_channelB)
{
	_pin_pwm_output_channelA = pin_pwm_output_channelA;
	_pin_pwm_output_channelB = pin_pwm_output_channelB;
	_pin_dir_channelA = pin_dir_channelA;
	_pin_dir_channelB = pin_dir_channelB;
	_pin_brake_channelA = pin_brake_channelA;
	_pin_brake_channelB = pin_brake_channelB; 
	_pin_current_channelA = pin_current_channelA;
	_pin_current_channelB = pin_current_channelB;

	//Direction and PWM output
	pinMode(_pin_dir_channelA, OUTPUT);
	pinMode(_pin_dir_channelB, OUTPUT);
	pinMode(_pin_pwm_output_channelA, OUTPUT);
	pinMode(_pin_pwm_output_channelB, OUTPUT);	
	pinMode(_pin_brake_channelA, OUTPUT);
	pinMode(_pin_brake_channelB, OUTPUT);	
	
}
	
void ArduinoMotorShieldDriver::writePWM(int pwmSpeed)
{
	digitalWrite(_pin_brake_channelA, LOW);
	digitalWrite(_pin_brake_channelA, LOW);	
	analogWrite(_pin_pwm_output_channelA, pwmSpeed);
	analogWrite(_pin_pwm_output_channelB, pwmSpeed);	
}

void ArduinoMotorShieldDriver::setDirectionCW()
{
	digitalWrite(_pin_dir_channelA, LOW);
	digitalWrite(_pin_dir_channelB, LOW);	
}		

void ArduinoMotorShieldDriver::setDirectionCCW()
{
	digitalWrite(_pin_dir_channelA, HIGH);
	digitalWrite(_pin_dir_channelB, HIGH);	
}

void ArduinoMotorShieldDriver::setBrake()
{
	digitalWrite(_pin_brake_channelA, HIGH);
	digitalWrite(_pin_brake_channelA, HIGH);	
}

float ArduinoMotorShieldDriver::getCurrent()
{	
  // 5V/1.65V/A => max current = 3.03A corresponds to a reading of 1024 per channel)
  return 	map(float(analogRead(_pin_current_channelA)),0.0,1024.0,0.0,3.03) +
			map(float(analogRead(_pin_current_channelB)),0.0,1024.0,0.0,3.03);  
}
