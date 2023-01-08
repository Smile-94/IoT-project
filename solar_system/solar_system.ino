#define ldr_sensor 13
#define current_sensor A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr_sensor,INPUT);
  pinMode(current_sensor,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr_value=digitalRead(ldr_sensor);
  int current_value=analogRead(current_sensor);
  delay(1000);

  Serial.println("Current Value");
  Serial.println(current_value);

  Serial.println("LDR Value");
  Serial.println(ldr_value);

}
