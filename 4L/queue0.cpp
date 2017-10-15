#include "queue.h"

// singly linked list implementation of queue
// empty queue is represented by null front and rear pointers

queue::queue(){
}

queue::~queue(){
}

// copy constructor
queue::queue(const queue &v){
}

// assignment operator
queue& queue::operator=(const queue &rhs){
    return *this;
}

void queue::enqueue(const TYPE data){
}

TYPE queue::dequeue(){
	TYPE val;

	return val;
}

void queue::dump(ostream &os){
}

int queue::size(){
    return 0;
}

bool queue::empty(){
    return true;
}

