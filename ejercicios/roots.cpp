#include <cstdio>
#include <cmath>

void roots (double a, double b, double c);

int main (void)
{

  roots(2, 10, 1);
  
  return 0;
}


void roots (double a, double b, double c)
{
  double det = std::sqrt(b*b -4*a*c);
  double x1 = (-b - det)/(2.0*a);
  double x2 = -2.0*c/(b + det);
  double f1 = a*(x1*x1) + b*x1 + c;
  double f2 = a*(x2*x2) + b*x2 + c;

  std::printf("%.16e \t %.16e \t %.16e \t %.16e \n", x1,x2,f1,f2);
}
