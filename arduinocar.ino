#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial CAR_BT(11,12); //定義 PIN11 及 PIN12 分別為 RX 及 TX 腳位

/* Input for leftMotor:
   IN1      IN2      Action
   LOW      LOW      Stop
   HIGH     LOW      Forward  
   LOW      HIGH     Backward
   HIGH     HIGH     Stop
*/

const int leftMotorIn1 = 5;
const int leftMotorIn2 = 6;

/* Input for rightMotor:
   IN3      IN4      Action
   LOW      LOW      Stop
   HIGH     LOW      Forward  
   LOW      HIGH     Backward
   HIGH     HIGH     Stop
*/

const int rightMotorIn3 = 9;      
const int rightMotorIn4 = 10;

const int ENA = 2;
const int ENB = 3;


void setup()  
{
  pinMode(leftMotorIn1, OUTPUT);
  pinMode(leftMotorIn2, OUTPUT);
  pinMode(rightMotorIn3, OUTPUT);
  pinMode(rightMotorIn4, OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  Serial.begin(9600); //Arduino起始鮑率：9600
  CAR_BT.begin(9600); //藍牙鮑率：9600 注意！每個藍牙晶片的鮑率都不太一樣，請務必確認
}

void loop()
{
  int inSize;
  int input;
  if( (inSize = (CAR_BT.available())) > 0) { //讀取藍牙訊息
      Serial.print("size = ");
      Serial.println(inSize);
      Serial.print("Input = ");
      Serial.println(input = CAR_BT.read());

      
      if( input == 8 ) {
        forward();
        Serial.println(input);
      }
      
      if( input == 2 ) {
        backward();
        Serial.println(input);
      }
    
      if( input == 7 ) {
        Fleft();
        Serial.println(input);
      }
      
      if( input == 9 ) {
        Fright();
        Serial.println(input);
      }
      if( input == 1 ) {
        Bleft();
        Serial.println(input);
      }
      
      if( input == 3 ) {
        Bright();
        Serial.println(input);
      }
      if( input == 5 ) {
        motorstop();
        Serial.println(input);
      }
  }    
}

void motorstop()
{
  digitalWrite(leftMotorIn1, LOW);
  digitalWrite(leftMotorIn2, LOW);
  digitalWrite(rightMotorIn3, LOW);
  digitalWrite(rightMotorIn4, LOW);
}

void forward()
{
  analogWrite(leftMotorIn1, 0);
  analogWrite(leftMotorIn2, 255);
  analogWrite(rightMotorIn3, 255);
  analogWrite(rightMotorIn4, 0);
}

void backward()
{
  analogWrite(leftMotorIn1, 255);
  analogWrite(leftMotorIn2, 0);
  analogWrite(rightMotorIn3, 0);
  analogWrite(rightMotorIn4, 255);
}

void Fright()
{
    analogWrite(leftMotorIn1, 0);
    analogWrite(leftMotorIn2, 255);
    analogWrite(rightMotorIn3, 150);
    analogWrite(rightMotorIn4, 0);
}

void Fleft()
{
    analogWrite(leftMotorIn1, 0);
    analogWrite(leftMotorIn2, 150);
    analogWrite(rightMotorIn3, 255);
    analogWrite(rightMotorIn4, 0);
}
void Bright()
{
    analogWrite(leftMotorIn1, 255);
    analogWrite(leftMotorIn2, 0);
    analogWrite(rightMotorIn3, 0);
    analogWrite(rightMotorIn4, 150);
}

void Bleft()
{
    analogWrite(leftMotorIn1, 150);
    analogWrite(leftMotorIn2, 0);
    analogWrite(rightMotorIn3, 0);
    analogWrite(rightMotorIn4, 255);
}
