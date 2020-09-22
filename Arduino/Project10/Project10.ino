const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int SwitchStatePin = 5;
const int potPin = A0;

int switchState = 0;
int previousSwitchState = 0;
int directionSwitchState = 0;
int prevDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;
void setup() {
 pinMode(directionSwitchPin, INPUT);
 pinMode(SwitchStatePin, INPUT);
 pinMode(controlPin1, OUTPUT);
 pinMode(controlPin2, OUTPUT);
 pinMode(enablePin, OUTPUT);
 digitalWrite(enablePin, LOW);
}

void loop() {
 switchState = digitalRead(SwitchStatePin);
 delay(1);
 directionSwitchState = digitalRead(directionSwitchPin);
 motorSpeed = analogRead(potPin)/4;
 if(switchState != previousSwitchState){
  if(switchState == HIGH){
    motorEnabled = !motorEnabled;
  }
 }
 if(directionSwitchState != prevDirectionSwitchState){
  if(directionSwitchState == HIGH){
    motorDirection = !motorDirection;
  }
 }
 if(motorDirection == 1){
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW);
 }
 else{
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH);
 }
 if(motorEnabled ==1){
  analogWrite(enablePin, motorSpeed);
 }
 else{
  analogWrite(enablePin, 0);
 }
 prevDirectionSwitchState = directionSwitchState;
 previousSwitchState = switchState;
}
