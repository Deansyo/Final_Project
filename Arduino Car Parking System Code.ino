#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //Change the HEX address
#include <Servo.h> 

Servo myservo1;
Servo myservo2;

int IR1 = 2;
int IR2 = 4;
int IR3 = 8;
int IR4 = 7;

int Slot = 4;           //Enter Total number of parking Slots

int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;

void setup() {
  lcd.init();
  lcd.backlight();
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);
pinMode(IR3, INPUT);
pinMode(IR4, INPUT);
 
myservo1.attach(3);
myservo1.write(100);
myservo2.attach(9);
myservo2.write(100);

lcd.setCursor (0,0);
lcd.print("     ARDUINO    ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");
delay (2000);
lcd.clear();  
}

void loop(){ 

if(digitalRead (IR1) == LOW && flag1==0){
if(Slot>0){flag1=1;
if(flag2==0){myservo1.write(0); Slot = Slot-1;}
}
else{
lcd.setCursor (0,0);
lcd.print("    SORRY   ");
lcd.setCursor (0,1);
lcd.print("  Parking Full  "); 
delay(2000);
lcd.clear(); 
}
}

if(digitalRead (IR2) == LOW && flag2==0){flag2=1;
if(flag1==0){myservo1.write(0);}
}

if(flag1==1 && flag2==1){
delay(1000);
myservo1.write(100);
flag1=0, flag2=0;
}

lcd.setCursor (0,0);
lcd.print("    WELCOME!    ");
lcd.setCursor (0,1);
lcd.print("  Slot Left:  ");
lcd.print(Slot);


if(digitalRead (IR3) == LOW && flag3==0){
if(Slot<4){flag3=1;
if(flag4==0){myservo2.write(0); Slot = Slot+1;}

}

}

if(digitalRead (IR4) == LOW && flag4==0){flag4=1;
if(flag3==0){myservo2.write(0);}



if(flag3==1 && flag4==1){
delay (1000);
myservo2.write(100);
flag3=0, flag4=0;

}

lcd.setCursor (0,0);
lcd.print("    WELCOME!    ");
lcd.setCursor (0,1);
lcd.print("  Slot Left:  ");
lcd.print(Slot);
}
}