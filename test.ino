#include <LiquidCrystal.h>
#define test1 A3
#define test2 A4
#define test3 A5
int t=0;
int k=1;
//接线 VDD-5V，v0-r-gnd,rs-12,E-11,D4D5D6D7-5,4,3,2,A-3.3V,K-GND
int in=A0;
int btn1=9;//电压放大倍数
int btn2=10;//输入输出抗阻
int b1,b2;
float u1,u2,u3,u,tempu;
//12题目6 13题目7
float r1=0;//输入抗阻
float r2=0;//输出抗阻
float d1=0;//放大倍数
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void fangdabeishu(){
  d1=u2/u3;
  lcd.print("v's EF:");
  lcd.print(d1,2);
  lcd.display();
  Serial.println("电压放大倍数");
  Serial.println(d1);
  delay(2000);  
  lcd.noDisplay();
}

void kangzuxianshi(){
  r1=(u1*2000)/(u1-u2);
  tempu=u3;
  if(tempu<(u3-0.5)&&tempu>(u3+0.5))
  {
  r2=(tempu-u3)/(tempu)*5100;
  lcd.print("Rin:");
  lcd.print(r1,2);
  lcd.print("Rout:");
  lcd.print(r2,2);
  delay(2000);
  lcd.noDisplay();
  }
  else
  {
  lcd.print("Rin:");
  lcd.print(r1,2);
  lcd.print("no change");
  delay(2000);
  }
}

void setup() {
Serial.begin(9600);
pinMode(in,INPUT);
pinMode(btn1,INPUT);
pinMode(btn2,INPUT);
pinMode(test1,INPUT);
pinMode(test2,INPUT);
pinMode(test3,INPUT);
lcd.begin(16, 2);
}

void loop() {
  b1=digitalRead(btn1);
  b2=digitalRead(btn2);
  u1 = 1.2;
  u2 = analogRead(test2)*(5.0/1023.0);
  u3 = 11.3;
  Serial.println(u1);
  Serial.println(u2);
  Serial.println(u3);
  delay(1000);
  //Serial.println(u2);
  //Serial.println(u3);
/*  
if(b1==0 && b2==0)
{ lcd.print("nothing");
  Serial.println("没有进行按键选择");
  lcd.display();
  delay(2000);
  lcd.noDisplay();
}
*/
if(k=1)
{
  void fangdabeishu();
  d1=u3/u2;
  lcd.print("v's EF:");
  lcd.print(d1,2);
  lcd.display();
  delay(5000);  
  lcd.noDisplay();
  Serial.println("fangdabeishu");
  k=2;
}

if(k=2)
{
  void kangzuxianshi();
  Serial.println("kangzuxianshi");
  r1=(u1*2000)/(u1-u2);
  tempu=u3;
  if(tempu<(u3-0.5)&&tempu>(u3+0.5))
  {
  r2=(tempu-u3)/(tempu)*5100;
  lcd.print("Rin:");
  lcd.print(r1,2);
  lcd.print("Rout:");
  lcd.print(r2,2);
  lcd.display();
  delay(5000);
  lcd.noDisplay();
  k=0;
  }
  else
  {
  lcd.print("Rin:");
  lcd.print(r1,2);
  lcd.print("no change");
  lcd.display();
  delay(5000);
  lcd.noDisplay();
  k=0;
  }
}
}
