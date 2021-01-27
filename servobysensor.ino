#include<Servo.h>
#define SERVO1_PIN 4
#define SERVO2_PIN 5
Servo myservo1;
Servo myservo2;
float i=0;
int m;
int c=0;
int pos=0;
int strength = 20;


void setup() {
// put your setup code here, to run once:
//波特率设置为9600 
  Serial.begin(9600);  

/*雨滴传感器输入引脚*/
   pinMode(A0,INPUT);
    myservo1.attach(4);
    myservo2.attach(5);
}

void loop() {
// put your main code here, to run repeatedly:
   i=analogRead(A0);
   Serial.print("rain is ");
   Serial.println(i,3);
   delay(1000);
   
   if((i<300)&&c==0)
   { for (pos = 90; pos <= 180; pos ++) { // 0°到180°
     myservo1.write(pos);              // 舵机角度写入
     delay(strength);                       // 等待转动到指定角度
     }
      delay(1000);
    for (pos = 90; pos <= 180; pos ++) { // 0°到180°
     myservo2.write(pos);              // 舵机角度写入
     delay(strength);                       // 等待转动到指定角度
     }
     c=1;
   }
 if(i>400&&c==1)
   {
    for (pos = 0; pos <= 90; pos ++) { // 0°到180°
     myservo2.write(pos);              // 舵机角度写入
     delay(strength);                       // 等待转动到指定角度
     }
      delay(1000);
  for (pos = 0; pos <= 90; pos ++) { // 0°到180°
   myservo1.write(pos);              // 舵机角度写入
   delay(13);                       // 等待转动到指定角度
     }
     
     c=0;
   }
   
}
