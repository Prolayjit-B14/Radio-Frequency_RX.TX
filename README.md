📡 ESP32 + Arduino UNO – 433 MHz RF ON/OFF LED Project

This project demonstrates wireless communication between an ESP32 (Transmitter) and an Arduino UNO (Receiver) using 433 MHz ASK RF modules with the RadioHead ASK library.
The ESP32 sends "ON" or "OFF" when a push button is pressed/released. The Arduino receives the message and controls an LED accordingly.

🛠️ Hardware Required

ESP32 Dev Board (TX side)

Arduino UNO (RX side)

433 MHz RF Transmitter module (3 pins: VCC, GND, DATA)

433 MHz RF Receiver module (4 pins: VCC, GND, DATA, ANT coil)

Push button + 10kΩ resistor (or use ESP32’s INPUT_PULLUP)

LED + 220Ω resistor

Breadboard + jumper wires

(Optional) Wires/antenna (~17 cm) for better range

⚡ Wiring
ESP32 (Transmitter)
ESP32 Pin	Connects To
3.3V	VCC of TX module
GND	GND of TX module
GPIO17	DATA of TX module
GPIO4	Push button (other side to GND)
Arduino UNO (Receiver)
UNO Pin	Connects To
5V	VCC of RX module
GND	GND of RX module & LED
11	DATA of RX module
8	LED → 220Ω resistor → GND
📂 Software Setup

Install Arduino IDE.

Install RadioHead library (from Arduino Library Manager).

Open and upload the following sketches:

ESP32 → TX Code (esp32_tx.ino)

Arduino UNO → RX Code (uno_rx.ino)

🚀 Usage

Power both boards.

Open Serial Monitor:

ESP32 at 115200 baud

Arduino UNO at 9600 baud

Press and release the button on the ESP32:

ESP32 prints "Sent: ON" / "Sent: OFF".

Arduino prints:

RX Ready...
Got: ON
→ LED ON
Got: OFF
→ LED OFF


LED on pin 8 turns ON or OFF accordingly.

🔧 Troubleshooting

Garbage data (��) → Make sure both TX & RX use RadioHead (not VirtualWire).

No LED response → Check RX wiring (LED pin 8 → 220Ω → GND).

Very short range → Add a simple wire antenna (~17 cm) to both modules.

ESP32 TX init failed → Double-check you’re using a 3.3V transmitter (some require 5V).

📌 Notes

Works at 1000 bps (ASK/OOK modulation).

Range indoors without antenna: ~20–30 cm; with antenna: up to ~30 m.

Can be extended for sending sensor values, text messages, or multiple commands.
