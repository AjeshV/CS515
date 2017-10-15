/*CS515 Assignment 4P
File: queue.cpp
Name: Ajesh Vijay Vijayaragavan
Section: 02
Date: 10/05/2017
Collaboration Declaration: no*/


#include "queue.h"

// circular array implementation of queue
/*queue::queue(){
    rear = -1;  // rear used as the count of queue items
    front = 0;  // front points to queue front
	for(int i=0; i<MAX_CAP; i++)
		_arr[i]=0;
}
*/

queue::queue(int size)
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


queue::~queue()
{
	delete []_arr;
}

//add an element to the end of queue (expand if necessary)
void queue::enqueue(int data){

    if(_size==_capacity)
    {
     int k=(_capacity*2);
     _capacity=k;
     int* _arr2=new TYPE[_capacity];
     int i;
     for (i=0;i<size();i++)
     {
       
     }
     delete []_arr;
     _arr=_arr2;

    }

    else{
    _arr[_front+_size] = data;
	}
}
// remove an element from the front of queue
TYPE queue::dequeue(){
    _size--;	
    return _arr[_front++];
}
// output queue elements from queue front to queue end
// elements are separated with a white space.

void queue::dump(ostream &os){
    for(int i=_front; i<=_size; i++)
    {
        os<<_arr[i]<<" ";
    }
    os << endl;
}
// return the number of elements currently in the queue
int queue::size(){
    return (_size - _front + 1);
}
// return true if the queue is empty, false otherwise
bool queue::empty(){
    if (_size==0)
    {
	    return true;
    }
    else
    {
	    return false;
    }
}
/*
bool queue::full(){
    return (size() >= MAX_CAP) ? true : false;
    
}*/
