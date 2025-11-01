#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 9;
const int echoPin = 8;

Servo myServo;
const int servoPin = 10;


long duration;
int distance;

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);

  lcd.print("Ultrasonic Servo");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1500);
  lcd.clear();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 

  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm   "); 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 20) {
    myServo.write(0);
    lcd.setCursor(0, 1);
    lcd.print("Servo: 0 deg     ");
  } 
  else if (distance > 10) {
    myServo.write(90);
    lcd.setCursor(0, 1);
    lcd.print("Servo: 90 deg    ");
  } 
  else {
    myServo.write(180);
    lcd.setCursor(0, 1);
    lcd.print("Servo: 180 deg   ");
  }

  delay(300); 
}
