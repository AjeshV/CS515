/*
CS515 Lab 3L
File: stack.cpp
Name: Ajesh Vijay Vijayaragavan
section: 02
Date: 02/20/2017
Collaboration: CS515 modules, online theory
*/


#include <iostream>
#include "stack.h"
using namespace std;

int _tos = 15;

//constructor with default capacity value
stack::stack(int x)
{
_tos = 0;
_capacity=x;
_arr = new TYPE[_capacity];
}

// copy constructor
stack::stack(const stack&a)
{
_tos=a._tos;
_capacity=a._capacity;
_arr = new TYPE[_capacity];

for (int i = 0; i < _capacity; i++)
{
_arr[i]=a._arr[i];
}
}

// assignment operator
stack&stack::operator=(const stack&a)
{
if (this == &a)
return *this;
delete []_arr;
_tos = a._tos;
_capacity = a._capacity;
if (_capacity > 0)
{
_arr = new TYPE[_capacity];

for (int i = 0; i < _capacity; i++)
{
_arr[i] = a._arr[i];
}
return *this;
}
}

stack::~stack()
{
delete []_arr;
}

void stack::push(const TYPE x)
{
if (size() == capacity())
{
throw FullStackException();
}
else
{
_tos++;
_arr[_tos]=x;
}
}

void stack::pop()
{
if (empty()==true)
{
throw EmptyStackException();
}
else
{
_tos--;
}
}

TYPE& stack::top()
{
if (empty()==true)
{
throw EmptyStackException();
}
else
{
cout << _arr[_tos--] << endl;
return _arr[_tos];
}
}

bool stack::empty()
{
if(_tos==0)
{
return true;
}
else
{
return false;
}
}

int stack::size()
{
return _tos; //size
}

int stack::capacity()
{
return _capacity;
}





