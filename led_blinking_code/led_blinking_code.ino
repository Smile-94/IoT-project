
int red_LED=7;
int green_LED=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_LED,OUTPUT);
  pinMode(green_LED,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(red_LED,HIGH);
  digitalWrite(green_LED,HIGH);
  delay(1000);
  digitalWrite(red_LED,LOW);
  digitalWrite(green_LED,LOW);
  delay(1000);

}
