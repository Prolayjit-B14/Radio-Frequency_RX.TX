#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(1000, -1, 17, -1);   // 1000bps, txPin=GPIO17

const int buttonPin = 4;
int lastState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);

  if (!driver.init()) {
    Serial.println("TX init failed!");
  } else {
    Serial.println("TX Ready...");
  }
}

void loop() {
  int state = digitalRead(buttonPin);

  if (state != lastState) {
    if (state == LOW) {
      const char *msg = "ON";
      driver.send((uint8_t*)msg, strlen(msg));
      driver.waitPacketSent();
      Serial.println("Sent: ON");
    } else {
      const char *msg = "OFF";
      driver.send((uint8_t*)msg, strlen(msg));
      driver.waitPacketSent();
      Serial.println("Sent: OFF");
    }
    lastState = state;
  }

  delay(50);
}
