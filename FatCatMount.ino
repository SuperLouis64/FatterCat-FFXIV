/* Fat Cat set-up
 *  Goal: When I sit, I fat cat
 *  Touch sensor can be sat on to press the numpad 7
 *  Numpad 7 is the hotbar key I use for my mounts on FFXIV
 */
#include <Keyboard.h>


bool isSitting;

// touch sensor stuff
const int SENSOR_PIN = 4; // the pin that the TOUCH SENSOR is connected to
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

 // read the state of the the input pin:
  currentState = digitalRead(SENSOR_PIN);

  if(lastState == LOW && currentState == HIGH)
      {
        Serial.println("The sensor is touched");
      }

  if(currentState == HIGH && !isSitting)
    {
      Keyboard.press (231); // numpad 7
      Keyboard.release (231); // code for numpad 7
      isSitting = true;
    }

  if(currentState == LOW && isSitting)
     {
      Keyboard.press (231);
      Keyboard.release (231);
      isSitting = false;
     }


  // save the the last state
  lastState = currentState;
    
  // debug stuff
  //   Serial.println(isSitting); 

}
