# 📡 ESP32 + Arduino UNO – 433 MHz RF ON/OFF LED Project

This project shows how to use wireless communication between an **ESP32 (Transmitter)** and an **Arduino UNO (Receiver)** with **433 MHz ASK RF modules** and the **RadioHead ASK library**.  

The ESP32 sends `"ON"` or `"OFF"` when a button is pressed or released. The Arduino receives the message and turns an LED **ON** or **OFF** based on the message.

---

## 🛠️ Hardware Required
- ESP32 Dev Board (TX side)  
- Arduino UNO (RX side)  
- 433 MHz RF Transmitter module (3 pins: VCC, GND, DATA)  
- 433 MHz RF Receiver module (4 pins: VCC, GND, DATA, ANT coil)  
- Push button + 10kΩ resistor (or use ESP32’s `INPUT_PULLUP`)  
- LED + 220Ω resistor  
- Breadboard + jumper wires  
- *(Optional)* Wires/antenna (~17 cm) for better range  

---

## ⚡ Wiring

### ESP32 (Transmitter)

| ESP32 Pin | Connects To             |
|-----------|--------------------------|
| `3.3V`    | VCC of TX module         |
| `GND`     | GND of TX module         |
| `GPIO17`  | DATA of TX module        |
| `GPIO4`   | Push button (other side to GND) |

### Arduino UNO (Receiver)

| UNO Pin | Connects To                   |
|---------|--------------------------------|
| `5V`    | VCC of RX module              |
| `GND`   | GND of RX module & LED        |
| `11`    | DATA of RX module             |
| `8`     | LED → 220Ω resistor → GND     |

---

## 📂 Software Setup
1. Install **Arduino IDE**.  
2. Install the **RadioHead library** (from Arduino Library Manager).  
3. Upload:  
   - `esp32_tx.ino` → ESP32 (Transmitter)  
   - `uno_rx.ino` → Arduino UNO (Receiver)  

---

## 🚀 Usage
1. Power both boards.  
2. Open **Serial Monitor**:  
   - ESP32 → **115200 baud**  
   - Arduino UNO → **9600 baud**  
3. Press and release the button on the ESP32:  


**ESP32 output:**
```text
Sent: ON
Sent: OFF
RX Ready...
Got: ON
→ LED ON
Got: OFF
→ LED OFF


- LED on pin 8 turns **ON** or **OFF** accordingly.  

---

## 🔧 Troubleshooting
- **Garbage data (��)** → Ensure both TX and RX use **RadioHead**, not VirtualWire.  
- **No LED response** → Check RX wiring (LED pin 8 → 220Ω → GND).  
- **Very short range** → Add a ~17 cm antenna to both TX and RX.  
- **ESP32 TX init failed** → Verify your transmitter works at **3.3V** (some modules require 5V).  

---

## 📌 Notes
- Works at **1000 bps (ASK/OOK modulation)**.  
- Indoor range: ~20–30 cm (without antenna), ~30 m (with antenna).  
- Can be extended to send **sensor values, text, or multiple commands**.  
