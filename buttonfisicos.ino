const int LED = 3;
const int LED2 = 9;
int cont = 0;
const int PULSADOR1 = 2;
const int PULSADOR2 = 8;
int estado1 = LOW;
int estado2 = LOW;

void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(PULSADOR1,INPUT);
  pinMode(PULSADOR2,INPUT);
}

void loop(){
  
  do{
  estado1 = digitalRead(PULSADOR1);
  estado2 = digitalRead(PULSADOR2);  
  }while(estado1 == LOW && estado2 == LOW);

  if(estado1 == HIGH){
    cont++;
    Serial.println("PushButton 1 ha sido presionado");
  }else{
    Serial.println("PushButton 1 sin presionar");
  }

  if(estado1 == HIGH && cont == 2){
    digitalWrite(LED,!digitalRead(LED));
    delay(5000);
    digitalWrite(LED,LOW);
  }

  if(cont == 4){
    digitalWrite(LED2,!digitalRead(LED2));
    delay(5000);
    digitalWrite(LED2,LOW);
    cont = 0;
  }
  
  if(estado2 == HIGH){
    cont++;
    Serial.println("PushButton 2 ha sido presionado");
  }else{
    Serial.println("PushButton 2 sin presionar");
  }

  if(estado2 == HIGH && cont == 2){
    digitalWrite(LED,!digitalRead(LED));
    delay(5000);
    digitalWrite(LED,LOW);
  }

  if(estado2 == HIGH && cont == 4){
    digitalWrite(LED2,!digitalRead(LED2));
    delay(5000);
    digitalWrite(LED2,LOW);
    cont = 0;
  }
  
  do{
  estado1 = digitalRead(PULSADOR1);
  estado2 = digitalRead(PULSADOR2);  
  }while(estado1 == HIGH || estado2 == HIGH);

}
