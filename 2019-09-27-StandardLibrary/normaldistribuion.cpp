#include <random>
#include <iostream>
#include <vector>
 
int main()
{
  const int NSAMPLES = 1e8;
  int seed = 1;
  
  const double xmin =0.0;
  const double xmax = 1.0;
  const double dx = 0.01;
  const int nbins = (xmax-xmin)/dx;
  
  std::vector<double> histo(nbins);
  
  std::mt19937 gen(seed); //Standard mersenne_twister_engine seeded with seed
  std::normal_distribution<> dis(0.5,0.2);

  for (int n = 0; n < NSAMPLES; ++n) {
    double r = dis(gen);
    int idx = int(r/dx);
    if (0 <= idx and idx < nbins){
    histo[idx] += 1;
    }
  }

  for(int i = 0; i < nbins; i++){
    std::cout << xmin + i*dx << "\t" << histo[i]/(NSAMPLES*dx) << "\n";
  }
  
  return 0;  
}
