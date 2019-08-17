/*
	Filename: fir.cpp
		Complex FIR or Match filter
		firI1 and firI2 share coef_t c[N]
		firQ1 and firQ2 share coef_t c[N]
		
	INPUT:
		I: signal for I sample
		I: signal for Q sample

	OUTPUT:
		X: filtered output
		Y: filtered output

*/

#include "fir.h"


void firI1 (data_t *y, data_t x)
{
	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};
	#pragma HLS ARRAY_PARTITION variable=c cyclic factor=4 dim=1
	#pragma HLS RESOURCE variable=c core=ROM_2P
	static data_t shift_reg[N];
	#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=4 dim=1
	#pragma HLS RESOURCE variable=shift_reg core=RAM_T2P_BRAM
	acc_t acc;
	acc = 0;

	int i;

	for (i = N-1; i > 0; i--)
	{

	#pragma HLS PIPELINE II=1
		shift_reg[i] = shift_reg[i-1];
	}
	for (i = N-1; i > 0; i--)
	{
	#pragma HLS PIPELINE II=1
		acc += shift_reg[i] * c[i];
	}
	shift_reg[0] = x;
	acc += x * c[0];
	*y = acc;

}


void firI2 (data_t *y,data_t x)
{

	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};

	#pragma HLS ARRAY_PARTITION variable=c cyclic factor=4 dim=1
	#pragma HLS RESOURCE variable=c core=ROM_2P
	static data_t shift_reg[N];
	#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=4 dim=1
	#pragma HLS RESOURCE variable=shift_reg core=RAM_T2P_BRAM
	acc_t acc;
	acc = 0;

	int i;

	for (i = N-1; i > 0; i--)
	{

	#pragma HLS PIPELINE II=1
		shift_reg[i] = shift_reg[i-1];
	}
	for (i = N-1; i > 0; i--)
	{

	#pragma HLS PIPELINE II=1
		acc += shift_reg[i] * c[i];
	}
	shift_reg[0] = x;
	acc += x * c[0];
	*y = acc;

}


void firQ1 (data_t *y, data_t x)
{

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};


	#pragma HLS ARRAY_PARTITION variable=c cyclic factor=4 dim=1
	#pragma HLS RESOURCE variable=c core=ROM_2P
	static data_t shift_reg[N];
	#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=4 dim=1
	#pragma HLS RESOURCE variable=shift_reg core=RAM_T2P_BRAM
	acc_t acc;
	acc = 0;

	int i;

	for (i = N-1; i > 0; i--)
	{

	#pragma HLS PIPELINE II=1
		shift_reg[i] = shift_reg[i-1];
	}
	for (i = N-1; i > 0; i--)
	{

	#pragma HLS PIPELINE II=1
		acc += shift_reg[i] * c[i];
	}
	shift_reg[0] = x;
	acc += x * c[0];
	*y = acc;

}

void firQ2 (data_t *y, data_t x)
{

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};

	#pragma HLS ARRAY_PARTITION variable=c cyclic factor=4 dim=1
	#pragma HLS RESOURCE variable=c core=ROM_2P
	static data_t shift_reg[N];
	#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=4 dim=1
	#pragma HLS RESOURCE variable=shift_reg core=RAM_T2P_BRAM
	acc_t acc;
	acc = 0;

	int i;

	for (i = N-1; i > 0; i--)
	{

	#pragma HLS PIPELINE II=1
		shift_reg[i] = shift_reg[i-1];
	}
	for (i = N-1; i > 0; i--)
	{

	#pragma HLS PIPELINE II=1
		acc += shift_reg[i] * c[i];
	}
	shift_reg[0] = x;
	acc += x * c[0];
	*y = acc;

}


void fir (data_t I,data_t Q,data_t *X,data_t *Y)
{

	data_t IIfir, QQfir, IQfir, QIfir;

	firI1(&IIfir,I);
	firI2(&QIfir,Q);

	firQ1(&QQfir,Q);
	firQ2(&IQfir,I);

	*X = IIfir + QQfir;
	*Y = QIfir - IQfir;

}
