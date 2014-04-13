/* 
 * Project 10
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the knapsack definition file and contains a knapsack class holds data, weight limit, capacity,
 * and size
 *
 */
#ifndef KNAPSACK_H
#define KNAPSACK_H
#include "package.h"
class Knapsack {
  private: 
    /* data_ holds an array of Packages */
    Package* data_;
    /* weight limit of knapsack */
    long weight_limit_;
    /* maximum size for data array */
    long capacity_;
    /* current size for data array */
    long size_;
  public:
    /*
     * constructor function
     * sets weight limit,capacity, and allocates memory
     */
    Knapsack(long max);
    /*
     * add function
     * adds package to data array and extends capacity if need be
     * returns true or false whether it was succesfully added
     *
     */
    /* deconstructor function
     * deletes data array
     */
    ~Knapsack();
    bool add(Package p);
    /*
     * empty function
     * returns true or false based on if data is empty
     */
    bool empty();
    /*
     * weight function
     * returns combined weight of all packages
     */
    long weight();
    /*
     * priority function
     * returns combined priority of all packages
     */
    long priority();
    /*
     * friend operator for <<
     * returns ostream, basically outputs all content in knapsack
     */
    friend ostream& operator<<(ostream &out, const Knapsack &ks);
    /*
     * friend operator for solve_KS Algorithm 
     * takes a vector of packages, sorts them and inserts as many as possible into data_
     * returns void
     */
    friend void solve_KS(vector<Package>& vp, Knapsack& k);
};
#endif
