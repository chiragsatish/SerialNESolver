#include<iostream>
#include<xmmintrin.h>
#include "multiply.h"
using namespace std;

void matrix_multiplication_SSE(float* A, float* B,float * result,int n1,int m1,int m2,int lda,int ldb)
{
    int i,j,k;
    for(i = 0; i < n1; ++i){
        for(j = 0; j < m2; ++j){
            for(k = 0; k < m1; ++k)
            {	
                *(result+i*lda+j) += A[i*ldb+k] * B[k*lda+j];
            }
        }
    }
}
