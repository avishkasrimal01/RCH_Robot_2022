#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pmw1 200
#define pmw2 190
#define d 300
#define e 5

LiquidCrystal_I2C lcd(0x27, 16, 4);

int motor1pin1 = 6;
int motor2pin1 = 9;
int motor1pin2 = 12;
int motor2pin2 = 13;

int IRSensor1 = 2;
int IRSensor2 = 3;
int IRSensor3 = 4;
int IRSensor4 = 5;
int IRSensor5 = 7;
int IRSensor6 = 8;
int IRSensor7 = 10;
int IRSensor8 = 11;

int statusSensor1;
int statusSensor2;
int statusSensor3;
int statusSensor4;
int statusSensor5;
int statusSensor6;
int statusSensor7;
int statusSensor8;




void setup()
{

  Serial.begin(9600);

  lcd.begin(16, 4);
  lcd.init();
  lcd.backlight();

  pinMode (IRSensor1, INPUT);
  pinMode (IRSensor2, INPUT);
  pinMode (IRSensor3, INPUT);
  pinMode (IRSensor4, INPUT);
  pinMode (IRSensor5, INPUT);
  pinMode (IRSensor6, INPUT);
  pinMode (IRSensor7, INPUT);
  pinMode (IRSensor8, INPUT);


  pinMode(motor1pin1, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  void DisplayIR();
  void forward();
  void moter_control();
  void left();
  void right();
  void Stop();
  void revers();

}

void loop()
{

  DisplayIR();
  moter_control();
  //forward();





}

void forward()
{
  analogWrite(motor1pin1, pmw1);
  analogWrite(motor2pin1, pmw2);
  delay(11);
}

void left()
{
  analogWrite(motor1pin1, pmw1);
  analogWrite(motor2pin1, 10);
  delay(10);

}
void right()
{
  analogWrite(motor2pin1, 255);
  analogWrite(motor1pin1, 5);
  delay(10);

}
void Stop()
{
  analogWrite(motor1pin1, 0);
  analogWrite(motor1pin2, 0);

  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 0);
}
void revers()
{
  analogWrite(motor1pin2, pmw1);
  analogWrite(motor2pin2, pmw2);
  analogWrite(motor1pin1,   0);
  analogWrite(motor2pin1,   0);
}


void moter_control()
{
  if (statusSensor1 == 1 && statusSensor2 == 1 && statusSensor3 == 1 && statusSensor4 == 1 && statusSensor5 == 1 && statusSensor6 == 1 && statusSensor7 == 1 && statusSensor8 == 1)
  {
    forward();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 1 && statusSensor5 == 1 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    forward();
  }
    else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 1 && statusSensor4 == 1 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    forward();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 1 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    forward();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 1 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    forward();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 1 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    forward();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 1 && statusSensor3 == 1 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    left();
    //delay(500);
  }
  else if (statusSensor1 == 0 && statusSensor2 == 1 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    left();
    //delay(500);
  }
  else if (statusSensor1 == 1 && statusSensor2 == 1 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    left();
    //delay(500);
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 1 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    left();
    //delay(500);
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 1 && statusSensor6 == 1 && statusSensor7 == 1 && statusSensor8 == 1)
  {
    delay(d);
    right();
    

  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 1 && statusSensor4 == 1 && statusSensor5 == 1 && statusSensor6 == 1 && statusSensor7 == 1 && statusSensor8 == 1)
  {
    delay(d);
    right();

  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 1 && statusSensor5 == 1 && statusSensor6 == 1 && statusSensor7 == 1 && statusSensor8 == 1)
  {
    delay(d);
    right();

  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 1 && statusSensor7 == 1 && statusSensor8 == 1)
  {
    delay(d);
    right();

  }
  else if (statusSensor1 == 0 && statusSensor2 == 1 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 1 && statusSensor8 == 1)
  {
    delay(d);
    right();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 1 && statusSensor8 == 1)
  {
    delay(d);
    right();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 1 && statusSensor5 == 0 && statusSensor6 == 1 && statusSensor7 == 1 && statusSensor8 == 1)
  {
    delay(d);
    right();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 ==  0 && statusSensor5 == 0 && statusSensor6 == 1 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    delay(d);
    right();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 ==  0 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 1 && statusSensor8 == 0)
  {
    delay(d);
    right();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 ==  0 && statusSensor5 == 1 && statusSensor6 == 1 && statusSensor7 == 1 && statusSensor8 == 0)
  {
    delay(d);
    right();
  }
  //else if (statusSensor1 == 1 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 ==  0 && statusSensor5 == 0 && statusSensor6 == 1 && statusSensor7 == 0 && statusSensor8 == 1)
  //{
    //delay(d);
    //right();
 // }
    else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 ==  0 && statusSensor5 == 1 && statusSensor6 == 1 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    delay(d);
    right();
  }
    else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 1 && statusSensor7 == 1 && statusSensor8 == 0)
  {
    forward();
  }
  else if (statusSensor1 == 0 && statusSensor2 == 0 && statusSensor3 == 0 && statusSensor4 == 0 && statusSensor5 == 0 && statusSensor6 == 0 && statusSensor7 == 0 && statusSensor8 == 0)
  {
    Stop();
    delay(10);
    //revers();
  }
  else
  {
    Stop();
  }
}

void DisplayIR()
{

  statusSensor1 = digitalRead (IRSensor1);

  Serial.print("IR 1:  ");
  Serial.println(statusSensor1);
  lcd.setCursor(4, 0);
  lcd.print(statusSensor1);


  statusSensor2 = digitalRead (IRSensor2);

  Serial.print("IR 2:  ");
  Serial.println(statusSensor2);
  lcd.setCursor(5, 0);
  lcd.print(statusSensor2);

  statusSensor3 = digitalRead (IRSensor3);

  Serial.print("IR 3:  ");
  Serial.println(statusSensor3);
  lcd.setCursor(6, 0);
  lcd.print(statusSensor3);


  statusSensor4 = digitalRead (IRSensor4);

  Serial.print("IR 4:  ");
  Serial.println(statusSensor4);
  lcd.setCursor(7, 0);
  lcd.print(statusSensor4);


  statusSensor5 = digitalRead (IRSensor5);

  Serial.print("IR 5:  ");
  Serial.println(statusSensor5);
  lcd.setCursor(8, 0);
  lcd.print(statusSensor5);


  statusSensor6 = digitalRead (IRSensor6);

  Serial.print("IR 6:  ");
  Serial.println(statusSensor6);
  lcd.setCursor(9, 0);
  lcd.print(statusSensor6);


  statusSensor7 = digitalRead (IRSensor7);

  Serial.print("IR 7:  ");
  Serial.println(statusSensor7);
  lcd.setCursor(10, 0);
  lcd.print(statusSensor7);


  statusSensor8 = digitalRead (IRSensor8);

  Serial.print("IR 8:  ");
  Serial.println(statusSensor8);
  lcd.setCursor(11, 0);
  lcd.print(statusSensor8);


}
