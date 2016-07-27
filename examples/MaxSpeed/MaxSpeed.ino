/*
 * Makes the driven motor turn at max speed indefinitely
 *
 * Must include MotorDriver library from https://github.com/soliedra/MotorDriver
 * The Arduino IDE doesn't include it automatically!
 */
#include <MotorDriver.h>
#include <ArduinoMotorShieldDriver.h>

#define PIN_DIR_CHANNEL_A     12
#define PIN_DIR_CHANNEL_B     13    
#define PIN_PWM_CHANNEL_A     5  
#define PIN_PWM_CHANNEL_B     11
#define PIN_BRAKE_CHANNEL_A   9
#define PIN_BRAKE_CHANNEL_B   8
#define PIN_CURRENT_CHANNEL_A A0
#define PIN_CURRENT_CHANNEL_B A1

ArduinoMotorShieldDriver driver = ArduinoMotorShieldDriver(PIN_DIR_CHANNEL_A,PIN_DIR_CHANNEL_B,PIN_PWM_CHANNEL_A,PIN_PWM_CHANNEL_B,PIN_BRAKE_CHANNEL_A,PIN_BRAKE_CHANNEL_B,PIN_CURRENT_CHANNEL_A,PIN_CURRENT_CHANNEL_B);

void setup() {
  
  // make it turn at max speed
  driver.writePWM(255);
}

void loop() {
  // nothing to repeat
}
