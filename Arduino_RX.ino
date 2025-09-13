#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(1000, 11, -1, 0);  
// speed=1000bps, rxPin=11, txPin unused, pttPin unused

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);

  if (!driver.init()) {
    Serial.println("RX init failed!");
  } else {
    Serial.println("RX Ready...");
  }
}

void loop() {
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    buf[buflen] = '\0';   // make string
    String msg = String((char*)buf);

    Serial.print("Got: ");
    Serial.println(msg);

    if (msg == "ON") {
      digitalWrite(8, HIGH);
      Serial.println("→ LED ON");
    } else if (msg == "OFF") {
      digitalWrite(8, LOW);
      Serial.println("→ LED OFF");
    } else {
      Serial.println("→ Unknown message");
    }
  }
}
