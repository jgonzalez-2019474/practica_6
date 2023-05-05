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


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


#define POU_LCD 0x27
#define Filas 2
#define Columnas 16
#define trig A0
#define echo A1
#define Buzzer 12
#define LED_1 11
#define LED_2 10
#define LED_3 9
#define LED_4 8
#define LED_5 7
#define LED_6 6
#define LED_7 5
#define LED_8 4
#define LED_9 3
#define LED_10 2
int DISTANCIA;
int i;


LiquidCrystal_I2C LCD_javier(POU_LCD, Columnas, Filas);

void configurarPines() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(LED_8, OUTPUT);
  pinMode(LED_9, OUTPUT);
  pinMode(LED_10, OUTPUT);
  for(i=2; i<=11;i++){
  }
  pinMode(Buzzer ,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  LCD_javier.init();
  LCD_javier.backlight();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void setup()
{
  configurarPines();
}


void loop()
{
  VoidBuzzer();
  VoidBarraLED();
}
int VoidBuzzer(){
  long Duracion;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  Duracion = pulseIn(echo, HIGH);
  DISTANCIA = Duracion/59;
  delay(50);
  return DISTANCIA;
}
int VoidBarraLED(){
   if( DISTANCIA > 45){
    LCD_javier.setCursor(0,0);
    LCD_javier.print("ALCANCE LEJANO");
    LCD_javier.setCursor(0,1);
    LCD_javier.print("     PRIVADO    ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
  }
  if( DISTANCIA < 45 && DISTANCIA > 30){
    LCD_javier.setCursor(0,0);
    LCD_javier.print("DISTANCIA CERNCANA");
    LCD_javier.setCursor(0,1);
    LCD_javier.print("      PRIVADO       ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
  }
  if( DISTANCIA < 30 && DISTANCIA > 15){
    LCD_javier.setCursor(0,0);
    LCD_javier.print("   PRECAUCION   ");
    LCD_javier.setCursor(0,1);
    LCD_javier.print("      PRIVADO       ");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    tone(Buzzer, 523);
    delay(5000);
    noTone(Buzzer);
  }


  if( DISTANCIA < 15 && DISTANCIA > 0){
    LCD_javier.setCursor(0,0);
    LCD_javier.print("    INVADIENDO  ");
    LCD_javier.setCursor(0,1);
    LCD_javier.print("      PRIVADO       ");
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    tone(Buzzer, 700);
    delay(10000);
    noTone(Buzzer);
 }
    else {
    noTone(Buzzer);
 }
    return 0;
 }
