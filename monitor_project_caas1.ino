#include <LiquidCrystal_I2C.h>
#include <Servo.h>  
#include <ESP8266WiFi.h>
#include "AntaresESP8266HTTP.h"

#define ACCESSKEY "d523c0ae9f0d6eb4:0b7d61861736096b" //API key Antares
#define WIFISSID "Sergio" //SSID dan password wifi
#define PASSWORD "12345678nz"
#define projectName "Smart__Parking" //Nama Aplikasi Antares
#define sensorultrasonik1 "Ultrasonik_Masuk"
#define sensorPIR "PIR_Masuk"
#define sensorultrasonik2 "Ultrasonik_Parkir" //Nama Device Antares

AntaresESP8266HTTP antares(ACCESSKEY);

Servo servo;       
#define trigger1      D5  //trigger1  = trigger untuk portal masuk di pin D5       
#define echo1         D6  //echo1     = echo untuk portal masuk di pin D6
#define trigger2      D4  //trigger2  = trigger untuk parkir kendaraan di pin D4
#define echo2         D8  //echo2     = echo untuk parkir kendaraan di pin D8
#define PIR           D7  //PIR berada di Pin D7

LiquidCrystal_I2C lcd(0x27,D2,D1); //0x27 adalah alamat untuk LCD, D2 pin SDA, D1 pin SCL

void setup() 
{
  
  pinMode(trigger1, OUTPUT);  
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
  servo.attach(D0);
  delay(2000);
  servo.write(0);
  pinMode(PIR, INPUT);
  Serial.begin(9600); 
  lcd.begin();
  lcd.backlight();
  antares.setDebug(true);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFISSID, PASSWORD);
  Serial.println("");
 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WIFISSID);
  
  
// Mengatur posisi kursor LCD  (kolom, baris)
  lcd.setCursor(0, 0);
// Menampilkan Text pada LCD
  lcd.print("SMART PARKING");
  lcd.setCursor(0, 1);                       
  lcd.print("Selamat Datang");             
  delay(2000);           
// Menghapus Text pada LCD  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kelompok 2");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Sergio");
  delay(1000);
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("Arief");
  delay(1000);
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("Azmi");
  delay(1000);
  lcd.clear();
}

void loop() 
{

//=============  ULTRASONIC MASUK  =================??

  long duration, jarak;
  int kondisiPIR = digitalRead(PIR);
  digitalWrite(trigger1, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger1, LOW);
  duration = pulseIn(echo1, HIGH);
  jarak = (duration/2) / 29.1;

  if(jarak >= 0 && jarak <=7  )
    {
      if(kondisiPIR == HIGH)
      {
       lcd.clear();
      lcd.print("Selamat Datang ");
      lcd.setCursor(0, 1);
      lcd.print("Parkiran Telkom"); 
      servo.write(90);
      Serial.println("pintu terbuka"); 
      antares.add("jarak", jarak);
      antares.add("PIR", kondisiPIR);
      }
      else
      {
       servo.write(0); 
      }
    }   
  else
    {
      servo.write(0);
    }
  delay(5000);

//==============  ULTRASONIC PARKIR1   ===============??

  digitalWrite(trigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger2, LOW);
  duration =pulseIn(echo2, HIGH);
  jarak= (duration/2) / 29.1;
  
  if(jarak >=0 && jarak <=7)
  { 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Parkiran Penuh");  
      delay(150);
      Serial.println("Parkiran Penuh");
      antares.add("jarak", jarak);
  }
  else 
  {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Parkiran Kosong");
      delay(150);
      Serial.println("Parkiran kosong");
  }
  antares.sendNonSecure(projectName, sensorultrasonik1);
  antares.sendNonSecure(projectName, sensorPIR);
  antares.sendNonSecure(projectName, sensorultrasonik2);
  delay(1000); 
}
