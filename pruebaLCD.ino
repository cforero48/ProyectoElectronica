#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Crear el objeto LCD dirección 0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

Void setup(){
  // Inicializar el LCD
  lcd.init();
  
  // Encender la luz de fondo.
  lcd.backlight();
  
  // Escribir mensaje de bienvenida
  lcd.print("Hola, bienvenido")
}

void loop(){
  // Ubicar el cursos en la primera posición (columna:0) de la segunda fila (fila:1)
  lcd.setCursor(0, 1);
  // Escribirel número de segundos transcurridos
  lcd.print(millis()/1000);
  lcd.print(" Segundos");
  delay(100);
}
