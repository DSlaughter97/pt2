//*********************************************************************
// File:big_primes.cc
// Author: David W. Juedes
// Date: January 19, 2017
// Purpose: Reads as input a number n (from the standard input) and outputs
// the nth prime number.
//*************************************************************************
#include <iostream>
#include <cmath>
using namespace std;

//*************************************************************
//Function: IsPrime
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

//*************************************************************************
//Function: main()
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
  for (long long j=1;j<n;j++) {
    next_p = NextPrime(next_p);
  }

  cout << "The " << n << "th prime " << " is " << next_p << endl;
  // cout << "Notice that this is less than " << n*(log(n))+n*(log(log(n)))+2*n << endl;
}
