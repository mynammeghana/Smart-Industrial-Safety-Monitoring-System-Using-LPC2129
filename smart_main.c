
#include"smart_header.h"

int main()
{
//unsigned int adc_temp_value;
float t_out;
int m_out;
smart_adc_init();
smart_lcd_init();
smart_uart0_init(9600);
IODIR0=7<<17;
//IOSET0=7<<17;
	while(1)
	{
//		IODIR0=7<<17;
		IOSET0=7<<17;
//		adc_temp_value=smart_adc_read(1);
//		temp=(adc_temp_value*3.3)/1023;
//		t_out=(temp-0.05)/0.1;
		t_out=temp_sensor(1);
		smart_uart0_tx_string("Temparature:");
		smart_uart0_float(t_out);
		smart_uart0_tx_string("\r\n");
		smart_lcd_cmd(0x80);
		smart_lcd_string("Temp:");
		smart_lcd_float(t_out);
		smart_lcd_data('C');
		smart_uart0_tx_string("PIR Sensor:");
		m_out=motion_sensor(3);
			//if((IOPIN0>>30)&1)
			if(m_out)
				smart_uart0_tx_string("Worker Detected");
			else
				smart_uart0_tx_string("NO Worker Detected");
		smart_uart0_tx_string("\r\n");
		smart_uart0_tx_string("Flame Sensor:");
			if((IOPIN0>>5)&1)
				smart_uart0_tx_string("No Fire");
			else
				smart_uart0_tx_string("Fire Detected");
		smart_uart0_tx_string("\r\n");

			if( m_out &&  (((IOPIN0>>5)&1)==0))
				{
					smart_uart0_tx_string("Machine status : NOT Safe\r\n");
					smart_lcd_cmd(0xc0);
					smart_lcd_string("status : NOT Safe");
					IOCLR0=1<<19;
					smart_uart0_tx_string("LED Status : RED LED ON \r\n");
					delay_ms(100);
				}
			else if(((IOPIN0>>5)&1)==0)
				{
					IOCLR0=1<<18;
					smart_uart0_tx_string("LED Status : YELLOW LED ON \r\n");
					delay_ms(100);
				}
			else
				{
					smart_uart0_tx_string("Machine status : Safe\r\n");
					smart_lcd_cmd(0xc0);
					smart_lcd_string("status : Safe");
					IOCLR0=1<<17;
					smart_uart0_tx_string("LED Status : GREEN LED ON \r\n");
					delay_ms(100);
				}
	}
}

