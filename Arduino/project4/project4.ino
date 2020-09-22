const int greenLEDpin= 9;
const int redLEDpin = 11;
const int blueLEDpin = 10;

const int greenSensPin= A2;
const int redSensPin= A1;
const int blueSensPin= A0;

int redVal= 0;
int blueVal= 0;
int greenVal= 0;

int redSens= 0;
int blueSens= 0;
int greenSens= 0;
void setup() {
  Serial.begin(9600);
  pinMode(greenLEDpin, OUTPUT);
  pinMode(redLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
}

void loop() {
  redSens= analogRead(redSensPin);
  delay(5);
  blueSens= analogRead(blueSensPin);
  delay(5);
  greenSens= analogRead(greenSensPin);
  Serial.print("Sensor Values:\t red: ");
  Serial.print(redSens);
  Serial.print("\t blue: ");
  Serial.print(blueSens);
  Serial.print("\t green: ");
  Serial.println(greenSens);
  redVal= redSens/4;
  blueVal= blueSens/4;
  greenVal= greenSens/4;
  Serial.print("Color Values:\t red: ");
  Serial.print(redVal);
  Serial.print("\t blue: ");
  Serial.print(blueVal);
  Serial.print("\t green: ");
  Serial.println(greenVal);
  analogWrite(redLEDpin, redVal);
  analogWrite(greenLEDpin, greenVal);
  analogWrite(blueLEDpin, blueVal);
}
