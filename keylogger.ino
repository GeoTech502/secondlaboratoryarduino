#define PIN_LED 3
#define PIN_LED2 9

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_LED2,OUTPUT);
  digitalWrite(PIN_LED,0);
  digitalWrite(PIN_LED2,0);
}

int vled = 0, pos, vled2 = 0;
String cad,cad1,cad2;

void loop() {
 if(Serial.available()){
  cad = Serial.readString();
  pos = cad.indexOf(',');
  cad1 = cad.substring(0,pos);
  cad2 = cad.substring(pos+1);

  if(vled != cad1.toInt()){
    vled = cad1.toInt();
  }

  if(vled2 != cad2.toInt()){
    vled2 = cad2.toInt();
  }
  
  Serial.println(cad1);
  Serial.println(cad2);
 }

  digitalWrite(PIN_LED,vled);
  digitalWrite(PIN_LED2,vled2);
  delay(500);
  digitalWrite(PIN_LED,0);
  digitalWrite(PIN_LED2,0);
  delay(500);
}
