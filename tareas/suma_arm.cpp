#include <fstream>
#include <cmath>


int main(void)
{
  const int Nmax =1000;
  double sum = 0 ;

  std::ofstream fout ("datos.txt");
  
  for (int i = 1; i < Nmax+1; i++)
    {
      sum += 1.0/i;
      fout << i << "\t" << sum << "\n";
    }

  fout.close();
  
  return 0;
}
