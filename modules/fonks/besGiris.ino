//besiyeri giriş

#define POMPA_BESIYERI 7 // Peristaltik pompa için kullanılan pin
#define SIVI_SEVIYE_SENSORU_PIN 2 // Dijital sıvı seviye sensörü için kullanılan pin

void setup() {
  pinMode(POMPA_BESIYERI, OUTPUT);
  pinMode(SIVI_SEVIYE_SENSORU_PIN, INPUT);
}

void pompaBesiyeriCalistir() {
  // Sıvı seviye sensöründen değeri oku
  int siviSeviyesi = digitalRead(SIVI_SEVIYE_SENSORU_PIN);

  // Eğer sıvı seviyesi 0'a eşitse, pompayı çalıştır
  while (siviSeviyesi = 0) {
    digitalWrite(POMPA_BESIYERI, HIGH); // Pompa çalıştır
    siviSeviyesi = digitalRead(SIVI_SEVIYE_SENSORU_PIN); // Sıvı seviyesini tekrar oku
  }

  digitalWrite(POMPA_BESIYERI, LOW); // Pompa durdur
}