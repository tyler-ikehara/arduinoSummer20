/* A program that changes the color of a RGB LED depending on how long a specific button is held.
 * Full video of the circuit: https://www.youtube.com/watch?v=q72axrMjkzs
 * - Tyler Ikehara 2020
 */

//Declaring pin numbers
const int redLEDpin = 11;
const int greenLEDpin = 9;
const int blueLEDpin = 10;

const int buttonRedPin = 2;
const int buttonGreenPin = 3;
const int buttonBluePin = 4;

//initializing variables
int redVal = 1;
int blueVal = 1;
int greenVal = 1;
int buttonR = 0;
int buttonG = 0;
int buttonB = 0;
void setup() { //setting up the serial monitor and the pinmodes of the LEDs and buttons.
  Serial.begin(9600);
  pinMode(redLEDpin, OUTPUT);
  pinMode(greenLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
  pinMode(buttonRedPin, INPUT);
  pinMode(buttonGreenPin, INPUT);
  pinMode(buttonBluePin, INPUT);
}

void loop() { //depending on which button is pressed, the value of the R, G, or B LED is changed
  buttonR = digitalRead(buttonRedPin);
  buttonB = digitalRead(buttonBluePin);
  buttonG = digitalRead(buttonGreenPin);
  while(buttonR == HIGH || buttonB == HIGH || buttonG == HIGH){
      if(buttonR == HIGH && buttonG == HIGH && buttonB == HIGH){
        analogWrite(redLEDpin, redVal);
        analogWrite(blueLEDpin, blueVal);
        analogWrite(greenLEDpin, greenVal);
        redVal++;
        blueVal++;
        greenVal++;
        delay(50);
        buttonR = digitalRead(buttonRedPin);
        buttonG = digitalRead(buttonGreenPin);
        buttonB = digitalRead(buttonBluePin);
    }
      else if(buttonR == HIGH && buttonG == HIGH && buttonB == LOW){
        analogWrite(redLEDpin, redVal);
        analogWrite(blueLEDpin, blueVal);
        analogWrite(greenLEDpin, greenVal);
        redVal++;
        blueVal--;
        greenVal++;
        delay(50);
        buttonR = digitalRead(buttonRedPin);
        buttonG = digitalRead(buttonGreenPin);
        buttonB = digitalRead(buttonBluePin);
    }
     else if(buttonR == HIGH && buttonG == LOW && buttonB == HIGH){
        analogWrite(redLEDpin, redVal);
        analogWrite(blueLEDpin, blueVal);
        analogWrite(greenLEDpin, greenVal);
        redVal++;
        blueVal++;
        greenVal--;
        delay(50);
        buttonR = digitalRead(buttonRedPin);
        buttonG = digitalRead(buttonGreenPin);
        buttonB = digitalRead(buttonBluePin);
    }
     else if(buttonR == LOW && buttonG == HIGH && buttonB == HIGH){
        analogWrite(redLEDpin, redVal);
        analogWrite(blueLEDpin, blueVal);
        analogWrite(greenLEDpin, greenVal);
        redVal--;
        blueVal++;
        greenVal++;
        delay(50);
        buttonR = digitalRead(buttonRedPin);
        buttonG = digitalRead(buttonGreenPin);
        buttonB = digitalRead(buttonBluePin);
    }
     else if(buttonR == HIGH && buttonG == LOW && buttonB == LOW){
        analogWrite(redLEDpin, redVal);
        analogWrite(blueLEDpin, blueVal);
        analogWrite(greenLEDpin, greenVal);
        redVal++;
        blueVal--;
        greenVal--;
        delay(50);
        buttonR = digitalRead(buttonRedPin);
        buttonG = digitalRead(buttonGreenPin);
        buttonB = digitalRead(buttonBluePin);
    }
     else if(buttonR == LOW && buttonG == LOW && buttonB == HIGH){
        analogWrite(redLEDpin, redVal);
        analogWrite(blueLEDpin, blueVal);
        analogWrite(greenLEDpin, greenVal);
        redVal--;
        blueVal++;
        greenVal--;
        delay(50);
        buttonR = digitalRead(buttonRedPin);
        buttonG = digitalRead(buttonGreenPin);
        buttonB = digitalRead(buttonBluePin);
    }
     else if(buttonR == LOW && buttonG == HIGH && buttonB == LOW){
        analogWrite(redLEDpin, redVal);
        analogWrite(blueLEDpin, blueVal);
        analogWrite(greenLEDpin, greenVal);
        redVal--;
        blueVal--;
        greenVal++;
        delay(50);
        buttonR = digitalRead(buttonRedPin);
        buttonG = digitalRead(buttonGreenPin);
        buttonB = digitalRead(buttonBluePin);
    }
      else{
        analogWrite(redLEDpin, redVal);
        analogWrite(blueLEDpin, blueVal);
        analogWrite(greenLEDpin, greenVal);
        redVal--;
        blueVal--;
        greenVal--;
        delay(50);
        buttonR = digitalRead(buttonRedPin);
        buttonG = digitalRead(buttonGreenPin);
        buttonB = digitalRead(buttonBluePin);
      }
  }
    Serial.print("Red Val: ");
    Serial.print(redVal);
    Serial.print("\t Blue Val: ");
    Serial.print(blueVal);
    Serial.print("\t Green Val: ");
    Serial.println(greenVal);
 
}
