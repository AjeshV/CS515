/**CS515 Lab 9
  *File: set.cpp
  *Name: Ajesh Vijay Vijayaragavan
  *Section: 2
  *Date: 04/12/2017
  *Collaboration Declaration: Assistance received from TA, PAC, Online resources. 
 */
#include "set.h"
Set::Set(){
 _root=new TrieNode;
 _size=0;
}
bool Set::insert(string str1){
  if(find(str1)){
   return false;
  }TrieNode* x1 = _root;
 for(int i=0; i<str1.length(); i++){
   int j=(int)(str1.at(i))-97;
 if(!(x1->child[j])){
   x1->child[j]=new TrieNode;
  }x1 = x1->child[j];
 }x1->isWord = true;
  _size++;
  return true;
}
bool Set::erase(string str1){
 if(_size==0){
  return false;
 }TrieNode* x1=_root;
 for(int i=0; i<str1.length(); i++){
  int j=(int)(str1.at(i))-97;
  if(!(x1->child[j])){
	return false;
  }x1=x1->child[j];
  }if(x1->isWord){
  x1->isWord=false;
  _size--;
  return true;
  }else{
  return false;
  }
}
bool Set::find(string str1){
 TrieNode* x1=_root;
 if(_size==0){
	return false;
 }for(int i=0;i<str1.length();i++){
  int j=(int)(str1.at(i))-97;
 if(!(x1->child[j])){
   return false;
  }x1=x1->child[j];
 }if(x1->isWord){
	return true;
 }else{
	return false;}
}
int Set::size(){
	return _size;
}