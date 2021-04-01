#include <LiquidCrystal_I2C.h>
#include <Servo.h>  
#include <ESP8266WiFi.h>
#include "AntaresESP8266HTTP.h"

#define ACCESSKEY "5b00cd16ad87ef4f:353456772f535c49" //API key Antares
#define WIFISSID "Sergio" //SSID dan password wifi
#define PASSWORD "12345678nz"
#define projectName "Smart_--Parking" //Nama Aplikasi Antares
#define deviceName "ParkirSensor" //Nama Device Antares

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
  Serial.begin(115200); 
  lcd.begin();
  lcd.backlight();
  antares.setDebug(true);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFISSID, PASSWORD);
  Serial.println("");
 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WIFISSID);

  //koneksikan ke  antares

  antares.setDebug(true);
  antares.wifiConnection(WIFISSID, PASSWORD);

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

  int durasi, jarak1, jarak2;
  int kondisiPIR = digitalRead(PIR);
  digitalWrite(trigger1, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger1, LOW);
  durasi = pulseIn(echo1, HIGH);
  jarak1 = (durasi/2) / 29.1; 
  
  if(jarak1 >= 0 && jarak1 <=7  )
    {
      if(kondisiPIR == HIGH)
      {
       lcd.clear();
      lcd.print("Selamat Datang ");
      lcd.setCursor(0, 1);
      lcd.print("Parkiran Telkom"); 
      servo.write(90);
      Serial.println("pintu terbuka"); 
      Serial.println(jarak1);
      Serial.println(kondisiPIR);
      
      //buat sebuah variabel penampung data yang akan dikrim ke Antares
      antares.add("Jarak Kendaraan(cm)", jarak1);
      antares.add("Kondisi PIR", kondisiPIR);
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
  durasi =pulseIn(echo2, HIGH);
  jarak2= (durasi/2) / 29.1;
  
  if(jarak2 >=0 && jarak2 <=7)
  { 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Parkiran Penuh");  
      delay(150);
      Serial.println("Parkiran Penuh");
      antares.add("Jarak Parkiran(cm)", jarak2);
      Serial.println(jarak2);
      
  }
  else 
  {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Parkiran Kosong");
      delay(150);
      Serial.println("Parkiran kosong");
  }
  antares.send(projectName, deviceName);
  delay(5000); 
}
