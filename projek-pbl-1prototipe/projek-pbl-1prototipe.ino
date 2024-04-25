// Mendefinisikan pin yang digunakan
const int trigPin = 2;
const int echoPin = 3;
const int ledPin = 4;
const int pirPin = 5;

int pirState = LOW; // Variabel untuk menyimpan status sensor PIR

// Variabel untuk menyimpan jarak yang diukur
long waktu;
int jarak;

void setup() {
  // Mengatur pin sebagai input atau output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);   

  // Menginisialisasi Serial Monitor
  Serial.begin(9600);
}

void loop() {
  pirState = digitalRead(pirPin);  // Membaca nilai dari sensor PIR

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
   if(jarak <=50){
    digitalWrite(ledPin, HIGH);
    delay(500);
    Serial.println("a. Gerakan Terdeteksi dari S.Ultrasonik");
   }else if(pirState == HIGH){
    digitalWrite(ledPin, HIGH);
    delay(500);
    Serial.println("b. Gerakan Terdeteksi dari S.Pir");
   }else if (jarak <= 50 && pirState == HIGH) {
    digitalWrite(ledPin, HIGH);  
    delay(500);
    Serial.println("c. Gerakan terdeteksi dari kedua Sensor");  
  } else if(jarak >50 || pirState == HIGH){
    digitalWrite(ledPin, HIGH);  
    delay(500);
    Serial.println("d. Gerakan terdeteksi dari S.Pir tanpa S.U");
  }else if(jarak <=50 || pirState == LOW){
    digitalWrite(ledPin, HIGH);   
    delay(500);
    Serial.println("e. Gerakan terdeteksi dari S.U tanpa S.Pir");
  }else{
    digitalWrite(ledPin, LOW);   
    Serial.println("f. Gerakan tidak terdeteksi dari kedua sensor");
  }
  delay(500);
}
  //   // Jika sensor PIR mendeteksi gerakan
  // if (pirState1 == HIGH) {
  //   digitalWrite(ledPin, HIGH);   // Menyalakan LED
  //   Serial.println("Gerakan pir1 terdeteksi!");  // Menampilkan pesan di Serial Monitor
  //   Serial.println("Gerakan pir2 tidak terdeteksi!");  // Menampilkan pesan di Serial Monitor
  // } else if (pirState2 == HIGH) {
  //   digitalWrite(ledPin, HIGH);   // Menyalakan LED
  //   Serial.println("Gerakan pir1 tidak terdeteksi!");  // Menampilkan pesan di Serial Monitor
  //   Serial.println("Gerakan pir2 terdeteksi!");  // Menampilkan pesan di Serial Monitor
  // } else if(pirState1 == HIGH && pirState2 == HIGH){
  //   digitalWrite(ledPin, HIGH);   // Menyalakan LED
  //   Serial.println("Gerakan pir1 terdeteksi!");  // Menampilkan pesan di Serial Monitor
  //   Serial.println("Gerakan pir2 terdeteksi!");  // Menampilkan pesan di Serial Monitor
  // }else{
  //   digitalWrite(ledPin, LOW); // Mematikan LED
  //   Serial.println("Gerakan pir1 tidak terdeteksi!");
  //   Serial.println("Gerakan pir2 tidak terdeteksi!");
  // }

