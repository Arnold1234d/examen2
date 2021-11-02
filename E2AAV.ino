#include <LiquidCrystal.h>
double v=0.0;
double Fuerza=0.0;
double Rs=0.0;
double Peso=0.0;
LiquidCrystal lcd(10, 9, 5, 4, 3, 2);





void setup()
{
lcd.begin(16, 2);
pinMode(A0,INPUT);
Serial.begin(8600);
}







void loop() {

float x=analogRead(A0);

v=x*5/1023;
Rs = 120*(5/v -1);
  if(x<500)
  {
    Fuerza=pow(Rs/4.6986,-1/0.974);
    
    
  }
  else{
        Fuerza=pow(Rs/5.732,-1/0.682);  
  }
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Fuerza:");
lcd.print(Fuerza,3);
lcd.print("N");





lcd.setCursor(3,1);
lcd.print("Peso:");
Peso=1000*((Fuerza/9.81));

lcd.print(Peso,2);
lcd.print("g");
lcd.print("");
delay(1000);
}
