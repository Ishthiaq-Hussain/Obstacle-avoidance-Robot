const int trig=8;
const int echo=9;
int rir=0;
int lir=0;
long int d;
const int rmf=13;
const int rmb=12;
const int lmf=11;
const int lmb=10;
void setup() {
pinMode(8,OUTPUT);
pinMode(9,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(rmf,OUTPUT);
pinMode(rmb,OUTPUT);
pinMode(lmf,OUTPUT);
pinMode(lmb,OUTPUT);
Serial.begin(9600);
}
void loop() {
  digitalWrite(trig,HIGH);
  delay(15);
  digitalWrite(trig,LOW);
  d=pulseIn(echo,HIGH);
  rir=analogRead(A3);
  lir=analogRead(A4);
  if(d<=700||rir<=100||lir<=100)
  {
    obstacle(); 
  }
}
  void obstacle()
{
  if(d>=700)
   { 
    digitalWrite(rmf,HIGH);
    digitalWrite(rmb,LOW);
    digitalWrite(lmf,HIGH);
    digitalWrite(lmb,LOW); 
    delay(10);
   }
  else
  {
   compare();
  }  
}
void compare()
{
  if(lir>rir) 
   {
    digitalWrite(rmf,HIGH);
    digitalWrite(rmb,LOW);
    digitalWrite(lmf,LOW);
    digitalWrite(lmb,LOW); 
    delay(10); 
  }
  else if(rir>lir)
  {
    digitalWrite(rmf,LOW);
    digitalWrite(rmb,LOW);
    digitalWrite(lmf,HIGH);
    digitalWrite(lmb,LOW); 
    delay(10); 
  }
  else 
  {
    digitalWrite(lmf,LOW);
    digitalWrite(lmb,LOW);
    digitalWrite(rmf,LOW);
    digitalWrite(rmb,LOW); 
    delay(10); 
  }
}
