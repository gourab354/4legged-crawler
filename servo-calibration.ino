/* -----------------------------------------------------------------------------
  - Project: Quadruped Servo Calibration Code (All Servos to 90°)
   -----------------------------------------------------------------------------*/

#include <Servo.h>

// Define 12 servos for 4 legs
Servo servo[4][3];

// Define servos' ports matching your hardware wiring
const int servo_pin[4][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };

void setup() {
  // Start serial monitor for feedback
  Serial.begin(9600);
  Serial.println("Starting Servo Calibration...");
  Serial.println("All servos are being sent to 90 degrees (Center Position).");

  // Attach all servos and write them to 90 degrees
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      servo[i][j].attach(servo_pin[i][j]);
      servo[i][j].write(90); // Neutral calibration angle
      delay(100); // Small delay to prevent power surges
    }
  }

  Serial.println("Calibration complete. You can now mount your servo horns.");
}

void loop() {
  // Keep holding the 90-degree position while you screw on the mechanical linkages
}