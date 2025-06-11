#include <LiquidCrystal_I2C.h>
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
int seconds = 0;
int sensorValue = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUMPIXELS      8

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; 

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup()
{
  dht.begin();
  lcd.init(); // initialize the lcd
  lcd.backlight(); 
  pixels.begin(); 
  pinMode(A0, INPUT);
}

void loop()
{
  delay(2000); // wait a few seconds between measurements

  float humi  = dht.readHumidity();    // read humidity
  float tempC = dht.readTemperature(); // read temperature

  lcd.clear();
  // check if any reads failed
  if (isnan(humi) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  } else {
    lcd.setCursor(0, 0);  // start to print at the first row
    lcd.print("Temp: ");
    lcd.print(tempC);     // print the temperature
    lcd.print((char)223); // print ° character
    lcd.print("C");

    lcd.setCursor(0, 1);  // start to print at the second row
    lcd.print("Humi: ");
    lcd.print(humi);      // print the humidity
    lcd.print("%");
  }
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  
   if (sensorValue < 500) {
    pixels.setPixelColor(0, pixels.Color(255, 255, 254));
  	pixels.setPixelColor(1, pixels.Color(255, 255, 254));
  	pixels.setPixelColor(2, pixels.Color(255, 255, 254));
  	pixels.setPixelColor(3, pixels.Color(255, 255, 254));
 	pixels.setPixelColor(4, pixels.Color(255, 255, 254));
  	pixels.setPixelColor(5, pixels.Color(255, 255, 254));
  	pixels.setPixelColor(6, pixels.Color(255, 255, 254));
  	pixels.setPixelColor(7, pixels.Color(255, 255, 254));
    pixels.show();
 
  } else {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  	pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  	pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  	pixels.setPixelColor(3, pixels.Color(0, 0, 0));
 	pixels.setPixelColor(4, pixels.Color(0, 0, 0));
  	pixels.setPixelColor(5, pixels.Color(0, 0, 0));
  	pixels.setPixelColor(6, pixels.Color(0, 0, 0));
  	pixels.setPixelColor(7, pixels.Color(0, 0, 0));
  	pixels.setPixelColor(8, pixels.Color(0, 0, 0));
    pixels.show();
  }
}
