#include<Servo.h>

#define pir_sensor 13
#define red_led 12
#define gree_led 11

int sensor_value;
int sensor_value2;

Servo door_open;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pir_sensor, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(gree_led, OUTPUT);
  
  door_open.attach(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value=digitalRead(pir_sensor);
  
  
  
 
  if(sensor_value==1){
    Serial.println("RED");
    door_open.write(0);
    digitalWrite(red_led,HIGH);
    delay(500);
    digitalWrite(red_led,LOW);
    delay(500);
  }else{
    Serial.println("GREEN");
    door_open.write(180);
    digitalWrite(gree_led,HIGH);
    delay(500);
    digitalWrite(gree_led,LOW);
    delay(500);
  }

}
