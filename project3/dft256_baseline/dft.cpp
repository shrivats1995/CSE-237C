#include<math.h>
#include "dft.h"
#include"coefficients256.h"

typedef float temp_var;

void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE])
{
	int i,j;
	temp_var w;
	temp_var c,s;

	temp_var temp_real_samples[SIZE];
	temp_var temp_imag_samples[SIZE];

	for (i = 0; i < SIZE; i += 1)
	{
		temp_real_samples[i] = 0;
		temp_imag_samples[i] = 0;
		w = -(2.0 * 3.141592653589 /SIZE) * (temp_var)i;

		for (j = 0; j < SIZE; j += 1)
		{
			c = cos(j * w);
			s = sin(j * w);

			temp_real_samples[i] += (real_sample[j] * c - imag_sample[j] * s);
			temp_imag_samples[i] += (real_sample[j] * s + imag_sample[j] * c);
		}
	}

	for (i = 0; i < SIZE; i += 1)
	{
		real_sample[i] = temp_real_samples[i];
		imag_sample[i] = temp_imag_samples[i];
	}
}

