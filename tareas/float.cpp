#include <iostream>

int main (void)
{
  int i = 0;
  float over = 1.0;
  float under = 1.0;

  while(under > 0)
    {
      over *=2.0;
      under/=2.0;
      ++i;

      std::cout << i << "\t" << under << "\t" << over << "\n";
    }
  
  return 0;
}
