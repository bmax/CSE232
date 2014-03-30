/* 
 * Project 8
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the player file and contains mmethods that holds buy, sell, and to_str 
 *
 */
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<map>
#include "player.h"
using std::string;
using std::ostringstream;
using std::ifstream;
using std::getline;
using std::vector;
using std::find;
using std::toupper;

/*
 * buy function
 * takes Market reference, stock, date, and quantity
 * returns true or false depending if conditions meet to buy 
 */
bool Player::buy(Market &m, string stock, long date, long quantity) {
  bool result=true;
  double stockprice = m.get_price(stock,date)*quantity;
  if (stockprice > 0 && stockprice <= cash) {
    stocks[stock]+=quantity;
    cash -= stockprice;
  }
  else 
    result=false;
  return result;
}
/*
 * sell function
 * takes Market reference, stock, date, and quantity
 * returns true or false depending if conditions meet to sell 
 */
bool Player::sell(Market &m, string stock, long date, long quantity) {
  bool result = true;
  double stockprice = m.get_price(stock,date)*quantity;
  auto mark = stocks.find(stock); 
  if (mark != stocks.end()) {
    if (stocks[stock] >= quantity && stockprice > 0) {
      cash +=stockprice;
      stocks[stock]-=quantity;
    }
    else 
      result=false;
  } else 
    result=false;
  return result;
}
/*
 * to string function
 * returns string of all Player data members 
 * return string
 */
string Player::to_str() {
  ostringstream result;
  result << "Player has: "<<cash<<" dollars, Stocks are:\n";
  for (auto ele : stocks) {
    result << ele.first<<", quantity "<<ele.second<<"\n";
  }
  return result.str();
}
