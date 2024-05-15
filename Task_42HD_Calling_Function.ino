/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/b467fe5b-a100-4d45-b966-6b5bc450e35a 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  String light_id;
  bool green_light;
  bool red_light;
  bool yellow_light;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

const int redLedPin = 21;
const int yellowLedPin = 20;
const int greenLedPin = 15;

void setup() {

  // Set LED pins as output
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);  
  pinMode(greenLedPin, OUTPUT);
  
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  
}

void onLightIdChange()  
{
  // Turn off all LEDs
  turnoffAllLights();
  
  // Determine which LED to turn on based on the received value
  if (light_id == "red") 
  {
    digitalWrite(redLedPin, HIGH); // Turn on red LED
  }
  else if (light_id == "yellow") 
  {
    digitalWrite(yellowLedPin, HIGH); // Turn on yellow LED
  } 
  else if (light_id == "green") 
  {
    digitalWrite(greenLedPin, HIGH); // Turn on green LED
  } 
  else 
  {
    Serial.println("Invalid value received");
  }
}

void onRedLightChange()  
{
  // Turn off all LEDs
  turnoffAllLights();

  if (red_light == true)
  {
    digitalWrite(redLedPin, HIGH);
  }
  else if (red_light == false)
  {
    digitalWrite(redLedPin, LOW);
  }    
}

void onYellowLightChange()  
{
  // Turn off all LEDs
  turnoffAllLights();

  if (yellow_light == true)
  {
    digitalWrite(yellowLedPin, HIGH);
  }
  else if (yellow_light == false)
  {
    digitalWrite(yellowLedPin, LOW);
  }  
}

void onGreenLightChange()  
{
  // Turn off all LEDs
  turnoffAllLights();

  if (green_light == true)
  {
    digitalWrite(greenLedPin, HIGH);
  }
  else if (green_light == false)
  {
    digitalWrite(greenLedPin, LOW);
  }  
}

void turnoffAllLights()
{
  // Turn off all LEDs
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);  
  digitalWrite(greenLedPin, LOW);
}