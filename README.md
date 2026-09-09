# Smart-Industrial-Safety-Monitoring-System-Using-LPC2129

## A Smart Industrial Safety Monitoring System developed using the ARM7 LPC2129 microcontroller. The system monitors important safety parameters such as temperature, worker/motion detection, and fire detection using multiple sensors. The monitored information is displayed on a 16×2 LCD and transmitted to a PC/Laptop through UART.

# Smart Industrial Safety Monitoring System

## The project uses the LPC2129 microcontroller to collect and process data from the LM35 temperature sensor, PIR motion sensor, and flame sensor. Based on the sensor conditions, the system displays the current status and provides visual indication using LEDs.

# Features
- Temperature Monitoring: Measures temperature using the LM35 sensor through the LPC2129 ADC.
- Worker/Motion Detection: Detects worker or motion presence using a PIR sensor.
- Fire Detection: Detects the presence of fire using a flame sensor.
- LCD Display: Displays temperature and system status on a 16×2 LCD.
- UART Communication: Sends sensor information and system status to a PC/Laptop terminal.
- LED Indication: Uses Green, Yellow, and Red LEDs to indicate system conditions.
- Multi-Sensor Integration: Combines analog and digital sensor inputs with the LPC2129.
