int wavedigital[255];
int cycle;
volatile int wave = 0;
void setup() 
{  
     Serial.begin(9600);
     pinMode(0, OUTPUT); 
     pinMode(1, OUTPUT); 
     pinMode(2, OUTPUT); 
     pinMode(3, OUTPUT); 
     pinMode(4, OUTPUT); 
     pinMode(5, OUTPUT); 
     pinMode(6, OUTPUT);
     pinMode(7, OUTPUT); 
     cycle=int(analogRead(A0)/10)+1;
     wagegen();
} 


void loop() 
{ 
     for (int i=0;i<255;i++) 
     { 
         PORTD=wavedigital[i]; 
         delayMicroseconds(10);
     }    
}


// 波形选择程序
void waveSelect() 
{
    wagegen();
    delay(3000);
}

//波形数值生成
void wagegen()
{
     float x; 
     float y; 
     for(int i=0;i<255;i++)
       {
          x=(float)i;
          y=sin((x/255)*2*PI);
          wavedigital[i]=int(y*128)+128;
       }
} 
  
