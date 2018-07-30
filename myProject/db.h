/****************************************************************************
 *
 * Copyright 2018 baruncorechips All Rights Reserved.
 *
 * Filename 			: db.h
 * Author               : Unbok Wi
 * Date                 : 2018.07.24.
 * Version				: 1.0
 * Modification history :
 *
 ****************************************************************************/
#define A0 2272
#define B0 2028
#define C0 1912
#define D0 1703
#define E0 1517
#define F0 1432
#define G0 1277
#define A1 1136
#define B1 1023
#define C1 902
#define D1 803
#define E1 758
#define F1 676
#define G1 602
#define A2 568
#define B2 506
#define C2 477
#define D2 425
#define E2 379
#define F2 358
#define G2 318

//
//void R(int scale, int num)
//{
//	int buzz;
//	int cycle = 130;
//	buzz=pwm_open(PWM_PIN);
//	pwm_write(buzz, scale, cycle);
//	up_mdelay(2450/num);
//	pwm_close(buzz);
//}

	int RYTHME[] =		//tone
	{
		B1, B1, C1,
		E1, E1, E1, C1, E1, C1, E1, F1, F1,
		1, 1, 1, A1, F1, E1,
		D1, E1, F1, E1, E1, D1, B1, B1, D1, C1,
		C1, 1, 1, 1, B1, C1,
		E1, E1, E1, C1, C1, E1, C1, E1, E1, F1,
		F1, 1, 1, 1, F1, E1,
		D1, E1, F1, E1, D1, D1, 1, B1,
		A2, G1, E1, F1, A2, A2, G1, 1, G1, A2,
		B2, E1, E1, E1, E1, E1, E1, B1, 1, B1, B1, B1, B1, B1,
		B2, E1, E1, E1, E1, E1, E1, B1, 1, B1, B1, B1, B1, B1,
		B2, E1, E1, E1, E1, C1, E1, E1, C1, E1, E1, E1, E1,
		G1, A2, G1, F1, F1, 1,
		1, 1, F1, F1, F1, F1, F1,
		G1, F1, G1, F1, G1, F1, G1, G1, D1,
		D1, E1, F1, 1, 1, F1, F1,
		G1, F1, G1, F1, G1, F1, G1, G1, D1,
		D1, E1, F1, E1, 1, 1, E1, E1, F1,
		G1, B2, G1, F1, F1, F1, E1,
		G1, B2, G1, F1, F1, F1, E1,
		F1, E1, F1, E1, F1, F1, F1, D1,
		D1, E1, F1, E1, E1, 1,
		G1, B2, B2, G1, G1, B2, B2, F1,
		F1, 1, F1, E1, F1, E1, F1, E1, E1,
		G1, B2, B2, G1, G1, B2, B2, E1,
		E1, 1, 1, 1, E1, 1, E1
	};

	int BEAT[] =		//numbers = note length(ex. 4 = quarter note)
	{
		16, 16, 16,
		8, 8, 8, 8, 8, 16, 8, 8, 16,
		2, 8, 16, 16, 16, 16,
		8, 16, 8, 8, 16, 8, 16, 8, 8, 16,
		4, 4, 4, 8, 16, 16,
		8, 16, 8, 8, 16, 8, 16, 8, 16, 8,
		4, 4, 4, 8, 16, 16,
		8, 16, 8, 8, 16, 4, 8, 8,
		8, 8, 8, 16, 16, 8, 8, 8, 16, 16,
		8, 16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 16, 16,
		8, 16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 16, 16,
		8, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16,
		8, 8, 8, 8, 4, 8,
		8, 16, 16, 16, 16, 16, 16,
		8, 8, 8, 8, 8, 8, 8, 16, 16,
		8, 8, 4, 8, 16, 16, 8,
		8, 8, 8, 8, 8, 8, 8, 16, 16,
		8, 8, 8, 8, 8, 16, 16, 8, 8,
		8, 8, 8, 8, 4, 8, 8,
		8, 8, 8, 8, 4, 8, 8,
		8, 8, 8, 8, 8, 8, 16, 16,
		8, 8, 8, 8, 4, 4,
		4, 8, 16, 16, 4, 8, 16, 16,
		4, 8, 16, 16, 8, 16, 8, 8, 16,
		4, 8, 16, 16, 4, 8, 16, 16,
		4, 2, 4, 8, 8, 8, 8
	};
