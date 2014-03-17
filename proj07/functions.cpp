/* 
 * Project 7
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 *
 * Created on February 27, 2014, 5:24 PM
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include<cctype> 
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ifstream;
using std::map;
using std::ostringstream;
using std::ostream_iterator;
using std::pair;
using std::sort;
void read_stopwords(vector<string> &v, string file_name) {
  ifstream stopfile(file_name);
  string word;
  while (stopfile >> word) {
    v.push_back(word);
  }
}

string lower_and_strip(string s) {
  string target = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
  string news;
  if (s.find_first_of(target) != string::npos || s.find_last_of(target) != string::npos) {
    s = s.substr(s.find_first_of(target),s.find_last_of(target)-s.find_first_of(target)+1);
    for(int i =0; i<s.size();i++) {
      news+= tolower(s[i]);
    }
  }
  return news;
}
void read_file(map<string, long> &m,
    vector<string> &stop_list,
    string file_name) {
  ifstream wordfile(file_name);
  string word;
  while (wordfile >> word) {
    string strippedword = lower_and_strip(word);
    auto mark = find(stop_list.begin(), stop_list.end(), strippedword);
    if(mark == stop_list.end()) {
      if (strippedword != "") {
        m[strippedword] ++;
      }
    }
  }
}
string p_to_s(pair<string, long>p){
  ostringstream oss;
  oss << p.first <<"-"<<p.second;
  return oss.str();
}
bool sortfreq(pair<string,long> s1, pair<string,long> s2){
  return (s2.second > s1.second);
}
string print_map(map<string,long> &m, string order="alpha") {
  ostringstream oss;
  if (order=="alpha") 
    transform(m.begin(), m.end(), ostream_iterator<string>(oss, "\n"), p_to_s);
  if (order=="count") {
    vector<pair<string,long>> v(m.begin(),m.end()); 
    sort(v.begin(),v.end(),sortfreq);
    transform(v.begin(), v.end(), ostream_iterator<string>(oss, "\n"), p_to_s);
  }
  return oss.str(); 
}
vector<string> sorted_words(map<string,long> &m) {
  vector<string> v;
  for (auto ele:m) 
    v.push_back(ele.first);

  return v;
}

