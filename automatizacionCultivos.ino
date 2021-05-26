#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pinLDR A0
#define pinLM35 A1
#define pinMQ135 A2
#define pinSIG0040 A3

float luz;
float temperatura;
float aire;
float humedad;
float factorBP = 100.0 / 1023.0; // Factor de Conversión de bits a porcentaje
float factorBT = 500.0 / 1023.0; // Factor de Conversión de bits a °C

//Crear el objeto LCD dirección 0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27, 20, 4);  //

void setup(){
  
  Serial.begin(9600);
  pinMode(pinLDR, INPUT);
  pinMode(pinLM35, INPUT);
  pinMode(pinMQ135, INPUT);
  pinMode(pinSIG0040, INPUT);
  
  Serial.print("Fotoresistor");
  Serial.print(" ");
  Serial.println("Temperatura");
  Serial.print(" ");
  Serial.println("Aire");
  Serial.print(" ");
  Serial.println("Humedad");
  Serial.print(" ");
  
  // Inicializar el LCD
  lcd.init();
  
  // Encender la luz de fondo.
  lcd.backlight();
}

void loop(){
  //Definen variables de los sensores
  luz = analogRead(pinLDR)*factorBP;
  temperatura = analogRead(pinLM35)*factorBT;
  aire = analogRead(pinMQ135)*factorBP;
  humedad = analogRead(pinSIG0040)*factorBP;
  
  // Cursor en la primera posición de la primera fila
  lcd.setCursor(0,0);
  lcd.print("L:");
  lcd.print(luz, 1);//1 decimal
  lcd.print("%   ");
  
  // Cursor en la 11° posición de la primera fila
  lcd.setCursor(10,0);
  lcd.print("T:");
  lcd.print(temperatura,1);//1 decimal
  lcd.print("337C  ");
  
  // Cursor en la primera posición de la 2° fila
  lcd.setCursor(0,1);
  lcd.print("A:");
  lcd.print(aire,1); //1 decimal
  lcd.print("337C  "); // "337" -> "°"
  
  // Cursor en la 11° posición de la 2° fila
  lcd.setCursor(10,1);
  lcd.print("H:");
  lcd.print(humedad);
  lcd.print("%   ");
  
  delay(200);
}
