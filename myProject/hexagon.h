/****************************************************************************
*
* Copyright 2018 baruncorechips All Rights Reserved.
*
* Filename: hexagon.h
* Author: sj.yang
* Release date: 2018/07/06
* Version: 1.0
*
****************************************************************************/

#ifndef HEXAGON_H_
#define HEXAGON_H_

static void show_usage_hexagon(FAR const char *program);
int hexagon_main(int argc, FAR char *argv[]);
int hexagon_led_main(int argc, FAR char *argv[]);
int hexagon_switch_main(int argc, FAR char *argv[]);
int hexagon_light_main(int argc, FAR char *argv[]);
int hexagon_ir_main(int argc, FAR char *argv[]);
int hexagon_temp_main(int argc, FAR char *argv[]);
int hexagon_buzzer_main(int argc, FAR char *argv[]);


#endif /* HEXAGON_H_ */
