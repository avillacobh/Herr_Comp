#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "papi.h"



int trans (const double * M, double *MT,int N, int Nb);

int main ()
{
  const int N = 8192;
  // Declare as pointers and ask for memory to use the heap
  double *A = new double [N*N], *AT = new double [N*N];
  
  // initialize matrices
  for (int ii =0; ii < N; ++ii) {
    for (int jj =0; jj < N; ++jj) {
      A[ii*N + jj] = ii + jj + 1; 
      AT[ii*N + jj] = 0.0;
    }
  }

  // PAPI vars
  float real_time, proc_time,mflops;
  long long flpops;
  float ireal_time, iproc_time, imflops;
  long long iflpops;
  int retval;

  for(int Nb = 1; Nb <= N; Nb*=2)
    {
      // start PAPI counters
      if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
        {
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
        }

      trans(A, AT, N, Nb);

      if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
        {
        printf("retval: %d\n", retval);
        exit(1);
        }
      

      printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n",
  	 real_time, proc_time,flpops,mflops);
      
      // Do something here, like computing the average of the resulting matrix, to avoid the optimizer deleting the code
      printf("%e.15\n", AT[0]);
    }
  
  delete [] A;
  delete [] AT;


  
  // variando el tamaño
  int nb=32; //bloque óptimo

  for(int n = nb; n <= 2*N; n*=2){
    // initialize matrices
    for (int ii =0; ii < n; ++ii) {
      for (int jj =0; jj < n; ++jj) {
	A[ii*n + jj] = ii + jj + 1; 
	AT[ii*n + jj] = 0.0;
      }
    }

    // start PAPI counters
    if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
      {
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
      }
    
    trans(A, AT, n, nb);
    
    if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
      {
        printf("retval: %d\n", retval);
        exit(1);
      }
    
    
    printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n",
	   real_time, proc_time,flpops,mflops);
    
    // Do something here, like computing the average of the resulting matrix, to avoid the optimizer deleting the code
    printf("%e.15\n", AT[0]); 
    
    delete [] A;
    delete [] AT;
  }
  
  return 0;
}

int trans (const double * M, double *MT, int N, int Nb)
{
  for (int bi = 0; bi < N; bi+=Nb){
    for (int bj = 0; bj < N; bj+=Nb){
       for (int i = 0; bi < Nb; ++i){
	 for (int j = 0; j < Nb; ++j){
	   MT[N*(bi+i)+bj+j] = M[N*(bj+j)+bi+i];
	 }
       }
    }
  }
  return 0;
}
