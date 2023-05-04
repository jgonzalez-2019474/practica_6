/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Javier Andre Gonzalez Barrera
Carné: 2019474
*/

#include <LiquidCrystal.h>

#define RS 6
#define Enable 7
#define D7 2
#define D6 3
#define D5 4
#define D4 5
#define trig A1
#define echo A0
#define Buzzer 8

int Distancia;
int Duracion;
int conteo = 0;
int Fre = 440;

LiquidCrystal LCD_javier(RS, Enable, D4, D5, D6, D7);

byte cometa1[] = {
  B11111,
  B01111,
  B00111,
  B10011,
  B11001,
  B11100,
  B11110,
  B11111
};

byte cometa2[] = {
  B00000,
  B00000,
  B00000,
  B10000,
  B11000,
  B11100,
  B11110,
  B11111
};

void configurarPines() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void configurarLCD() {
  LCD_javier.begin(16, 2);
  LCD_javier.setCursor(0, 0);
  LCD_javier.print("Num de cometas");
  LCD_javier.setCursor(0, 0);
  LCD_javier.createChar(1, cometa1);
  LCD_javier.createChar(2, cometa2);
}

void setup() {
  configurarPines();
  configurarLCD();
}

void loop() {
  LCD_javier.write(1);
  LCD_javier.write(2);

  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  Duracion = pulseIn(echo, HIGH);
  Distancia = Duracion / 59;
  Serial.println(Distancia);
  delay(500);

  if (Distancia > 6 && Distancia < 10) {
    conteo = incrementarConteo(conteo);
  }

  actualizarDisplay(conteo);
  reproducirBuzzer(conteo);
}

int incrementarConteo(int conteoActual) {
  return conteoActual + 1;
}

void actualizarDisplay(int conteoActual) {
  if (conteoActual < 16) {
    int columna = 0;
    int i = 0;
    while (i < conteoActual) {
      if (columna == 0) {
        LCD_javier.setCursor(i, 1);
        LCD_javier.write(1);
        columna = 1;
        i++;
      } else if (columna == 1) {
        LCD_javier.setCursor(i, 1);
        LCD_javier.write(2);
        columna = 0;
        i++;
      }
    }
    for (i = i; i < 16; i++) {
      LCD_javier.setCursor(i, 1);
      LCD_javier.write(' ');
    }
  } else {
    LCD_javier.setCursor(15, 1);
    LCD_javier.write(2);
    delay(600);
    LCD_javier.setCursor(15, 1);
    LCD_javier.write(1);
    delay(600);
  }
}

void reproducirBuzzer(int conteoActual) {
  if (conteoActual >= 16) {
    tone(Buzzer, Fre, 440);
  } else {
    noTone(Buzzer);
  }
}
