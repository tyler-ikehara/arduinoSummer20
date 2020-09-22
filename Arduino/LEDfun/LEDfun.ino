/* A program that changes the color of a RGB LED depending on which button is pressed.
 * The value written to the R, G, or B depends on the value of a potentiometer.
 * Full video of the circuit: https://www.youtube.com/watch?v=rthQdZFWuiM
 * - Tyler Ikehara 2020
*/

//declaring pin numbers
int redRGBpin = 11;
int blueRGBpin = 10;
int greenRGBpin = 9;

int redVal = 0;
int blueVal = 0;
int greenVal = 0;

const int potPin = A0;

int greenButton = 5;
int blueButton = 4;
int redButton = 3;
int controlButton = 2;

int greenLed = 8;
int blueLed = 7;
int redLed = 6;

//initializing variables
int blueState = 0;
int redState = 0;
int greenState = 0;
int controlState = 0;

int pinVal = 0;
int colorVal = 0;

int count =0;
void setup() { //setting up serial monitor and pinmodes of the LEDs and buttons
  Serial.begin(9600);
  pinMode(redRGBpin, OUTPUT);
  pinMode(blueRGBpin, OUTPUT);
  pinMode(greenRGBpin, OUTPUT);
  pinMode(greenButton, INPUT);
  pinMode(blueButton, INPUT);
  pinMode(redButton, INPUT);
  pinMode(controlButton, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
//setting the intial values of the RGB LED to 0, and setting the other LEDs to be off
  analogWrite(redRGBpin, redVal);
  analogWrite(blueRGBpin, blueVal);
  analogWrite(greenRGBpin, greenVal);
  digitalWrite(greenLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(redLed, LOW);
}

void loop() { //determines which button is being pressed
  blueState = digitalRead(blueButton);
  greenState = digitalRead(greenButton);
  redState = digitalRead(redButton);
  controlState = digitalRead(controlButton);
  if(blueState == HIGH){ //depending on which button is pressed, the same colored LED turns on
    reset();
    digitalWrite(blueLed, HIGH);
    pinVal = blueRGBpin; //the pin that we will edit later is changed to the pin of the certain color of the RGB LED
  }
  if(greenState == HIGH){
    reset();
    digitalWrite(greenLed, HIGH);
    pinVal = greenRGBpin;
  }
  if(redState == HIGH){
    reset();
    digitalWrite(redLed, HIGH);
    pinVal = redRGBpin;
  }
  if(greenState == HIGH){
    reset();
    digitalWrite(greenLed, HIGH);
    pinVal = greenRGBpin;
  }
  if(controlState == HIGH){ //if the control button is held for a certain time, the program turns everything back off
    if(count <4){
      reset();
    }
    count ++;
    pinVal = 0;
    colorVal= 0;
    if(count >=4){ //code to write the RGB LED all to 0
      analogWrite(redRGBpin, colorVal);
      analogWrite(blueRGBpin, colorVal);
      analogWrite(greenRGBpin, colorVal);
      count = 0;
    }
    delay(500);
  }
  colorVal = LedVal(); //determines the value that the potentiometer reads
  analogWrite(pinVal, colorVal);  //writes the value to the pin that was selected above
  Serial.print("count = ");
  Serial.println(count);
}

int LedVal(){ //function that updates the value of the RGB LED
   int potVal = analogRead(A0); //reads the value of the potentiometer
   int led = map(potVal, 0, 1023, 0, 255); //maps the values of the potentiometer to the RGB range
   Serial.print("Pot Val: ");
   Serial.print(potVal);
   Serial.print("\t LED val: ");
   Serial.println(led);
   return(led); //returns the remapped value
}

void reset(){ //simple code to turn all of the other LEDs off
  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
}
