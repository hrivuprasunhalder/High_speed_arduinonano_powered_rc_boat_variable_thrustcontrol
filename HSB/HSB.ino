int mtr_A_en= 5;
int mtr_A_in1= 6;
int mtr_A_in2= 7;

int mtr_B_en= 10;
int mtr_B_in1= 8;
int mtr_B_in2= 9;

int ch1= 2;
int ch3= 3;

void setup() {  


  pinMode(mtr_A_en,OUTPUT);
  pinMode(mtr_A_in1,OUTPUT);
  pinMode(mtr_A_in2,OUTPUT);

  pinMode(mtr_B_en,OUTPUT);
  pinMode(mtr_B_in1,OUTPUT);
  pinMode(mtr_B_in2,OUTPUT);  

  pinMode(ch1,INPUT);
  pinMode(ch3,INPUT);

  
}

void loop() {

  
  int steer= pulseIn(ch1,HIGH,25000);
  int throttle= pulseIn(ch3,HIGH,25000);


  int speed= map(throttle,1000,2000,40,255);
  analogWrite(mtr_A_en,speed);
  analogWrite(mtr_B_en,speed);
  
  
  digitalWrite(mtr_A_in1,LOW);
  digitalWrite(mtr_A_in2,HIGH);
  digitalWrite(mtr_B_in1,LOW);
  digitalWrite(mtr_B_in2,HIGH);

  if(steer>1650){
     
     analogWrite(mtr_A_en,(speed-100));
    
  }

  else if(steer< 1350)
  {
    analogWrite(mtr_B_en,(speed-100));
  }

}
