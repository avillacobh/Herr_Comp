#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "papi.h" 



int mult (const double *A, const double *B, double *C, int N, int Nb);

int main ()
{
  std::string datos1;
  std::string datos2;
  
  std::cin >> datos1;
  std::cin >> datos2;
  
  const int N = 8192;
  
  // Declare as pointers and ask for memory to use the heap
  double *A = new double [N*N], *B = new double [N*N], *C = new double[N*N];

  // initialize matrices
  for (int ii =0; ii < N; ++ii) {
    for (int jj =0; jj < N; ++jj) {
      A[ii*N + jj] = ii + jj + 1; 
      B[ii*N + jj] = ii + jj -2;
      C[ii*N + jj] = 0.0;
    }
  }

   // PAPI vars
  float real_time, proc_time,mflops;
  long long flpops;
  float ireal_time, iproc_time, imflops;
  long long iflpops;
  int retval;

  std::ofstream fout (datos1);
  
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

      mult(A, B,C,N, Nb);

      if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
        {
        printf("retval: %d\n", retval);
        exit(1);
        }
      

      fout << Nb << "\t" << real_time << "\t" << proc_time << "\n";
      
      // Do something here, like computing the average of the resulting matrix, to avoid the optimizer deleting the code
      int tmp = 0;
      for (int i = 0 ; i < N*N; i++){
	tmp += C[i];
      }
      printf("%d\n", tmp);
    }

  fout.close();
  
  delete [] A;
  delete [] B;
  delete [] C;

  //variando el tamaño

  int nb = 32; //bloque que óptimo

  std::ofstream fout2 (datos2);
  
  for(int n = nb; n <= 2*N; n*=2){
    double *A = new double [n*n], *B = new double [n*n], *C = new double[n*n];
    
    // initialize matrices
    for (int ii =0; ii < n; ++ii) {
      for (int jj =0; jj < n; ++jj) {
	A[ii*n + jj] = ii + jj + 1; 
	B[ii*n + jj] = ii + jj -2;
	C[ii*n + jj] = 0.0;
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
    
    mult(A, B,C,n, nb);
    
    if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
      {
	printf("retval: %d\n", retval);
	exit(1);
      }
    
    
    fout2 << n << "\t" << real_time << "\t" << proc_time << "\n";
    
    // Do something here, like computing the average of the resulting matrix, to avoid the optimizer deleting the code
    int tmp = 0;
    for (int i = 0 ; i < n*n; i++){
      tmp += C[i];
    }
    printf("%d\n", tmp);
    
    delete [] A;
    delete [] B;
    delete [] C;
    
  }
  return 0;
}


int mult (const double *A, const double *B, double *C,int N, int Nb)
{
for (int bi = 0; bi < N; bi+=Nb){
  for (int bj = 0; bj < N; bj+=Nb){
    for (int bk = 0; bk < N; bk+=Nb){
      for (int i = 0; i < Nb; i++){
	 for (int j = 0; j < Nb; j++){
	    for (int k = 0; k < Nb; k++){
	      C[N*(bi + i)+ bj+j]+= A[N*(bi+i)+bk+k]*B[N*(bk+k)+bj+j]; 
	    }
	 }
      }
    }
  }
 }
 return 0;
}
