/* 
 * Project 5
 * Brandon Max
 * netid - maxbrand
 * Section 002
 *
 * Definitions of all functions that will be used.
 * 
 *
 * Created on February 20, 2014, 5:24 PM
 *
 */
#ifndef madlib   
#define mablib

#include <iostream>
#include <vector>
#include <string>
#include <random>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::default_random_engine;
/* function header for load_word_file accepts a string */
vector<string> load_word_file(string filename);
/* function header for random_word accepts a reference vector, reference random generator */
string random_word(vector<string>&, default_random_engine&);
/* function header for split accepts a string and reference vector */
void split(string, vector<string>&);
/* function header for process_documt accepts four strings for file names and one int seed */
void process_document(string noun_file, string verb_file, string in_file, string out_file, int seed = 98765);
#endif
