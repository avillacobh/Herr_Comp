#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func1 ( float ***a, int n);
void func2 ( float ***a, int n);
void func3 ( float ***a, int n);


int main(){
  const int n = 128;
  float ***a;
  int i,j;
  
  // Allocating memory for array/matrix
  a = malloc(n*sizeof(float **));
  for (i=0; i<n; i++){
    a[i] = malloc(n*sizeof(float*));
    for (j=0; j<n; j++)
      a[i][j] = malloc(n*sizeof(float));
  }
 
  func1(a,n);
  func2(a,n);
  func3(a,n);

  
  // Clearing memory
  for (i=0; i<n; i++){
    for (j=0; j<n; j++)
      free(a[i][j]);
    free(a[i]);
  }
  free(a);

  return 0;
}


void func1 ( float ***a, int n)
{
  int i,j,k;
  clock_t cputime1, cputime2;
  cputime1 = clock();
  for (k=0; k<n; ++k)
    for (j=0; j<n; ++j)
      for (i=0; i<n; ++i)
        a[i][j][k] = 1.0;
  cputime2=clock() - cputime1;
  printf("Time with fast index inside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);
}

void func2 ( float ***a, int n)
{
  int i,j,k;
  clock_t cputime1, cputime2;
  cputime1 = clock();
  for(i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      for (k=0; k<n; ++k)
        a[i][j][k] = 2.3;
  cputime2=clock() - cputime1;
  printf("Time with fast index outside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);
}

void func3 ( float ***a, int n)
{
  int i,j,k;
  clock_t cputime1, cputime2;
  cputime1 = clock();
  for(i = n-1; i>=0; --i)
    for (j=n-1; j>=0; --j)
      for (k=n-1; k>=0; --k)
        a[i][j][k] = 1.1;
  cputime2=clock() - cputime1;
  printf("Time with fast index outside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);

}
