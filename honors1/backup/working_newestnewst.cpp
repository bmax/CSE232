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
 * Function roll dice accepts vector<long> and a random engine generator
 * returns a random number 1-6;
 * .
 */
long roll_dice(default_random_engine &dre) {
  vector<long> die = {1,2,3,4,5,6};
  uniform_int_distribution<long> dist(0,die.size()-1);
  return die.at(dist(dre));
}
void roll(pair<long, long> &hand, default_random_engine &dre) {
  hand.first = roll_dice(dre);
  hand.second= roll_dice(dre);
}
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
void add_wins(long &whowon, pair<long,long> &wins) {
  if (whowon == 1) 
    wins.first++;
  else if (whowon == 2)
    wins.second++;
  else {
    wins.second++;wins.first++;
  }
}
string do_games( int player_one_hold_value, int &hold_value, default_random_engine &eng, long &num_games, long &total_games, pair<long,long> &wins) {
  stringstream ios;
  long ones=0,doubleones=0;
  for (long start_games=0; start_games<num_games;start_games++) {
    long whowon = versus(player_one_hold_value,hold_value, eng,ones,doubleones);
    add_wins(whowon, wins);
    total_games++;
  }

  ios <<"t\t"<<player_one_hold_value <<"\t\t\t\t\tvs\t\t\t\t"<<hold_value;
  float perc = (static_cast<float>(wins.first) /num_games)*100;
  ios <<"\t\t\t\t\t\t"<<wins.first << "\t\t\t\t" << wins.second << "\t\t\t\t\t\t\t\t" <<perc<<"%"<<"\t\t\t\t\t\t\t\t\t\t"<<ones<<"\t\t\t\t\t"<<doubleones<<endl;
  return ios.str(); 
}
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
  output << "Number of games per hold value: "<<num_games<<endl;
  output << "P1 Hold Value\t\tvs\t\tP2 Hold Value\t\tP1 Wins\t\tP2 wins\t\tP1 winning chance(percent)\t\t# of 1's\t\t# of double 1's\n";
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
    output << "----"<<endl;
  }
  output << "Total num of games played: " << total_games;
  output.close();
}
