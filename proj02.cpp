/* 
 * Project 2
 * Brandon Max
 * netid - maxbrand
 * Section 002
 *
 * Small program to output prime numbers that add up to the even, greater than 2,
 * integer that is inputted.
 * 
 * Created on January 23, 2014, 6:15 PM
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

/*
 * 
 */
long checkPrime(long numToCheck) {
	 bool prime=true;
	 for (long ii = 2; ii < numToCheck; ii++) {
			if (numToCheck%ii == 0) {
				 ii++;
				 prime=false;
				 break;
			}

	 }
	 return prime;
}				
int main() {
	 long evennumber;
	 long prime1, prime2;
	 cout << "Give me an even number >= 4 or 0 to quit:";
	 cin >> evennumber;
	 while (evennumber != 0) {
			if (evennumber >= 4 && evennumber % 2 == 0) {
				 for (long i = 2; i <= evennumber; i++) {
						bool prime = checkPrime(i);
						if (prime == true){ 
							 long difference = evennumber - i;
							 bool prime2 = checkPrime(difference);
							 if (prime2 == true && difference != 1) {
									cout << "The number: " << evennumber << " is the sum of the primes: " << difference << "," << i << endl;
									break;
							 }
						}
				 }
			} else {
				 cout << "Number must be even and >= 4, try again!"<<endl;
			}
			cout << "Give me an even number >= 4 or 0 to quit:";
			cin >> evennumber;
	 }
}

