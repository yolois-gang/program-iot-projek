// Define pin untuk sensor ultrasonik pertama
const int TPin1 = 2;
const int EPin1 = 3;

// Define pin untuk sensor ultrasonik kedua
const int TPin2 = 4;
const int EPin2 = 5;

// Define pin LED
const int redLed = 6;
const int greenLed = 7;

// Variabel untuk menyimpan waktu pulsa ultrasonik
long waktu1, jarak1, waktu2, jarak2;

void setup() {
  pinMode(TPin1, OUTPUT);
  pinMode(EPin1, INPUT);
  pinMode(TPin2, OUTPUT);
  pinMode(EPin2, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger sensor ultrasonik pertama
  digitalWrite(TPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(TPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TPin1, LOW);
  
  // Hitung durasi pulsa dari sensor ultrasonik pertama
  waktu1 = pulseIn(EPin1, HIGH);
  
  // Hitung jarak berdasarkan durasi
  jarak1= waktu1*0.034/2;

  // Trigger sensor ultrasonik kedua
  digitalWrite(TPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(TPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TPin2, LOW);
  
  // Hitung durasi pulsa dari sensor ultrasonik kedua
  waktu2 = pulseIn(EPin2, HIGH);
  
  // Hitung jarak berdasarkan durasi
  jarak2 = waktu2*0.034/2;

  // Cek jika kedua sensor mendeteksi objek dalam jarak tertentu
  if(jarak1 <=50){
    digitalWrite(greenLed, HIGH);
    Serial.println("a. Gerakan terdeteksi di SU-1");
    delay(1000);
    digitalWrite(greenLed,LOW);
  }else if(jarak2 <=50){
    digitalWrite(greenLed, HIGH);
    Serial.println("b. Gerakan terdeteksi di SU-2");
    delay(1000);
    digitalWrite(greenLed,LOW);
  } else if(jarak1 <=50 && jarak2 <=50){
    digitalWrite(greenLed, HIGH);
    Serial.println("c. Gerakan terdeteksi di SU-1");
    Serial.println("d. Gerakan terdeteksi di SU-2");
    delay(1000);
    digitalWrite(greenLed,LOW);
  }else{
    Serial.println("e. Gerakan tidak terdeteksi");
    digitalWrite(redLed, HIGH); 
    delay(700);
    digitalWrite(redLed, LOW); 
    delay(700);
  }

  // Tampilkan pembacaan sensor ultrasonik ke Serial Monitor
  Serial.print("Sensor 1: ");
  Serial.print(jarak1);
  Serial.print(" cm | Sensor 2: ");
  Serial.print(jarak2);
  Serial.println(" cm");

  delay(100); // Beri sedikit waktu untuk membaca sensor sebelum membaca kembali
}
