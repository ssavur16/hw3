#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  Heap(int m=2, PComparator c = PComparator());
  ~Heap();
  void push(const T& item);
  T const & top() const;
  void pop();
  bool empty() const;
  size_t size() const;

  std::vector<T> items_;

private:
  /// Add whatever helper functions and data members you need below
  void trickleDown();
  void trickleUp(int loc);
  int m_;
  PComparator c_;
};

// Add implementation of member functions here

/**
  * @brief Construct a new Heap object
  * 
  * @param m ary-ness of heap tree (default to 2)
  * @param c binary predicate function/functor that takes two items
  *          as an argument and returns a bool if the first argument has
  *          priority over the second.
  */
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) :
  m_(m), c_(c)
{
  // default m = 2, which will indicate a binary tree
  // default PComparator = std::less<T>, which will indicate a min-heap
}

/**
  * @brief Destroy the Heap object
  * 
  */
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
  while(!items_.empty()) {
    items_.pop_back();
  }
}

/**
  * @brief Returns true if the heap is empty
  */
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  if(items_.size() == 0) return true;
  else return false;
}

/**
  * @brief Returns size of the heap
  */
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return items_.size();
}

/**
  * @brief Returns the top (priority) item
  * 
  * @return T const& top priority item
  * @throw std::underflow_error if the heap is empty
  */
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::underflow_error("Heap underflow"));
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
/**
  * @brief Remove the top priority item
  * 
  * @throw std::underflow_error if the heap is empty
  */
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::underflow_error("Heap underflow"));
  }

  // swap "best" and "worst" node
  std::swap(items_.front(), items_.back());

  // pop the "best" node, now at the end of items_ vector
  items_.pop_back();

  // trickle down
  trickleDown();
}

// helper function for pop()
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown() 
{
  size_t parent_loc = 0;
  std::vector<size_t> child_indices;
  child_indices.push_back(parent_loc);

  if(items_.size() > 1) {
    while(child_indices[0] < (items_.size() - 1)) { // will stop iterating once p_loc is a leaf node
      child_indices.clear();

      // create a vector that stores all indices whose nodes are potential switches with parent
      for(int i = 1; i <= m_; i++) {
        int child_loc = (m_ * parent_loc) + i;
        if(child_loc < static_cast<int>(items_.size())) {
          if( (!c_(items_[parent_loc], items_[child_loc])) || (items_[parent_loc] == items_[child_loc])) {
            child_indices.push_back(child_loc);
          }
        }
      }

      // if vector is empty, then node is in correct spot and should exit loop
      if(child_indices.empty()) {
        break;
      }

      else if(child_indices.size() == 1) {
        std::swap(items_[parent_loc], items_[child_indices[0]]);
        parent_loc = child_indices[0];
      }

      // if child_indices.size() > 1, then swap parent with child that best fits comparator
      else {
        size_t loc = 0;
        for(size_t j = 0; j < child_indices.size() - 1; j++) {
          if( (!c_(items_[child_indices[loc]], items_[child_indices[j+1]])) && (items_[child_indices[loc]] != items_[child_indices[j+1]]) ) {
            loc = j+1;
          }
        }
        std::swap(items_[parent_loc], items_[child_indices[loc]]);
        parent_loc = child_indices[loc];
      }
    }
  }
}

/**
  * @brief Push an item to the heap
  * 
  * @param item item to heap
  */
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  int loc = size();

  // push item to the "worst" position, or end of the vector
  items_.push_back(item);

  // trickle up
  trickleUp(loc);
}

// helper function for push()
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int loc) 
{
  int parent_loc = (loc - 1) / m_;

  if(items_.size() > 1) {
    while( ( (c_(items_[loc], items_[parent_loc])) || (items_[loc] == items_[parent_loc]) ) && (loc > 0) ) {
      std::swap(items_[loc], items_[parent_loc]);

      // update loc and parent_loc after std::swap()
      loc = parent_loc;
      parent_loc = (loc - 1) / m_;
    }
  }
}

#endif

