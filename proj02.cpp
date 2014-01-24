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
int main() {
	 long evennumber;
	 long primes;
	 cout << "Give me an even number >= 4 or 0 to quit:";
	 cin >> evennumber;
	 while (evennumber != 0) {
			if (evennumber >= 4 && evennumber % 2 == 0) {
				 for (int i = 2; i <= evennumber; i++) {
						bool prime=true;
						for (int ii = 2; ii < i; ii++) {
							 if (i%ii == 0) {
									cout << i << " off the table " << endl; 
									break;
							 prime=false;
							 }
							 cout << i << "%" << ii << " " <<i%ii << endl;

						}
				 }
			} else {
				 cout << "Number must be even and >= 4, try again!"<<endl;
			}
			cout << "Give me an even number >= 4 or 0 to quit:";
			cin >> evennumber;
	 }
}

