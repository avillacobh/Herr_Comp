#include "sum3.h"

float sum3 (int max)
{
  float sum = 0.0;

  for (int i = 1; i <= max; i++)
    {
      sum += 1.0/(2.0*i*(2*i+1));
    }
  return sum;
}
