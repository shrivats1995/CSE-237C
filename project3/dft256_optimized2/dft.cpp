#include<math.h>
#include "dft.h"
#include"coefficients256.h"

typedef float temp_var;

void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE], DTYPE outReal[SIZE], DTYPE outImag[SIZE])
{
	int i,j;
	temp_var w;
	temp_var c,s;


	for (i = 0; i < SIZE; i += 1)
	{
		outReal[i] = 0;
		outImag[i] = 0;

		for (j = 0; j < SIZE; j += 1)
		{
			c = cos_coefficients_table[(i * j)%SIZE];
			s = sin_coefficients_table[(i * j)%SIZE];

			outReal[i] += (real_sample[j] * c - imag_sample[j] * s);
			outImag[i] += (real_sample[j] * s + imag_sample[j] * c);
		}
	}


}
