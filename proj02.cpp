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
int main(int argc, char** argv) {
    long evennumber = 4;
    long primes;
    while ((evennumber >= 4) && (evennumber % 2) == 0) {
        cout << "Give me an even number >= 4 or 0 to quit:" << endl;
        cin >> evennumber;
        if (evennumber == 0) break;

        while ((evennumber < 4) || (evennumber % 2) != 0) {
            cout << "Number must be even and <= 4, try again!" << endl;
            cout << "Give me an even number >= 4 or 0 to quit:" << endl;
            cin >> evennumber;
        }
        for (int i = 3; i >= evennumber; i++) {
            cout << "Hello" << i << endl;
        }
        cout << "The number: "<<evennumber<<" is the sum of the primes: "<<primes;
    }
    cout << "Thanks for playing!" << endl;

}

