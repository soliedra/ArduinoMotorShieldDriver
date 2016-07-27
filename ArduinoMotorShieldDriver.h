/*
 * Implementation of MotorDriver for the ArduinoMotorShield.
 * MotorDriver V_1_0 library at: https://github.com/soliedra/MotorDriver
 * 
 * This shield provides a dual driver controlled by channels A and B.
 * In this case both channels have been connected in parallel to be able
 * to deliver a maximum current of 4 Amps to the driven motor.
 * 
 * DC motor driver connections:
 * 
 * Function         | Channel A   | Channel B |
 *---------------------------------------------
 * Direcion         | D12 	  | D13       |
 *---------------------------------------------
 * PWM	            | D5	  | D11       |
 *---------------------------------------------
 * Brake            | D9      | D8        |
 *---------------------------------------------
 * Current sensing  | A0      | A1        |
 ----------------------------------------------
 *
 * When the Direction pins are HIGH the motor turns CCW and
 * CW when LOW.
 * 
 * NOTICE: In an Arduino motor shield digital pin 3 is used to carry 
 * the Channel A PWM signal. As long  as that same pin is used by the encoder B input
 * pin (external interrupt), channel A PWM has been moved to digital PIN 5.
 * In my case the Digital male pins 2 and 3 have been cut off from the motor
 * Shield, and the pin 3 has been brigded to the arduino pin 5 on the top side
 * of the shield with a piece of wire.
 * 
 * 
 * Hardware
 * --------
 * Modified [Arduino Motor Shield](https://www.arduino.cc/en/Main/ArduinoMotorShieldR3) as mentioned above.
 * Arduino UNO R3
 * A 12V geared DC motor from a battery drill. Output speed aprox 600rpm
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
		ArduinoMotorShieldDriver(uint8_t pin_dir_channelA = 12, uint8_t pin_dir_channelB = 13, uint8_t pin_pwm_output_channelA = 5,uint8_t pin_pwm_output_channelB = 11, uint8_t pin_brake_channelA = 9,uint8_t pin_brake_channelB = 8,uint8_t pin_current_channelA = A0,uint8_t pin_current_channelB = A1);
		
		void writePWM(int pwmSpeed);
		void setDirectionCW();
		void setDirectionCCW();
		void setBrake();
		float getCurrent();
		
	private:	
		uint8_t _pin_pwm_output_channelA, _pin_pwm_output_channelB, _pin_dir_channelA, _pin_dir_channelB;
		uint8_t _pin_brake_channelA, _pin_brake_channelB, _pin_current_channelA, _pin_current_channelB;
};
#endif
