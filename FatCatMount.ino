/* Fat Cat set-up
 *  Goal: When I sit, I fat cat
 *  Only mount when the motion is live (give it a couple of seconds)
 *  Touch sensor can be sat on to confirm?
 *  be able to stitch this into something ontop of the fat cat
 */
#include <Wire.h>
#include <I2Cdev.h>
#include <Mouse.h>
#include <Keyboard.h>
#include <Joystick.h>

int pirPin = 2; // the output of the PIR
int pirStatus = 0; 

bool isSitting;

// touch sensor stuff
const int SENSOR_PIN = 4;
int lastState = LOW;      // the previous state from the input pin
int currentState;         // the current reading from the input pin

void setup() 
{
  //pinMode(pirPin, INPUT);
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
  isSitting = false;
}

void loop() 
{
  /*
  pirStatus = digitalRead(pirPin);
  if(pirStatus == HIGH)
    {
      Serial.println("motion detected");
    }
  */

 // read the state of the the input pin:
  currentState = digitalRead(SENSOR_PIN);

  if(lastState == LOW && currentState == HIGH)
      {
        Serial.println("The sensor is touched");
      }

  if(currentState == HIGH && !isSitting)
    {
      Keyboard.press (231); // numpad 7
      Keyboard.release (231);
      isSitting = true;
    }

  if(currentState == LOW && isSitting)
     {
      Keyboard.press (231);
      Keyboard.release (231);
      isSitting = false;
     }

   Serial.println(isSitting);

  // save the the last state
  lastState = currentState;
    

}
