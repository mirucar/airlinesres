const int LEDdizisi[] = {5, 6, 7};
void setup() {
  for(int i=0; i<3; i++) {
    pinMode(LEDdizisi[i], OUTPUT);
  }

}

void loop() {
  for(int i=0; i<3; i++) {
    digitalWrite(LEDdizisi[i], HIGH);
    delay(70);
    digitalWrite(LEDdizisi[i], LOW);
  }
  for(int j=2; j>-1; j--) {
    digitalWrite(LEDdizisi[j], HIGH);
    delay(70);
    digitalWrite(LEDdizisi[j], LOW);
  }

}
