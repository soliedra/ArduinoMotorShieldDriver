/*
 * Makes the driven motor turn at max speed indefinitely
 *
 * Must include MotorDriver library from https://github.com/soliedra/MotorDriver
 * The Arduino IDE doesn't include it automatically!
 */
#include <MotorDriver.h>
#include <ArduinoMotorShieldDriver.h>

#define PIN_DIR_CHANNEL_A    12
#define PIN_DIR_CHANNEL_B    13    
#define PIN_PWM_CHANNEL_A    5  
#define PIN_PWM_CHANNEL_B    11



ArduinoMotorShieldDriver driver = ArduinoMotorShieldDriver(PIN_DIR_CHANNEL_A,PIN_DIR_CHANNEL_B,PIN_PWM_CHANNEL_A,PIN_PWM_CHANNEL_B);

void setup() {
  
  // make it turn at max speed
  driver.writePWM(255);
}

void loop() {
  // nothing to repeat
}
