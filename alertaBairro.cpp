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

void turnLeds(int green, int yellow, int red) {
    digitalWrite(LED_GREEN, green);
    digitalWrite(LED_YELLOW, yellow);
    digitalWrite(LED_RED, red);
}

void turnBuzzer(int buzzer) {
    digitalWrite(BUZZER, buzzer);
}

long getHumidityPercentage() {
  	int humiditySensorOutput = analogRead(SENSOR_HUMIDITY_POTENTIOMETER);
	long humidityPercentage = map(humiditySensorOutput, 0, 1023, 0, 100);

	Serial.print("Humidade: ");
  	Serial.println(humidityPercentage);

	return humidityPercentage;
}

long getTemperatureCelsius() {
	int rawValue = analogRead(SENSOR_TEMPERATURE);
    long voltage = (rawValue / 1023.0) * 5000.0;
    long tempCelsius = (voltage - 500) * 0.1;

	Serial.print("Temperatura: ");
  	Serial.println(tempCelsius);

  	return tempCelsius;
}