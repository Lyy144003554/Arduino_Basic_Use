const int TrigPin = 2; //发出超声波
const int EchoPin = 3; //收到超声波
const int led = 13;//小灯引脚为13
float cm; //厘米大小，浮点型
void setup() 
{ 
  Serial.begin(9600); //设置波特率
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT); 
  pinMode(led, OUTPUT); //设置管脚为输出模式
  pinMode(A0,INPUT);//模拟口输入模式
  Serial.begin(9600);//波特率9600
} 
void loop() 
{ 
  digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin 
  delayMicroseconds(2);       // delayMicroseconds在更小的时间内延时准确
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW); //通过这里控制超声波的发射
  cm = pulseIn(EchoPin, HIGH) / 58.0; //将回波时间换算成cm 
  cm = (int(cm * 100.0)) / 100.0; 
  Serial.print("Distance:"); 
  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println(); 
  delay(1000); 
  Serial.println(analogRead(A0));//串口发送模拟电压值
  delay(500);    
if ( cm < 3 )
{
Serial.println("窗户已关闭");
digitalWrite(led,HIGH);
delay(1000);
}
if ( cm >= 3 )
{
Serial.println("窗户未关闭");
digitalWrite(led,LOW);
delay(1000);

}
}
  
