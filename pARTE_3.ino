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

#define Address_LCD 0x27
#define Filas 2
#define Columnas 10
#define trig 11
#define echo 12
int DISTANCIA;
long Duracion;
LiquidCrystal_I2C LCD_JAVIER(Address_LCD, Columnas, Filas);

byte Geometry[] = {
  B11111,
  B10101,
  B11011,
  B11011,
  B10101,
  B11111,
  B10001,
  B11111
};

void setup()
{
  LCD_JAVIER.begin(16, 2);
  LCD_JAVIER.createChar(1, Geometry);
  LCD_JAVIER.write(1);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  LCD_JAVIER.init();
  LCD_JAVIER.backlight();
}


void loop()
{
  DIFERENCIA();
  Sensor();
}
int DIFERENCIA(){ 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  Duracion = pulseIn(echo, HIGH);
  DISTANCIA = Duracion/59;
  delay(50);
  return DISTANCIA;
}
int Sensor(){
   if( DISTANCIA > 30){
    LCD_JAVIER.setCursor(7,0);
    LCD_JAVIER.print("30");
    LCD_JAVIER.setCursor(0,1);
    LCD_JAVIER.print("     FREE      ");
    LCD_JAVIER.setCursor(3,0);
    LCD_JAVIER.print("    ");
    LCD_JAVIER.setCursor(9,0);
    LCD_JAVIER.print("    ");
    LCD_JAVIER.setCursor(0,0);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.setCursor(13,0);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
  }
  if( DISTANCIA == 20 ){
    LCD_JAVIER.setCursor(7,0);
    LCD_JAVIER.print("20");
    LCD_JAVIER.setCursor(0,1);
    LCD_JAVIER.print("   CAUTION      ");
    LCD_JAVIER.setCursor(5,0);
    LCD_JAVIER.print("  ");
    LCD_JAVIER.setCursor(9,0);
    LCD_JAVIER.print("  ");
    LCD_JAVIER.setCursor(0,0);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.setCursor(11,0);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
  }
  if( DISTANCIA == 10){
    LCD_JAVIER.setCursor(7,0);
    LCD_JAVIER.print("10");
    LCD_JAVIER.setCursor(0,1);
    LCD_JAVIER.print("      STOP      ");
    LCD_JAVIER.setCursor(0,0);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.setCursor(9,0);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);
    LCD_JAVIER.write(1);

  }
  return 0;
 }
