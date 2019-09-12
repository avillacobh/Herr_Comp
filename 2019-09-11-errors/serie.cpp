#include <fstream>
#include <cmath>




int main (void)
{
  int N =50;
  double x =0.01;
  
  std::ofstream fout ("datos.txt");

  for(x = 0.1; x< 8.0; x += 0.1){
    double term = x;
    double sum = x;
    
    for (int ii = 2; ii <= N; ++ii)
      {
	term = term*(-1)*x*x/((2*ii)*(2*ii+1));
	sum += term;
      }

    fout << x << "\t" << sum << "\t" << std::sin(x) << "\n";
  }
  fout.close();
  
  return 0;
}


