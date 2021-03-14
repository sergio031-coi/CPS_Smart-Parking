#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int servoPin = D3;
Servo servoMotor;       
int trigPinmasuk = D5;       
int echoPinmasuk = D6;

int PIR = D7;
int pirState = LOW;
int PIRval = 0;
long duration;
int jarakcm;        
LiquidCrystal_I2C lcd(0x27,D1,D2);
void setup() {
  
pinMode(trigPinmasuk, OUTPUT);  
pinMode(echoPinmasuk, INPUT);

pinMode(PIR, INPUT);
servoMotor.attach(servoPin);
Serial.begin(9600); 
lcd.begin();
lcd.backlight();


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
  
digitalWrite(trigPinmasuk, LOW);
delayMicroseconds(2); 
digitalWrite(trigPinmasuk, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPinmasuk, LOW);
duration = pulseIn(echoPinmasuk, HIGH);
jarakcm = (duration/2) * 0.034;
int val = digitalRead(PIR);
Serial.print("Deteksi PIR: ");
Serial.println(val);

 if(jarakcm <=150 && val == HIGH)
  {
        
      lcd.clear();
      lcd.print("Selamat Datang SP");
      Serial.print("KEBUKA");
      lcd.setCursor(0, 1);
      lcd.print("Parkiran Telkom");
      delay(150); 
     
    
      servoMotor.write(90);
    } 
  
  else
  {
    servoMotor.write(0);
  }
  delay(0);

  
}
