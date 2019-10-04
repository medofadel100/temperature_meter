/*
 *
 * The project is about measureing temperature with DHT11 Temperature sensor
 * and display the result at LCD
 * circuit and wiring one this link
 * "DHT11"
 * Make the DHT11 sensor face you
 * data(the pin in the left of DH11)   >> pin 7
 * Vcc(pin in the center of DHT11)  >> arduino 5v pin
 * Gnd( pin in the right of DHT11  >> Ground pin
 * "LCD"
 * D4 >> pin 5
 * D5 >> pin 4
 * D6 >> pin 3
 * D7 >> pin 2' 
 * R/W >> GND
 * Enable >> pin 11
 * RS >> pin 12
 * V0 >> 10K pot
 */

//include the library
#include "DHT.h" //Temperature sensor library  
#include <LiquidCrystal.h> // LCD library 
#define DHTPIN 7 //data pin from temp sesnor 
#define DHTTYPE DHT11 //temp sensor type 
DHT dht (DHTPIN, DHT11); // temp initalize
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
void setup() {

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("Good day ^_^ ");
}


void loop()
{
  delay(3000); //wait 
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    lcd.setCursor(0,2);
    lcd.print("Failed to read ");
    Serial.print("F");
    delay(2000);
    return;
  }
  lcd.clear(); //clear LCD from any previes words 
  lcd.setCursor(1,0);
  lcd.print("Temperature is");
  lcd.setCursor(0, 2);
  lcd.print(t); // display temp in LCD 
  lcd.print(" *C");
}


