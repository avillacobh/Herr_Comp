#include <iostream>
#include <complex>

int main (void)
{
  std::complex<double> z;
  z.real (2.69);
  z.imag(-5.85);
  std::complex<double> z2 = {-5.3,3.3};
  
  std::cout << z << std::endl;
  std::cout << z2 << std::endl;
  std::cout << z + z2 << std::endl;
  std::cout << z*z2 << std::endl;
  std::cout << z/z2 << std::endl;
  
  return 0;
}
