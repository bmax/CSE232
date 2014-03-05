/* 
 * Project 6
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * This program is made to similuate "walks" through nodes.
 *
 * Created on February 27, 2014, 5:24 PM
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ifstream;
using std::map;
using std::istringstream;

/*
 * Function accepts a reference to a map with key long and value string and a reference to a filename
 * splits file text for an id and a website url and inserts it into map 
 * returns void 
 */
void read_index(map<long, string> &m, string &file_name) {
  ifstream node_file(file_name);
  string line, name;
  long id;
  while (node_file >> name >> id) {
    m[id] = name;
  }
}
/*
 * Function accepts a reference to a map with key long and value vector<long> and a reference to a filename
 * splits file text for an id of arc begin and id arc end
 * returns void 
 */
void read_arc(map<long, vector<long>> &m, string &file_name) {
  ifstream arc_file(file_name);
  long idbegin, idend;
  vector<long> v;
  while (arc_file>>idbegin>>idend) {
    auto &addto = m[idbegin];
    addto.push_back(idend);
  }
}

/*
 * Function accepts a random engine and a vector 
 * returns a random value from a vector long 
 * returns long 
 */
long select(default_random_engine &dre, vector<long> &container) {
  uniform_int_distribution<long> dist(0,container.size()-1);
  return container.at(dist(dre));
}
/*
 * Function accepts a map with a key of long, and any type value 
 * returns a vector<long> of keys, so you can use select to get random value
 * returns vector<long> 
 */
template <typename T> vector<long> get_ids(map<long, T> &randmap) {
  vector<long> nodekeys;
  for (auto itr=randmap.begin(); itr!=randmap.end();itr++) {
    nodekeys.push_back(itr->first);

  }
  return nodekeys;
}
/*

 * Function accepts map of a long and vector, map of a long and string, total walks, walk length and a random engine generator 
 * returns a visit count map with key website name and value visit_count 
 * returns map of string and long 
 */
map<string, long> do_walk(map<long, vector<long>> &arc_map, map<long,string> &index_map, long total_walks, long walk_length, default_random_engine &dre) {
  map<string, long> visit_count;
  for (int i = 0;i<total_walks;i++) {
    bool done = false;
    vector<long> nodekeys = get_ids(index_map); 
    long firstid = select(dre,nodekeys);
    long tmp_walk_length = walk_length;
    while (tmp_walk_length > 0) {
      visit_count[index_map[firstid]]++;
      if (arc_map.find(firstid) != arc_map.end()) 
        firstid =select(dre,arc_map[firstid]) ;
      else  
        tmp_walk_length=0;
      tmp_walk_length--;
    }
  }

  return visit_count;
}
