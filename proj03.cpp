/* 
 * Project 3
 * Brandon Max
 * netid - maxbrand
 * Section 002
 *
 * Small program to output prime numbers that add up to the even, greater than 2,
 * integer that is inputted.
 * 

 * Created on January 28, 2014, 5:24 PM
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
 * Function accepts two longs; first and second
 * Function sorts the input received from IO
 * outputs nothing
 */
void order_parameters(long &first, long &second) {
    if (first > second) {
        long temp = first;
        first = second;
        second = temp;
    }
}

/*
 * Function accepts two longs; number and power
 * Returns true only if num is an narcissistic number of order power. 
 * outputs true/false
 * 
 * 
 */
bool narc_num(long num, long power) {

}

/*
 * Function accepts there longs; first,last, and power.
 * First - first number in range of numbers to be checked
 * Last - last number in range to be checked (inclusive)
 * power, the power (order)  of the narcissistic number.
 * outputs an  integer
 */
int check_range(long first, long last, long power) {
    order_parameters(first, last);
    for (int i = first; i <= last; i++) {
        narc_num(i, power);
    }
    return 2;
}

/*
 * Main Function
 */
int main() {
    long first, last, power;
    cout << "give space seperated start stop power:";
    cin >> first >> last >> power;
    while (first > 0 && last > 0 && power > 0) {
        check_range(first, last, power);
        cout << "give space seperated start stop power:";
        cin >> first >> last >> power;
    }
    cout << "Thanks for playing" << endl;
}


