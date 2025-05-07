# Hob2Hood IR Controller with Arduino

This project is a custom Arduino sketch to control an AEG / Electrolux Hob2Hood-compatible range hood using raw IR commands. It simulates the Hob2Hood protocol by sending carefully timed infrared pulses to toggle fan levels and lights, allowing manual or automated control without a compatible hob.

Tested with AEG DBB5960HM
## Features

- ✅ Send IR signals to:
  - Turn light on/off
  - Set fan speed (1–4)
  - Turn fan off
- ✅ Uses raw IR pulse timing based on the reverse-engineered Hob2Hood protocol
- ✅ Compatible with most Arduino boards (tested on Uno)
- ✅ Uses the [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) library

## Requirements

- Arduino board (Uno, Nano, etc.)
- IR LED (with current-limiting resistor)
- IR LED connected to **pin 3** by default (changeable in code)
- Arduino IDE installed

## Setup

1. Install the [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) library from the Library Manager.
2. Connect the IR LED to pin 3 (through a 100Ω–220Ω resistor).
3. Upload the `Hob2HoodIR.ino` sketch.
4. Point the IR LED toward your Hob2Hood-compatible range hood.

## Code Overview

The sketch uses raw IR timings based on 725µs units. Each function (Fan 1–4, Fan Off, Light On/Off) is represented as an array of pulse durations.

Example:
```cpp
IrSender.sendRaw(rawFan1, sizeof(rawFan1) / sizeof(rawFan1[0]), 38);
