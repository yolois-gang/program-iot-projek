const int ledHijau = 2;
const int ledMerah = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledHijau, HIGH);
  delay(1000);
  digitalWrite(ledHijau, LOW);
  delay(1000);
  digitalWrite(ledMerah, HIGH);
  delay(1000);
  digitalWrite(ledMerah, LOW);
  delay(1000);
}
