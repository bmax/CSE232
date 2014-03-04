/* 
 * Project 5
 * Brandon Max
 * netid - maxbrand
 * Section 002
 *
 * A madlib program that takes an story file, verb file, noun file, and output file to create the story .
 * takes random verbs and nouns and fills it in to the story file.
 *
 * Created on February 20, 2014, 5:24 PM
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ifstream;
using std::ofstream;
using std::istringstream;
/*
 * Function accepts a string and a reference to a vector
 * splits string by white space delimiter and puts it into vector
 * returns void 
 */
void split(string text, vector<string> &v) {
  istringstream iss(text);
  string sub;
  while (iss >> sub) {
    v.push_back(sub);
  }
}
/*
 * Function accepts a string which is a filename
 * opens filename and splits up by new lines into vector
 * returns vector
 */
vector<string> load_word_file(string filename) {
  string line;
  vector<string> t;
  ifstream wordfile(filename);
  while (getline(wordfile,line,'\n')) {
    split(line,t);
  }
  return t;
}
/*
 * Function accepts a string which is a filename specifically for in_file
 * opens filename and splits up by new lines into vector and keeps original formatting
 * returns vector
 */
vector<string> load_in_file(string filename) { 
	 ifstream tmpfile(filename);
  string line;
	vector<string> templatefile;
  while (getline(tmpfile,line,'\n')) {
    split(line,templatefile);
    templatefile.push_back("\n");
  }
	return templatefile;
}
/*
 * Function accepts a reference to a vector and a random generate engine 
 * returns a random word from a vector 
 * returns string 
 */
string random_word(vector<string> &v, default_random_engine &dre) {
  uniform_int_distribution<long> dist(0,v.size()-1);
  return v.at(dist(dre));
}
/*
 * Function accepts four string, one int
 * main function that loads noun, verb, in_file and chooses random words and inserts them into out_file
 * seed is used for random engine generator
 * returns void 
 */
void process_document(string noun_file, string verb_file, string in_file, string out_file, int seed = 98765) {
  vector<string> nouns = load_word_file(noun_file);
  vector<string> verbs = load_word_file(verb_file);
  vector<string> templatefile = load_in_file(in_file); 
  default_random_engine engine(seed);
  for ( auto &ele : templatefile) {
    string rand_noun = random_word(nouns,engine); 
    string rand_verb = random_word(verbs,engine); 
    if (ele == "<noun>") ele = rand_noun;
    else if (ele == "<verb>") ele = rand_verb;
  }
  ofstream output(out_file);
  for (auto ele : templatefile) {
    if (ele != "\n") ele+=" ";
    output << ele;

  }
}

