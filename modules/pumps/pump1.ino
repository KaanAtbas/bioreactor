//besiyeri giriş
// Pin tanımlamaları
#define POMPA_PIN 2 // Pompanın bağlı olduğu pin
#define INTERVAL 3600000 // 60 dakika = 3600000 milisaniye

unsigned long previousMillis = 0; // Önceki milisaniye değeri saklanacak değişken

bool pompaDurumu = false; // Pompanın açık veya kapalı olduğunu belirten değişken

void setup() {
  pinMode(POMPA_PIN, OUTPUT); // Pompa pini çıkış olarak ayarlanır
}

void pompaKontrol() {
  unsigned long currentMillis = millis(); // Geçerli milisaniye değeri alınır

  if (currentMillis - previousMillis >= INTERVAL) { // Belirli aralıklarda kontrol edilir
    previousMillis = currentMillis; // Önceki milisaniye değeri güncellenir

    // Pompa durumuna göre işlem yapılır
    if (pompaDurumu) {
      digitalWrite(POMPA_PIN, LOW); // Pompa kapatılır
    } else {
      digitalWrite(POMPA_PIN, HIGH); // Pompa açılır
    }

    // Pompa durumu tersine çevrilir
    pompaDurumu = !pompaDurumu;
  }
}

void loop() {
  // Pompa kontrol fonksiyonu çağrılır
  pompaKontrol();

  // Diğer işlemler buraya yazılabilir, ancak delay() kullanılmamalıdır
}

