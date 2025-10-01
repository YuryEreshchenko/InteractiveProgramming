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
int ledCounter = 0;

bool buttonPressed = false;

String currentColor = "OFF";

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

  Serial.print("Current Color : ");
  Serial.println(currentColor);


  pushButtonState = digitalRead(pushButton);
  //Inverse the state becuase module gives the opposite
  if (pushButtonState == LOW) {
    pushButtonState = HIGH;
  } else if (pushButtonState == HIGH) {
    pushButtonState = LOW;
  }

  if (pushButtonState == HIGH && !buttonPressed) {
    ledCounter++;
    buttonPressed = true;
    delay(5);  //Debounce
  } else if (pushButtonState == LOW && buttonPressed) {
    buttonPressed = false;
    delay(5);  //Debounce
  }

  //OFF
  if (ledCounter == 0) {
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    currentColor = "OFF";
  }

  //RED
  if (ledCounter == 1) {
    TurnColorON(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    currentColor = "RED";
  }

  //GREEN
  else if (ledCounter == 2) {
    TurnColorOFF(RedLEDPin);
    TurnColorON(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    currentColor = "GREEN";
  }

  //BLUE
  else if (ledCounter == 3) {
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorON(BlueLEDPin);
    delay(1000);
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    currentColor = "BLUE";
  }

  //YELLOW
  else if (ledCounter == 4) {
    TurnColorON(RedLEDPin);
    TurnColorON(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    currentColor = ("YELLOW");
  }

  //PURPLE
  else if (ledCounter == 5) {
    TurnColorON(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorON(BlueLEDPin);
    delay(1000);
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    currentColor = "PURPLE";
  }

  //CYAN
  else if (ledCounter == 6) {
    TurnColorOFF(RedLEDPin);
    TurnColorON(GreenLEDPin);
    TurnColorON(BlueLEDPin);
    delay(1000);
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    currentColor = "CYAN";
  }

  //WHITE
  else if (ledCounter == 7) {
    TurnColorON(RedLEDPin);
    TurnColorON(GreenLEDPin);
    TurnColorON(BlueLEDPin);
    delay(1000);
    TurnColorOFF(RedLEDPin);
    TurnColorOFF(GreenLEDPin);
    TurnColorOFF(BlueLEDPin);
    delay(1000);
    currentColor = "WHITE";
  }

  else if (ledCounter == 8) {
    ledCounter = 0;
  }
}

void TurnColorON(int color) {
  digitalWrite(color, LOW);  // turn the led (HIGH is the voltage level)
}

void TurnColorOFF(int color) {
  digitalWrite(color, HIGH);  // turn the led (HIGH is the voltage level)
}
