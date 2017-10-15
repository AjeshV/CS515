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
	if (origRoot == 0)
		newRoot = 0;
	else{
		newRoot = new Elem;
		newRoot->key = origRoot->key;
		newRoot->data = origRoot->data;
		newRoot->rightThread = origRoot->rightThread; 
		copyCode(newRoot->left, origRoot->left);
		if (!origRoot->rightThread) 
			copyCode(newRoot->right, origRoot->right);
	}
}  

//destructor
template<typename KEY, typename T>
Map<KEY, T>::~Map()
{
	if(_root->left != _root)
		destructCode( _root->left );
	delete _root;
}

// common code for deallocation
template<typename KEY, typename T>
void Map<KEY, T>::destructCode(Elem *& p)
{
	if( p->left != NULL )
	{
		destructCode( p->left );
	}
	if( p->right != NULL && !p->rightThread )
	{
		destructCode( p->right );
	}
	delete p;
}

// helper method for inserting record into tree.
template<typename KEY, typename T>
bool Map<KEY, T>::insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft )
{
	// Elem* cur = root->left;
	// Elem* parent = cur;

	// while( cur != NULL )
	// {
	// 	if( key < cur->key )
	// 	{
	// 		parent = cur;
	// 		cur = cur->left;
	// 	}
	// 	else
	// 	{
	// 		parent = cur;
	// 		cur = cur->right;
	// 	}
	// }

	if (root == _root || root == 0 ) {
        root = new Elem;
        root->data = data;
        root->key = key;
        root->left = 0;
        root->right = lastLeft;
        root->rightThread = true;
      //  cout << "first" << endl;
        return true;
    }
    
    if (key == root->key){
        return false;
    }
    // insert at left
    if (key < root->key)
    {
    	return insert( root->left, key,data,root );
    	//cout << "first" << endl;	
    }

    // insert at right
    if (!root->rightThread){
         
        return insert(root->right, key, data, lastLeft);
       // cout << "not right thread" << endl;
        //return false;
    } 
    else {  // current's right is a thread; add a new node
        root->rightThread = false;
        root->right = new Elem;
        root->right->data = data;
        root->right->key = key;
        root->right->left = 0;
        root->right->right = lastLeft;
        root->right->rightThread = true;
       // cout << "current's right is a thread" << endl;
        return true;
    }

}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::begin() const {  // return the left most (smallest) tree node
	// fill in here
	Elem *temp = _root;
	while( temp->left != NULL && temp->left != _root )
	{
		temp = temp->left;
	}
	Map::Iterator itr( temp );
	return itr;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::end() const {  // return the dummy root node
	// fill in here
	Map::Iterator itr( _root );
	return itr;
} 

 
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::Iterator::operator++(int){
	// fill in here
	//cout << "cur right " << _cur->rightThread << endl;
	//cout << "left " << _cur->left->key << endl;
	//cout << "right " << _cur->right->key << endl; 
	if(_cur->right==0) {
		Iterator itr(_cur);
		return itr;	
	} 
	if(_cur->rightThread)
	{
		_cur=_cur->right;
	}
	else
	{
		_cur = _cur->right;
		while( _cur->left != 0)
		{
			_cur = _cur->left;
		}
	}
	
	Iterator itr( _cur);
	//_cur = _cur->next;
	
	return itr;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Elem& Map<KEY, T>::Iterator::operator*(){ 
	// fill in here
	return *_cur;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Elem* Map<KEY, T>::Iterator::operator->(){ 
	// fill in here
	return _cur;
}

template <typename KEY, typename T>
Map<KEY, T>& Map<KEY, T>::operator=(const Map<KEY, T> &rhs){

if( &rhs != this)
{
Elem * newRoot = rhs._root;
copyCode( newRoot, _root);
}
return *this;
}

// assignment operator
template<typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator==(Iterator it)
{
	return _cur->key == it->key;
}

template<typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator!=(Iterator it)
{
	if( _cur != it._cur )
    {
    	return true;
    }
  		return false;
}

template <typename KEY, typename T>
int Map<KEY, T>::size() const{
	return _size;
}

// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
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


// insert an element into the Map; return true if successful
template<typename KEY, typename T>
bool Map<KEY, T>::insert(KEY key, T value )
{
	 if (insert(_root->left, key, value, _root)){
        _size++;
        return true;
    }
    return false;
}

// remove an element from the Map; return true if successful
template<typename KEY, typename T>
bool Map<KEY, T>::erase(KEY key)
{
	Elem* lroot = _root->left;
	Elem* parent = _root;
	bool isleft;
	//cout << "Hello key " << key << endl;
	if(find(key) != end() )
	{
		while( lroot && lroot != _root )
		{
			//cout << "ROOT KEY " << lroot->key << endl;
			if(key < lroot->key)
			{
				parent = lroot;
				isleft = true;
				lroot = lroot->left;
			}
			else if( key > lroot->key && lroot->rightThread)
			{
				parent = lroot;
				isleft = false;
				lroot = lroot->right;
			}
			else 
			{
				break;
			}
		}
	}
	else
	{
		return false;
	}
	//cout << "parent " << parent->key << endl;
	
	if(!lroot || lroot == _root )
	{
		return false;
	}
	//right child case
	if( lroot->left == NULL && !lroot->rightThread)
	{
		if(isleft)
		{
			parent->left = lroot->right;
		}
		else// if(parent->key < lroot->right->key )
		{
			parent->right = lroot->right;
		}
		_size--;
		delete lroot;
		return true;
	}
	//left child case
	else if( lroot->left != NULL && !lroot->rightThread )
	{
		
		if(isleft)
		{
			parent->left = lroot->left;
			Elem* hold;
			hold = lroot->left;
			while(!hold->rightThread)
			{	
				//cout<<">"<<endl;
				hold = hold->right;
			}
			hold->right = parent;
		}
		else// if(parent->key < lroot->left->key )
		{
			parent->right = lroot->left;
			Elem* hold;
			hold = lroot->left;
			while(!hold->rightThread)
			{
				//cout<<"<"<<endl;
				hold = hold->right;
			}
			hold->right = lroot->right;
		}
		_size--;
		delete lroot;
		return true;
	}
	//leaf node case
	else if(lroot->left == NULL && lroot->rightThread)
	{
		if( isleft )
		{
			parent->left = 0;
		}
		else// if(key > parent->key )
		{
			parent->right = lroot->right;
			parent->rightThread = true;
		}
		_size--;
		delete lroot;
		return true;
	}
	//two children case
	else //if(lroot->left != NULL && lroot->right != NULL )
	{
		Elem* sp = lroot;
		Elem* s = lroot->right;
		
		while( s->left != NULL )
		{
			sp = s;
			s = s->left;
		}
		Elem* ltemp;
		Elem* rtemp;
		ltemp = lroot->left;
		rtemp = lroot->right;
		lroot->left = s->left;
		lroot->right = s->right;
		s->left = ltemp;
		s->right = rtemp;
		
		// if( lroot->right->key > lroot->key )
// 		{
// 			lroot = lroot->right;
// 		}
// 		else
// 		{
// 			lroot = lroot->left;
// 		}
		if(sp == lroot)
			{
				s->right = lroot->right;
				if(s->rightThread){
					s->rightThread = true;
				}
				else{
					s->right=lroot->right;
				}
			}
			else
			{
				if(!s->rightThread){
					sp->left = lroot->right;
				}
				else{
					sp->left=0;
				}
				s->rightThread = false;
			}
			
		if( isleft )
		{
			parent->left = s;
			
		}
		else
		{
			parent->right = s;
		}
		s->rightThread = false;


		_size--;
		delete lroot;
		return true;
	}
	return false;
}

// return an iterator pointing to the end if the element is not found,
// otherwise, return an iterator to the element
template<typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::find(KEY key) const
{
	// Elem *hold = _root->left;
// 	while( hold )
// 	{
// 		if( key < hold->key )
// 		{
// 			hold = hold->left;
// 		}
// 		else if( key > hold->key && !hold->rightThread )
// 		{
// 			hold = hold->right;
// 		}
// 		else
// 		{
// 			break;
// 		}
// 	}
// 	Map::Iterator itr( hold );
// 	if( hold == NULL )
// 	{
// 		itr = end();
// 	}
// 	return itr;
	Map<KEY, T>::Iterator iter = begin();
    while (iter != end()){
    	if(iter-> key == key){
        	break;
        }
        iter++;
    }
	return iter;
}

//overloaded subscript operator
template <typename KEY, typename T>
T& Map<KEY, T>::operator[](KEY key)
{
	 Map::Iterator itr = find(key);
	 T val;
	
	 if( itr != end() )
	 {
	 	//_size++;
	 	return itr->data;
	 }
	_size++;
	insert( _root->left, key, val, _root );
	itr = find(key);
	return itr->data;
}

// outputs information in tree in inorder traversal order
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