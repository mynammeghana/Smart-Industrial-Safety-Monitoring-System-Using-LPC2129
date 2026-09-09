#include<lpc21xx.h>

extern void smart_lcd_float(float n);
extern void smart_lcd_int(int num);
extern void smart_lcd_init(void);
extern void smart_lcd_cmd(unsigned char cmd);
extern void smart_lcd_data(unsigned char data);
extern void smart_lcd_string(char *p);

extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);

extern void smart_uart0_float(float n);
extern void smart_uart0_int(int num);
extern void smart_uart0_tx_string(char *ptr);
extern unsigned char smart_uart0_rx(void);
extern void smart_uart0_tx(unsigned char data);
extern void smart_uart0_init(unsigned int baud);

extern void smart_adc_init(void);
extern unsigned char smart_adc_read(unsigned int ch_num);
extern float temp_sensor(unsigned int adc_temp_value);
extern int motion_sensor(unsigned int ch_num);

