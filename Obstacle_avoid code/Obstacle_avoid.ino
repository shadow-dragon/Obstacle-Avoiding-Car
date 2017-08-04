/*
   Code for self-driving car
*/
#define echopin 8 //Echo pin
#define trigpin 9 //Trigger pin

int maximumRange = 30;
float duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  {
    digitalWrite(trigpin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    duration = pulseIn (echopin, HIGH);
    distance = duration / 58.2;
    delay (50);
    Serial.println(distance);
  }

  if (distance >= 30) {

    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, LOW);
    digitalWrite (7, LOW);
    delay (500);

  } else {

    digitalWrite (4, HIGH);
    digitalWrite (5, LOW);
    digitalWrite (6, LOW);
    digitalWrite (7, HIGH);
    delay (2000);

  }


}
