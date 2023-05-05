#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_LCD 0x27
#define Filas 2
#define Columnas 16
#define Temp 2
#define LED_1 3
#define LED_2 4
#define LED_3 5

int Fahrenheit;
int obtenerTemperaturaFahrenheit();
int Celsius;
int obtenerTemperaturaCelsius();
void inicializarLCD();
void LCD_javier();
void mostrarTemperaturaLCD(int temperaturaCelsius, int temperaturaFahrenheit, int icono);

byte Termometro[] = {
    B00100,
    B01010,
    B01010,
    B01010,
    B01010,
    B11111,
    B11111,
    B01110
};
byte grados[] = {
    B00111,
    B00101,
    B00111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
};
byte Copo[] = {
    B10101,
    B01110,
    B01110,
    B10101,
    B00000,
    B00000,
    B00000,
    B00000
};
byte Fuego[] = {
    B00000,
    B00100,
    B01010,
    B10101,
    B01110,
    B11111,
    B11111,
    B11111
};
byte Humano[] = {
    B01110,
    B11111,
    B01110,
    B10101,
    B01110,
    B00100,
    B00100,
    B01010
};

OneWire ourWire(Temp);
DallasTemperature SENSOR(&ourWire);
LiquidCrystal_I2C LCD_JAVIER(I2C_LCD, Columnas, Filas);

void setup() {
    delay(1000);
    Serial.begin(9600);
    SENSOR.begin();
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    LCD_JAVIER.begin(16, 2);
    LCD_JAVIER.init();
    LCD_JAVIER.backlight();
    LCD_JAVIER.createChar(1, Termometro);
    LCD_JAVIER.createChar(2, grados);
    LCD_JAVIER.createChar(3, Copo);
    LCD_JAVIER.createChar(4, Fuego);
    LCD_JAVIER.createChar(5, Humano);

    inicializarLCD();
}

void loop() {
    LCD_javier();
}

int obtenerTemperaturaCelsius() {
    SENSOR.requestTemperatures();
    int celsius = SENSOR.getTempCByIndex(0);
    return celsius;
}

int obtenerTemperaturaFahrenheit() {
    SENSOR.requestTemperatures();
    int fahrenheit = SENSOR.getTempFByIndex(0);
    return fahrenheit;
}

void inicializarLCD() {
    LCD_JAVIER.begin(16, 2);
    LCD_JAVIER.init();
    LCD_JAVIER.backlight();
}
void mostrarTemperaturaLCD(int temperaturaCelsius, int temperaturaFahrenheit, int icono) {
    LCD_JAVIER.setCursor(0, 0);
    LCD_JAVIER.print("Termometro");
    LCD_JAVIER.setCursor(10, 0);
    LCD_JAVIER.write(icono);
    LCD_JAVIER.setCursor(0, 1);
    LCD_JAVIER.print(temperaturaCelsius);
    LCD_JAVIER.setCursor(5, 1);
    LCD_JAVIER.write(2);
    LCD_JAVIER.setCursor(6, 1);
    LCD_JAVIER.print("C");
    LCD_JAVIER.setCursor(7, 1);
    LCD_JAVIER.write(3);
    LCD_JAVIER.setCursor(9, 1);
    LCD_JAVIER.print(temperaturaFahrenheit);
    LCD_JAVIER.setCursor(14, 1);
    LCD_JAVIER.write(2);
    LCD_JAVIER.setCursor(15, 1);
    LCD_JAVIER.print("F");
}

void LCD_javier() {
    Fahrenheit = obtenerTemperaturaFahrenheit();
    Celsius = obtenerTemperaturaCelsius();

    if (Celsius > 30) {
        mostrarTemperaturaLCD(Celsius, Fahrenheit, 4);
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, LOW);
    } else if (Celsius > 15 && Celsius < 30) {
        mostrarTemperaturaLCD(Celsius, Fahrenheit, 5);
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, LOW);
    } else {
        mostrarTemperaturaLCD(Celsius, Fahrenheit, 3);
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, HIGH);
    }
}
