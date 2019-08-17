/*
	Filename: fir.h
		Header file
		FIR lab wirtten for 237C class at UCSD.

*/
#ifndef PHASE_DETECTOR_H_
#define PHASE_DETECTOR_H_

const int SAMPLES = 1024;
#include <ap_fixed.h>

//const int N = 32;

#define NO_ITER 16

typedef int   coef_t;
typedef ap_fixed<22, 8, AP_RND, AP_WRAP, 1> data_t;


void phasedetector (
  data_t *I,
  data_t *Q,

  data_t *R,
  data_t *theta,

  int length
  );

void cordiccart2pol(data_t x, data_t y, data_t * r, data_t * theta);

void fir (
  data_t I,
  data_t Q,

  data_t *X,
  data_t *Y
  );

#endif
