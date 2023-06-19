#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define ID "43 D7 17 0E"

#define LedVerde 26
#define LedVermelho 12
#define tranca 2
#define SS_PIN 14
#define RST_PIN 27

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "Batman Ext";
const char* password = "vitor2005";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setup()
{
  SPI.begin();
  lcd.begin(16, 2);
  mfrc522.PCD_Init();
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  timeClient.begin();
  timeClient.setTimeOffset(-3 * 3600);  // Ajuste de fuso horário em segundos (Brasília, UTC-3)
}

void loop() {
  lcd.home();
  lcd.print("Aguardando");
  lcd.setCursor(0, 1);
  lcd.print("Leitura do Cartao");

  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  String idCartao = "";

  Serial.print("ID do cartao: ");

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    idCartao.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    idCartao.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  idCartao.toUpperCase();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ID do cartao:");
  lcd.setCursor(0, 1);
  lcd.print(idCartao);

  delay(2000);

  lcd.clear();

  timeClient.update();
  String datetime = timeClient.getFormattedTime();

  lcd.setCursor(0, 0);
  lcd.print("Data e hora atual:");
  lcd.setCursor(0, 1);
  lcd.print(datetime);

  delay(2000);

  lcd.clear();

  if (idCartao.length() > 0) {
    digitalWrite(LedVerde, HIGH);
    lcd.print("Acesso Liberado");
    lcd.setCursor(0, 1);
    lcd.print("ID: " + idCartao);
    digitalWrite(tranca, HIGH);

    delay(5000);

    digitalWrite(tranca, LOW);
    digitalWrite(LedVerde, LOW);
  }

  lcd.clear();
}
