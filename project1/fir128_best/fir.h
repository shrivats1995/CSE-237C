/*
	Filename: fir.h
		Header file
		FIR lab wirtten for WES/CSE237C class at UCSD.

*/
#ifndef FIR_H_
#define FIR_H_

const unsigned char N=128;

typedef char coef_t;
typedef  int 	data_t;
typedef int	acc_t;

void fir (
  data_t *y,
  coef_t x
  );

#endif
