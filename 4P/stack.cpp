/*CS515 Assignment 4P
File: stack.cpp
Name: Ajesh Vijay Vijayaragavan
section: 01
Date: 03/02/2017
Collaboration: Assistance received from TA, PAC, Online resources.
*/

#include <iostream>
#include "stack.h"
using namespace std;

stack::stack(int size){
_tos = -1;
if (size == 0)
{
 _capacity = INITCAP;
 _arr = new TYPE[_capacity];
}
else{
 _capacity = size;
 _arr = new TYPE[_capacity];
}
}

stack::stack(const stack& a):_capacity(a._capacity),_tos(a._tos)
{
 _arr = new TYPE[_capacity];
for (int i = 0; i < _capacity; i++)
{
 _arr[i]=a._arr[i];
}
}

stack& stack::operator=(const stack& a){
if (this == &a)
{
 return *this;
}
 delete []_arr;
 _capacity = a._capacity;
 _tos = a._tos;
if (_capacity > 0)
{
 _arr = new TYPE[_capacity];

for (int i = 0; i < _capacity; i++){
 _arr[i] = a._arr[i];
}
 return *this;
}
}

stack::~stack(){
 delete []_arr;
}

void stack::push(const TYPE x){
if (_tos + 1 == _capacity)
{
 _capacity *= 2;
 int* arr2 = new TYPE[_capacity];
 for (int i = 0; i < _capacity/2; i++)
 {
    arr2[i] = _arr[i];	 
 }
 delete []_arr;
 _arr = arr2;
 _arr[++_tos] = x;
}
else
{
 _arr[++_tos]=x;
}
}

void stack::pop(){
if (_tos<0)
{
 throw EmptyStackException();
}
else
{
 _tos--;
}
}

TYPE& stack::top(){
if (_tos == -1)
{
 _capacity *= 2;
 int* arr2 = new TYPE[_capacity];
 for (int i = 0; i < _capacity; i++)
 {
   arr2[i] = _arr[i];  
 }
 delete []_arr;
 _arr = arr2;
}
 return _arr[_tos];
}

bool stack::empty(){
if(_tos<0)
{
 return true;
}
else
{
 return false;
}
}

int stack::size(){
 return (_tos + 1); //size
}

int stack::capacity(){
 return _capacity;
}

void stack::dump(ostream &os){
 for (int i = _tos; i >= 0; i--)
 {
   os << _arr[i] << " ";
 }
 os << endl;
}



