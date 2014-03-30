/* 
 * Project 8
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the market file and contains market methods stocks, symbols and get_price
 *
 */
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include "market.h"
using std::string;
using std::istringstream;
using std::ifstream;
using std::getline;
using std::vector;
using std::find;
using std::toupper;
/*
 * constructor function
 * takes stock file and reads through it and puts it into stocks map
 * returns void 
 */
Market::Market(string filename) { 
	 ifstream dow(filename);
	 string line,stockdata;
	 long date;
	 double stocknums;
	 while (getline(dow,line, '\n')) {
			vector<double> d;
			istringstream oss(line);
			oss >> date;
			while (oss >> stocknums) {
				 d.push_back(stocknums);
			}
			stocks[date] = d; 
	 }
}
/*
 * get price function
 * takes stock and date and returns price if exsists.
 * returns double
 */
double Market::get_price(string stock, long date) {
	 string stockupper;
	 // uppercase the stock
	 for (string::size_type i=0; i<stock.length(); ++i)
			stockupper += toupper(stock[i]);
	 // find if there is a stock in symbols;
	 auto where = find(symbols.begin(),symbols.end(),stockupper); 
	 if (where != symbols.end()) {
			int location = where-symbols.begin();
			auto stockmap = stocks.find(date);
			if (stockmap != stocks.end()) { 
				 return stockmap->second.at(location);
			}
	 }
	 return -1.0;
}
