/****************************************************************************
*
* Copyright 2018 Primesoft All Rights Reserved.
*
* Filename: gpio.h
* Author: enj.park, yr.kim
* Release date: 2018/05/02
* Version: 2.0
*
****************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include <fcntl.h>
#include <tinyara/gpio.h>

#define	HIGH	1
#define	LOW		0

void gpio_write(int port, int value);
int gpio_read(int port);

#endif /* GPIO_H_ */
