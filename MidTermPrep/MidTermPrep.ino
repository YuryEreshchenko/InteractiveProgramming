const int RedLEDPin = 9;
const int GreenLEDPin = 10;
const int BlueLEDPin = 11;

const int pushButton = 2;

int buttonState = 0;

unsigned long pressingTime = 0;
const long longPressInterval = 1000;
bool buttonPressed = false; 

int ledCounter = 1;           // Tracks current color (1-7)


void setup() {

  Serial.begin(9600);
  pinMode(RedLEDPin, OUTPUT);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(BlueLEDPin, OUTPUT);
  pinMode(pushButton, INPUT);

}

void loop() {

  int clickType = checkButton();

  if ( clickType == 1){
    changeLEDColor();
  }
}

void changeLEDColor(){
    
    ledCounter++;

    if (ledCounter == 5){
    ledCounter = 0;
    } 
    if (ledCounter == 0){
    PowerLEDControl(0, 0, 0);
    }
    if (ledCounter == 1){
    PowerLEDControl(0, 255, 255);
    }
    if (ledCounter == 2){
    PowerLEDControl(255, 0, 255);
    }
    if (ledCounter == 3){
    PowerLEDControl(255, 255, 0);
    }
    if (ledCounter == 4){
    PowerLEDControl(255, 255, 255);
    }

}


int checkButton(){
  int clickType = 0;
  buttonState = !digitalRead(pushButton);
  delay(5);

  if (buttonState == HIGH && !buttonPressed){
    pressingTime = millis();
    buttonPressed = true;
  }
  if (buttonState == LOW && buttonPressed){
    unsigned long currentTime = millis();
    if (currentTime - pressingTime < longPressInterval){
      Serial.println("Short click");
      clickType = 1;
    }
    else {
      Serial.println("Long Press");
      clickType = 2;
    }
    buttonPressed = false;
  }

  return clickType;

}



void PowerLEDControl(int red, int green, int blue) {
  analogWrite(RedLEDPin, red);
  analogWrite(GreenLEDPin, green);
  analogWrite(BlueLEDPin, blue);
}



