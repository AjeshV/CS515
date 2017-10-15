/*CS515 Assignment 4P
File: queue.cpp
Name: Ajesh Vijay Vijayaragavan
Section: 2
Date: 03/02/2017
Collaboration Declaration: Assistance received from TA, PAC, Online resources.
*/

#include <iostream>
#include "queue.h"
queue::queue(int a){
  _size = 0;
  _front = 0;
if(a==0){
   _capacity = INITCAP;
   _arr = new TYPE[_capacity];
}
else{
   _capacity = a;
   _arr = new TYPE[a];
}
}

queue::queue(const queue& k):_front(k._front),_capacity(k._capacity),_size(k._size){
  _arr = new TYPE[_capacity];
  for( int i = 0; i < _capacity; i++ ){
   _arr[i] = k._arr[i];
  }
}

queue& queue::operator=(const queue& j){
  if(this == &j)
  {
   return *this;
  }
  delete[] _arr;
  _capacity = j._capacity;
  _front = j._front;
  _size = j._size;
  if( _capacity > 0 )
  {
   _arr = new TYPE[_capacity];
for( int i = 0; i < _capacity; i++ ){
  _arr[i] = j._arr[i];
}
}
return *this;
}

queue::~queue(){
   delete []_arr;
}

void queue::enqueue(int data)
{
if(_size == _capacity)
{
   _capacity*= 2;
   int* arr2 = new TYPE[_capacity];
for( int i = 0; i < size(); i++ )
{
   arr2[(_front+i+(_capacity/2))%_capacity] = _arr[(_front+i)%(_capacity/2)];
}
delete []_arr;
 _arr = arr2;
 _front = _front+(_capacity /2);
}
_arr[ (_front + _size ) % _capacity] = data;
_size++;
}

TYPE queue::dequeue(){
if(!empty()){
   _size--;
   return _arr[_front++ % _capacity];
}
else{
   throw EmptyQueueException();
}
}

TYPE& queue::front(){
 if( !empty() ){
   return _arr[(_front)%_capacity];
 }
 else{
   throw EmptyQueueException();
 }
}

int queue::size(){ 
   return _size;
}

bool queue::empty(){
if( _size == 0){
  return true;
}
else{
  return false;
}
}

int queue::capacity(){
   return _capacity;
}

void queue::dump(ostream &os){
for( int j = 0; j < _size; j++ ){
	os << _arr[(_front+j)%_capacity] << " ";
}
	os << endl;
}
