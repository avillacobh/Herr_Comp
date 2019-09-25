#include "sum1.h"

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
