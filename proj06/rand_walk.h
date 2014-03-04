#ifndef rand_walk
#define rand_walk
#include <iostream>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;
void read_index(map<long, string> &m, string &file_name);
void read_arc(map<long, vector<long>> &m, string &file_name);
long select(default_random_engine &dre, vector<long> &container);
map<string, long> do_walk(map<long, vector<long>> &arc_map, map<long, string> &index_map, long total_walks, long walk_length, default_random_engine &dre);

#endif
