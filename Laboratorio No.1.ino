int MonitorSerial;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if (digitalRead(2) == 1) {

    for (int x = 3; x <= 10; x++) {
      digitalWrite(x, LOW);
      delay(250);
    }
    for (int x = 10; x >= 3; x--) {
      digitalWrite(x, HIGH);
      delay(250);
    }
  } else if (Serial.available() > 0) {
    MonitorSerial = Serial.read();
    if (MonitorSerial == '2') {
      for (int x = 3; x <= 10; x++) {
        digitalWrite(x, HIGH);
      }
      Serial.println("Prende");
      delay(2000);
      for (int x = 3; x <= 10; x++) {
        digitalWrite(x, LOW);
      }
      Serial.println("Apaga");
      delay(2000);
      for (int x = 3; x <= 10; x++) {
        digitalWrite(x, HIGH);
      }
      Serial.println("Prende");
      delay(2000);
      for (int x = 3; x <= 10; x++) {
        digitalWrite(x, LOW);
      }
      Serial.println("Apaga");
      delay(2000);
    }
  } else {
    for (int x = 3; x <= 10; x++) {
        digitalWrite(x, HIGH);
      }
  }
}