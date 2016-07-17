/*
 * Implementation of MotorDriver for the ArduinoMotorShield.
 * MotorDriver V_1_0 library at: https://github.com/soliedra/MotorDriver
 * 
 * This shield provides a dual driver controlled by channels A and B.
 * In this case both channels have been connected in parallel to be able
 * to deliver a maximum current of 4 Amps to the driven motor.
 * 
 * Connections:
 * ------------
 * 
 * Function         | Channel A   | Channel B |
 *---------------------------------------------
 * Direcion         | D12 	      | D13       |
 *---------------------------------------------
 * PWM	            | D5 (brigded | D11       |
 *                  | to D3)      |           |
 ----------------------------------------------
 *
 * When the Direction pins are HIGH the motor turns CCW and
 * CW when LOW.
 *
 * Author: Javier Casado
 * Licence: CC BY
 */
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
