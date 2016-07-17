# ArduinoMotorShieldDriver
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
