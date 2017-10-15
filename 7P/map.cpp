/**CS515 Assignment 7
  *File: map.cpp
  *Name: Ajesh Vijay Vijayaragavan
  *Section: 1
  *Date: 03/30/2017
  *Collaboration Declaration: Assistance received from TA, PAC and Online resources. 
*/
// A non-generic Map ADT implemented with a BST data structure
// The BST is not-balanced and non-threaded
#include <iostream>
#include "map.h"
Map::Map(){
 // create a dummy root node and set up an empty tree
 _root = new Elem;
 _root->left = _root;  
 _root->right = 0;
 _size = 0;	
}

// copy constructor
Map::Map(const Map &v){
// if empty tree
 if (v._root == v._root->left){
  _root = new Elem;
  _root->left = _root;  // empty tree
  _root->right = 0;
  _size = 0;
 } else {
  _root = new Elem;
  _root->left = _root;
  _root->right = 0;
  copyCode(_root->left, v._root->left);
  _size = v._size;
 }
} 

// common copy code for deep copy a tree
void  Map::copyCode(Elem* &newRoot, Elem* origRoot){
 if (origRoot == 0)
   newRoot = 0;
 else{
  newRoot = new Elem;
  newRoot->key = origRoot->key;
  newRoot->data = origRoot->data;
  copyCode(newRoot->left, origRoot->left);
  copyCode(newRoot->right, origRoot->right);
 }
}

Map::~Map()
{
 if(_root->left!=_root)
 destructCode(_root->left);
 delete _root;
}

Map&Map::operator=(const Map &rhs)
{
 //if(&rhs!=this)
 //{
  Elem* a=rhs._root;
  copyCode(_root,a);
 //}
  _size = rhs._size;
 
 return *this;
}

bool Map::insert(KEY_TYPE key, VALUE_TYPE value)
{
 return insert(_root,key,value);
}

bool Map::erase(KEY_TYPE key)
{
/*	
 Map::Iterator it = find(key);
 if (it == end()){
  return false;
 }
 Elem *a = new Elem;
 Elem *b = new Elem;
 b =_root;
 a =_root->left;
 if (a=_root){
  return false;
 }
 while(a->key!=key){
  if (a->key < key){
   b=a; 
   a=a->right;
  }else if (a->key>key){
   b=a;
   a=a->left;
  }
 }int k=0;
 if(b->right==a){
  k=1;
 }else if(b->left==a){
  k=1;
 }else if(b->left==a){
  k=2;
 }
//
if(a->left == NULL && a->right == NULL){
   if (k==1){
   b->right = 0;
   _size--;
   delete a;
   return true;
  }else if(k==2){
    b->left = 0;
    _size--;
    delete a;
    return true;
 }
  else
  {
	  _size--;
	  delete a;
	  return true;
  }
}
//
if ((a->left!= NULL && a->right ==NULL)||(a->left==NULL && a->right!=NULL)){
  if (a->right == NULL){
   if(k==1){
    b->right = a->left;
    _size--;
    delete a;
    return true;
   }if (k==2){
    b->left = a->left;
    _size--;
     delete a;
    return true;			
   } 
  }if (a->left == NULL){
  if (k==1){
   b->right = a->right;
   _size--;
   delete a; 
   return true;
  }if (k==2){
   b->left = a->right;
   _size--;
   delete a;
   return true;
  }
 }
}
//
if (a->left!=NULL && a->right!=NULL){ 
 Elem *x1 = new Elem;
 Elem *x2 = new Elem;
 x1 = a->right;
 x2 = a->right;
 while(x1->left){
  x2 = x1;
  x1=x1->left; 
 }x1->left = a->left;
 if(x2!=x1){
   x2->left=x1->right;
   x1->right=a->right;
 }else{
  x1->right = x2->right;		 
 }
   if (k==1){
    b->right = x1;
    _size--;
    delete a;
    return true;
   }else if (k==2){
    b->left = x1;
    _size--;
    delete a;
    return true;
   }
}return false;
}

*/	
 Iterator it = find(key);
 if(it == end())
 {
  return false;
 } 
 Elem* a=_root->left;
 Elem* b=_root;

 if(a==_root)
 {
	 return false;
 }
 if(!a)
 {
  return false;
 }
 while(a)
 {
   if(key<a->key)
   {
    b=a;
    a=a->left;
   }
    else if(key>a->key)
    {
     b=a;
     a=a->right;
   }
    else
    {
     break;
    }
 }
 if(a->left==NULL && a->right==NULL)
 {
  if(key<b->key)
  {
    b->left = 0;
  }
  else if(key>b->key)
  {
   b->right = 0;
  }
  _size--;
  delete a;
  return true;
 }
 else if((a->left!=NULL&&a->right==NULL)||(a->left==NULL&&a->right!=NULL))
 {
  if(a->left!=NULL)
   {
    if(a==_root->left)
    {
     _root->left = a->left;
    }
   else
   {
    b->left=a->left;
   }
  }
  else
  {
   if(_root->left==a)
   {
    _root->left=a->right;
   }
  else
  {
   b->right=a->right;
  }
 }
   _size--;
   delete a;
   return true;
 }
 else if(a->left!=NULL && a->right!=NULL)
 {
//-------------------------//
   Elem *x1 = new Elem;
   Elem *x2 = new Elem;
   x1 = a->right;
   x2 = a->right;
   while (x1->left!=NULL)
   {
	   x2 = x1;
	   x1 = x1->left;
   }
   x1->left = a->left;
   if(x2!=x1)
   {
	   x2->left = x1->right;
	   x1->right = a->right;
   }
   else
   {
	   x1->right = x2->right;
   }
   if (a->data>_root->data)
   {
	   b->right = x1;
	   _size--;
	   delete a;
	   return true;
   }
   else if (a->data<_root->data)
   {
	   b->left = x1;
	   _size--;
	   delete a;
	   return true;
   }

 }
 return false;
}
//--------------------------------------------------
/*
  Elem* x1;
  if(a->right!=NULL)
  {
   x1=a->right;
 while(x1->left!=NULL)
 {
   b=x1;
   x1=x1->left;	
  }
 }
  else
  {
   while(a->left!=NULL)
   {
   if(a->data<_root->data)
   {
    x1=_root;
    _root=_root->left;
  }
  else if(a->data>_root->data)
  {	
  _root = _root->right;
}
else{
  break;
 }
 }
}
  x1->left= a->left;
  x1->right= a->right;
  _size--;
  delete a;
  return true;
}
  return false;
}

*/


int Map::size() const
{
 return _size;
}

Map::Iterator Map::find(KEY_TYPE key)const
{
 Elem *a =_root->left;
 while(a){
  if(key < a->key){
   a = a->left;
  }
  else if(key>a->key){
  a= a->right;
  }
  else{
  break;
  }
  }Map::Iterator y(a);
  if(a==NULL){
  y=end();
 }
return y;
}
//using iterators for map beginning and end
Map::Iterator Map::begin() const{
 Elem *a=_root;
 while(a->left!=NULL){
  a=a->left;
 }
 Map::Iterator y(a);
 return y;
}

Map::Iterator Map::end() const
{
 Map::Iterator y(_root);
 return y;
}

VALUE_TYPE& Map::operator[](KEY_TYPE key){
 Map::Iterator y =find(key);
 VALUE_TYPE q;
 if(y!=end()){
 return y->data;
 }
   insert(_root,key,q);
   y=find(key);
   return y->data;
}

Map::Elem& Map::Iterator::operator*(){
 return *_cur;
}

Map::Elem* Map::Iterator::operator->(){
 return _cur;
}

bool Map::Iterator::operator==(Iterator y){
 if(_cur==y._cur){
 return true;
 }
 return false;
}

bool Map::Iterator::operator!=(Iterator y)
{
 if(_cur!=y._cur){
 return true;
 }
 return false;
}

bool Map::insert(Elem *& root, const KEY_TYPE& key, const VALUE_TYPE& data)
{
/*
	if (root == _root)
	{
		Elem *node = new Elem;
		node->key = key;
		node->data = data;
		node->right = 0;
		node->left = 0;
		_root->left = node;
		_size++;
		return true;
	}
	if (root->key == key)
	{
		return false;
	}
	if (key < root->key)
	{
		if (root->left==0)
		{
			Elem *node = new Elem;
			node->data = data;
			node->key = key;
			node->right = 0;
			node->left = 0;
			root->left = node;
			_size++;
			return true;
		}
		return insert(root->left, key, data);
	}
	if (key>root->key)
	{
		if (root->right==0)
		{
			Elem *node = new Elem;
			node->data = data;
			node->key = key;
			node->right = 0;
			node->left = 0;
			root->right = node;
			_size++;
			return true;
		}
		return insert(root->right,key,data);
	}
}
*/
	
 Map::Iterator y=end();
 if(y==find(key))
 {
  Elem* a = new Elem;
   a->data = data;
   a->key = key;
   a->right = NULL;
   a->left = NULL;
  if(root==root->left)
  {
    root->left=a;
    _size++;
   return true;
  }
   Elem* k = root->left;
   Elem* m = root->left;
  while(k!=NULL)
  {
   m=k;
  if(key<k->key)
  {
    k = k->left;
    //a->right = NULL;
    //a->left = NULL;
  }
   else
  {
    k=k->right;
    //a->right = NULL;
    //a->left = NULL;
  }
  } 
   if(key<m->key)
   {
    m->left = a;
    //a->right = NULL;
    //a->left = NULL;
   }
   else
   {
     m->right = a;
     //a->right = NULL;
     //a->left = NULL;
   }
    _size++;
  return true;
 }
  return false;
 }



void Map::destructCode(Elem *& p)
{
 if(p->left!=NULL){
 destructCode(p->left);    
 }    
 if(p->right!=NULL){
  destructCode(p->right);
  }
  delete p;
}
// 
//  Do Not Modify Below Here
//
//
// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
void Map::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		printTree(out, level+1, p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->key << " " << p->data << '\n';
		printTree(out, level+1, p->left);
	}
}

// outputs information in tree
ostream& Map::dump(ostream& out) const{
	if ( _root == _root->left) { // tree empty
		return out;
	}
	printTree(out, 0, _root->left);   // print tree structure
	return out;
}

// outputs using overloaded << operator
ostream& operator<< (ostream& out, const Map& v){
	v.dump(out);
	return out;
}
