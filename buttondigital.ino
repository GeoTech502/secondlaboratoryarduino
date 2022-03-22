const int LED = 3;

void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,0);
}

void loop(){
if (Serial.available()>0){
    char serialData = Serial.read();
    if (serialData == '1'){
      digitalWrite(LED,0);
    }
    if (serialData == '0'){
      digitalWrite(LED,1);
    }
  }
}
