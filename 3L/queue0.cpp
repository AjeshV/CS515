/*
CS515 Lab 3L
Name: Ajesh Vijay Vijayaragavan
Section: 01
Date: 02/20/2017
Collaboration: CS515 modules
*/

#include "queue.h"

// circular array implementation of queue
queue::queue(){
    rear = -1;  // rear used as the count of queue items
    front = 0;  // front points to queue front
	for(int i=0; i<MAX_CAP; i++)
		item[i]=0;
}

void queue::enqueue(int data){
    if (rear>=(MAX_CAP-1))
    {
    item[++rear%MAX_CAP] = data;
    }
    else
    {
    item[++rear] = data;  
    }
}

int queue::dequeue(){
   if (size() ==1 && front>=MAX_CAP)
   {
    return item[rear--%MAX_CAP];
   }
   else if ( size() == 1)
   {
    return item[rear--];
   }
   else if (front>(MAX_CAP-1))
   {
    return item[front++%MAX_CAP]; 
   }
   else
   {
    return item[front++];
   }
}

void queue::dump(ostream &os){
    for(int i=front; i<=rear; i++)
    if (front > MAX_CAP)
    {
       os<<item[i%MAX_CAP]<<endl;
    }
    else
    {
        os<<item[i%MAX_CAP]<<endl;
    }
}

int queue::size(){
    return (rear - front + 1);
}

bool queue::empty(){
    return (front > rear) ? true : false;
}

bool queue::full(){
    return (size() >= MAX_CAP) ? true : false;
    
}
