#include "Arduino.h"
#include "voiture_elegoo.h"
#include <Servo.h>
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define LED 13


int Echo = A4;
int Trig = A5;
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(3);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
}
void avant(int car_speed)
{

  analogWrite(ENA, car_speed);
  analogWrite(ENB, car_speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void arriere(int car_speed)
{

  analogWrite(ENA, car_speed);
  analogWrite(ENB, car_speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void gauche(int car_speed)
{

  analogWrite(ENA, car_speed);
  analogWrite(ENB, car_speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void droite(int car_speed)
{
  analogWrite(ENA, car_speed);
  analogWrite(ENB, car_speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void arret() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

int distance_devant() {
  myservo.write(90);
  delay(500);
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  int valeur = (int)pulseIn(Echo, HIGH) / 5;
  Serial.println("devant");
  Serial.println(valeur);
  return valeur;
}

int distance_droite() {
  myservo.write(0);
  delay(500);
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  int valeur = (int)pulseIn(Echo, HIGH) / 5;
  Serial.println("droite");
  Serial.println(valeur);

  return valeur;
}

int distance_gauche() {
  myservo.write(180);
  delay(500);
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  int valeur = (int)pulseIn(Echo, HIGH) / 5;
  Serial.println("gauche");
  Serial.println(valeur);
  return valeur;
}
