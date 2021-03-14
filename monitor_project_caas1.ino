#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo servo;       
int trigPinmasuk = D5;       
int echoPinmasuk = D6;
int trigPinparkir1 = D4;
int echoPinparkir1 = D8;

int PIR = D7;
int pirState = LOW;
int PIRval = 0;
long duration;
int jarakcm;        
LiquidCrystal_I2C lcd(0x27,D1,D2);

void setup() {
  
pinMode(trigPinmasuk, OUTPUT);  
pinMode(echoPinmasuk, INPUT);
pinMode(trigPinparkir1, OUTPUT);
pinMode(echoPinparkir1, INPUT);

pinMode(PIR, INPUT);
servo.attach(D0);
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
jarakcm = (duration/2) / 2.91;
int val = digitalRead(PIR);
Serial.print("Deteksi PIR: ");
Serial.println(val);

 if(jarakcm <=35 && val == HIGH)
  {
        
      lcd.clear();
      lcd.print("Selamat Datang ");
      lcd.setCursor(0, 1);
      lcd.print("Parkiran Telkom");
      delay(150); 
      servo.write(90);
      Serial.println("Tes ultrasonic1");
      Serial.print("Deteksi PIR: ");
      Serial.println(val);

    } 
  
  else
  {
    servo.write(0);
  }
  delay(0);

  
//==============  ULTRASONIC PARKIR1   ===============??


  digitalWrite(trigPinparkir1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinparkir1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinparkir1, LOW);
  duration =pulseIn(echoPinparkir1, HIGH);
  jarakcm= (duration/2) / 2.91;
  for (int positionCounter = 0; positionCounter < 30; positionCounter++) {
      
    // scroll satu posisi ke kiri
    lcd.scrollDisplayLeft();
    delay(100);
  }
  
  if(jarakcm <=35)
  { 
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print("Parkiran Penuh");
      Serial.println("tes ultrasonic2");
      
      delay(150);
    
  }
  else 
  {
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print("Parkiran Kosong");
      delay(150);
  
  }
  delay(0); 
}
