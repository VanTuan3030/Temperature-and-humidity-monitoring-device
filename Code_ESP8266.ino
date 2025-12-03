#define BLYNK_TEMPLATE_ID "TMPL6uVNDAH4b"
#define BLYNK_TEMPLATE_NAME "BTL"
#define BLYNK_AUTH_TOKEN "U82JVWh4Zm3v_ytmEdHUQzDGqenU9kLR"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHTesp.h"

const char* ssid = "Iphone";
const char* pass = "12345678";

DHTesp dht;
#define DHT 16   // Chân D0 (GPIO 16) nối cảm biến DHT11
#define quat 4   // Chân D2 (GPIO 4) nối Relay điều khiển quạt

unsigned long timeBlink = millis();
boolean updateRelay = 0;

WidgetLED LEDCONNECT(V0);

#define QUAT V3      
#define NHIETDO V1  
#define DOAM V2     

BLYNK_CONNECTED() {
  // Đồng bộ trạng thái mới nhất của nút QUAT từ server về thiết bị
  Blynk.syncVirtual(QUAT);
}

BLYNK_WRITE(QUAT) {
  int p = param.asInt(); // Lấy giá trị 0 hoặc 1 từ nút nhấn
  digitalWrite(quat, p); // Điều khiển bật/tắt relay quạt theo giá trị nhận được
}

void setup() {
  Serial.begin(115200); 
  pinMode(quat, OUTPUT);
  dht.setup(DHT, DHTesp::DHT11);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  if (millis() - timeBlink > 1000) {
        if (LEDCONNECT.getValue()) {
      LEDCONNECT.off();
    } else {
      LEDCONNECT.on();
    }
    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();

    Blynk.virtualWrite(NHIETDO, temperature);
    Blynk.virtualWrite(DOAM, humidity);

    if (temperature > 33) {
      digitalWrite(quat, HIGH);    // Bật relay (quạt)
      Blynk.virtualWrite(QUAT, 1); // Cập nhật trạng thái nút nhấn trên Blynk thành ON
      
      // Gửi thông báo cảnh báo về điện thoại
      Blynk.logEvent("CANH_BAO_NHIET_DO", "NHIET DO QUA CAO: " + String(temperature) + "°C \nBAT QUAT THONG GIO");
    }

    timeBlink = millis();
  }
}