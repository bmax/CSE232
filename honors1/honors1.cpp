/* 
 * Honors Project 
 * Brandon Max
 * netid - maxbrand
 * Section 002
 *
 * simulate game PIG and keep stats.
 * 
 * Created on February 12, 2014, 5:24 PM
 */
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
using std::cout;
using std::cin;
using std::setw;
using std::endl;
using std::string;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::map;
using std::pair;
using std::stringstream;
using std::ofstream;

/*
 * Function roll dice accepts a random engine generator
 * returns a long, random number 1-6;
 */
long roll_dice(default_random_engine &dre) {
  vector<long> die = {1,2,3,4,5,6};
  uniform_int_distribution<long> dist(0,die.size()-1);
  return die.at(dist(dre));
}
/*
 * Function roll two dice accepts pair of two longs and a random engine generator
 * sets hand pair to roll_Dice
 * returns void
 */
void roll(pair<long, long> &hand, default_random_engine &dre) {
  hand.first = roll_dice(dre);
  hand.second= roll_dice(dre);
}
/*
 * Function accepts a hold_value, player that is total score, random engine, and two longs to keep track of 1's and double 1's
 * does all the necessary components and checks of playing the "game"
 * returns void
 */
void take_turn(long hold_value, long &player, default_random_engine &dre, long &ones, long &doubleones) {
  bool turn = true;
  pair<long, long> hand;
  int local_score=0;
  while (turn == true ) {
    roll(hand,dre); 
    if (hand.first == 1 && hand.second == 1) {
      // if double 1's set player_Score to 0 and end turn
      local_score = 0;
      doubleones++;
      player= 0;
      turn=false;
    } else if (hand.first == 1 || hand.second == 1) {
      // if one die has a one, end turn and set local to 0
      ones++;
      local_score = 0;
      turn = false;
    } else if (hand.first == hand.second) {
      // if double besides 1 then make while for them to roll again and note it
      local_score += hand.first+hand.second;
    } else if (hand.first != 1 || hand.second != 1) {
      // add both to local score if not 1's
      local_score += hand.first+hand.second;
    }
    if (turn != false) {
      int result;
      if (local_score >= hold_value) {
        turn=false;
        player+=local_score;
      }
    } else {
      player+=local_score;
    }
  }
}
/*
 * Function accepts two hold values, one for each player, random engine, and two longs ot keep track of ones  
 * Calls take_turn as many times as necessary for two players to verse.
 * Returns an int based on who won.
 */
int versus( int hold_value_one, int hold_value_two, default_random_engine &dre,long &ones, long &doubleones) {
  int r = 0;
  long player_one=0;
  long player_two=0;
  // player one
  while (player_one < 100 && player_two < 100) {
    take_turn(hold_value_one,player_one,dre,ones,doubleones);
    // player two 
    if (player_one < 100) 
      take_turn(hold_value_two,player_two,dre,ones,doubleones);
  }
  if (player_one >= 100 && player_two >= 100)
    r=1;
  else if (player_one >= 100)  
    r= 1;
  else if (player_two >= 100)
    r = 2;
  player_one=0;player_two=0;
  return r;
}
/*
 * Function accepts long and a pair of longs
 * Adds up how many times a player won.
 * Returns void
 */
void add_wins(long &whowon, pair<long,long> &wins) {
  if (whowon == 1) 
    wins.first++;
  else if (whowon == 2)
    wins.second++;
  else {
    wins.second++;wins.first++;
  }
}
/*
 * Function accepts two hold values, a random engine generator, num of games, total games, and wins
 * Does for loop to run so many games add's wins up, tallys total games, and also does formatting
 * Returns string for formatting 
 */
string do_games( int player_one_hold_value, int &hold_value, default_random_engine &eng, long &num_games, long &total_games, pair<long,long> &wins) {
  stringstream ios;
  long ones=0,doubleones=0;
  for (long start_games=0; start_games<num_games;start_games++) {
    long whowon = versus(player_one_hold_value,hold_value, eng,ones,doubleones);
    add_wins(whowon, wins);
    total_games++;
  }

  ios <<player_one_hold_value <<"\t\t\t\t\tvs\t\t\t\t"<<hold_value<<endl;
  ios << "--------------------------"<<endl;
  float perc = (static_cast<float>(wins.first) /num_games)*100;
  ios <<"P1 wins: "<<setw(17)<<wins.first << endl << "P2 wins: "<<setw(17)<< wins.second <<endl<< "P1 % Of Winning: "<<setw(8)<<perc<<"%"<<endl<<"1's Rolled: "<<setw(14)<<ones<<endl<<"Double 1's Rolled: "<<setw(7)<<doubleones<<endl;
  ios << "--------------------------"<<endl;
  return ios.str(); 
}
/**
 *
 * Maybe not usually make a function comment for int main() but this does some important stuff more than just asking for random seed
 * 
 * runs the 10 vs X code, to make sure it goes through everyone
 * and outputs information to output file
 * 
 */
int main() {
  string output_file;
  long rand_seed,num_games;

  cout << "Please give me a random seed to use: ";
  cin >> rand_seed;
  cout << "Please give me output file:";
  cin >> output_file;
  cout << "How many games to play per head to head round: ";
  cin >> num_games;
  default_random_engine eng(rand_seed);
  ofstream output(output_file);
  //playero one and player two;
  long total_games=0;
  output << "Total games played: "<<num_games*20<<endl;
  output << "Number of games per hold value: "<<num_games<<endl;
  for (int ii = 1; ii<=5;ii++) {
    for (int hold_value = 10; hold_value<=30;hold_value+=5) {
      if (ii ==1) {
        pair<long,long> wins;
        if (hold_value!=10) { 
          output << do_games(10,hold_value,eng,num_games,total_games, wins);

        }
      }
      else if (ii ==2) {
        pair<long,long> wins;
        if (hold_value!=15) { 
          output << do_games(15,hold_value,eng,num_games,total_games, wins);
        } 

      }
      else if (ii == 3) {
        pair<long,long> wins;
        if (hold_value!=20) {
          output<<  do_games(20,hold_value,eng,num_games,total_games, wins);
        }

      }
      else if (ii == 4) {
        pair<long,long> wins;
        if (hold_value!=25) { 
          output << do_games(25,hold_value,eng,num_games,total_games, wins);
        } 
      }
      else if (ii == 5) {
        pair<long,long> wins;
        if (hold_value!=30) { 
          output<<do_games(30,hold_value,eng,num_games,total_games, wins);
        }
      }
    }
  }
  output.close();
}
