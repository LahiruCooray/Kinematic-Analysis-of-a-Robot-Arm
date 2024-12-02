#include <Servo.h>

Servo servo2, servo3, servo4;

// Input beta angles
float beta1 = 45;  // Replace with actual input value
float beta2 = 60;  // Replace with actual input value
float beta3 = -30; // Replace with actual input value

float calculateTheta2(float beta1) {
  return beta1; // θ2 = β1
}

float calculateTheta3(float beta2) {
  return beta2 - 45; // θ3 = β2 - π/4 
}

float calculateTheta4(float beta3, float beta2) {
  return beta3 - beta2 + 45; // θ4 = β3 - β2 + π/4 
}

// Function to map angle to servo range (0°-180°)
int mapToServoRange(float angle) {
  return map(angle, -90, 90, 0, 180); // Maps from -90° to 90° to 0-180°
}

void setup() {
  // Attach servos to pins
  servo2.attach(9);  // Pin for Servo 2
  servo3.attach(10); // Pin for Servo 3
  servo4.attach(11); // Pin for Servo 4

  // Initialize servos to 90° (neutral position)
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  delay(500); // Wait for servos to stabilize
}

void loop() {
  // Calculate theta angles
  float theta2 = calculateTheta2(beta1);
  float theta3 = calculateTheta3(beta2);
  float theta4 = calculateTheta4(beta3, beta2);

  // Map theta angles to servo range
  int servo2Pos = mapToServoRange(theta2);
  int servo3Pos = mapToServoRange(theta3);
  int servo4Pos = mapToServoRange(theta4);

  // Move servos to calculated positions
  servo2.write(servo2Pos);
  servo3.write(servo3Pos);
  servo4.write(servo4Pos);

  // Add a delay to allow servos to move
  delay(500);
}
