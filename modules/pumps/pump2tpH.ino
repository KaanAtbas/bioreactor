#include <pump3.ino>

//pompa baz sonrası tahliye



// Pin tanımlamaları
#define POMPA_TAHLIYE 9  // Peristaltik pompa için kullanılan pin
#define SEVIYE_SENSORU_PIN 7  // Dijital sıvı seviye sensörü için kullanılan pin

void setup() {
  pinMode(POMPA_TAHLIYE, OUTPUT);  // Pompa pinini çıkış olarak ayarla
  pinMode(SEVIYE_SENSORU_PIN, INPUT);  // Sıvı seviye sensörü pinini giriş olarak ayarla
}

void loop() {
  // Sıvı seviye sensöründen okunan değeri al
  int seviye = digitalRead(SEVIYE_SENSORU_PIN);
  
  // Eğer sıvı seviyesi 0 ise pompayı çalıştır
while (POMPA_BAZ == HIGH) {
    digitalWrite(POMPA_TAHLIYE, HIGH);  // Pompa çalıştır
  } else {
  
    digitalWrite(POMPA_TAHLIYE, LOW);  // Pompa durdur
  }
}

