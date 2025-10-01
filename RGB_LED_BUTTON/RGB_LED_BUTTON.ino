/*Yury Ereshchenko 114012010
This codes controls the RGB light
It cycles the colors of RedLEDPin, GreenLEDPin, BlueLEDPin, yellow, pink, turquoise and white


09/24/2025

*/


//Setup Arduino pins
const int RedLEDPin = 9;
const int GreenLEDPin = 10;
const int BlueLEDPin = 11;

const int pushButton = 2;
int pushButtonState = 0;

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

  pushButtonState = digitalRead(pushButton);
  //Inverse the state becuase module gives the opposite
  if (pushButtonState == LOW) {
    pushButtonState = HIGH;
  }
  else if (pushButtonState == HIGH) {
    pushButtonState = LOW;
  }

  Serial.println(pushButtonState);
  delay(1);

  if (pushButtonState == HIGH){
    TurnColorON(RedLEDPin);
    TurnColorON(GreenLEDPin);
    TurnColorON(BlueLEDPin);
  }

  else {
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
  }
  
  // //Make sure its off
  // TurnColorOFF(RedLEDPin);
  // TurnColorOFF(GreenLEDPin);
  // TurnColorOFF(BlueLEDPin);

  // //GreenLEDPin
  // TurnColorON(GreenLEDPin);
  // delay(5000);
  // TurnColorOFF(GreenLEDPin);
  // delay(1000);

  // //YELLOW
  // TurnColorON(RedLEDPin);
  // TurnColorON(GreenLEDPin);
  // delay(1000);
  // TurnColorOFF(RedLEDPin);
  // TurnColorOFF(GreenLEDPin);
  // delay(1000);

  // //RedLEDPin
  // TurnColorON(RedLEDPin);
  // delay(8000);
  // TurnColorOFF(RedLEDPin);
  // delay(1000);

  // //BlueLEDPin
  // TurnColorON(BlueLEDPin);
  // delay(2000);
  // TurnColorOFF(BlueLEDPin);
  // delay(2000);


  // //PINK
  // TurnColorON(RedLEDPin);
  // TurnColorON(BlueLEDPin);
  // delay(2000);
  // TurnColorOFF(RedLEDPin);
  // TurnColorOFF(BlueLEDPin);
  // delay(2000);

  // //TURQUOISE
  // TurnColorON(GreenLEDPin);
  // TurnColorON(BlueLEDPin);
  // delay(2000);
  // TurnColorOFF(GreenLEDPin);
  // TurnColorOFF(BlueLEDPin);
  // delay(2000);

  // //WHITE
  // TurnColorON(RedLEDPin);
  // TurnColorON(GreenLEDPin);
  // TurnColorON(BlueLEDPin);
  // delay(2000);
  // TurnColorON(RedLEDPin);
  // TurnColorON(GreenLEDPin);
  // TurnColorON(BlueLEDPin);
  // delay(2000);
}

void TurnColorON(int color) {
  digitalWrite(color, LOW);  // turn the LED on (HIGH is the voltage level)
}

void TurnColorOFF(int color) {
  digitalWrite(color, HIGH);  // turn the LED on (HIGH is the voltage level)
}
