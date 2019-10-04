#include <cstdio>
#include <cmath>

double sum (int n);

int main (void)
{
  int max = 5000;
  double gamma = 0.0;
  double gamma2 = 0.0;
  
  for (int i = 1; i <=  max; i++){
    gamma = sum(i)- std::log(i);
    gamma2 = sum(i) -std::log(i + 0.5);
    
    if (i%100 == 0){
      std::printf ("%10d \t %20.16e \t %20.16e \n", i, gamma, gamma2);
    }
  }

  return 0;
}


double sum (int n)
{
  double sum =0;
  for (int i = 1; i<=n; i++)
    {
      sum += 1.0/i;
    }
  return sum;
}
