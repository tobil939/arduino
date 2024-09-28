#define signal 2
#define fups 3
#define takt 8
#define fups_ein 13
#define safety_pin 9
int lastsignalstate;


void setup() {
  pinMode(signal, INPUT);
  pinMode(fups, INPUT);
  pinMode(takt, OUTPUT);
  pinMode(fups_ein, OUTPUT);
  pinMode(safety_pin, OUTPUT);
}

void loop() {
  digitalWrite(takt, HIGH);
  digitalWrite(fups_ein, LOW);
  digitalWrite(safety_pin, LOW);
  lastsignalstate = 0; 


  if (digitalRead(fups) == HIGH){
    digitalWrite(fups_ein, HIGH);
  } 

 if (digitalRead(signal) == HIGH){
    lastsignalstate = 1;
  }
  
  delayMicroseconds(1000);

  if (lastsignalstate == 1 && digitalRead(fups) == HIGH && digitalRead(signal)== LOW){
    delayMicroseconds(10);
    digitalWrite(safety_pin, HIGH);
    delay(5000);
    digitalWrite(safety_pin, LOW);
  }
  digitalWrite(takt, LOW);
}



