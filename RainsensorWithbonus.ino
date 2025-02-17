#include <Servo.h>


Servo myservo;       
Servo speedServo;     

int i = 0;  

const int ledPins[4] = {2, 3, 4, 5};

void setup() {
  Serial.begin(9600);
    myservo.attach(9);     
  speedServo.attach(10);  
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void updateSpeedIndicator(int angle, int ledIndex) {
  speedServo.write(angle);
  for (int i = 0; i < 4; i++) {
    if (ledIndex == i) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
    if (ledIndex < 0) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void loop() {
  int reqSenVal = analogRead(A0);
  Serial.println(reqSenVal);
  delay(1);
  if (reqSenVal > 1000) {
    Serial.println("No rain detected, wiper off");
    updateSpeedIndicator(0, -1);
    myservo.write(0);  
    delay(5);
  }
  else if (reqSenVal <= 1000 && reqSenVal > 800) {
    Serial.println("Level 1 - Low speed");
    updateSpeedIndicator(45, 0);  
    for (i = 0; i <= 180; i++) {
      myservo.write(i);
      delay(20);
    }
    delay(1);
    for (i = 180; i >= 0; i--) {
      myservo.write(i);
      delay(20);
    }
  }
  else if (reqSenVal <= 800 && reqSenVal > 600) {
    Serial.println("Level 2 - Moderate speed");
    updateSpeedIndicator(90, 1);  
    for (i = 0; i <= 180; i++) {
      myservo.write(i);
      delay(10);
    }
    delay(1);
    for (i = 180; i >= 0; i--) {
      myservo.write(i);
      delay(10);
    }
  }
  else if (reqSenVal <= 600 && reqSenVal > 460) {
    Serial.println("Level 3 - High speed");
    updateSpeedIndicator(135, 2);
    for (i = 0; i <= 180; i++) {
      myservo.write(i);
      delay(7);
    }
    delay(1);
    for (i = 180; i >= 0; i--) {
      myservo.write(i);
      delay(7);
    }
  }
  else { 
    Serial.println("Heavy Rain Detected - Very High speed");
    updateSpeedIndicator(180, 3); 
    for (i = 0; i <= 180; i++) {
      myservo.write(i);
      delay(3);
    }
    delay(1);
    for (i = 180; i >= 0; i--) {
      myservo.write(i);
      delay(3);
    }
  }
}
