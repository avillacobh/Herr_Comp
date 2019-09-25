#include "sum2.h"

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
