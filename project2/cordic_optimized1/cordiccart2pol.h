#ifndef CORDICCART2POL_H
#define CORDICCART2POL_H

#include<ap_fixed.h>

#define NO_ITER 16

typedef int   coef_t;
typedef ap_fixed<15, 3 , AP_RND, AP_WRAP, 1> data_t;
//typedef ap_fixed<15, 3 , AP_RND, AP_WRAP, 1> data_t1;

//typedef ap_fixed<64,32,AP_RND> acc_t;

void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta);

#endif
