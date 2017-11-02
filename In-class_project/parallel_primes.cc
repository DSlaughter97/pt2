// File: parallel_primes.cc
// Author: Lucas Nation
// Date: 1/25/17
// Purpose: Reads as input a number n and outputs the nth prime number in parallel and at least twice as 
//          fast as "big_primes.cc"
//

#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

//*************************************************************
//Function: IsPrime
//Author: David W. Juedes
//Purpose: Determines whether x is a prime number by examining all
//integers i < sqrt(x).
//******************************************************************
bool IsPrime(long long x) {
  long long i=2;

  while (i*i <=x) {
    if (x%i==0) {
      return false;
    }
    i++;
  }
  return true;
}


//*************************************************************************
// Function:NextPrime(prev)
// Author: David W. Juedes
// Purpose: Returns the next prime number larger than prev.
//************************************************************************
long long NextPrime(long long prev) {

  long long i;
  i=prev+1;
  while (!IsPrime(i)) {
    i++;
  }
  return i;
}

// Function: countprimes(i,j)
// Author: Lucas Nation
// Purpose: count the number of prime numbers in a specific range.
//

int countprimes(int i,int j) {

  int c = 0;

#pragma omp parallel for reduction(+:c)
  for(int k=i; k < j; k++)
  {
    if(IsPrime(k))
      c++;
  }
return c;

}

// Function: findnthprime(start,difference,n)
// Author: Lucas Nation
// Purpose: find the nth prime number

int findnthprime(int startrange, int c, int x) {

for(int i=startrange; i>0; i--) {
  if(IsPrime(i))
    c--;
  else if(c<x)
    return i+1;

}
}

//*************************************************************************
//Function: main()
//Author: David W. Juedes
//Purpose: reads in "n", and outputs the nth prime number.
//Note: By the Rosser's theorem, the nth prime number is less than
// n log n + n log log n + 2n.
// Here, log n is natural log function.
//
//*****************************************************************************
int main() {
  long long n;
  cin >> n;
  long long next_p = 2;
  
  if(n < 55) {
    for (long long j=1;j<n;j++) {
      next_p = NextPrime(next_p);
    }
  }
  else {
    int counter = 0;
    int start = 2;
    int difference;
    while(counter < n) {
      counter = counter + countprimes(start,start+100000);
      start += 100000;
    }
    next_p = findnthprime(start,counter,n);
  }
  cout << "The " << n << "th prime " << " is " << next_p << endl;
  //cout << "Notice that this is less than " << n*(log(n))+n*(log(log(n)))+2*n << endl;


}
