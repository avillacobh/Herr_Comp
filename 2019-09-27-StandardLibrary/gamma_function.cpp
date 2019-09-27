#include <cstdio>
#include <cmath>

int main (void)
{
  const double xmin = -5.0;
  const double xmax =10.0;
  const double dx = 0.0001;
  const int NSTEPS = (xmax - xmin)/dx;
  
  for(int i = 0; i <= NSTEPS; i++){
    double x = xmin + i*dx;
    std::printf("%25.16e \t %25.16e \n", x, std::tgamma (x)); 
  }
  
  return 0;
}
