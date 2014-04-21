/*
 * Project 11
 * Brandon Max
 * netid - maxbrand
 * Section 002
 *
 * This is the singlelinkmap definition file which contains a struct
 for node and a class for the single list
 *
 */
#ifndef SINGLELINKMAP_H
#define SINGLELINKMAP_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<algorithm>
using std::swap;

template <typename Key_Type, typename Value_Type>
/*
 *Node struct which contains an pointer to next node
 *Templated Key_Type Key_
 *Templated Value_Type value_
 *all public
 */
struct Node{
public:
    Node *next_;
    Key_Type key_;
    Value_Type value_;
    
    Node() : key_( Key_Type() ), value_( Value_Type() ), next_(nullptr) {};
    Node(Key_Type k, Value_Type d) : key_(k), value_(d), next_(nullptr) {};
    ostream& print_node(ostream&);
};

// print a node as "Key:Value"
// return the ostream passed in
template<typename Key_Type, typename Value_Type>
ostream& Node<Key_Type,Value_Type>::print_node(ostream& out){
    out << key_<<":"<<value_;
    return out;
}


template <typename Key_Type, typename Value_Type>
/* SingleLinkMap class
 * All templated 
 * private: begin node and last node
 * public functions with constructor, destructor
 copy constructor, append back and print list
 *
 */
class SingleLinkMap{
private:
    Node<Key_Type,Value_Type> *begin_;
    Node<Key_Type,Value_Type> *last_;
    
public:
    SingleLinkMap() : begin_(nullptr), last_(nullptr) {};
    SingleLinkMap(SingleLinkMap &l);
    ~SingleLinkMap();
    SingleLinkMap& operator=(SingleLinkMap l);
    void append_back(const Key_Type &key, const Value_Type &val);
    ostream& print_list(ostream&);
    Value_Type find_then_front(Key_Type);
    Value_Type find_then_swap(Key_Type);
};

// copy constructor
// makes sure not copying itself and appends everything back
template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type,Value_Type>::SingleLinkMap(SingleLinkMap<Key_Type,Value_Type> &l){
    // Fix me
    if (this != &l) {
      begin_=nullptr;
      last_=nullptr;
        for (auto ptr = l.begin_; ptr!=nullptr; ptr = ptr->next_) {
            append_back(ptr->key_,ptr->value_);
        }
    }
}

// destructor
// deletes every node individually
template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type,Value_Type>::~SingleLinkMap(){
    if (begin_ != nullptr) {
        Node<Key_Type,Value_Type> *current = begin_;
        Node<Key_Type,Value_Type> *follow = begin_->next_;
        while (follow != nullptr) {
            delete current;
            current = follow;
            follow = follow->next_;
        }
        delete follow;
        delete current;
    }
}

// = operator
// swap last and begin
// returns SingleLinkMap
template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type,Value_Type>& SingleLinkMap<Key_Type,Value_Type>::operator=(SingleLinkMap<Key_Type,Value_Type> l){
    // Fix me
    swap(last_,l.last_);
    swap(begin_,l.begin_);
    return *this;
    
}

// append_back function
// takes in a key and value, makes a new node in list
// returns void
template<typename Key_Type, typename Value_Type>
void SingleLinkMap<Key_Type,Value_Type>::append_back(const Key_Type &key, const Value_Type &val){
    // Fix me
    Node<Key_Type,Value_Type> *n = new Node<Key_Type,Value_Type>(key,val);
    if (last_ != nullptr){
        last_->next_ = n;
        last_ = n;
    }
    else {
        begin_=n;
        last_=n;
    }
    
}

// print singlelinkmap
// returns ostream
template<typename Key_Type, typename Value_Type>
ostream& SingleLinkMap<Key_Type,Value_Type>::print_list(ostream &out){
    // Fix me
    out << "List: ";
    for (auto ptr = begin_; ptr!=nullptr; ptr = ptr->next_) {
        ptr->print_node(out);
        if (ptr->next_ != nullptr)
            out<<", ";
    }
    return out;
}

// find_then_Front function
// takes key and finds that node and places it in front
// returns value of key found
template<typename Key_Type, typename Value_Type>
Value_Type SingleLinkMap<Key_Type,Value_Type>::find_then_front(Key_Type key){
    Node<Key_Type, Value_Type> *last = begin_;
    Node<Key_Type, Value_Type> *prvlast = nullptr;
    
    while (last != nullptr && last->key_ != key) {
        prvlast = last;
        last = last->next_;
    }
    if (last != nullptr && last != begin_) {
        last = prvlast->next_->next_;
        auto tmp = prvlast->next_;
        prvlast->next_ = last;
        tmp->next_ = begin_;
        begin_ = tmp;
        return begin_->value_;
    }
    return Value_Type();
}

// find_then_swap function
// takes key and finds node and swaps it with node next to it.
// returns value of key found
template<typename Key_Type, typename Value_Type>
Value_Type SingleLinkMap<Key_Type,Value_Type>::find_then_swap(Key_Type key){
    // Fix me
    Node<Key_Type, Value_Type> *last = begin_;
    Node<Key_Type, Value_Type> *current = nullptr;
    Node<Key_Type, Value_Type> *prvprvlast = nullptr;
    
    while (last->next_ != nullptr && last->next_->key_ != key) {
        prvprvlast = last;
        current = last->next_->next_;
        last = last->next_;
    }
    
    if (current != nullptr && current != begin_) {
        auto tmp = current->next_;
        swap(*last,*current);
        
        last->next_ = current->next_;
        current->next_ = tmp;
        return last->value_;
    }
    return Value_Type();
}

#endif
