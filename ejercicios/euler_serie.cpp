#include <cstdio>
#include <cmath>

double serie (double x);

int main (void)
{

  std::printf("%.16e \t %.16e\n", serie (-25.5), serie(3.14159));
 
  return 0;
}


double serie (double x)
{
  double eps = 1e-6;
  int max = 500;
  
  double term = 1.0;
  double sum = 1.0;
  if(x<0){
    for(int i = 0; i<=max; i++)
      {
	term *= -x/(i+1.0);
	sum += term;
	if (std::abs(term) < eps) return 1.0/sum;
      }
  }else{
    for(int i = 0; i<=max; i++)
      {
	term *= x/(i+1.0);
	sum += term;
	if (std::abs(term) < eps) return sum;
      }
  }
  
}
