/* 
 * Project 4
 * Brandon Max
 * netid - maxbrand
 * Section 002
 *
 * Prints out all lychrel numbers within a given range and limit.
 * 

 * Created on February 12, 2014, 5:24 PM
 */
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::cin;
using std::string;

/*
 * Function accepts a long;
 * revereses the order of the long and returns that number.
 */
long rev_num(long n) {
    long reversenum;
    //    for (reversenum=0; n; n/=10) 
    //       reversenum = reversenum*10 + n%10;
    string snum = std::to_string(n);
   // snum = std::reverse(snum.begin(), snum.end());
    cout << snum;
    return reversenum;
}
/*
 * Function accepts a long;
 * Checks if number is a palindrome; returns true if it is or false if it is not.
 */
bool is_palindrome(long n) {
    return (rev_num(n) == n);
}
/*
 * Function accepts two longs; the first and second inputs from user;
 * if first is greater than second than two numbers should be swapped
 */
void order_parameters(long &first, long &second) {
    long swap;
    if (first > second) {
        swap = first;
        first = second;
        second = swap;
    }
}
int main() {
    rev_num(123);
    long test = 197;
    long test1 = 195;
    order_parameters(test, test1);
    cout << test << " " << test1;
}
