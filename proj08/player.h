/* 
 * Project 8
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the player definition file and contains a player struct that holds buy, sell, and to_str 
 *
 */
#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include "market.h"
using std::cout; using std::endl;
#include<map>
#include<vector>
using std::vector;using std::map;
#include<string>
using std::string;

struct Player {
  double cash;
  map<string,long> stocks;
  /* default constructor
   * returns void
   */
  Player() = default;
  /* Player constructor
   * takes double and sets cash value
   */
  Player(double cash) : cash(cash) {};
/*
 * buy function
 * takes Market reference, stock, date, and quantity
 * returns true or false depending if conditions meet to buy 
 */
  bool buy(Market &m, string stock, long date, long quantity);
/*
 * sell function
 * takes Market reference, stock, date, and quantity
 * returns true or false depending if conditions meet to sell 
 */
  bool sell(Market &m, string stock, long date, long quantity);
/*
 * to string function
 * returns string of all Player data members 
 * return string
 */
  string to_str();
};
#endif
