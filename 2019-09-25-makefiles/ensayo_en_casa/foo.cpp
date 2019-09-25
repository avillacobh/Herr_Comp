#include "foo.h"

void foo(int N)
{
  std::cout << "Hola\n";
  int sum = 0;
  for (int i = 1; i<= N; i++)
    {
      sum += i;
    }
  std::cout<< "suma de "<< N << " primeros números es " << sum << std::endl;
}
