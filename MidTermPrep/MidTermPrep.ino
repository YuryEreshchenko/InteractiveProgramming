const int RedLEDPin = 9;
const int GreenLEDPin = 10;
const int BlueLEDPin = 11;

const int pushButton = 2;

int buttonState = 0;

unsigned long pressingTime = 0;
const long longPressInterval = 1000;
bool buttonPressed = false; 

void setup() {

  Serial.begin(9600);
  pinMode(RedLEDPin, OUTPUT);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(BlueLEDPin, OUTPUT);
  pinMode(pushButton, INPUT);

}

void loop() {

  checkButton();

  // if ( buttonState == HIGH){
  //   PowerLEDControl(0, 0, 0);
  // }
  // else{
  //   PowerLEDControl(255, 255, 255);
  // } 

}

void checkButton(){
  buttonState = !digitalRead(pushButton);

  if (buttonState == HIGH && !buttonPressed){
    pressingTime = millis();
    buttonPressed = true;
  }
  if (buttonState == LOW && buttonPressed){
    unsigned long currentTime = millis();
    if (currentTime - pressingTime < longPressInterval){
      Serial.println("Short click");
    }
    else {
      Serial.println("Long Press");
    }
    buttonPressed = false;
  }
}



void PowerLEDControl(int red, int green, int blue) {
  analogWrite(RedLEDPin, red);
  analogWrite(GreenLEDPin, green);
  analogWrite(BlueLEDPin, blue);
}



