#include <Stepper.h>
Stepper myStepper(400, 8, 9, 10, 11);
int south=0;
int north=0;
int east=0;
int d=0;
int in1 = 9;
int in2 = 8;

int in3 = 7;
int in4 = 6;
int south1[10];
int north1[10];
int east1[10];
int i;
void setup() {
  
  // put your setup code here, to run once:
  
 myStepper.setSpeed(60);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  d=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  readmics();

  //delay(1000);

}

void readmics(){
  for(i=0;i<10;i++){
  south1[i]=analogRead(A5);
  south=south+south1[i];
  east1[i]=analogRead(A4);
  east=east+east1[i];
  north1[i]=analogRead(A3);
  north=north+north1[i];
  }
  south=south/10;
  north=north/10;
  east=east/10;
  //Serial.println(south);
  //Serial.println(east);
  //Serial.println(north);
  //Serial.println();
  //Serial.println();
  
  if(north>65||south>87||east>77)
  
  {
     Serial.println(south);
  Serial.println(east);
  Serial.println(north);
  Serial.println();
  Serial.println();
    if(north+22>south&&north+10>east){
     if(d==-1)
         myStepper.step(-1100);
     if(d==0)
        myStepper.step(-550);
     
     
    d=1;
     Serial.println("North");
    }
       if(south>north+22&&south>east+10){
        if(d==1)
         myStepper.step(1100);
         if(d==0)
           myStepper.step(550);
       
      Serial.println("south");
      d=-1;
       }
       if(east+10>south&&east>north+10){
        if(d==-1)
        myStepper.step(-550);
        if(d==1)
         myStepper.step(550);
        d=0;
       
      Serial.println("east");
       }
       }
    
  delay(100);
   
   
  
}
