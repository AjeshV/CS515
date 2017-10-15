/**CS515 Lab 7
 * File: set.cpp     
 * Name: Ajesh Vijayaragavan    
 * Section: 1
 * Date: 03/29/2017 
 * Collaboration Declaration: Assistance received from TA, PAC and Online resources.
*/

#include <stack>
#include <queue>
#include "set.h"

Set::Set():_size(0){
    // create a dummy root node
    _root = new Elem;
    _root->info = numeric_limits<int>::max();
    _root->left = _root;  // empty tree
    _root->right = 0;
    _root->rightThread = false;
}

Set::~Set(){
    if (_root->left != _root)  // not an empty tree
        destructCode(_root->left);
    delete _root;
}

void Set::destructCode(Elem *& p){
  if(p==NULL)
  {
   return;
  }
  if(p->left!=NULL)
  {
   destructCode(p->left);
  }
  if(p->right!=NULL && !p->rightThread)
  {
   destructCode(p->right);
  }
  delete p;
}


// returns true if the new node is inserted, otherwise false
bool Set::insert(ELEMENT_TYPE v){
    if (insert(_root->left, v, _root)){
        _size++;
        return true;
    }
    return false;
}

// insert helper method
// returns true if the new node is inserted, otherwise false
bool Set::insert(Elem *&cur, const ELEMENT_TYPE &value, Elem *lastLeft){
    if (cur == _root || cur == 0) {
        cur = new Elem;
        cur->info = value;
        cur->left = 0;
        cur->right = lastLeft;
        cur->rightThread = true;
        return true;
    }
    
    if (value == cur->info){
        return false;
    }
    // insert at left
    if (value < cur->info)
        return insert( cur->left, value, cur);
    
    // insert at right
    if (!cur->rightThread){
        return insert(cur->right, value, lastLeft);
    } else {  // current's right is a thread; add a new node
        cur->rightThread = false;
        cur->right = new Elem;
        cur->right->info = value;
        cur->right->left = 0;
        cur->right->right = lastLeft;
        cur->right->rightThread = true;
        return true;
    }
}

// print out tree elements in depth first in order
void Set::depthFirstInOrder(){
 Elem *a=_root;
 stack<Elem*> b;
 b.push(a->left);
 while(a->left!=NULL){
  a=a->left;
 }
 while(a!=_root){
  cout << a->info << " ";
  if(a->rightThread){
   a=a->right;
  }
  else{
  if(a->right!=NULL){
   a=a->right;
   while(a->left!=NULL){
    a=a->left; }
  }
   }
 } 
}
void Set::breadthFirst(){
 if(_root==NULL)
 {
  return;
 }
 queue<Elem*> a;
 a.push(_root->left);
 while(!a.empty()){
  Elem *b=a.front();
  cout << b->info << " ";
  a.pop();
  if(b->left!=NULL){
   a.push(b->left);
  }
  if(b->right!=NULL && !b->rightThread){
   a.push(b->right);
  }
 }  
}

int Set::size() const{
    return _size;
}

// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
void Set::printTree(ostream& out, int level, Elem *p){
    int i;
    if (p) {
        if (p->right && !p->rightThread)
            printTree(out, level+1,p->right);
        for(i=0;i<level;i++)
            out << "\t";
        out << p->info << '\n';
        printTree(out, level+1,p->left);
    }
}

// outputs information in tree in inorder traversal order
ostream& Set::dump(ostream &out){
    if ( _root == _root->left) // tree empty
        return out;
    printTree(out, 0, _root->left);   // print tree structure
    return out; 
}


// outputs using overloaded << operator
ostream& operator << (ostream &s, Set &v){
    v.dump(s);
    return s;
}

