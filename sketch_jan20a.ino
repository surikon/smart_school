#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Wire.h>

#define LoudSensor A2 //Датчик шума
#define LightSensor1 A1 //Датчик освещения 1 
#define TemHumSensor 2 //DHT22

DHT dht(TemHumSensor, DHT22); //Инициализируем датчик
LiquidCrystal_I2C lcd(0x3F,16,2); //Инициализируем дисплей

void setup()
{
  lcd.init();  //Запускаем дисплей     
  lcd.backlight(); // Включаем подсветку дисплея
  Serial.begin(9600); //Запуск Serial-соединения
  dht.begin(); //начало сканирования
}

void loop()
{
  delay(10);
  int h = dht.readHumidity();  //Влажность
  int t = dht.readTemperature();  //Температура
  
  /*
  lcd.setCursor(0, 1);  
  lcd.print(h);
  lcd.setCursor(0, 0);
  lcd.print("t: ");
  lcd.setCursor(3, 0);
  lcd.print(t);
  lcd.setCursor(6, 0);
  lcd.print("C");
  */

  int light = analogRead(LightSensor1);
  Serial.println(light);
}

