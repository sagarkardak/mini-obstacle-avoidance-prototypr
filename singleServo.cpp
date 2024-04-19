//C++ code
#include <Servo.h>

int trigPin=5;
int echoPin=4;
int servoSig=6;
int a;
Servo myServo;

float duration_us, distance_cm;

void setup()
{
  Serial.begin(960);
  
  myServo.attach(6);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoSig, OUTPUT);

}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(echoPin, LOW);
  
  duration_us=pulseIn(echoPin, HIGH);
  distance_cm=0.017*duration_us;
    
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  if (distance_cm<=10)
  {
    myServo.write(180);
    delay(15);
  }
  else{
    myServo.write(0);
    delay(15);
  }
  
  delay(50);
}
