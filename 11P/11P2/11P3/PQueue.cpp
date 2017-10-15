/** CS515 Lab 10
  * File: PQueue.cpp
  * Name: Ajesh Vijay Vijayaragavan
  * Section: 2
  * Date: 04/19/2017
  * Collaboration Declaration: Assistance received from TA,PAC,online resources.
  */  
//#include "PQueue0.h"
//#include <iostream>
//using namespace std;
template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue(){
 _size=0;
}
template<class T,int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue(T* items,int size){
 _array[0]=0;
 for(int i=1;i<=size;i++){
  _array[i]=items[i-1];
 }_size=size;
 buildHeap();
}
template<class T,int MAX_SIZE>
void PQueue<T,MAX_SIZE>::insert(T x1){
 _size++;
 _array[_size]=x1;
moveUp();
}
template<class T,int MAX_SIZE>
T PQueue<T, MAX_SIZE>::findMin(){
  return _array[1];
}
template<class T,int MAX_SIZE>
void PQueue<T, MAX_SIZE>::deleteMin(){
if(_size>=0){
 //int y1=_array[1];
 _array[1]=_array[_size];
 _size--;
 moveDown(1);}
}
template<class T,int MAX_SIZE>
bool PQueue<T, MAX_SIZE>::isEmpty(){
  return _size==0;
}
template<class T,int MAX_SIZE>
int PQueue<T,MAX_SIZE>::size(){
  return _size;
}
template<class T,int MAX_SIZE>
void PQueue<T, MAX_SIZE>::buildHeap(){
for(int i=_size/2;i>0;i--){
 moveDown(i); 
 }
}
template<class T,int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveDown(int a1)

{
    int x=a1;
    while(x*2<=_size||(2*x)+1<=_size){
	     T left=_array[x*2];
	      T right=_array[(2*x)+1];
	       if( *left > *right ){
		        if(_array[x]>right){
			               _array[(2*x)+1]=_array[x];
			               _array[x] = right;
			        x=(2*x)+1;
		         }else{
		         break; }
	       }else if(*_array[x]>left){
  _array[x*2]=_array[x];
  _array[x]=left;
        x=x*2;
       }else{
        break;}
 }
}

/*

{
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
// int y1=_array[z];
 T end=_array[z];
 _array[z]=_array[a1];
 _array[a1]=end;
 moveDown(z);}
}
*/
template<class T,int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveUp(){
 int pos=_size;
 while(pos>1&&_array[pos]<_array[pos/2]){
 //int y1=_array[pos];
  T end=_array[pos];
 _array[pos]=_array[(pos)/2];
 _array[(pos)/2]=end;
 pos=(pos)/2;
 }
}
