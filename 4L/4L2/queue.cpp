/*CS515 Lab 4
 File: queue.cpp
 Name: Ajesh Vijay Vijayaragavan
 Section: 01
 Date: 10/01/2017
 Collaboration Declaration: Assistance received from TA, PAC, Online resources.
*/
#include "queue.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// singly linked list implementation of queue
// empty queue is represented by null front and rear pointers
queue::queue()
{
 _front = NULL;
 _rear = NULL;
 _size = 0;
}
// copy constructor
queue::queue(const queue &v):_front(v._front), _rear(v._rear){
  _front = NULL;
  _rear = NULL;
  _size = 0;
  node *r;
  r = v._front;
  int n;

  while( r!= NULL )
  {
   n = r->list;
   r = r->next;
   enqueue(n);
  }
}
// assignment operator
queue& queue::operator=(const queue &rhs){

if(this != &rhs)
{
 node *s = _front;
 while(s= NULL)
 {
  _front = _front->next;
  delete s;			
  s = _front;
 }
  _front = NULL;
  _rear = NULL;
  _size = 0;

node *r = rhs._front;
while( r!= rhs._rear->next )
{ 
  enqueue( r->list );
  r = r->next;
}
}
}

queue::~queue(){
node *r = _front;
while( r!= NULL )
{
  _front = _front->next;
  delete r;
  r = _front;
}
}

void queue::enqueue(const TYPE data){

node *r = new node;
r->list = data;
if( _front == NULL )
{
  _front = r;
  _front->next = NULL;
  _front->prev = NULL;
}
else
{
  _rear->next = r;
  r->next = NULL;
  r->prev = _rear;
}
  _rear = r;
  _size++;
}

TYPE queue::dequeue()
{ 
  node *r;
  TYPE val;
if(_front == NULL)
{
 throw EmptyQueueException();
}	else
{ 
 r = _front;
 _front = _front->next;
 val = r->list;
 delete r;
 _size--;

if( empty())
{	    
  _front = NULL;
  _rear = NULL;
}
    return val;
  }	
}

void queue::dump(ostream &os){
   node *head = _front;
   while( head )
   {
     cout << head->list << " ";
     head = head->next; 
   }
   cout << endl;
}

int queue::size(){
   return _size;
}

bool queue::empty(){
   return (_size == 0 ) ? true : false;
}
