// Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per revolution
const int stepsPerRevolution = 1019;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 bps
  myStepper.setSpeed(16);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'l') {
      myStepper.step(0.1*stepsPerRevolution);  // Rotate left
    } else if (command == 'r') {
      myStepper.step(-0.1*stepsPerRevolution);  // Rotate right
    }
  }
}

