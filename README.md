# Hob2Hood IR Control with Arduino + Home Assistant

This project allows you to control an AEG / Electrolux Hob2Hood-compatible extractor fan and light using raw IR signals sent from an Arduino. It mimics the proprietary Hob2Hood protocol via carefully timed raw IR bursts.

The IR commands have been tested and confirmed to work with a compatible extractor hood. Each signal was also learned by a [SwitchBot Hub Mini](https://www.switch-bot.com/products/switchbot-hub-mini), enabling easy automation via [Home Assistant](https://www.home-assistant.io/).

Tested with AEG DBB5960HM
---

## 🛠️ Hardware Used

### 🔹 IR Transmitter Module
- KY-005 style IR LED module  
- **AliExpress:** [Infrared transmitter LED module](https://nl.aliexpress.com/item/1005007335850929.html)

### 🔹 Arduino-Compatible Board
- UNO R3 clone with USB  
- **AliExpress:** [UNO R3 Compatible Board](https://nl.aliexpress.com/item/1005007728270103.html)

### 🔹 Optional: SwitchBot Hub Mini
- Used to learn and replay IR commands.
- Fully integrates with Home Assistant using the SwitchBot integration.

---

## 🚀 How It Works

Using the [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) library, the Arduino transmits IR signals that match the Hob2Hood protocol by using raw microsecond timing sequences.

### Supported Commands

| Function     | Status     |
|--------------|------------|
| Light On     | ✅ Works   |
| Light Off    | ✅ Works   |
| Fan Level 1  | ✅ Works   |
| Fan Level 2  | ✅ Works   |
| Fan Level 3  | ✅ Works   |
| Fan Level 4  | ✅ Works   |
| Fan Off      | ✅ Works   |

Each command is sent via `IrSender.sendRaw()` at 38 kHz carrier frequency.

---

## 📋 Instructions

1. Clone or download this repository.
2. Open the `.ino` sketch in the Arduino IDE.
3. Upload the sketch to your Arduino board.
4. Connect the IR LED to the correct GPIO pin (default is pin 3).
5. Point the IR LED at your extractor hood and power on the Arduino.

> Tip: You can manually trigger individual commands from the sketch loop or wrap them in button presses for more control.

---

## 🧩 Home Assistant Integration

1. Use the SwitchBot app to learn each IR signal from the Arduino.
2. Assign meaningful names (e.g., `fan_2`, `light_off`) in the app.
3. Add the SwitchBot integration to Home Assistant.
4. Call the learned IR commands using the `switchbot.send_command` service.

**Example:**
```yaml
service: switchbot.send_command
data:
  device: fan_3
  command: turn_on
