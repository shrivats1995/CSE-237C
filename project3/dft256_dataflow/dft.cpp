#include<math.h>
#include "dft.h"
#include"coefficients256.h"

typedef float temp_var;

// convert current implementation to function canonical form for dataflow pragma
// try to use 2 loops to pipeline them and unroll to make pipeline efficient

void func1_takeInputs(DTYPE *in_R, DTYPE *in_I, DTYPE *temp_R, DTYPE *temp_I)
{
	int i;
	for (i = 0; i<SIZE; i++ )
	{
		*(temp_R + i) = *(in_R + i);
		*(temp_I + i) = *(in_I + i);
	}
}

void func2_returnOutputs(DTYPE *temp_R, DTYPE *temp_I, DTYPE *out_R, DTYPE *out_I)
{
	int i,j;
		temp_var c[SIZE], s[SIZE];

		for (i = 0; i < SIZE; i += 1)
		{

			temp_var  valTempR[SIZE], valTempI[SIZE];
			for (j = 0; j < SIZE; j ++)
			{
				c[j] = cos_coefficients_table[(i * j)%SIZE];
				s[j] = sin_coefficients_table[(i * j)%SIZE];
			}

			for (j = 0; j < SIZE; j ++)
			{
#pragma HLS UNROLL factor=16
				out_R[i] += (*(temp_R + j) * c[j] - *(temp_I + j) * s[j]);
				out_I[i] += (*(temp_R + j) * s[j] + *(temp_I + j) * c[j]);

			}


		}
}



void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE], DTYPE outReal[SIZE], DTYPE outImag[SIZE])
{
	func2_returnOutputs(real_sample, imag_sample, outReal, outImag);
}
