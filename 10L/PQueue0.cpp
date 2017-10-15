/** CS515 Lab 10
  * File: PQueue0.cpp
  * Name: Ajesh Vijay Vijayaragavan
  * Section: 1
  * Date: 04/19/2017
  * Collaboration Declaration: Assistance received from TA,PAC,online resources.
  */
#include <iostream>
#include "PQueue0.h"
#include <cstdlib>
PQueue::PQueue(){
 _size = 0;
}
PQueue::PQueue(int* items,int size){
  _array[0] = 0;
 for(int i=1;i<=size;i++){
  _array[i]=items[i-1];
 }_size=size;
 buildHeap();
}
void PQueue::insert(T x1){
 _size++;
 _array[_size]=x1;
 moveUp();
}
T PQueue::findMin(){
  return _array[1];
}
void PQueue::deleteMin(){
 if(_size>=0){
 int y1=_array[1];
 _array[1]=_array[_size];
 _size--;
 moveDown(1);}
}
bool PQueue::isEmpty(){
  return _size==0;
}
int PQueue::size(){
  return _size;
}
void PQueue::buildHeap(){
 for(int i=_size/2;i>0;i--){
  moveDown(i);
 }
}
void PQueue::moveDown(int a1){
  int x=a1*2;
  int y=a1*2+1;
  int z;
 if(x<=_size&&_array[x]<_array[a1]){
  z=x;
 }else{
  z=a1;}
 if(y<=_size&&_array[y]<_array[z]){
  z=y;
}if(z!=a1){
 int y1=_array[z];
 _array[z]=_array[a1];
 _array[a1]=y1;
 moveDown(z);}
}
void PQueue::moveUp(){
 int pos=_size;
 while(pos>1&&_array[pos]<_array[pos/2]){
 int y1=_array[pos];
 _array[pos]=_array[(pos)/2];
 _array[(pos)/2]=y1;
 pos=(pos)/2;
 }
}