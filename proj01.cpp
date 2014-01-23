/* 
 * Project 1 - Asks for three inputs and outputs some calculations.
 * Name: Brandon Max
 * MSU ID: maxbrand
 * Section: 002
 * 
 * 
 * Created on January 9, 2014, 4:56 PM
 */

#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
/*
 * 
 */
int main(int argc, char** argv) {
    double debt, dollarHeight = .0043, inchToMile = .0000157828;
		int denom;
		long population;
    cout << "What is the current debt (in dollars):";
    cin >> debt;
    cout << "What denomination of US currency to use for height calc:";
    cin >> denom;
    double dollars = debt/denom;
    cout << "What is the current US population:";
    cin >> population;
    double miles = dollars * dollarHeight * inchToMile;
    double multiplesToTheMoon = miles / 238857;
    double peoplesDebt = debt / population;
    cout << "Miles high of indicated currency: " << round(miles) << endl;
    cout << "Multiples of distance to the moon:" << round(multiplesToTheMoon) << endl;
    cout << "What each person owes:" << round(peoplesDebt);
}


