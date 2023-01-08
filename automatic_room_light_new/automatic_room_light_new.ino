
//defining entry count sensor pin number
#define entry_tigger A0
#define entry_echo A1

//defining exit count sensor pin number
#define exit_tigger A4
#define exit_echo A5

//define relay on pin
#define room_light 7

float entry_distance=0;
float exit_distance=0;

int entry_flag=0;
int exit_flag=0;

int person=0;


void setup() {
  Serial.begin(9600);// initialize serial communication at 9600 bits per second:
  
  // set pin mode for entry sensor:
    pinMode(entry_tigger,OUTPUT);
    pinMode(entry_echo,INPUT);

  //set pin mode for exit sensor
    pinMode(exit_tigger,OUTPUT);
    pinMode(exit_echo,INPUT);

  //set pin mode for room light
    pinMode(room_light,OUTPUT);

}

float entry_exit_read(int sensor_tigger, int sensor_echo){

  float time;
  float distance;
  
  digitalWrite(sensor_tigger,LOW);
  delayMicroseconds(2);
  digitalWrite(sensor_tigger,HIGH);
  delayMicroseconds(10);
  time=pulseIn(sensor_echo,HIGH);

  distance=(time*0.034)/2;

  return distance;
   
}

void loop() {
  // Read entry and exit distance:
  entry_distance=entry_exit_read(entry_tigger,entry_echo);
  delay(30);
  exit_distance=entry_exit_read(exit_tigger,exit_echo);
  delay(30);
  
  Serial.println("Entry Distance");
  Serial.println(entry_distance);

  Serial.println("Exit Distance");
  Serial.println(exit_distance);

  Serial.println("Persion: ");
  Serial.println(person);
  delay(1000);

  if(entry_distance<90 && entry_flag==0){
    entry_flag=1;
    
    if(exit_flag==0){
      
        person = person+1;
     }
    
     
  }else if(exit_distance<90 && exit_flag==0){
       exit_flag=1;
       
       if(entry_flag==0){
        
          person = person-1;
      }
      
      
  }else if(entry_distance>90 && exit_distance>90 && entry_flag==1 && exit_flag==1){
      entry_flag=0, exit_flag=0;
      delay(1000); 
  }
  if(person>0){
       digitalWrite(room_light,HIGH); 
    }else{
        digitalWrite(room_light,LOW);
      
      }

  Serial.println("Entry Flag");
  Serial.println(entry_flag);
  
  Serial.println("Exit Flag");
  Serial.println(exit_flag);
}
