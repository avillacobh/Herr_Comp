#include <cstdio>
#include <cmath>

float sum1 (int max);
float sum2 (int max);
float sum3 (int max);

int main (void)
{
  int nmax =10000;
  for (int i = 1; i<= nmax; i++)
    {
      float s3 = sum3(i);
      float delta1 = std::abs((sum1(i)-s3)/s3);
      float delta2 = std::abs((sum2(i)-s3)/s3);
      std::printf ("%10d %10e %10e %10e %10e %10e \n",i,sum1(i),sum2(i),sum3(i), delta1, delta2);
    }

  return 0;
}

float sum1 (int max)
{
  float sum = 0.0;
  int sign = -1;

  for (int i = 1; i <= 2*max; i++)
    {
      sum += sign*i/(i+1.0);
      sign *=-1;
    }
  return sum;
}

float sum2 (int max)
{
  float sum1 = 0.0;
  float sum2 = 0.0;

  for (int i = 1; i <= max; i++)
    {
      sum1 += (2.0*i-1.0)/(2.0*i);
      sum2 += 2.0*i/(2.0*i+1.0);
    }
  return sum2 - sum1;
}

float sum3 (int max)
{
  float sum = 0.0;

  for (int i = 1; i <= max; i++)
    {
      sum += 1.0/(2.0*i*(2*i+1));
    }
  return sum;
}
