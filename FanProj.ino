const int trigPin = 13;
const int echoPin = 12;
const int motor_pin = 11;
const int button = 10;
int buttonState = 0;
const int pinF = 2;
const int pinG = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinA = 8;
const int pinB = 9;
const int red = 7;
long duration;
int distance;
int i = 0;
//All of these constants correspond to the arduino board. Note that some "outputs" aren't here because those “outputs” are the rgb green light and the fan itself because those are powered by the potentiometer which is powered by the motor_pin


void setup() {
  pinMode (button, INPUT_PULLUP);//Button
  pinMode(echoPin, INPUT); //Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(pinA, OUTPUT); //7 segment display
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode (motor_pin, OUTPUT); //Motor/potentiometer/green rgb light
  Serial.begin(9600);
}
void loop() {
  buttonState = digitalRead(button);// This section turns the arduino on from a "wait"/idle state
  if (buttonState == LOW) {
    i=1;
  }
  if (i==1) {
    digitalWrite(trigPin, LOW); //This below section up until the next comment helps take the info from the ultrasonic sensor and calculate it to gather data about the current distance (cm)
    delayMicroseconds(500);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: "); //This above section was to help us gage what distance would be appropriate for the fan/ find the current distance
    Serial.println(distance);
    if (distance <= 15) {
      digitalWrite (motor_pin, HIGH); //Within this certain distance which is adjustable, in this case 15 cm, "F" is displayed and the fan turns on. Note that components to indicate that the fan is off like the red rgb light or sections of the 7 segment are also turned off here
      digitalWrite (red, LOW);
      digitalWrite (pinA, HIGH);
      digitalWrite (pinB, LOW);
      digitalWrite (pinC, LOW);
      digitalWrite (pinD, LOW);
      digitalWrite (pinE, HIGH);
      digitalWrite (pinF, HIGH);
      digitalWrite (pinG, HIGH);
    }
    else if (distance > 15) {
      digitalWrite (motor_pin, LOW); //After a certain distance (in this case 15 cm), everything shuts off except the red rgb light and the "O" display which then turns on to signify that the fan is off
      digitalWrite (red, HIGH);
      digitalWrite (pinA, HIGH);
      digitalWrite (pinB, HIGH);
      digitalWrite (pinC, HIGH);
      digitalWrite (pinD, HIGH);
      digitalWrite (pinE, HIGH);
      digitalWrite (pinF, HIGH);
      digitalWrite (pinG, LOW);
    }
  }
}
