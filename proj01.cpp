/* 
 * File:   main.cpp
 * MSU ID: maxbrand
 * Section: 002
 * 
 * Created on January 9, 2014, 4:56 PM
 */

#include <iostream>
#include <cmath>

/*
 * 
 */
int main(int argc, char** argv) {
    double denom, population, debt, dollarHeight = .0043, inchToMile = .0000157828;

    std::cout << "What is the current debt (in dollars):";
    std::cin >> debt;
    std::cout << "What denomination of US currency to use for height calc:";
    std::cin >> denom;
    double dollars = debt/denom;
    std::cout << "What is the current US population:";
    std::cin >> population;
    double miles = dollars * dollarHeight * inchToMile;
    double multiplesToTheMoon = miles / 238857;
    double peoplesDebt = debt / population;
    std::cout << "Miles high of indicated currency: " << round(miles) << std::endl;
    std::cout << "Multiples of distance to the moon:" << round(multiplesToTheMoon) << std::endl;
    std::cout << "What each person owes:" << round(peoplesDebt);
}


