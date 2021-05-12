void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT); //D3ピンを出力に設定
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13,OUTPUT);
}

void brake(){
  digitalWrite(3, HIGH); //モータがfreeになる
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(13, HIGH);
  return 0;  
}
void free_motor(){
  digitalWrite(3, LOW); //モータがfreeになる
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(13, LOW);  
  return 0;  
}

void motor(int rot,int pwm){
  if(rot){
  analogWrite(3, LOW); //モータがfreeになる
  analogWrite(9, pwm);
  analogWrite(10, pwm);
  analogWrite(11, LOW); 
  }
  else{
  analogWrite(3, pwm );
  analogWrite(9, LOW);
  analogWrite(10, LOW);
  analogWrite(11, pwm);
  } 
  return 0; 
}

void loop() {
  motor(0,150);
  delay(5000);
  motor(1,150);
  delay(5000);
//  for(int i=0;i<255;i++){
//    motor(0,i);
//    delay(30);
//  }
//  brake();
//  for(int i=0;i<255;i++){
//    motor(1,i);
//    delay(30);
//  }
//  brake();
//  delay(3000);
}
