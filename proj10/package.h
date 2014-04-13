/* 
 * Project 10
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the package definition file and contains the package struct 
 *
 */
#ifndef PACKAGE_H
#define PACKAGE_H 

#include <iostream>
using std::ostream;
struct Package {
  /* weight of package */
  long weight_;
  /* priority of package */
  long priority_;
  /* default constructor */
  Package() = default;
  /* constructor function
   * takes in weight, priority
   * sets the variables
   */
  Package(long weight, long priority) : weight_(weight),priority_(priority) {};

};
/* operator for << 
 * prints out weight and priority when trying to cout << package class
 * returns ostream
 */
ostream &operator<<(ostream&, Package p);
/* package_compare function
 * used for sort, compares priority/weight
 * returns bool
 */
bool package_compare(const Package& lhs, const Package& rhs);
#endif
