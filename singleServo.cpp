//C++ code
/*Components used: Arduino Uno R3
                   Ultrasonic Sensor HC-SR04
                   Micro-Servo
  with Servo library
*/

#include <Servo.h>

const int trigPin=5;
const int echoPin=4;
int servoSig=6;
Servo myServo;

float duration_us, distance_cm;

void setup()
{
  Serial.begin(9600);
  
  myServo.attach(6);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoSig, OUTPUT);

}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  delay(10);
  
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
