#include<iostream>



int main (void)
{
  int a = 1;
  int i =0;
  
  while(a>0)
    {
      i++;
      a *=2;
      std::cout << a << "\n";
    }
  std::cout << "Se necesitaron "<< i << " iteraciones\n";
  return 0;
}
