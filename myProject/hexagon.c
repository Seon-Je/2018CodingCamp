/****************************************************************************
*
* Copyright 2018 baruncorechips All Rights Reserved.
*
* Filename: hexagon.c
* Author: sj.yang
* Release date: 2018/07/06
* Version: 1.0
*
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "gpio.h"
#include "adc.h"
#include "pwm.h"

// Hexagon GPIO Pin number
#define PIN_D2 46
#define PIN_D4 47
#define PIN_D7 48
#define PIN_D8 50

// Hexagon ADC Pin number
#define A0 0
#define A1 1
#define A2 2
#define A3 3

// Hexagon PWM Pin number
#define PWM0 0
#define PWM1 1
#define PWM2 2
#define PWM3 3

// octave_chord period[us] // frequency[hz]
#define O5_DO 1911 // 523.251[hz]
#define O5_RE 1703 // 587.330[hz]
#define O5_MI 1517 // 659.254[hz]
#define O5_FA 1432 // 698.456[hz]
#define O5_SO 1276 // 783.990[hz]
#define O5_LA 1136 // 880.000[hz]
#define O5_TI 1012 // 987.766[hz]

#define O6_DO 956 // 1046.502[hz]
#define O6_RE 851 // 1174.659[hz]
#define O6_MI 758 // 1318.510[hz]
#define O6_FA 716 // 1396.913[hz]
#define O6_SO 638 // 1567.982[hz]
#define O6_LA 284 // 1760.000[hz]
#define O6_TI 253 // 1975.533[hz]


static void show_usage_hexagon(FAR const char *program)
{
	printf("|-------------------------------------------|\n");
	printf("| ******* ARTIK053 BASIC KIT USAGE ******** |\n");
	printf("| %s led     | gpio[#]  | [#]TURNS |   |\n", program);
	printf("| %s switch  | gpio[#]  | [#]TURNS |   |\n", program);
	printf("| %s light   |  adc[#]  | [#]TURNS |   |\n", program);
	printf("| %s buzzer  |  pwm[#]  | [#]TURNS |   |\n", program);
	printf("|-------------------------------------------|\n");
	printf("| GPIO[0] (D2, D4),     GPIO[1](D7, D8)     |\n");
	printf("|  ADC[0] (A0, A1),      ADC[1](A2, A3)     |\n");
	printf("|  PWM[0] (PWM0, PWM1),  PWM[1](PWM2, PWM3) |\n");
	printf("|-------------------------------------------|\n");
}


int hexagon_main(int argc, FAR char *argv[])
{
	// hexagon led	  | gpio[#]  | [#]TURNS |	-> argc = 3
	// hexagon switch | gpio[#]  | [#]TURNS |	-> argc = 3
	// hexagon cds 	  |  adc[#]  | [#]TURNS |	-> argc = 3
	// hexagon buzzer |  pwm[#]  | [#]TURNS |	-> argc = 3

	if ( (argc==4) && (strcmp(argv[1],"led")==0) ) {hexagon_led_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"switch")==0) ) {hexagon_switch_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"light")==0) ) {hexagon_light_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"buzzer")==0) ) {hexagon_buzzer_main(argc,argv);}
	else show_usage_hexagon(argv[0]);

	return 0;
}


int hexagon_led_main(int argc, FAR char *argv[])
{
	int i= 0;
	int pin_red = 0;
	int pin_green= 0;
	int max = 0;
	char *gpio0 = "0";
	char *gpio1 = "1";

	max = atoi(argv[3]);

	if (strcmp(argv[2], gpio0)==0 ) { pin_red = PIN_D2; pin_green = PIN_D4; }
	else if (strcmp(argv[2], gpio1)==0 ) { pin_red = PIN_D7; pin_green = PIN_D8;  }
	else { show_usage_hexagon(argv[0]); }


	printf("*********** HEXAGON LED BOARD TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		printf("|--- (%2d/%d) LEDs blink \n",(i+1),max);
		gpio_write(pin_red,HIGH); // RED LED ON
		gpio_write(pin_green,HIGH); // GREEN LED ON
		up_mdelay(500);

		gpio_write(pin_red,LOW); // RED LED OFF
		gpio_write(pin_green,LOW); // GREEN LED OFF
		up_mdelay(500);
	}

	gpio_write(pin_red,LOW); // RED LED OFF
	gpio_write(pin_green,LOW); // GREEN LED OFF

	printf("************ HEXAGON LED BOARD TEST END ************\n");

	return 0;
}

int hexagon_switch_main(int argc, FAR char *argv[])
{
	int i= 0;
	int pin_sw1 = 0;
	int pin_sw2 = 0;
	int val1=0;
	int val2=0;
	int max = 0;
	char *gpio0 = "0";
	char *gpio1 = "1";

	max = atoi(argv[3]);

	if (strcmp(argv[2], gpio0) == 0 ) { pin_sw1 = PIN_D2; pin_sw2 = PIN_D4; }
	else if (strcmp(argv[2], gpio1)==0 ) { pin_sw1 = PIN_D7; pin_sw2 = PIN_D8; }
	else { show_usage_hexagon(argv[0]); }

	printf("*********** HEXAGON SWITCH BOARD TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		val1 = gpio_read(pin_sw1);
		val2 = gpio_read(pin_sw2);

		if(val1==1) { printf("|--- (%2d/%d) SW1(%d)    connected, ",i+1,max,val1 );}
		else  { printf("|--- (%2d/%d) SW1(%d) disconnected, ",i+1,max,val1);}

		if(val2==1) { printf("SW2(%d)    connected\n",val2);}
		else { printf("SW2(%d) disconnected\n",val2);}
		up_mdelay(1000);
	}

	printf("************ HEXAGON SWITCH BOARD TEST END ************\n");

	return 0;
}

int hexagon_light_main(int argc, FAR char *argv[])
{
	int32_t val;
	int i;
	int pin_cds;
	int max = 0;
	char *adc0 = "0";
	char *adc1 = "1";

	max = atoi(argv[3]);

	if (strcmp(argv[2], adc0)==0 ) { pin_cds = A0; }
	else if (strcmp(argv[2], adc1)==0 ) { pin_cds = A2; }
	else { show_usage_hexagon(argv[0]); }

	printf("*********** HEXAGON LIGHT BOARD TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		val = read_adc(pin_cds);
		printf("|--- (%2d/%d) Light Sensor value(ADC %d):%d\n", i+1, max, pin_cds, val);
		up_mdelay(1000);
	}

	printf("************ HEXAGON LIGHT BOARD TEST END ************\n");

	return 0;
}

int hexagon_buzzer_main(int argc, FAR char *argv[])
{
	int i;
	int fd;
	int pin_buzzer;
	int max = 0;
	char *pwm0 = "0";
	char *pwm1 = "1";
	int dutycycle=100;

	max = atoi(argv[3]);

	if (strcmp(argv[2], pwm0)==0 ) { pin_buzzer = PWM0; }
	else if (strcmp(argv[2], pwm1)==0 ) {pin_buzzer = PWM2; }
	else { show_usage_hexagon(argv[0]); }

	printf("*********** HEXAGON BUZZER BOARD TEST START ***********\n");
	fd = pwm_open(pin_buzzer);

	for(i=0 ; i<max ; i++)
	{
		printf("|--- (%2d/%d) Do Re Mi Fa So La Ti Do ~ \n", i+1, max);
		up_mdelay(50);
		pwm_write(fd, O5_DO, dutycycle);
		up_mdelay(300);

		up_mdelay(50);
		pwm_write(fd, O5_RE, dutycycle);
		up_mdelay(300);

		up_mdelay(50);
		pwm_write(fd, O5_MI, dutycycle);
		up_mdelay(300);

		pwm_write(fd, O5_FA, dutycycle);
		up_mdelay(300);

		pwm_write(fd, O5_SO, dutycycle);
		up_mdelay(300);

		pwm_write(fd, O5_LA, dutycycle);
		up_mdelay(300);

		pwm_write(fd, O5_TI, dutycycle);
		up_mdelay(300);

		pwm_write(fd, O6_DO, dutycycle);
		up_mdelay(300);
	}
	printf("************ HEXAGON BUZZER BOARD TEST END ************\n");
	pwm_write(fd, O5_DO, 0);
	pwm_close(fd);

	return 0;
}
