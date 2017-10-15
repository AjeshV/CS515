// Below are the stubs for SOME methods
// Make sure all methods in unorderedmap.h are implemented


// Constructs an empty unordered_map object, containing no elements and with a entry size of zero
	// Notice the hash table with a default size 101 is constructed but empty. 
template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::UnorderedMap(){
	tablesize = nextPrime(101);
	array = new Entry*[tablesize];
	for ( int i =0; i<tablesize; i++){
        array[i] = new Entry();
        array[i]->next = NULL;
    }
	
	entrysize = 0;
}
// Copy constructor The object is initialized to have the same contents and properties as the UnorderedMap object rhs. 
template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::UnorderedMap(const UnorderedMap& rhs)
{
	for ( int i =0; i<tablesize; i++){
        rhs.array[i] = array[i];
    }
}

template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>&UnorderedMap<KEY, T, H>::operator=( const UnorderedMap& rhs )
{
	
}

template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::~UnorderedMap(){

	for (int i =0; i<tablesize; i++)
    {
    	
    	Entry* hold = array[i]->next;
    	Entry* holdd;
    	while( hold != NULL )
    	{
    		holdd = hold;
    		hold = hold->next;
    		delete holdd;
    	}
         delete array[i];
    }
    delete [] array;
}

template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::insert(const KEY & newkey, const T & data){
	std::size_t key = H()(newkey); 
	int pos = key % tablesize;
	int loadfactor = entrysize/tablesize;

	if( loadfactor >= 2 )
	{
		rehash();
		pos = key % tablesize;
	}
	if( find(newkey) == end())
	{
		if( array[pos]->next == NULL )
		{
			array[pos]->next = new Entry(newkey, data, tablesize, array, true );//[newkey][data];
			array[pos]->next->next = NULL;
			//array[pos-1]->next = array[pos];
		}
		else
		{
			Entry *tmp = new Entry(newkey, data, tablesize, array, true );
			tmp->next = array[pos]->next;
			array[pos]->next = tmp;
		}
		entrysize++;
		return true;
	}
	return false;
}

template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::erase(const KEY& keyy)
{
	std::size_t key = H()(keyy); 
	int pos = key % tablesize;
	Iterator it = find( keyy );
	
	if( it != end() )
	{
		Entry* hold = array[pos];
		Entry* holdd = array[pos]->next;
		while( array[pos]->key != keyy )
		{
			array[pos] = array[pos]->next;
		}
		array[pos]->activate = false;
		entrysize--;
		return true;
	}
	return false;

}

template <typename KEY, typename T, typename H>
void UnorderedMap<KEY, T, H>::rehash( ){

	int size = tablesize;
    tablesize=nextPrime( tablesize*2 );
    Entry ** temparr = array;
    array = new Entry*[tablesize];
    for ( int i =0; i<tablesize; i++){
    	array[i]=new Entry();
        array[i]->next = NULL;//new Entry[tablesize];
    }

    //go over each element and insert in the new array from the temp array
	entrysize = 0;
    for( int i = 0; i < size; i++ )
    {
		Entry* curr = temparr[i];
		while( curr != NULL )
		{
			insert(curr->key, curr->data);
			curr = curr->next;
			//entrysize--;
		}
    }
    
    for (int i =0; i< size; i++)
    {
    	
    	Entry* hold = temparr[i];
    	Entry* holdd;
    	
    	while( hold != NULL )
    	{
    		holdd = hold;
    		hold = hold->next;
    		delete holdd;
    	}
        //delete [] temparr[i];
    }
    delete [] temparr;
}

// Searches the container for an element with the given key and returns an iterator to it if found, 
// otherwise it returns an iterator to UnorderedMap::end() (the element past the end of the container).
template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::find( const KEY & x ) const{
	//stub code; need to implement !!!
 std::size_t key = H()(x) % tablesize; 
 //int pos = key % tablesize;
 Entry *temp = array[key];
 while(temp){
  if(x == temp->key){
    break;
  }
 else{
   temp = temp->next;
 }
 }//return end();
 if(temp!=NULL){
  return Iterator(temp);
 }else{
    return end();
    //return temp;	
 }
} 

// If k matches the key of an element in the container, the function returns a reference to its mapped value.
// If k does not match the key of any element in the container, the function inserts a new element with that key 
// and returns a reference to its mapped value. Notice that this always increases the container size by one, 
// even if no mapped value is assigned to the element (the element is constructed using its default constructor).
template<typename KEY, typename T, typename H>
T& UnorderedMap<KEY, T, H>::operator[](const KEY & k){
	// stub code; need to implement !!!
	static T tmp;
	UnorderedMap::Iterator itr = find(k);
	if(itr != end() )
	{
		return itr->data;
	}
	//entrysize++;
	//cout << "l: 186" <<endl;
	insert( k, tmp );
	itr = find(k);
	return itr->data;
	
	//8P version
	// Map::Iterator itr = find(key);
// 	T val;
// 	if(itr != end()) 
// 	{
// 		return itr->data;
// 	}		
// 		insert(key,val);
// 		itr = find(key);
// 		return itr->data;
}


template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::Iterator::operator++(int){
	// stub code; need to implement !!!
	std::size_t key = H()(_cur->key); 
	int pos = key % _cur -> _tablesize;
	if( _cur->next != NULL )
	{
		_cur = _cur->next;
	}
	else
	{
		if( _cur->arr[pos] != NULL )
		{
			return Iterator(_cur->arr[pos]);
		}
	}
	return Iterator(NULL);
}

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::begin() const{
	// stub code; need to implement !!!
	//int i = array[0];
	//UnorderedMap::Iterator itr( next );
	if(entrysize > 0)
	{
		for(int i=0; i < tablesize; i++)
		{
			if( array[i] != NULL)
			{
				return Iterator(array[i]);
			}
		}
	}
	return Iterator(NULL);
}

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::end() const{
	// stub code; need to implement !!!
		//cout << "End : " << (array[tablesize+1]) << endl;
	//	return Iterator(array[tablesize+1]);
	
	return Iterator( NULL );
}

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Entry* UnorderedMap<KEY, T, H>::Iterator::operator->(){
	return _cur;
}

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Entry& UnorderedMap<KEY, T, H>::Iterator::operator*(){
	return *_cur;
}


template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::Iterator::operator!=(Iterator it){
	return _cur != it._cur;
}

template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::Iterator::operator==(Iterator it){
	return _cur == it._cur;
}

// Internal method to test if a positive number is prime (not efficient)
bool isPrime( int n ){
	if( n == 2 || n == 3 )
		return true;
	if( n == 1 || n % 2 == 0 )
		return false;
	for( int i = 3; i * i <= n; i += 2 )
		if( n % i == 0 )
			return false;
	return true;
}

// Internal method to return a prime number at least as large as n.
// Assumes n > 0.
int nextPrime( int n ){
	if( n % 2 == 0 )
		n++;
	for( ; !isPrime( n ); n += 2 )
		;
	return n;
}

