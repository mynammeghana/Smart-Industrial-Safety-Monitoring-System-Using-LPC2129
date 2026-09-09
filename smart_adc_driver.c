#include"smart_header.h"

void smart_adc_init(void)
{
PINSEL1 =0x15400000;
ADCR=0x00200400;
}

#define done ((ADDR>>31)&1)
unsigned char smart_adc_read(unsigned int ch_num)
{
unsigned int result=0;
ADCR |= (1<<ch_num);		  //select which channel
ADCR |= (1<<24);   //start adc
while(done==0); //wait for adc converter;
ADCR ^= (1<<24); //stop adc
ADCR ^= (1<<ch_num); //disselct channel
result = (ADDR>>6)&0X3FF; //DATA TO EXTRACT
return result;
}


float temp_sensor(unsigned int ch_num)
{
unsigned int adc_temp_value;
float temp,t_out;
adc_temp_value=smart_adc_read(ch_num);
temp=(adc_temp_value*3.3)/1023;
t_out=temp/0.010;
return t_out;
}

int motion_sensor(unsigned int ch_num)
{
unsigned int adc_motion_value;
adc_motion_value=smart_adc_read(ch_num);
if(adc_motion_value != 1023)
return 1;
else
return 0;
}

