/*Yury Ereshchenko 114012010
This codes controls the RGB light
It cycles the colors of RedLEDPin, GreenLEDPin, BlueLEDPin, yellow, pink, turquoise and white


09/24/2025

*/


//Setup Arduino pins
int RedLEDPin = 5;
int GreenLEDPin = 6;
int BlueLEDPin = 7;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(RedLEDPin, OUTPUT);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(BlueLEDPin, OUTPUT);
}



// the loop function runs over and over again forever
void loop() {

  //Make sure its off
  TurnColorOFF(RedLEDPin);
  TurnColorOFF(GreenLEDPin);
  TurnColorOFF(BlueLEDPin);

  //RedLEDPin
  TurnColorON(RedLEDPin);
  delay(2000);
  TurnColorOFF(RedLEDPin);
  delay(2000);

  //GreenLEDPin
  TurnColorON(GreenLEDPin);
  delay(2000);
  TurnColorOFF(GreenLEDPin);
  delay(2000);

  //BlueLEDPin
  TurnColorON(BlueLEDPin);
  delay(2000);
  TurnColorOFF(BlueLEDPin);
  delay(2000);

  //YELLOW
  TurnColorON(RedLEDPin);
  TurnColorON(GreenLEDPin);
  delay(2000);
  TurnColorOFF(RedLEDPin);
  TurnColorOFF(GreenLEDPin);
  delay(2000);

  //PINK
  TurnColorON(RedLEDPin);
  TurnColorON(BlueLEDPin);
  delay(2000);
  TurnColorOFF(RedLEDPin);
  TurnColorOFF(BlueLEDPin);
  delay(2000);

  //TURQUOISE
  TurnColorON(GreenLEDPin);
  TurnColorON(BlueLEDPin);
  delay(2000);
  TurnColorOFF(GreenLEDPin);
  TurnColorOFF(BlueLEDPin);
  delay(2000);

  //WHITE
  TurnColorON(RedLEDPin);
  TurnColorON(GreenLEDPin);
  TurnColorON(BlueLEDPin);
  delay(2000);
  TurnColorON(RedLEDPin);
  TurnColorON(GreenLEDPin);
  TurnColorON(BlueLEDPin);
  delay(2000);
}

void TurnColorON(int color) {
  digitalWrite(color, LOW);  // turn the LED on (HIGH is the voltage level)
}

void TurnColorOFF(int color) {
  digitalWrite(color, HIGH);  // turn the LED on (HIGH is the voltage level)
}
