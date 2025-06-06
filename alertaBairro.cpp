#include <LiquidCrystal_I2C.h>

#define LED_GREEN 13
#define LED_YELLOW 12
#define LED_RED 11
#define BUZZER 10

#define SENSOR_SOIL_MOISTURE A0
#define SENSOR_FORCE A1
#define SENSOR_HUMIDITY_POTENTIOMETER A2

LiquidCrystal_I2C lcd(0x27, 16, 2);

const long warningPercentage = 33;
const long dangerPercentage = 66;

const long warningForceAppliedRain = 3;
const long dangerForceAppliedRain = 6;

bool isSoilMoistureDanger = false;
bool isHumidityDanger = false;
bool isRainForceDanger = false;

bool isSoilMoistureWarning = false;
bool isHumidityWarning = false;
bool isRainForceWarning = false;

long soilMoisturePercentage = 0;
long humidityPercentage = 0;
long forceApplied = 0;

int showChangesTime = 0;
int showChangesDelay = 1000;

void setup() {
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    pinMode(SENSOR_HUMIDITY_POTENTIOMETER, INPUT);
    pinMode(SENSOR_FORCE, INPUT);

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

void lcdPrintFirstLine(char* text) {
    lcd.clear();
    lcd.home();
    lcd.print(text);
}

void lcdPrintSecondLine(char* text) {
    lcd.setCursor(0, 1);
    lcd.print(text);
}

void lcdPrintValueText(const char* prefix, float value, int decimalPlaces, const char* sufix) {
	lcd.setCursor(0, 1);
	lcd.print(prefix);
	lcd.print(value, decimalPlaces);
	lcd.print(sufix);
}

long getHumidityPercentage() {
  	int humiditySensorOutput = analogRead(SENSOR_HUMIDITY_POTENTIOMETER);
	long humidityPercentage = map(humiditySensorOutput, 0, 1023, 0, 100);

	Serial.print("Humidade: ");
  	Serial.println(humidityPercentage);

	return humidityPercentage;
}

long getSoilMoisturePercentage() {
    double moisture = analogRead(SENSOR_SOIL_MOISTURE);
    long moisturePercentage = map(moisture, 0, 876, 0, 100);

    Serial.print("Humidade Solo: ");
    Serial.println(moisturePercentage);

    return moisturePercentage;
}

long getForceNewton() {
    int force = analogRead(SENSOR_FORCE);
    //double forceNewtons = map(force, 0, 466, 0, 1000) / 100.0;
  	double forceNewton = (7.011e-8 * force * force * force + 1.468e-6 * force * force + 0.00545 * force - 0.00133) + 0.02;

    Serial.print("Forca aplicada: ");
    Serial.println(forceNewton);

    return (long)forceNewton;
}