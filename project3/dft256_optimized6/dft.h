
typedef float DTYPE;
#define SIZE 256 		/* SIZE OF DFT */
void dft(DTYPE XX_R[SIZE], DTYPE XX_I[SIZE], DTYPE OO_R[SIZE], DTYPE OO_I[SIZE]);
void func2_returnOutputs(DTYPE *temp_R, DTYPE *temp_I, DTYPE *out_R, DTYPE *out_I);
void func1_takeInputs(DTYPE *in_R, DTYPE *in_I, DTYPE *temp_R, DTYPE *temp_I);
void func3_storeOutputs(DTYPE *temp_R, DTYPE *temp_I, DTYPE *out_R, DTYPE *out_I);
