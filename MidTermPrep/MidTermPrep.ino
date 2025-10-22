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

  buttonState = !digitalRead(pushButton);

  if (buttonState == HIGH && !buttonPressed){
    pressingTime = millis();
    buttonPressed = true;
    Serial.println("1");

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

  // if ( buttonState == HIGH){
  //   PowerLEDControl(0, 0, 0);
  // }
  // else{
  //   PowerLEDControl(255, 255, 255);
  // } 

}

void PowerLEDControl(int red, int green, int blue) {
  analogWrite(RedLEDPin, red);
  analogWrite(GreenLEDPin, green);
  analogWrite(BlueLEDPin, blue);
}



