# Controle de Acesso com RFID e ESP32

Este é um projeto de controle de acesso utilizando um leitor RFID (RFID-RC522) e um microcontrolador ESP32. O sistema permite a liberação de acesso com base no ID de um cartão RFID válido.

## Pré-requisitos

- Placa ESP32
- Leitor RFID RFID-RC522
- Display LCD I2C (16x2)
- Bibliotecas necessárias:
  - MFRC522 (RFID)
  - LiquidCrystal_I2C (LCD)
  - WiFi
  - NTPClient
  - WiFiUdp

## Configuração

1. Conecte o leitor RFID (RFID-RC522) ao ESP32:
   - SDA: Pino 14 (ou outro pino SDA disponível no ESP32)
   - SCK: Pino 18 (ou outro pino SCK disponível no ESP32)
   - MOSI: Pino 23 (ou outro pino MOSI disponível no ESP32)
   - MISO: Pino 19 (ou outro pino MISO disponível no ESP32)
   - RST: Pino 27 (ou outro pino RST disponível no ESP32)

2. Conecte o display LCD I2C ao ESP32:
   - SDA: Pino 21 (ou outro pino SDA disponível no ESP32)
   - SCL: Pino 22 (ou outro pino SCL disponível no ESP32)

3. Defina as credenciais da sua rede Wi-Fi no código:
   ```cpp
   const char* ssid = "seu_SSID";
   const char* password = "sua_senha";
****
