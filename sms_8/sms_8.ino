#include <SoftwareSerial.h>

SoftwareSerial SIM900A(7,8);

String msg;

 

void setup() {

 // put your setup code here, to run once:

 SIM900A.begin(9600); // Setting the baud rate of GSM Module 

 Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)

 Serial.println ("SIM900A Ready");

 delay(100);

}

 

void loop() {

 // put your main code here, to run repeatedly: 

 while (Serial.available()==0){

 }

 msg=Serial.readString();

 SIM900A.println(msg);

 delay(1000);

 

 while (SIM900A.available()==0){

 }

 msg=SIM900A.readString();

 //msg.replace("\n", "");

 Serial.println(msg);

 delay(1000);

 

 msg = "";

}
