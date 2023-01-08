#define tigger A0
#define echo A1

#define red_led 7
#define green_led 4
#define yello_led 2

float time=0;
float distance=0;

int temp=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(yello_led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tigger,LOW);
  delayMicroseconds(2);
  digitalWrite(tigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(tigger,LOW);
  delayMicroseconds(2);

  time=pulseIn(echo,HIGH);
  distance=time*0.034/2;

  if(distance<4){
    digitalWrite(green_led,HIGH);
    delay(500);
    digitalWrite(green_led,LOW);
    delay(500);
    
  }else if(distance>4 && distance<12){
       digitalWrite(yello_led,HIGH);
       delay(500);
       digitalWrite(yello_led,LOW);
       delay(500);
    }else if(distance>12){
       digitalWrite(red_led,HIGH);
       delay(500);
       digitalWrite(red_led,LOW);
       delay(500);
        
      }

  Serial.println("Distance");
  Serial.println(distance);
  Serial.print("CM");
  delay(1000);

}
