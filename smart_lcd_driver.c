#include"smart_header.h"

void delay_ms(unsigned int ms)
{
T0PR=15000-1;
T0PC=0;
T0TC=0;
T0TCR=0X02;
T0TCR=0X01;
while(T0TC<ms);
T0TCR=0X00;
}

void delay_sec(unsigned int sec)
{
T0PR=15000000-1;
T0PC=0;
T0TC=0;
T0TCR=0X02;
T0TCR=0X01;
while(T0TC<sec);
T0TCR=0X00;
}

void smart_lcd_data(unsigned char data)
{
IOCLR0=0X7FF;
IOSET0=data;
IOSET0=1<<8;
IOCLR0=1<<9;
IOSET0=1<<10;
delay_ms(2);
IOCLR0=1<<10;
}

void smart_lcd_cmd(unsigned char cmd)
{
IOCLR0=0X7FF;
IOSET0=cmd;
IOCLR0=1<<8;
IOCLR0=1<<9;
IOSET0=1<<10;
delay_ms(2);
IOCLR0=1<<10;
}

void smart_lcd_init(void)
{
IODIR0=0X7FF;
smart_lcd_cmd(0x38);
smart_lcd_cmd(0x0e);
smart_lcd_cmd(0x01);
}

void smart_lcd_int(int num)
{
int a[10],i=0;
if(num==0)
smart_lcd_data('0');

if(num<0)
{
num=-num;
smart_lcd_data('-');
}
while(num>0)
{
a[i]=num%10+48;
num=num/10;
i++;
}

for(i=i-1;i>=0;i--)
smart_lcd_data(a[i]);

}

void smart_lcd_float(float n)
{
int num;
if(n==0)
smart_lcd_data('0');

if(n<0)
{
n=-n;
smart_lcd_data('-');
}

num=n;
smart_lcd_int(num);
smart_lcd_data('.');
num=(n-num)*1000000;
smart_lcd_int(num);

}

void smart_lcd_string(char *p)
{
while(*p)
{
smart_lcd_data(*p);
p++;
}
}

