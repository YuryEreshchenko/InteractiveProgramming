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
int ledCounter = 1;

bool buttonPressed = false;

String currentColor = "OFF";

bool ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

bool directionColor = true;


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

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    if (directionColor == true){
      ledCounter++;
      if (ledCounter == 5){
      ledCounter = 1;
      }
    }
    else {
      ledCounter--;
      if (ledCounter == 0){
      ledCounter = 4;
      }
    }
    }

  }
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
    
    directionColor = !directionColor;

    buttonPressed = true;
    delay(5);  //Debounce
    } 
    
  else if (pushButtonState == LOW && buttonPressed) {
    buttonPressed = false;
    delay(5);  //Debounce
  }



  //RED
  if (ledCounter == 1) {
    if (ledState == HIGH) {
      TurnColorON(RedLEDPin);
      TurnColorOFF(GreenLEDPin);
      TurnColorOFF(BlueLEDPin);
    } else {
      TurnColorOFF(RedLEDPin);
      TurnColorOFF(GreenLEDPin);
      TurnColorOFF(BlueLEDPin);
    }

    currentColor = "RED";


  }

  //GREEN
  else if (ledCounter == 2) {
    if (ledState == HIGH) {
      TurnColorOFF(RedLEDPin);
      TurnColorON(GreenLEDPin);
      TurnColorOFF(BlueLEDPin);
    } else {
      TurnColorOFF(RedLEDPin);
      TurnColorOFF(GreenLEDPin);
      TurnColorOFF(BlueLEDPin);
    }
    currentColor = "GREEN";
  }

  //BLUE
  else if (ledCounter == 3) {
    if (ledState == HIGH) {
      TurnColorOFF(RedLEDPin);
      TurnColorOFF(GreenLEDPin);
      TurnColorON(BlueLEDPin);
    } else {
      TurnColorOFF(RedLEDPin);
      TurnColorOFF(GreenLEDPin);
      TurnColorOFF(BlueLEDPin);
    }
    currentColor = "BLUE";
  }

  //WHITE
  else if (ledCounter == 4) {
    if (ledState == HIGH) {
      TurnColorON(RedLEDPin);
      TurnColorON(GreenLEDPin);
      TurnColorON(BlueLEDPin);
    } else {
      TurnColorOFF(RedLEDPin);
      TurnColorOFF(GreenLEDPin);
      TurnColorOFF(BlueLEDPin);
    }

    currentColor = "WHITE";
    
  }


  


}

void TurnColorON(int color) {
  digitalWrite(color, LOW);  // turn the led (HIGH is the voltage level)
}

void TurnColorOFF(int color) {
  digitalWrite(color, HIGH);  // turn the led (HIGH is the voltage level)
}
