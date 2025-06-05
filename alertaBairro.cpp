#include <LiquidCrystal_I2C.h>

#define LED_GREEN 13
#define LED_YELLOW 12
#define LED_RED 11
#define BUZZER 10

#define SENSOR_SOIL_MOISTURE A0
#define SENSOR_FORCE A1
#define SENSOR_HUMIDITY_POTENTIOMETER A2
#define SENSOR_TEMPERATURE A3

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    pinMode(SENSOR_HUMIDITY_POTENTIOMETER, INPUT);

    lcd.init();
    lcd.clear();
    lcd.backlight();
    
    Serial.begin(9600);
}

void loop() {

}