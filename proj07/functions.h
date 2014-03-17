/* 
 * Project 7
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This project creates a number of functions to completely read and do check on certain files.
 * Created on March 16, 2014, 5:24 PM
 *
 */
#ifndef functions 
#define functions

#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<algorithm>
using std::find; using std::set_intersection; using std::set_difference;
#include<iterator>
using std::ostream_iterator;
using std::find;
/*
 * Function accepts a string 
 * strips and lowercases the string 
 * returns string 
 */
string lower_and_strip(string s);
/*
 * Function accepts a vector of strings and string file_name
 * goes through each word in file and puts it into vector.
 * returns void 
 */
void read_stopwords(vector<string> &v, string file_name);
/*
 * Function accepts a map w/ string key and long values, vector of strings, and string file_name
 * read through a file and if there is a word in the stop_list
 * then don't add it to map. if there isn't a word in stop list, add it to map and update frequency 
 * returns void 
 */
void read_file(map<string, long> &m,
    vector<string> &stop_list,
    string file_name);

/*
 * Function map of string key nad long values, and an order string 
 * goes through a map and sorts it by either alpha or frequency
 * than prints the map.
 * returns string 
 */
string print_map(map<string,long> &m, string order="alpha");

/*
 * Function accepts a map of key string and long value
 * sorts words alphabetically and puts into vector of strings.
 * returns void 
 */
vector<string> sorted_words(map<string, long> &m);
/*
 * Function accepts four iterators and then a destination iterator.
 * goes through first two iterator from begin to end and checks if an
 * value exsists in the second iterators, if it does then outputs it to destination
 * returns void
 */
template<typename Itr1, typename Itr2, typename Out>
void my_set_intersection(Itr1 source1_begin, Itr1 source1_end, Itr2 source2_begin, Itr2 source2_end, Out dest) {
  auto p =find(source1_begin,source1_end,"liberty");
  for (auto it=source1_begin;it!=source1_end;it++) {
    auto p = find(source2_begin,source2_end,*it);
    if (p != source2_end) { 
      *dest = *p;
      p++;
    }
  }
}
/*
 * Function accepts four iterators and then a destination iterator.
 * goes through first two iterator from begin to end and checks if an 
 * value does not exists in the second iterators, if it doesn't then outputs it to destination
 * returns void
 */
template<typename Itr1, typename Itr2, typename Out> void my_set_difference(Itr1 source1_begin, Itr1 source1_end, Itr2 source2_begin, Itr2 source2_end, Out dest) {
  auto p =find(source1_begin,source1_end,"liberty");
  for (auto it=source1_begin;it!=source1_end;it++) {
    auto p = find(source2_begin,source2_end,*it);
    if (p == source2_end) {
      *dest = *it;
      p++;
    }
  }
}
#endif
