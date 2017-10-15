/**CS515 Assignment 8
  *File: map.cpp
  *Name: Ajesh Vijay Vijayaragavan
  *Section: 1
  *Date: 04/06/2017
  *Collaboration Declaration: Assistance received from TA, PAC, Online resources. 
 */
// A generic Map implemented with right-threaded BST
// BST is not balanced
// helper container for thread copying
template <typename KEY, typename T>
Map<KEY, T>::Map(){
	// create a dummy root node
	_root = new Elem;
	_root->left = _root;  // empty tree
	_root->right = 0;
	_root->rightThread = false;
	_size = 0;

}
// copy constructor 
template <typename KEY, typename T>
Map<KEY, T>::Map(const Map<KEY,T> &v){
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
		copyCode(_root->left, v._root->left); // to deep copy the tree without dummy nodes
		copyThread(_root, v._root); // to copy the threading; must pass dummy nodes to complete the threads
		_size = v._size;
	}
} 
// construct a key-element map to rethread the new tree
// the map contains all nodes key values and their corresonding elem node address 
// for furture lookup in setting up threads
template <typename KEY, typename T>
void Map<KEY, T>::addToMap(Elem* root, map<KEY, Elem*> &keyElemMap){
	if (root) {
		keyElemMap[root->key] = root; 
		addToMap(root->left, keyElemMap);
		if (!root->rightThread)
			addToMap(root->right, keyElemMap);
	}
}
// common copy code for thread copying
template <typename KEY, typename T>
void Map<KEY, T>::copyThread(Elem* &newRoot, Elem* origRoot){
	// construct the key-element map for new and orig tree
	map<KEY, Elem*> newKeyElemMap; 
	map<KEY, Elem*> origKeyElemMap;
	addToMap(newRoot->left, newKeyElemMap);
	addToMap(origRoot->left, origKeyElemMap);

	// start at the last element in the tree, which threads to root
	typename std::map<KEY, Elem*>::reverse_iterator it = origKeyElemMap.rbegin();
	newKeyElemMap[it->first] -> rightThread = true;
	newKeyElemMap[it->first] -> right = newRoot;
	
	// then thread the rest of the tree backwardly 
	it++;
	while(it != origKeyElemMap.rend()){
		if (it->second->rightThread){
			newKeyElemMap[it->first] -> rightThread = true;
			newKeyElemMap[it->first] -> right = newKeyElemMap[ origKeyElemMap[it->first]->right->key ];
		}
		it++;
	} 
}
// common copy code for deep copy a tree without copying threads
template <typename KEY, typename T>
void  Map<KEY,T>::copyCode(Elem* &newRoot, Elem* origRoot){
 if (origRoot == 0){
	newRoot = 0;
 }		
 else{
 newRoot = new Elem;
 newRoot->key = origRoot->key;
 newRoot->data = origRoot->data;
 newRoot->rightThread = origRoot->rightThread; 
 copyCode(newRoot->left, origRoot->left);
 if (!origRoot->rightThread){ 
   copyCode(newRoot->right, origRoot->right);
 }
}
}  
template<typename KEY, typename T>
Map<KEY, T>::~Map(){
 if(_root->left!=_root){
  destructCode(_root->left);
 }
 delete _root;
}
template<typename KEY, typename T>
void Map<KEY, T>::destructCode(Elem *& p)
{
	
 if(p->left!=NULL)
 {
  destructCode(p->left);
 }
 if(p->right!=NULL&&!p->rightThread)
 {
  destructCode(p->right);
  delete p;
 }
}
// helper method for inserting record into tree.
template<typename KEY, typename T>
bool Map<KEY, T>::insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft )
{
 if (root==_root||root==0){
  root = new Elem;
  root->data=data;
  root->key=key;
  root->left=0;
  root->right=lastLeft;
  root->rightThread=true;
  return true;
 }
 if (key==root->key){
  return false;
 }
 if (key<root->key){
   return insert(root->left, key,data,root);
 }
 if (!root->rightThread){      
   return insert(root->right, key, data, lastLeft);
 } 
 else {
  root->rightThread=false;
  root->right=new Elem;
  root->right->data=data;
  root->right->key=key;
  root->right->left=0;
  root->right->right=lastLeft;
  root->right->rightThread=true;
  return true;
 }
}
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::begin() const {  // return the left most (smallest) tree node
 Elem *a=_root;
 while(a->left!=NULL && a->left!=_root)
 {
  a=a->left;
 }
 Map::Iterator it(a);
 return it;
}
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::end() const {  // return the dummy root node
 Map::Iterator it(_root);
 return it;
} 
 
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::Iterator::operator++(int){
 if(_cur->right==0) {
   Iterator it(_cur);
   return it;	
   } 
 if(_cur->rightThread)
 {
  _cur=_cur->right;
 }
 else
 {
  _cur=_cur->right;
  while(_cur->left!=0)
  {
   _cur=_cur->left;
  }
 }
Iterator it(_cur);
return it;
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
Map<KEY, T>& Map<KEY, T>::operator=(const Map<KEY, T> &rhs){
if( &rhs!=this)
{
  Elem * newRoot=rhs._root;
  copyCode(newRoot,_root);
  copyThread(newRoot,_root);
}
return *this;
}
template<typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator==(Iterator it){
 return _cur->key == it->key;
}

template<typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator!=(Iterator it){
 if(_cur!=it._cur){
  return true;
 }
 return false;
}

template <typename KEY, typename T>
int Map<KEY, T>::size() const{
	return _size;
}

//output the structure of tree. The tree is output as "lying down"
//in which _root is the LEFT most Elem.
template <typename KEY, typename T>
void Map<KEY, T>::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		if (p->right && !p->rightThread)
			printTree(out, level+1,p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->key << " " << p->data << '\n';
		printTree(out, level+1,p->left);
	}
}

//insert an element into the Map; return true if successful
template<typename KEY, typename T>
bool Map<KEY, T>::insert(KEY key, T value )
{
 if (insert(_root->left, key, value, _root)){
 _size++;
 return true;
 }
 return false;
}

//remove an element from the Map; return true if successful
template<typename KEY, typename T>
bool Map<KEY, T>::erase(KEY key){
 Elem* y=_root->left;
 Elem* x = _root;
 bool isleft;
 if(find(key) != end() )
 {
  while(y&&y!=_root)
  {
  if(key<y->key)
  {
   x = y;
   isleft = true;
   y = y->left;
  }
 else if( key > y->key && y->rightThread)
 {
  x = y;
  isleft = false;
  y = y->right;
 }
 else{
  break;
 }
}
}
else{
  return false;
}
 if(!y||y==_root){
   return false;
  }
 if(y->left==NULL&&!y->rightThread){
  if(isleft){
  x->left = y->right;
  }
  else{
  x->right = y->right;
  }
 _size--;
 delete y;
 return true;
 }
 else if(y->left!= NULL&&!y->rightThread)
{
  if(isleft)
  {
   x->left=y->left;
   Elem* hold;
   hold=y->left;
  
   while(!hold->rightThread)
   {	
	hold=hold->right;
   }
	hold->right=x;
  }
  else
  {
  x->right=y->left;
  Elem* hold;
  hold=y->left;
  
  while(!hold->rightThread)
   {
	hold=hold->right;
   }
    hold->right=y->right;
  }
  _size--;
  delete y;
  return true;
}
else if(y->left==NULL && y->rightThread){
 if(isleft)
 {
  x->left=0;
 }
 else
 {
  x->right=y->right;
  x->rightThread=true;
 }
 _size--;
 delete y;
 return true;
 }
 else
{
 Elem* q=y;
 Elem* r=y->right;
 while(r->left!=NULL){
 q=r;
 r=r->left;
 }
 Elem* a;
  Elem* b;
 a=y->left;
 b=y->right;
  y->left=r->left;
  y->right=r->right;
 r->left=a;
 r->right=b;
  if(q==y)
  {
   r->right=y->right;
   if(r->rightThread)
   {
	r->rightThread=true;
   }
 else{
  r->right=y->right;
  }
 }
 else{
  if(!r->rightThread){
   q->left=y->right;
 }
 else{
  q->left=0;
 }
 r->rightThread=false;
 }
if(isleft){
  x->left=r;
 } 
 else{
   x->right=r;
 }
  r->rightThread=false;
  _size--;
  delete y;
  return true;
  }
  return false;
}
// return an iterator pointing to the end if the element is not found,
// otherwise, return an iterator to the element
template<typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::find(KEY key) const
{
 Map<KEY, T>::Iterator i=begin();
 while (i!=end()){
 if(i-> key==key){
   break;
 }
 i++;
 }return i;
  return i;
}
//overloaded subscript operator
template <typename KEY, typename T>
T& Map<KEY, T>::operator[](KEY key)
{
  Map::Iterator it=find(key);
  T val;
 if(it!=end())
 {
  return it->data;
 } 
 _size++;
 insert( _root->left, key, val, _root );
 it=find(key);
 return it->data;
}
template <typename KEY, typename T>
ostream& Map<KEY, T>::dump(ostream& k) const{
if ( _root == _root->left) {
 return k;
}
 printTree(k, 0, _root->left);
 return k;
}
template<typename KEY, typename T>
ostream& operator<< (ostream& k, const Map<KEY, T>& v){
 v.dump(k);
 return k;
}
