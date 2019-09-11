#include <cstdio>


int main (void)
{
  double eps = 1.0;
  double one = 1.0;
  int i =0;
  while(eps > 0)
    {
      i++;
      eps /= 2;
      one = 1.0 +eps;
      std::printf("%8d %24.16e %24.16e\n" , i, one, eps);
      // if(one <=1) break;
    }
  
  return 0;
}
