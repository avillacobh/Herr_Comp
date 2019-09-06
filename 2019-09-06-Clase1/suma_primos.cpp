#include<iostream>

int isprime (int a);
int sumprimes (int min, int max);

int main (void)
{

  sumprimes (50,100);

  return 0;
}


int isprime (int a)

{
  for (int i=2; i < a; i++)
    {
      if (a % i == 0){
	return 0;
      }
    }
  return 1;
}

int sumprimes (int min, int max)
{
  int sum =0;

  for (int i = min; i <= max; i++)
    {
      if ( isprime(i) == 1)
	{
	  sum = sum +i;
	}
    }
  std::cout<< sum << std::endl;
  return 0;
}
