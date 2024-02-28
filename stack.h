#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
  
  private:
    std::vector<T> stack_;
};

// All templated implementations must be in a header file
template<typename T>
Stack<T>::Stack() : std::vector<T>()
{

}

template<typename T>
Stack<T>::~Stack() {
  
}

template<typename T>
size_t Stack<T>::size() const
{
  return stack_.size();
}

template<typename T>
bool Stack<T>::empty() const
{
  return stack_.empty();
}

template<typename T>
void Stack<T>::push(const T& item)
{
  stack_.push_back(item);
}

template<typename T>
void Stack<T>::pop()
{
  if(!empty()) {
    stack_.pop_back();
  }
  else { throw(std::underflow_error("Stack underflow")); }
}

template<typename T>
T const & Stack<T>::top() const
{
  if(!empty()) {
    return stack_[size() - 1];
  }
  else { throw(std::underflow_error("Stack underflow")); }
}

#endif