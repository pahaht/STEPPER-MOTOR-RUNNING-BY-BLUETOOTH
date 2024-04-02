#include <AFMotor.h> // Adafruit Motor Shield library

#define STEP_PIN 2 // Step pin connected to L293D shield input 1
#define DIR_PIN 3  // Direction pin connected to L293 shield input 2

AF_Stepper motor(200, 1);

void setup() {
  Serial.begin(9600);  // Initialize the hardware serial communication
  motor.setSpeed(100);  // Set the speed of the stepper motor (0-255)
}

void loop() {
  if (Serial.available()) {
    char receivedChar = Serial.read(); // Read the incoming data from the Bluetooth module
    // Perform actions based on the received data
    if (receivedChar == '7') {
      motor.step(200, FORWARD, SINGLE); // Rotate the stepper motor 200 steps in one direction
    }
  }
}
