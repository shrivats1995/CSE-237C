#include<math.h>
#include "dft.h"
#include"coefficients1024.h"

typedef float temp_var;

void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE], DTYPE outReal[SIZE], DTYPE outImag[SIZE])
{

#pragma HLS ARRAY_PARTITION variable=imag_sample cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=real_sample cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=sin_coefficients_table cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=cos_coefficients_table cyclic factor=16 dim=1
	int i,j;
	temp_var w;
	temp_var c,s;


	for (i = 0; i < SIZE; i += 1)
	{
		outReal[i] = 0;
		outImag[i] = 0;

		for (j = 0; j < SIZE; j += 1)
		{

			#pragma HLS UNROLL factor=16

			c = cos_coefficients_table[(i * j)%SIZE];
			s = sin_coefficients_table[(i * j)%SIZE];

			outReal[i] += (real_sample[j] * c - imag_sample[j] * s);
			outImag[i] += (real_sample[j] * s + imag_sample[j] * c);
		}
	}


}
