/*
	Filename: phasedetector.cpp
		Phase detector

	INPUT:
		I: signal for I sample
		Q: signal for Q sample
		length: array size

	OUTPUT:
		R: Radius
		Theta: Angle

*/

#include "phasedetector.h"
#include "fir.h"
void phasedetector (data_t *I, data_t *Q, data_t *R, data_t *theta, int length)
{
#pragma HLS INTERFACE axis register both port=theta
#pragma HLS INTERFACE axis register both port=R
#pragma HLS INTERFACE axis register both port=Q
#pragma HLS INTERFACE axis register both port=I
	data_t x,y;
	data_t r1, t1;
	for(int i=0;i<length;i++)
	{
		#pragma HLS loop_tripcount min=1024 max=1024
		fir(*I, *Q, &x, &y);
		cordiccart2pol(x, y, R, theta);
		I++;
		Q++;
		R++;
		theta++;
	}
}




