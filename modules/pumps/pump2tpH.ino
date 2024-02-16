#include <pump3.ino>

//pompa baz sonrası tahliye



// Pin tanımlamaları
#define POMPA_PIN 9  // Peristaltik pompa için kullanılan pin
#define SEVIYE_SENSORU_PIN 7  // Dijital sıvı seviye sensörü için kullanılan pin

void setup() {
  pinMode(POMPA_PIN, OUTPUT);  // Pompa pinini çıkış olarak ayarla
  pinMode(SEVIYE_SENSORU_PIN, INPUT);  // Sıvı seviye sensörü pinini giriş olarak ayarla
}

void loop() {
  // Sıvı seviye sensöründen okunan değeri al
  int seviye = digitalRead(SEVIYE_SENSORU_PIN);
  
  // Eğer sıvı seviyesi 0 ise pompayı çalıştır
  if (seviye == 0) {
    digitalWrite(POMPA_PIN, HIGH);  // Pompa çalıştır
  } else {
  
    digitalWrite(POMPA_PIN, LOW);  // Pompa durdur
  }
}

while 

