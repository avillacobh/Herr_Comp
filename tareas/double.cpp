#include <iostream>

int main (void)
{
  int i = 0;
  double over = 1.0;
  double under = 1.0;

  while(under > 0)
    {
      over *=2.0;
      under/=2.0;
      ++i;

      std::cout << i << "\t" << under << "\t" << over << "\n";
    }
  
  return 0;
}
