// Mendefinisikan pin yang digunakan
const int trigPin = 2;
const int echoPin = 3;
const int ledPin = 4;

// Variabel untuk menyimpan jarak yang diukur
long waktu;
int jarak;

void setup() {
  // Mengatur pin sebagai input atau output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Menginisialisasi Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Mengirimkan sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Menerima sinyal ultrasonik yang dipantulkan
  waktu = pulseIn(echoPin, HIGH);

  // Menghitung jarak berdasarkan waktu yang diukur
  jarak = waktu * 0.034 / 2;

  // Menampilkan jarak pada Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  // Mengontrol LED berdasarkan jarak yang diukur
  if (jarak <= 10) {
    digitalWrite(ledPin, HIGH);  // Menyalakan LED jika jarak kurang dari atau sama dengan 10 cm
  } else {
    digitalWrite(ledPin, LOW);   // Mematikan LED jika jarak lebih dari 10 cm
  }

  delay(500);
}