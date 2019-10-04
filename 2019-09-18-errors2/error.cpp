#include <cstdio>
#include <cmath>

int main (void)
{
  int max = 100;
  
  float a = 1.0 ,b= 1.0, c =0.0;
  float x1=0.0, x2 = 0.0, x3 = 0.0, x4=0.0 ;

  
  for (int i = 1; i <= max; i++)
    {
      c= std::pow(10.0, -i);
      float det = std::sqrt (b*b - 4*a*c);
      x1 = (-b + det)/(2*a);
      x2 = (-b - det)/(2*a);
      x3 = (-2*c)/(b + det);
      x4 = (-2*c)/(b - det);

      std::printf("%10d %10.6f %10.6f %10.6f %10.6f\n",i, x1, x2, x3, x4);
    }
  return 0;
}
