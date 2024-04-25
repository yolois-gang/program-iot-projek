// Deklarasi pin sensor PIR dan LED
const int pirPin1 = 2;
const int pirPin2 = 3;
const int redLed = 4;
const int greenLed = 5;

int pirState1 = LOW; // Variabel untuk menyimpan status sensor PIR
int pirState2 = LOW; // Variabel untuk menyimpan status sensor PIR

void setup() {
  pinMode(redLed, OUTPUT); // Mengatur pin LED sebagai output
  pinMode(greenLed, OUTPUT); // Mengatur pin LED sebagai output
  pinMode(pirPin1, INPUT);  // Mengatur pin sensor PIR sebagai input
  pinMode(pirPin2, INPUT);  // Mengatur pin sensor PIR sebagai input
  Serial.begin(9600);  // Mengaktifkan Serial Monitor
}

void loop() {
  pirState1 = digitalRead(pirPin1);  // Membaca nilai dari sensor PIR
  pirState2 = digitalRead(pirPin2);  // Membaca nilai dari sensor PIR
  
  // Jika sensor PIR mendeteksi gerakan
  if (pirState1 == HIGH) {
    digitalWrite(greenLed, HIGH);  
    delay(1000);
    digitalWrite(greenLed, LOW);  
    Serial.println("Gerakan pir1 terdeteksi!");  // Menampilkan pesan di Serial Monitor
    Serial.println("Gerakan pir2 tidak terdeteksi!");  // Menampilkan pesan di Serial Monitor
  } else if (pirState2 == HIGH) {
    digitalWrite(greenLed, HIGH);   
    delay(1000);
    digitalWrite(greenLed, LOW);
    Serial.println("Gerakan pir1 tidak terdeteksi!");  // Menampilkan pesan di Serial Monitor
    Serial.println("Gerakan pir2 terdeteksi!");  // Menampilkan pesan di Serial Monitor
  } else if(pirState1 == HIGH && pirState2 == HIGH){
    digitalWrite(greenLed, HIGH); 
    delay(1000);
    digitalWrite(greenLed, LOW);  
    Serial.println("Gerakan pir1 terdeteksi!");  // Menampilkan pesan di Serial Monitor
    Serial.println("Gerakan pir2 terdeteksi!");  // Menampilkan pesan di Serial Monitor
  }else{
    digitalWrite(redLed, HIGH);
    delay(1000);
    digitalWrite(redLed, LOW);
    delay(1000);
    Serial.println("Gerakan pir1 tidak terdeteksi!");
    Serial.println("Gerakan pir2 tidak terdeteksi!");
  }
  delay(500); // Delay untuk menghindari pembacaan yang berulang-ulang
}




  // NYALA LED LEMAH - ADANYA KESALAHAN LOGIKA
  // if (pirState1 == HIGH) {
  //   digitalWrite(ledPin, HIGH);   // Menyalakan LED
  //   Serial.println("Gerakan pir1 terdeteksi!");  // Menampilkan pesan di Serial Monitor
  // } else {
  //   digitalWrite(ledPin, LOW); // Mematikan LED
  //   Serial.println("Gerakan pir1 tidak terdeteksi!");
  // }
  // delay(500);
  //   if (pirState2 == HIGH) {
  //   digitalWrite(ledPin, HIGH);   // Menyalakan LED
  //   Serial.println("Gerakan pir2 terdeteksi!");  // Menampilkan pesan di Serial Monitor
  // } else {
  //   digitalWrite(ledPin, LOW); // Mematikan LED
  //   Serial.println("Gerakan pir2 tidak terdeteksi!");
  // }
  // delay(500);


  