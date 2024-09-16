#include <FastLED.h>
#include <HardwareSerial.h>
#include <Arduino.h>

#define NUM_LEDS 60
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setAllLeds(CRGB color) {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = color;
    }
    FastLED.show();
}

void setup() {
    Serial.begin(9600);  // UART通信を初期化
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    setAllLeds(CRGB(128, 0, 128));  // デフォルトは紫
}

void loop() {
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        command.trim();  // 余分な空白を削除

        if (command == "red") {
            setAllLeds(CRGB::Red);
        } else if (command == "blue") {
            setAllLeds(CRGB::Blue);
        } else if (command == "white") {
            setAllLeds(CRGB::White);
        }
    }
}