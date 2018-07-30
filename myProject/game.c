#include <apps/shell/tash.h>
#include <tinyara/config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "game.h"
#include "mario.h"
#include "pwm.h"
#include "gpio.h"
#include "adc.h"
#include "db.h"


//┌**********이진수 게임, 오르골에 사용**********┐//
#define SW_LEFT 46
#define SW_RIGHT 47
#define ooo 48
#define xxx 50
//└**********이진수 게임, 오르골에 사용**********┘//


//┌**********나만의 악기 I에 사용**********┐//
#define DO_btn      46   //button GPIO PIN number
#define RE_btn      47
#define MI_btn      48
#define SO_btn      50
//└**********나만의 악기 I에 사용**********┘//

//┌**********나만의 악기 II에 사용**********┐//
#define SW_BZ1 46	//도,레,미,파,솔 연주 버튼
#define SW_BZ2 47	//라,시,도,레,미 연주 버튼
//└**********나만의 악기 II에 사용**********┘//

//┌**********나만의 악기 I,나만의 악기 II에 사용**********┐//
#define   PWM_PIN         0   //PWM PIN number
//└**********나만의 악기 I,나만의 악기 II에 사용**********┘//

//┌**********투명자, 나만의 악기 II에 사용**********┐//
#define   ADC_PIN         0   //ADC PIN number
//└**********투명자, 나만의 악기 II에 사용**********┘//


/*************************************************
 * functions for games
 ************************************************/

//**********나만의 악기 I에서 사용**********//
//pwm 제어 함수
void pwm_func(int gpio_pin, int period, int duty_cycle, char* name) {
	int fd = pwm_open(PWM_PIN);
	printf("%s\n", name);
	pwm_write(fd,period,duty_cycle);
	while(gpio_read(gpio_pin)){}   //switch가 눌려있는 동안 while문 안에 머물기
	pwm_close(fd);
	return;
}
//**********나만의 악기 I에서 사용**********//






//**********2진수 게임**********//
int binary_main(int argc, FAR char *argv[])
{
   int rsw, lsw, val;

   while(1) {
      gpio_write(ooo, gpio_read(SW_RIGHT));
      gpio_write(xxx, gpio_read(SW_LEFT));
   }
   return 0;
}
//**********2진수 게임**********//


//**********감성자극 오르골**********//
int mp3_main(int argc, FAR char *argv[])
{
/*
	int flag=0;
	int lsw, rsw, i;
	int sw_left_pin = _;
	int sw_right_pin = _;

	int size = sizeof(song) / sizeof(int);
	printf("==============================================\n");
	printf("                                              \n");
	printf("                 MP3 PLAYER                   \n");
	printf("                                              \n");
	printf("==============================================\n");
	printf("                                              \n");
	printf("   Left switch : play | Right switch : exit   \n");
	while(flag==0){
		lsw = gpio_read(sw_left_pin);
		rsw = gpio_read(sw_right_pin);

		if (lsw==1 && rsw==0) {
			printf("                                              \n");
			printf("                    PLAY!                     \n");
			printf("                                              \n");
			for(i=0; i<size;i++) {
				muse(RYTHME[i],BEAT[i],PWM_PIN);
				if (gpio_read(sw_right_pin)==1) {
					i = size;
				}
			}
			flag = 1;
		} else if (rsw == 1 && lsw==0) {
			flag = 1;
			printf("                                              \n");
			printf("                    bye..                     \n");
			printf("                                              \n");
		} else
			flag=0;
	}

	printf("==============================================\n");
	printf("                                              \n");
	printf("           Player has done everything.        \n");
	printf("                End of player.                \n");
	printf("                                              \n");
	printf("==============================================\n");

	return 0;
*/
}
//**********감성자극 오르골**********//

//**********나만의 악기 I**********//

int piano_main(int argc, FAR char *argv[]) {
/*
   int duty_cycle = 100;

   printf("============= Play song =============\n");

   int do_btn = _;
   int re_btn = _;
   int mi_btn = _;
   int so_btn = _;

   //switch 처음 눌림 감지
   while(1){
      if(gpio_read(46) == 1) {
         pwm_func(do_btn, C6, duty_cycle, "DO");
      } else if(gpio_read(47) == 1) {
         pwm_func(re_btn, D6, duty_cycle, "RE");
      } else if(gpio_read(48) == 1) {
         pwm_func(mi_btn, E6, duty_cycle, "MI");
      } else if(gpio_read(50) == 1) {
         pwm_func(so_btn, G6, duty_cycle, "SO");
      }
   }

   return 0;
*/
}

//**********나만의 악기 I**********//

//**********투명자**********//

int ruler_main(int argc, FAR char *argv[]) {
/*
	int32_t val;
	int i;
	int adc_pinnum = _;


	printf("============= ADC IR Sensor Test Start =============\n");
	for (i = 1; i <= 10; i++) {
		val = read_adc(adc_pinnum);

		if(val>850)
			printf("0cm %d (%d / 10)\n",val,i);
		else if(val>500)
			printf("1cm %d (%d / 10)\n",val,i);
		else if(val>300)
			printf("2cm %d (%d / 10)\n",val,i);
		else if(val>200)
			printf("3cm %d (%d / 10)\n",val,i);
		else if(val>170)
			printf("4cm %d (%d / 10)\n",val,i);
		else if(val>150)
			printf("5cm %d (%d / 10)\n",val,i);
		else if(val>130)
			printf("6cm %d (%d / 10)\n",val,i);
		else
			printf("out of range (%d / 10)\n",i);

		up_mdelay(1000);
	}

	printf("============== ADC IR Sensor Test End ==============\n");

	return 0;
*/
}
//**********투명자**********//

//**********나만의 악기 II에 사용**********//
int play_song(int i){
/*
	int fd;
	int pwm_pinnum = _;
	if(gpio_read(SW_BZ1) == 1 || gpio_read(SW_BZ2) == 1){
		fd = pwm_open(pwm_pinnum);
		pwm_write(fd,i,100);

		if(i == E7)
		printf("E7\n");
		else if(i == D7)
		printf("D7\n");
		else if(i == C7)
		printf("C7\n");
		else if(i == B6)
		printf("B6\n");
		else if(i == A6)
		printf("A6\n");
		else if(i == G6)
		printf("G6\n");
		else if(i == F6)
		printf("F6\n");
		else if(i == E6)
		printf("E6\n");
		else if(i == D6)
		printf("D6\n");
		else if(i == C6)
		printf("C6\n");

		while(i==ir_scale() && (gpio_read(SW_BZ1) == 1 || gpio_read(SW_BZ2) == 1));
		pwm_close(fd);
	}

	else{
		printf("N\n");
		while(gpio_read(SW_BZ1) == 0 && gpio_read(SW_BZ2) == 0);
	}
*/
}
//**********나만의 악기 II에 사용**********//

//**********나만의 악기 II에 사용**********//
int ir_scale(void){
/*
   int i,ir_val;
   int adc_pinnum = _;

   ir_val = read_adc(adc_pinnum);

   if(gpio_read(SW_BZ2) == 1) {
      if(ir_val>550)
    	  i = A6;
      else if(ir_val>250)
    	  i = B6;
      else if(ir_val>140)
    	  i = C7;
      else if(ir_val>105)
    	  i = D7;
      else
    	  i = E7;
   } else {
      if(ir_val>550)
    	  i = G6;
      else if(ir_val>250)
    	  i = F6;
      else if(ir_val>140)
    	  i = E6;
      else if(ir_val>105)
    	  i = D6;
      else
    	  i = C6;
   }

   return i;
*/
}
//**********나만의 악기 II에 사용**********//

//**********나만의 악기 II**********//
int inst2_main(int argc, FAR char *argv[]){
/*
	while(1){
		play_song(ir_scale());
	}
	return 0;
*/
}
//**********나만의 악기 II**********//



static void show_game_hexagon(FAR const char *program)
{
   printf("|-------------------------------------------|\n");
   printf("| ******* ARTIK053 BASIC KIT GAMES ******** |\n");
   printf("|               %s binary                 |\n", program);
   printf("|              %s musicbox                |\n", program);
   printf("|             %s instrument1              |\n", program);
   printf("|               %s ruler                  |\n", program);
   printf("|             %s instrument2              |\n", program);
   printf("|-------------------------------------------|\n");

}


int game_main(int argc, FAR char *argv[])
{

   if ( (argc==2) && (strcmp(argv[1],"binary")==0) ) {binary_main(argc,argv);}
   else if ( (argc==2) && (strcmp(argv[1],"musicbox")==0) ) {mp3_main(argc,argv);}
   else if ( (argc==2) && (strcmp(argv[1],"instrument1")==0) ) {piano_main(argc,argv);}
   else if ( (argc==2) && (strcmp(argv[1],"ruler")==0) ) {ruler_main(argc,argv);}
   else if ( (argc==2) && (strcmp(argv[1],"instrument2")==0) ) {inst2_main(argc,argv);}
   else show_game_hexagon(argv[0]);

   return 0;
}







