# ArduinoMotorShieldDriver
 <p>
 Implementation of [MotorDriver](https://github.com/soliedra/MotorDriver) 
 for the [Arduino Motor Shield] (https://www.arduino.cc/en/Main/ArduinoMotorShieldR3).
 </p>
 <p> 
 This shield provides a dual driver controlled by channels A and B.
 In this case both channels have been connected in parallel to be able
 to deliver a maximum current of 4 Amps to the driven motor.
 </p>
 <p>
  I've cut off the male end of the pins pins D0,D1,D2 and D3 so they are disconnected 
  from the Arduino board underneath, with a short cable I've bridged the pins D3 and D5 on the top 
  side of the Arduino motor shield. The reason to do this is to leave the Arduino pins D2 and D3 
  free to connect the encoder feedback. Pins D2 and D3 are the external interrupt enabled pins</p>
 <p>
 <h3>Connections:</h3>
 </p>
### Example circuit connections
<table>
<tr><td>Function</td><td>Channel A</td><td>Channel B</td></tr>
<tr><td>Direction</td><td>D12</td><td>D13</td></tr>
<tr><td>PMW</td><td>D5</td><td>D11</td></tr>
<tr><td>Brake</td><td>D9</td><td>D8</td></tr>
<tr><td>Current sensing</td><td>A0</td><td>A1</td></tr>
</table>
<p>
 When the Direction pins are HIGH the motor turns CCW and
 CW when LOW.
 </p>
 <p>
 It contains the following methods:
 <ul>
 <li>writePWM(int pwmSpeed), sets the motor speed where 0 <= pwmSpeed <= 255</li>
 <li>setDirectionCW() sets the CW direction</li>
 <li>setDirectionCCW() sets the CCW direction</li>
 <li>setBrake() brakes the motor</li>
 <li>float getCurrent() returns the Amps through the motor.</li>
 </ul>
 </p>
 <p>
 Author: Javier Casado
 Licence: CC BY
</p>
