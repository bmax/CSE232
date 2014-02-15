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
    string snum = std::to_string(n);
    std::reverse(snum.begin(),snum.end());
    reversenum = std::stol(snum);
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
 * Function accepts two longs; the first and second inputs from user
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
/*
 * Function accepts two longs; the first is input number and limit from user
 * returns true if number exceeds limit (is lychrel), false otherwise
 */
bool check_lychrel (unsigned long n, long limit) {
    for(int i =0; i < limit; i++) {
        //        cout << "try #" << i << " and n = " << n << " " << is_palindrome(n) << endl;
        if (is_palindrome(n)) return false;
        n += rev_num(n);
    }
    return true;
}
/*
 * Function accepts 5 longs; the first is input number and limit from user
 * Prints any Lychrel numbers found in range and returns number of lychrels 
 */
long check_range (long start, long end, long limit, long &natural_cnt, long &pal_cnt) {
    long lychrel_cnt=0;
    order_parameters(start,end);
    while (start <= end) {
        if (is_palindrome(start)) {
            natural_cnt++;
        } else if (check_lychrel(start,limit)) {
            lychrel_cnt++;
            cout << "Found a lychrel number: " << start << endl;
        } else{
            pal_cnt++;
        }
        start++;
    }
    return lychrel_cnt;
}
int main() {
    long natural_cnt=0, pal_cnt=0, start, end, limit;
    cout << "Provide first, last and limit (all greater than one):";
    cin >>start >> end >> limit;
    while (start < 0 || end < 0 || limit < 0) {
        cout << "Try again, provide first, last and limit (all greater than one):";
        cin >>start >> end >> limit;

    }
    long lychrel_cnt = check_range(start,end,limit,natural_cnt,pal_cnt);

    cout << "Summary for range " << start << ", "
        << end<< " with limit: "<<limit<<endl;
    cout << "Lychrel count: " <<lychrel_cnt << ", Natural count: "
        <<natural_cnt<<", Palindrome count:" << pal_cnt << endl;
}
