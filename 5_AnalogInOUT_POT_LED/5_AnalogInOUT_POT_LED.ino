/*Yury Ereshchenko 114012010
This codes controls the RGB light
It cycles the colors of RedLEDPin, GreenLEDPin, BlueLEDPin, yellow, pink, turquoise and white


09/24/2025

*/


//Setup Arduino pins
const int RedLEDPin = 9;
const int GreenLEDPin = 10;
const int BlueLEDPin = 11;
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;  // value read from the pot
const int pushButton = 2;
int pushButtonState = 0;
int ledCounter = 1;

bool buttonPressed = false;

String currentColor = "OFF";

bool ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

bool directionColor = true;

int led = 9;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);

  pinMode(RedLEDPin, OUTPUT);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(BlueLEDPin, OUTPUT);

  pinMode(pushButton, INPUT);
}




// the loop function runs over and over again forever
void loop() {

  
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  brightness = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(brightness);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
  
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    if (brightness >= 255){
      ledCounter++;
    if (ledCounter > 4){
      ledCounter = 1;
    }
    }
  // wait for 30 milliseconds to see the dimming effect

  }
  delay(30);


  //RED
  if (ledCounter == 1) {
      TurnColor(RedLEDPin, brightness);
      TurnColor(GreenLEDPin, 255);
      TurnColor(BlueLEDPin, 255);
    currentColor = "RED";


  }

  //GREEN
  else if (ledCounter == 2) {
      TurnColor(RedLEDPin, 255);
      TurnColor(GreenLEDPin, brightness);
      TurnColor(BlueLEDPin, 255);
    currentColor = "GREEN";
  }

  //BLUE
  else if (ledCounter == 3) {

      TurnColor(RedLEDPin, 255);
      TurnColor(GreenLEDPin,255);
      TurnColor(BlueLEDPin, brightness);
    currentColor = "BLUE";
  }

  //WHITE
  else if (ledCounter == 4) {

      TurnColor(RedLEDPin, brightness);
      TurnColor(GreenLEDPin, brightness);
      TurnColor(BlueLEDPin, brightness);

    currentColor = "WHITE";

}
}

void TurnColor(int color, int brightness) {
  analogWrite(color, brightness);  
}