#include <iostream>
#include <functional>
#include "heap.h"
using namespace std;

int main() {
  // testing binary minHeap<int>
  cout << endl << "ThreeElementPush_0_10_5" << endl;
  Heap<int> int_heap;
	int_heap.push(0);
	int_heap.push(10);
  int_heap.push(5);
  
  cout << "heap.top() = " << int_heap.top() << endl; // should be 0
  int_heap.pop();
  cout << "heap.top() = " << int_heap.top() << endl; // should be 5
  int_heap.pop();
  cout << "heap.top() = " << int_heap.top() << endl; // should be 10
  int_heap.pop();
  cout << endl;

  // testing binary minHeap<int>
  cout << "ThreeElementPush_5_10_0" << endl;
  int_heap.push(5);
  int_heap.push(10);
  int_heap.push(0);
  
  cout << "heap.top() = " << int_heap.top() << endl; // should be 0
  int_heap.pop();
  cout << "heap.top() = " << int_heap.top() << endl; // should be 5
  int_heap.pop();
  cout << "heap.top() = " << int_heap.top() << endl; // should be 10
  int_heap.pop();
  cout << endl;

  // testing binary minHeap<string>
  cout << "HeapTest.StringStorage" << endl;
  Heap<string> string_heap;
  string_heap.push("blah");
  string_heap.push("bluh"); 
  string_heap.push("bloh");
  
  cout << "heap.top() = " << string_heap.top() << endl; // should be "blah"
  string_heap.pop();
  cout << "heap.top() = " << string_heap.top() << endl; // should be "bloh"
  string_heap.pop();
  cout << "heap.top() = " << string_heap.top() << endl; // should be "bluh"
  string_heap.pop();
  cout << endl;

  // testing quarternary minHeap<int>
  cout << "HeapTest.SixElementPush_QuaternaryHeap" << endl;
  Heap<int> quart_heap(4);
  quart_heap.push(0);
  quart_heap.push(5);
  quart_heap.push(10);
  quart_heap.push(15);
  quart_heap.push(20);
  quart_heap.push(25);

  cout << "heap.top() = " << quart_heap.top() << endl; // 0
  quart_heap.pop();
  cout << "heap.top() = " << quart_heap.top() << endl; // 5
  quart_heap.pop();
  cout << "heap.top() = " << quart_heap.top() << endl; // 10
  quart_heap.pop();
  cout << "heap.top() = " << quart_heap.top() << endl; // 15
  quart_heap.pop();
  cout << "heap.top() = " << quart_heap.top() << endl; // 20
  quart_heap.pop();
  cout << "heap.top() = " << quart_heap.top() << endl; // 25
  quart_heap.pop();
  cout << endl;
}