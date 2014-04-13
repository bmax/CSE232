/* 
 * Project 8
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the market definition file and contains a market struct that holds stocks, symbols and get_price
 *
 */
#ifndef MARKET_H
#define MARKET_H
#include<iostream>
using std::cout; using std::endl;
#include<map>
#include<vector>
using std::vector;using std::map;
#include<string>
using std::string;

struct Market {
  map<long,vector<double>> stocks;
  vector<string> symbols = {"AA","AXP","BA","BAC","CAT","CSCO","CVX","DD","DIS","GE","HD","HPQ","IBM","INTC","JNJ","JPM","KFT","KO","MCD","MMM","MRK","MSFT","PFE","PG","T","TRV","UTX","VZ","WMT","XOM"};
  /*
   * constructor function
   * returns void 
   */
  Market() = default;
  /*
   * constructor function
   * takes stock file and reads through it and puts it into stocks map
   * returns void 
   */
  Market(string filename) ;
  /*
   * get price function
   * takes stock and date and returns price if exsists.
   * returns double
   */
  double get_price(string stock, long date);

};
#endif
