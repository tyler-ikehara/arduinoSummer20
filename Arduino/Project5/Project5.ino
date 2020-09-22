#include <Servo.h>

Servo myServo;
int const potPin = A0;
int potVal;
int angle;
void setup() {
  myServo.attach(9);
  Serial.begin(9600);  
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("PotVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print("\t Angle: ");
  Serial.println(angle);
  myServo.write(angle);
  delay(15);
}
