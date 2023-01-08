int GASA0 = A0;
int FIREA1= A1;
int buzzer = 10;
int gasvalue;
int fireValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(GASA0, INPUT);
  pinMode(FIREA1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int somekSensor=analogRead(GASA0);
  int fireSensor=analogRead(FIREA1);
  
  gasvalue=(somekSensor)/35;
  fireValue=(fireSensor/1035)*100;
  
  Serial.println("Gas sensor value");
  Serial.println(somekSensor);
  Serial.print(gasvalue);
  Serial.print("% \n");
  Serial.println("Fire Sensor");
  Serial.println(fireSensor);
  Serial.print(fireValue);
  Serial.println("%");
  delay(1000);

  if(gasvalue>4 || fireSensor<500){
    Serial.println("Fire");
    tone(buzzer, 1000, 10000);
    delay(2000);
    noTone(buzzer);
    delay(100);
    }else{
      noTone(buzzer);
      }

}
