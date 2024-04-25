// Deklarasi pin sensor PIR dan LED
const int pirPin = 3;
const int ledPin = 2;

int pirState = LOW; // Variabel untuk menyimpan status sensor PIR

void setup() {
  pinMode(ledPin, OUTPUT); // Mengatur pin LED sebagai output
  pinMode(pirPin, INPUT);  // Mengatur pin sensor PIR sebagai input
  Serial.begin(9600);  // Mengaktifkan Serial Monitor
}

void loop() {
  pirState = digitalRead(pirPin);  // Membaca nilai dari sensor PIR
  
  // Jika sensor PIR mendeteksi gerakan
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);   // Menyalakan LED
    Serial.println("Gerakan pir terdeteksi!");  // Menampilkan pesan di Serial Monitor
  }else{
    digitalWrite(ledPin, LOW); // Mematikan LED
    Serial.println("Gerakan pir tidak terdeteksi!");
  }
  delay(500); // Delay untuk menghindari pembacaan yang berulang-ulang
}

