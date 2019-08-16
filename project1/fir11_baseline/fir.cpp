/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.

	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"

void fir (
  data_t *y,
  data_t x
  )
{
	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0,53};
	// Write your code here
	int i;
	static data_t regMem[N];
	acc_t sum;
	data_t xij;
	sum = 0;
	for(i = N-1; i>=0; i--)
	{
		if(i == 0)
		{
			regMem[0] = x;
			xij = x;
		}
		else
		{
			regMem[i] = regMem[i-1];
			xij = regMem[i];
		}
		sum = sum + (c[i] * xij);

	}

	*y = sum;

}

