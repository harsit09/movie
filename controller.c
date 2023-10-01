1) ELEVATOR
#include<stdio.h>
#include<reg51.h>

unsigned char xdata CommandWord  at  0xe803;
unsigned char xdata PortA  at  0xe800;
unsigned char xdata PortB  at  0xe801;
unsigned char xdata PresentFloor,RequestedFloor,Step = 0xf0;  
unsigned long xdata Count,i;

Delay()
{
  for(Count = 0; Count <= 4500; Count++);
}

Reset()
{
Step = Step & 0x0f;
PortA = Step;
Step = Step | 0xf0;
PortA = Step;
}
GoUp()
{
  switch(RequestedFloor)
  {
case 0x0d: while(Step < 0xf3)
{
  Step++;
  PortA = Step;
  Delay();
}
Reset();
break;

case 0x0b:  while(Step < 0xf6)
{
  Step++;
  PortA = Step;
  Delay();
}
Reset();
break;


case 0x07:  while(Step < 0xf9)
{
  Step++;
  PortA = Step;
  Delay();
}
Reset();
break;
  }
}

GoDown()
{
  switch(RequestedFloor)
  {
case 0x0d: while(Step > 0xf3)
{
  Step--;
  PortA = Step;
  Delay();
}
Reset();
break;

case 0x0b:  while(Step > 0xf6)
{
  Step--;
  PortA = Step;
  Delay();
}
Reset();
break;


case 0x0e:  while(Step > 0xf0)
{
  Step--;
  PortA = Step;
  Delay();
}
Reset();
break;
  }
}


void main()
{
  CommandWord = 0x82;
  PortA = 0xf0;    
  PresentFloor = 0x0e;
  while(1){
  RequestedFloor = PortB;
  RequestedFloor = RequestedFloor & 0x0f;

  if(RequestedFloor != 0x0f && RequestedFloor != PresentFloor){      
if(RequestedFloor < PresentFloor)
GoUp();
else
GoDown();
PresentFloor = RequestedFloor;
}
RequestedFloor = PortB;
    }
  }



2) SEVEN SEGMENT
#include<stdio.h>	
#include<reg51.h>

char xdata CommW at 0xe803;
char xdata portB at 0xe801;
char xdata portC at 0xe802;
char port[20] = {0x8e,0xf9,0xde,0x86,0xff,0xff,0xff,0xff,0x89,0x86,0xc7,0x8c},i;
delay()
 {
    long u;
	for(u=0;u<8000;u++);
   }
void main()
{
	int d,b,j,m;
	unsigned char k;
	CommW = 0x80;
	do
	{
	i=0;
	for(d=0;d<3;d++)
	{
		for(b=0;b<4;b++)
		{
		k = port[i++];
		for(j=0;j<8;j++)
		{
			m=k;
			k=k&0x80;
			{
			if(k==00)
			portB=0x00;
			else
			portB=0x01;
			}
			portC = 0x01;
			portC = 0x00;
			k=m;
			k<<=1;
		}
	}
delay();
}
}
while(1);
}	


3)STEPPER MOTOR - ANTI CLOCKWISE
#include<stdio.h>
#include<reg51.h>

char xdata port at 0xe803;
char xdata porta at 0xe800;
char idata acc at 0x30; 

delay()    //DELAY BETWEEN THE ROTATION OF THE STEPPER MOTOR
{
  int j;
  for(j = 0;j < 800; j++)
  {}            
}
void main()
{
  port = 0x80;  //CONFIGURE ALL THE PORTS OF 8255 AS OUTPUT PORT
  while(1)
  {						  
    acc = 0x11;  
    porta = acc; 			 
    delay();
    acc = 0x22;
    porta = acc;
    delay();
    acc = 0x44;
    porta = acc;
    delay();
    acc = 0x88;
    porta = acc;
    delay();
  }
}

4)STEPPER MOTOR CLOCKWISE
#include<stdio.h>
#include<reg51.h>

char xdata port at 0xe803;
char xdata porta at 0xe800;
char idata acc at 0x30; 

delay()    //DELAY BETWEEN THE ROTATION OF THE STEPPER MOTOR
{
  int j;
  for(j = 0;j < 800; j++)
  {}            
}
void main()
{
  port = 0x80;  //CONFIGURE ALL THE PORTS OF 8255 AS OUTPUT PORT
  while(1)
  {						  
    acc = 0x88;  
    porta = acc; 			 
    delay();
    acc = 0x44;
    porta = acc;
    delay();
    acc = 0x22;
    porta = acc;
    delay();
    acc = 0x11;
    porta = acc;
    delay();
  }
}

5)ROLLER MOTOR
#include<stdio.h>
#include<reg51.h>
char xdata CommW at 0xe803;
char xdata portB at 0xe801;
char xdata portC at 0xe802;
char port[20] = { 0xff, 0xff, 0xff, 0xff ,0x83,0x88,0xC8,0x82, 0x88,0xC7,0xC0,0xAF,0x86},i;
delay()
{
long u;
for(u=0;u<4000;u++);
}
void main()
{
int d,b,j,m;
unsigned char k;
CommW = 0x80;
do
{
i=0;
for(d=0;d<1;d++)
{
for(b=13;b>0;b--)
{
delay();
k = port[i++];
for(j=0;j<8;j++)
{
m=k;
k=k&0x80;
{
if(k==00)
portB=0x00;
else
portB=0x01;
}
portC = 0x01;
portC = 0x00;
k=m;
k<<=1;
}
}
delay();
}
}
while(1);
}
