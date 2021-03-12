#include <Servo.h>
#include <LiquidCrystal.h>


int servoPin = 5;
Servo servoMotor;
int echoPinmasuk = 6;
int trigPinmasuk = 11;
int echoPinparkir1 = 10;
int trigPinparkir1 = 9;
int PIR = 4;
int pirState = LOW;
int PIRval = 0;
long duration;
int jarakcm;
LiquidCrystal lcd(13, 12, 8, 7, 3, 2);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  servoMotor.attach(servoPin);
  pinMode(echoPinmasuk, INPUT);
  pinMode(trigPinmasuk, OUTPUT);
  pinMode(echoPinparkir1, INPUT);
  pinMode(trigPinparkir1, OUTPUT);
  pinMode(PIR, INPUT);
  
  
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
  
  digitalWrite(trigPinmasuk,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinmasuk, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinmasuk, LOW);
  duration = pulseIn(echoPinmasuk, HIGH);
  jarakcm= (duration/2) * 0.034;
  int val = digitalRead(PIR);
  Serial.print(val);
  
  

  if(jarakcm <=150)
  {
    if(val == HIGH)
    {    
      lcd.clear();
      lcd.print("Selamat Datang");
      lcd.setCursor(0, 1);
      lcd.print("Parkiran Telkom");
      delay(150);
    
      servoMotor.write(90);
    } 
  }
  else
  {
    servoMotor.write(0);
  }
  delay(0);
  
  
  //==============  ULTRASONIC PARKIR1   ===============??
  digitalWrite(trigPinparkir1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinparkir1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinparkir1, LOW);
  duration =pulseIn(echoPinparkir1, HIGH);
  jarakcm= (duration/2) * 0.034;
  for (int positionCounter = 0; positionCounter < 30; positionCounter++) {
      
		// scroll satu posisi ke kiri
		lcd.scrollDisplayLeft();
		delay(100);
  }
  
  if(jarakcm <=150)
  { 
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print("Parkiran Penuh");
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

