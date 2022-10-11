
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#include <Servo.h>
Servo myservo1;
Servo myservo2;

int flag1 = 0;
int flag2 = 0;

int ir_s1 = 2;
int ir_s2 = 4;

int Total = 4;
int Space;


void setup() {
pinMode(ir_s1, INPUT);
pinMode(ir_s2, INPUT);
  
myservo1.attach(7);
myservo2.attach(9);
myservo1.write(100);
myservo2.write(100);

lcd.clear();
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
lcd.print("  Car  Parking  ");
lcd.setCursor (0,1);
lcd.print("     Manager     ");
delay (2000);
lcd.clear();  

Space = Total;
}


void loop(){ 

lcd.setCursor (0,0);
lcd.print("Total Slots: ");
lcd.print(Total);


lcd.setCursor (0,1);
lcd.print("Free  Slots: ");
lcd.print(Space);

if(digitalRead (ir_s1) == LOW && flag1==0){
if(Space>0){myservo1.write(0);Space = Space-1;flag1=1;}

else{
lcd.setCursor (0,0);
lcd.print(" Sorry no Space ");  
lcd.setCursor (0,1);
lcd.print("    Available    "); 
delay (3000);
lcd.clear(); 
}
}

delay(2000);
if(digitalRead (ir_s1) == HIGH ){
{myservo1.write(100);
flag1=0;
}
}

if(digitalRead (ir_s2) == LOW && flag2==0 ){
if(Space<5){myservo2.write(0);Space = Space+1;flag2=1;}

}
delay(2000);
if(digitalRead (ir_s2) == HIGH ){
{myservo2.write(100);
flag2=0;}
}


}
