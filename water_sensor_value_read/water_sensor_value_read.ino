int green_LED=4;
int red_LED=7;
int water_sensor=A5;
int water_value=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(green_LED,OUTPUT);
  pinMode(red_LED,OUTPUT);
  pinMode(water_sensor,INPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:
 water_value=analogRead(water_sensor);

 if(water_value<150){

    Serial.println("Water label Low");
    digitalWrite(red_LED,HIGH);
    delay(5000);
    digitalWrite(red_LED,LOW);
    delay(1000);
  }
  if(water_value>500){

    Serial.println("Water label HIGH");
    digitalWrite(green_LED,HIGH);
    delay(500);
    digitalWrite(green_LED,LOW);
    delay(1000);
    
   }
  

}
