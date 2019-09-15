#include <iostream>

int isprime (int x);
void sumprimes (int min, int max);

int main(void)
{
  const int min = 500;
  const int max = 12400;

  sumprimes (min, max);
  
  return 0;
}


int isprime (int x)
{
  if (x < 2) return 0;
  
  for (int i =2; i < x ; i++)
    {
      if (x % i == 0) return 0;
    }
  return 1;
}

void sumprimes (int min, int max)
{
  int sum = 0;
  int count =0;
  
  for (int i = min ; i < max +1; i++)
    {
      if (isprime(i) > 0)
	{
	  sum +=i;
	  count +=1;
	}
    }
  std::cout << "Entre " << min << " y " << max << " hay " << count << " números primos y su suma es " << sum << "\n";
}

