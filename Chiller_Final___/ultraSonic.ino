
void ultraSonicSetting()
{
  pinMode(chiller1, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
}



int calculateLevel(){

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  t = pulseIn(echo, HIGH);
  h = t*340 / 20000;
  h = h + 5;  // offset correction
  if(h<0 || h>100) h=1; 

  return h;
}
