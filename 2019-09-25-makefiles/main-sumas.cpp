#include <cstdio>
#include <cmath>

#include "sum1.h"
#include "sum2.h"
#include "sum3.h"


int main (void)
{
  int nmax =5000;
  for (int i = 1; i<= nmax; i++)
    {
      float s3 = sum3(i);
      float delta1 = std::abs((sum1(i)-s3)/s3);
      float delta2 = std::abs((sum2(i)-s3)/s3);
      std::printf ("%10d %10e %10e %10e %10e %10e \n",i,sum1(i),sum2(i),sum3(i), delta1, delta2);
    }

  return 0;
}

