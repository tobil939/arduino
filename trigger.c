int led = 13; // pin 13 Zuweisung als led
int trig = 4; // pin 4 Zuweisung als trig, Ausgabe des Trigger
int sig = 3;  // pin 3 Zuweisung als sig, lisst GS_LS ein
int fups = 2; // pin 2 Zuweisung als fups, lisst das Triggersignal des FuPs ein

void setup() {
  pinMode(led, OUTPUT);  // led wird als Ausgang definiert
  pinMode(trig, OUTPUT); // trig wird als Ausgang definiert
  pinMode(sig, INPUT);   // sig wird als Eingang definiert
  pinMode(fups, INPUT);  // fups wird als Eingang definiert
}

void loop() {
  // Initialisierung
  digitalWrite(led, LOW);  // schaltet die LED aus
  digitalWrite(trig, LOW); // schaltet den Trigger aus

  // LED an wenn FuPs Trigger Aus
  if (digitalRead(fups) == HIGH) { // wenn fups high ist
    digitalWrite(led, HIGH);       // wird die LED eingeschaltet
  } else {
    digitalWrite(led, LOW); // wenn nicht, bleibt die LED aus
  }

  // Trigger wenn FuPs und Signal passen
  if (digitalRead(fups) == HIGH &&
      digitalRead(sig) == LOW) { // wenn fups high und sig low
    delayMicroseconds(500);      // 500 Mikrosekunden warten
    digitalWrite(trig, HIGH);    // Triggersignal ein schlaten
    delay(30000);                // Trigger 30s an lassen
    digitalWrite(tig, LOW);      // Trigger dann wieder aus schalten
  } else {
    digitalWrite(trig, LOW);
  }
}
