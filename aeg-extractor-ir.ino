#include <IRremote.h>

const int IR_SEND_PIN = 3;

#define HOB_TO_HOOD_UNIT_MICROS 725
#define H2H_1   HOB_TO_HOOD_UNIT_MICROS
#define H2H_2   (HOB_TO_HOOD_UNIT_MICROS * 2)
#define H2H_3   (HOB_TO_HOOD_UNIT_MICROS * 3)
#define H2H_4   (HOB_TO_HOOD_UNIT_MICROS * 4)
#define H2H_5   (HOB_TO_HOOD_UNIT_MICROS * 5)

uint16_t rawLightOn[] = {
  H2H_1, H2H_2, H2H_1, H2H_1, H2H_2, H2H_1, H2H_1, H2H_2, H2H_1,
  H2H_1, H2H_2, H2H_4, H2H_1, H2H_1, H2H_1, H2H_1, H2H_2
};

uint16_t rawLightOff[] = {
  H2H_1, H2H_2, H2H_1, H2H_1, H2H_1, H2H_1, H2H_1, H2H_3, H2H_1,
  H2H_1, H2H_1, H2H_2, H2H_1, H2H_2, H2H_1, H2H_1, H2H_1
};

uint16_t rawFan1[] = {
  H2H_2, H2H_2, H2H_1, H2H_2, H2H_3, H2H_2, H2H_1, H2H_2, H2H_1,
  H2H_1, H2H_1, H2H_2, H2H_1, H2H_3, H2H_1
};

uint16_t rawFan2[] = {
  H2H_2, H2H_2, H2H_1, H2H_4, H2H_1, H2H_3, H2H_5, H2H_3, H2H_3
};

uint16_t rawFan3[] = {
  H2H_1, H2H_3, H2H_4, H2H_4, H2H_3, H2H_1, H2H_1, H2H_3, H2H_3
};

uint16_t rawFan4[] = {
  H2H_2, H2H_3, H2H_2, H2H_1, H2H_2, H2H_3, H2H_2, H2H_2, H2H_1,
  H2H_3, H2H_1, H2H_1, H2H_2
};

uint16_t rawFanOff[] = {
  H2H_1, H2H_2, H2H_1, H2H_2, H2H_3, H2H_2, H2H_1, H2H_2, H2H_2,
  H2H_3, H2H_1, H2H_2, H2H_1, H2H_1, H2H_1
};

void setup() {
  IrSender.begin(IR_SEND_PIN); // Uses default IR_SEND_PIN
}

void loop() {
    IrSender.sendRaw(rawLightOn, sizeof(rawLightOn) / sizeof(rawLightOn[0]), 38);
    delay(5000);
}