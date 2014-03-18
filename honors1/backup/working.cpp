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
#include <map>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ifstream;
using std::map;
using std::pair;
using std::istringstream;


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
void take_turn(long hold_value, long &player, default_random_engine &dre) {
  bool turn = true;
  pair<long, long> hand;
  long local_score=0;
  while (turn == true ) {
    roll(hand,dre); 
    if (hand.first == 1 && hand.second == 1) {
      // if double 1's set player_Score to 0 and end turn
      local_score = 0;
      player= 0;
      turn=false;
    } else if (hand.first == 1 || hand.second == 1) {
      // if one die has a one, end turn and set local to 0
      local_score = 0;
      turn = false;
    } else if (hand.first == hand.second) {
      // if double besides 1 then make while for them to roll again
      cout << "You got a double "<<hand.first<<" & "<<hand.second<<" - Going again "<<endl;
      local_score += hand.first+hand.second;
    } else if (hand.first != 1 || hand.second != 1) {
      // add both to local score if not 1's
      local_score += hand.first+hand.second;
    }
    cout << "You rolled a "<<hand.first<< " & " << hand.second<<endl;
    if (turn != false) {
      int result;
      //player+= local_score;
     // local_score=0;
      cout << "Local score: "<<local_score<<endl;
      if (local_score >= hold_value) {
        turn=false;
        player+=local_score;
      }
    } else {
    player+=local_score;
    }
  }
  cout << "Ending turn; player score = "<<player<<endl;
}
int versus(long &player_one, int hold_value_one, long &player_two, int hold_value_two, default_random_engine &dre) {
  int r = 0;
  // player one
  while (player_one < hold_value_one && player_two < hold_value_two) {
  cout << "Player one turn:"<<endl;
  take_turn(hold_value_one,player_one,dre);
  // player two 
  cout << "Player two turn:"<<endl;
  take_turn(hold_value_two,player_two,dre);
  }
  if (player_two < player_one)  
    r= 1;
  else
    r = 2;
  /*cout << "Final scores for versus: "<<endl;
  cout << "--------------------"<<endl;
  cout << "Player one: "<<player_one<<endl;
  cout << "Player two: "<<player_two<<endl;
  cout << "--------------------"<<endl;
  */player_one=0;player_two=0;
  return r;
}
void add_wins(int &whowon, pair<long,long> &wins) {
  if (whowon == 1) 
    wins.first++;
  else if (whowon == 2)
    wins.second++;
  else {
    wins.second++;wins.first++;
  }
}
int main() {
  string output_file;
  long rand_seed,num_games;
  // first will be local_score, second will be player_score
  long player_one;
  long player_two;

  /*cout << "Please give me a random seed to use: ";
    cin >> rand_seed;
  //  cout << "Please give me output file:";
  // cin >> output_file;
  cout << "How many games to play per head to head round: ";
  cin >> num_games;
  */
  rand_seed=123;
  num_games=1000;
  default_random_engine eng(rand_seed);
  cout << "Player one starts"<<endl;
  //playero one and player two;
  long total_games=0;
  for (int ii = 0; ii<=5;ii++) {
    for (int hold_value = 10; hold_value<=30;hold_value+=5) {
      if (ii ==1) {
  pair<long,long> wins;
        if (hold_value!=10) { 
          for (int start_games=0; start_games<num_games;start_games++) {
            cout <<" 10 vs "<< hold_value << endl;
            int whowon = versus(player_one, 10, player_two, hold_value, eng);
            add_wins(whowon, wins);
            cout << "Player one won " << wins.first << " & Player two won " << wins.second << endl;
            total_games++;
          }
        }
      }/*
          if (ii ==2) {
          if (hold_value!=15) { 
          for (int start_games=0; start_games<num_games;start_games++) {
          cout <<" 15 vs "<< hold_value << endl;
          total_games++;
          }
          }
          }
          if (ii == 3) {
          if (hold_value!=20) {
          for (int start_games=0; start_games<num_games;start_games++) {
          cout <<" 20 vs "<< hold_value << endl;
          total_games++;
          }
          }
          }
          if (ii == 4) {
          if (hold_value!=25) { 
          for (int start_games=0; start_games<num_games;start_games++) {
          cout <<" 25 vs "<< hold_value << endl;
          total_games++;
          }
          }
          }
          if (ii == 5) {
          if (hold_value!=30) { 
          for (int start_games=0; start_games<num_games;start_games++) {
          cout <<" 30 vs "<< hold_value << endl;
          total_games++;
          }
          }
          }*/
    }
  }
  cout << "Total num of games played: " << total_games;
}
