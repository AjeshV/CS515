/** CS515 Assignment 9
  * File: map.cpp
  * Name: Ajesh Vijay Vijayaragavan
  * Section: 1
  * Date: 04/13/2017
  * Collaboration Declaration: Assistance received from TA, PAC, online resources. */ 
//A non-generic Map ADT implemented with an AVL tree
#include <map>
template <typename KEY, typename T>
Map<KEY, T>::Map(){
   _root= new Elem;
   _root->left= _root;
   _root->right= 0;
   _root->rightThread= false;
   _size= 0;
}
// copy constructor 
template <typename KEY, typename T>
Map<KEY, T>::Map(const Map& rhs){
if(rhs._root==rhs._root->right){
  _root=new Elem;
  _root->left=_root;
  _root->right=0;
  copyCode(_root->left,rhs._root->left);
  _size=rhs._size;
}else{
 _root=new Elem;
 _root->left=_root;
 _root->right=0;
 _size=0;
 }
} 
//Destructor
template <typename KEY, typename T>
Map<KEY, T>::~Map()
{
  destructCode(_root->left);
  delete _root;
}
//Code for deallocation
template <typename KEY, typename T>
void Map<KEY, T>::destructCode(Elem *& p){
if(p){
 if(p->left){
 	destructCode(p->left);
   }
   if(p->right && !p->rightThread){
    destructCode(p->right);
   }delete p;
}
}
//insert helper method
template <typename KEY, typename T>
bool Map<KEY, T>::insert(const KEY &key, const T &data, Elem *& node, Elem *lastleft){
 if (node==0||node==_root){
    node=new Elem;
	node->key=key;
	node->data=data;
	node->height=0;
	node->left=0;
	node->right=lastleft;
	node->rightThread=true;
  }else if (key<node->key){
    insert(key,data,node->left,node );
  }
  else if(key>node->key){
  if(node->rightThread){
    node->right=new Elem;
	node->right->data=data;
	node->right->key=key;
	node->right->left=0;
	node->right->right=lastleft;
	node->right->height=0;
	node->right->rightThread=true;
	node->rightThread=false;
 }else{
    insert(key,data,node->right,lastleft);
 }
}
if (height(node->left)-height(node->rightThread?0:node->right)==2){
    if(key < node->left->key){
        rotateRight(node);
 }else{
   doubleRotateRight(node); }
  }if (height(node->left)-height(node->rightThread?0: node->right)==-2){
     if (key > node->right->key){
	 rotateLeft(node);}
        else{
		doubleRotateLeft(node);}
 }
node->height = max(height(node->left), height(node->rightThread ? 0: node->right)) + 1;
	return true;
}
//Key element map to re thread the new tree
template <typename KEY, typename T>
void Map<KEY, T>::addToMap(Elem* root, map<KEY, Elem*> &keyElemMap){
  if(root){
    keyElemMap[root->key] = root; 
	addToMap(root->left, keyElemMap);
	if(!root->rightThread){
	   addToMap(root->right,keyElemMap);}
  }
}
//Copy code for thread copying
template <typename KEY, typename T>
void Map<KEY, T>::copyThread(Elem* &newRoot, Elem* origRoot){
  map<KEY, Elem*> newKeyElemMap; 
  map<KEY, Elem*> origKeyElemMap;
  addToMap(newRoot->left, newKeyElemMap);
  addToMap(origRoot->left, origKeyElemMap);
  typename std::map<KEY,Elem*>::reverse_iterator it=origKeyElemMap.rbegin();
  newKeyElemMap[it->first]->rightThread=true;
  newKeyElemMap[it->first]->right=newRoot;
  it++;
  while(it!=origKeyElemMap.rend()){
  if (it->second->rightThread){
	  newKeyElemMap[it->first]->rightThread=true;
	  newKeyElemMap[it->first]->right=newKeyElemMap[origKeyElemMap[it->first]->right->key];
	}it++;
  } 
}
//Deep copy a tree
template <typename KEY, typename T>
void  Map<KEY,T>::copyCode(Elem* &b, Elem* a){
  if (a==NULL ){
     b=NULL;
  }else{
  b=new Elem;
  b->key=a->key;
  b->data=a->data;
  copyCode(b->right,a->right);
  copyCode(b->left,a->left);	
  }
}
//Single left rotation
template <typename KEY, typename T>
void Map<KEY, T>::rotateLeft(Elem *& node){
  Elem* i=node->right;
  if(i->left){
	node -> right = i->left;
  }else{
  node->rightThread = true;
 }i->left=node;
  node = i;
  node->left->height=max(height(node->left->left),height(node->left->rightThread?0:node->left->right))+1;
  node->height=max(height(node->left),height(node->rightThread?0:node->right))+1;
}
//Single right rotation
template <typename KEY, typename T>
void Map<KEY, T>::rotateRight(Elem *& node){
   Elem* i = node->left;
if(!i->rightThread){
  node->left=i->right;
}else{
 node->left=NULL;
}
 i->right=node;
 i->rightThread=false;
 node=i;
 node->right->height=max(height(node->right->left),height(node->right->rightThread?0:node->right->right))+1;
 node->height=max(height(node->left),height(node->rightThread?0:node->right))+1;
}
//Double left rotation
template <typename KEY, typename T>
void Map<KEY, T>::doubleRotateLeft(Elem *& node){
	rotateRight(node->right);
	rotateLeft(node);
}
//Double right rotation
template <typename KEY, typename T>
void Map<KEY, T>::doubleRotateRight(Elem *& node) {
	rotateLeft(node->left);
	rotateRight(node);
}
template <typename KEY, typename T>
typename Map<KEY, T>::Elem& Map<KEY, T>::Iterator::operator*(){ 
	return *_cur;
}
template <typename KEY, typename T>
typename Map<KEY, T>::Elem* Map<KEY, T>::Iterator::operator->(){ 
	return _cur;
}
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::Iterator::operator++(int){
  Iterator it(_cur);
  if(_cur->right==0){
	return it;
  } 
  if(_cur->rightThread){
	 _cur=_cur->right;
}
else{
 _cur=_cur->right;
 while(_cur->left){
  _cur=_cur->left;
 }
}return it;
}
template <typename KEY, typename T>
bool Map<KEY, T>::Iterator::Iterator::operator==(Iterator it){
	return _cur == it._cur;
}
template <typename KEY, typename T>
bool Map<KEY, T>::Iterator::Iterator::operator!=(Iterator it){
	return _cur != it._cur;
}
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::begin() const {
  Elem* a=_root;
  while(a->left && a->left != _root){
	a=a->left;
}
Map::Iterator it(a);
return it;
}
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::end() const {
	Map::Iterator it(_root);
	return it;
} 
//Assignment operator
template <typename KEY, typename T>
Map<KEY, T>& Map<KEY, T>::operator=(const Map &rhs)
{
 if(rhs._root->left==rhs._root){
  _root=new Elem;
  _root->right=NULL;
  _root->left=_root;
  _size=0;  
 }
 else if(_root->left!=_root){
    destructCode(_root->left);
   	delete _root;
 }
 else if(this!=&rhs){
   		return *this;
 }
 return *this;
}
template <typename KEY, typename T>
bool Map<KEY, T>::insert(KEY key, T value){
 if(find(key)==end()){
 if(insert(key,value,_root->left,_root)){
   _size++;
   return true;
  }
 }else{
  return false;
  }
}
template <typename KEY, typename T>
int Map<KEY, T>::size() const{
  return _size;
}
//return an iterator pointing to the end if the element is not found,
//to the element otherwise
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::find(KEY key) const{
  Elem* s=_root->left;
  while(s!=NULL){
   if(s==_root){
	  s = NULL;
	}else if(key==s->key){
	  break;
	}else if(key>s->key&&!s->rightThread){
	  s=s->right;
	}else if(key<s->key){
	  s=s->left;
   }else{
	s = NULL;
  }
}Map::Iterator it(s);
  if(s==NULL){
	it=end();
  }return it;
}
// overloaded subscript operator
template <typename KEY, typename T>
T& Map<KEY, T>::operator[](KEY key){
  Map::Iterator it = find(key);
  T value;
  if(it!= end()){
   return it->data;
 }		
 insert(key,value);
 it = find(key);
 return it->data;
}
template <typename KEY, typename T>
int Map<KEY, T>::height(Elem *node) {
  return node==0?-1:node->height;
}
// output the structure of tree. The tree is output as "lying down"
// output each node's key, value and its tree height 
template <typename KEY, typename T>
void Map<KEY, T>::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		if (p->right && !p->rightThread)
			printTree(out, level+1,p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->key << " " << p->data << "(" << p->height << ")" << '\n';
		printTree(out, level+1,p->left);
	}
}

//Inorder traversal order
template <typename KEY, typename T>
ostream& Map<KEY, T>::dump(ostream& out) const{
	if ( _root == _root->left) {// tree empty
		return out;
	}
	printTree(out, 0, _root->left);   // print tree structure
	return out;
}

// outputs using overloaded << operator
template<typename KEY, typename T>
ostream& operator<< (ostream& out, const Map<KEY, T>& v){
	v.dump(out);
	return out;
}
