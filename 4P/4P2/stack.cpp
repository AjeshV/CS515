/** CS515 Assignment 4
 * File: stack.cpp
 * Name: Ajesh Vijay Vijayaragavan
 * Section: 01
 * Date: 10/05/2017
 * Collaboration Declaration:  */
#include <iostream>
#include "stack.h"
using namespace std;
//constructor with default capacity value
stack::stack(int size)
{
  if (size != 0)
  {
   _capacity = size;
   _arr = new TYPE[_capacity];
  }
  else if (size == 0)
  {
   _capacity = INITCAP;
   _arr = new TYPE[_capacity];
  }
}
//copy constructor
stack::stack(const stack& s)
{	
  //values = new double[size];
  _arr = new TYPE[_capacity];
  for (int i=0;i<=(_capacity-1);i++)
  {
	  //values[i]
	  _arr[i]=s._arr[i];
  }
}
//assignment operator
//From Classes 2 : Big-5 Implementation slide module
stack& stack::operator=(const stack& s)
{
 if (this == &s)
 {
	return *this;
 }
 delete []_arr;
 //size = s.size();
 _capacity = s._capacity;
 //inUse = s.inUse;
 _tos = s._tos;
 if (_capacity==0)
 {
    //Empty
 }
 else if ((_capacity-1)>=0)
 {
	//values = new double[size];
	_arr = new TYPE[_capacity];
	for (int i=0;i<=(_capacity-1);i++)
	{
		//values[i]=//.values[i];
		_arr[i]=s._arr[i];
	}
	//return *this;
 }
 return *this;
}
//destructor
stack::~stack()
{
     //delete []values;
     delete []_arr;
}
//push an element, expanding if necessary
//void push(const TYPE x)
void stack::push(const TYPE x)
{
 int v=_tos+1;
 if (v<_capacity)
 {
   //stack pointer to element just got pushed into stack
   _arr[v]=x;
 }
 else if(v==_capacity)
 {
	 //double the capacity, create new array with new capacity
	 //and copy elements from old array to new array with higher capacity
	 _capacity=_capacity*2;
	 int* arr2=new TYPE[_capacity];
	 int j=(_capacity/2);
	 int i;
	 for (i=0;i<j;i++)
	 {
		 arr2[i]=_arr[i];
	 }
	 delete []_arr;
         _arr=arr2;
	 _arr[v]=x;

 }
}

//remove an element; throw EmptyStackException when stack is empty
//void pop();
void stack::pop()
{
 int z = _tos;
 if (z == -1)
 {
	throw EmptyStackException();
 }
 else
 {
   int y = _tos-1; 
  _tos=y;
 }
}
// return a reference to the top element without popping; throw EmptyStackException when stack is empty
//TYPE& top()
TYPE& stack::top()
{
 if (_tos < 0)
 {
    throw EmptyStackException();
 }
  return _arr[_tos];
}


// return true if the stack is empty, false otherwise
//bool empty()
bool stack::empty()
{
/*  if ((_tos<=-1) && stack.Empty()) */
  if (_tos<=-1)
  {
	return true;
  }
  else
  {
        return false;
  }
}

// return the number of elements currently on the stack
//int  size()
int stack::size()
{
 //_tos is the current index
 int k = (_tos+1);
 return(k);
}

// return the current capacity of the stack
//int  capacity()
int stack::capacity()
{
	return _capacity;
}

// output stack elements from stack top to stack bottom
// elements are separated with a white space.
//void dump(ostream &os);
void stack::dump(ostream &os)
{
  int j=_tos;
  for (int i=j;i>-1;i--)
  {
   os << _arr[i] << " ";
  }
  os << endl;
}
/*
    TYPE * _arr;     // pointer to dynamic integer array
    int _tos;       // index to top of stack
    int _capacity;  // current capacity

*/


