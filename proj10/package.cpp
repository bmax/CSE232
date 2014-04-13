/* 
 * Project 10
 * Brandon Max
 * netid - maxbrand
 * Section 002
 * 
 * This is the package cpp file and contains a the methods for package struct,
 *
 */
#include <iostream>
using std::ostream;
using std::endl;
#include "package.h"
/* operator for << 
 * prints out weight and priority when trying to cout << package class
 * returns ostream
 */
ostream& operator<<(ostream &out, const Package &p) {
  out << "weight: "<<p.weight_<<" priority: "<<p.priority_<<endl;
  return out;
}
/* package_compare function
 * used for sort, compares priority/weight
 * returns bool
 */
bool package_compare(const Package& lhs, const Package &rhs) {
  return (lhs.priority_/lhs.weight_ > rhs.priority_/lhs.weight_);
}
