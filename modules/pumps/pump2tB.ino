//genel tahliye


// Pin tanımlamaları
#define POMPA_PIN 2 // Pompanın bağlı olduğu pin
#define INTERVAL 21600000 // 6 saat = 6 * 60 dakika * 60 saniye * 1000 milisaniye = 21,600,000 milisaniye

unsigned long previousMillis0 = 0; // Önceki milisaniye değeri saklanacak değişken

bool pompaDurumu = false; // Pompanın açık veya kapalı olduğunu belirten değişken

void setup() {
  pinMode(POMPA_PIN, OUTPUT); // Pompa pini çıkış olarak ayarlanır
}

void pompaKontrol() {
  unsigned long currentMillis0 = millis(); // Geçerli milisaniye değeri alınır

  if (currentMillis0 - previousMillis0 >= INTERVAL) { // Belirli aralıklarda kontrol edilir
    previousMillis0 = currentMillis0; // Önceki milisaniye değeri güncellenir

    // Pompa durumuna göre işlem yapılır
    if (pompaDurumu) {
      digitalWrite(POMPA_PIN, LOW); // Pompa kapatılır
    } else {
      digitalWrite(POMPA_PIN, HIGH); // Pompa açılır
    }

    if
    // Pompa durumu tersine çevrilir
    pompaDurumu = !pompaDurumu;
  }
}
