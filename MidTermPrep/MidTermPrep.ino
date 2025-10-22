const int RedLEDPin = 9;
const int GreenLEDPin = 10;
const int BlueLEDPin = 11;

const int pushButton = 2;

int buttonState = 0;

void setup() {

  pinMode(RedLEDPin, OUTPUT);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(BlueLEDPin, OUTPUT);
  pinMode(pushButton, INPUT);

}

void loop() {

  buttonState = !digitalRead(pushButton);
  
  if ( buttonState == HIGH){
      PowerLEDControl(RedLEDPin, 0);
      PowerLEDControl(GreenLEDPin, 0);
      PowerLEDControl(BlueLEDPin, 0);
  }
  else{
    PowerLEDControl(RedLEDPin, 255);
    PowerLEDControl(GreenLEDPin, 255);
    PowerLEDControl(BlueLEDPin, 255);
  } 

}

void PowerLEDControl(int color, int brightness) {
  analogWrite(color, brightness);
}



