#ifndef rand_walk
#define rand_walk
#include <iostream>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;
/*
 * Function accepts a reference to a map with key long and value string and a reference to a filename
 * splits file text for an id and a website url and inserts it into map 
 * returns void 
 */
void read_index(map<long, string> &m, string &file_name);
/*
 * Function accepts a reference to a map with key long and value vector<long> and a reference to a filename
 * splits file text for an id of arc begin and id arc end
 * returns void 
 */
void read_arc(map<long, vector<long>> &m, string &file_name);
/*
 * Function accepts a random engine and a vector 
 * returns a random value from a vector long 
 * returns long 
 */
long select(default_random_engine &dre, vector<long> &container);
map<string, long> do_walk(map<long, vector<long>> &arc_map, map<long, string> &index_map, long total_walks, long walk_length, default_random_engine &dre);

#endif
