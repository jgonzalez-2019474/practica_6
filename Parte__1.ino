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


#define RS  6
#define Enable 7
#define D7 2
#define D6 3
#define D5 4
#define D4 5

LiquidCrystal LCD_Javier(RS, Enable, D4, D5, D6, D7);


void setup()
{
  LCD_Javier.begin(16,2); 
  LCD_Javier.setCursor(0,0);
  LCD_Javier.print("Javier");
  LCD_Javier.setCursor(0,1);
  LCD_Javier.print("2019474");
}

void loop() {
}
  
