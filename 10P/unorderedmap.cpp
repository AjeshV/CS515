/** CS515 Assignment 10
  * File: unorderedmap.cpp
  * Name: Ajesh Vijay Vijayaragavan
  * Section: 1
  * Date: 04/20/2017
  * Collaboration Declaration: Assistance received from TA, PAC and Online resources.
  */
// Below are the stubs for SOME methods
// Make sure all methods in unorderedmap.h are implemented
template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::UnorderedMap(){
 tablesize=nextPrime(101);
 array=new Entry*[tablesize];
 for(int i=0;i<tablesize;i++){
 array[i]=new Entry();
 array[i]->next=NULL;
 }entrysize=0;
}
template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::UnorderedMap(const UnorderedMap& rhs){
 for(int i=0;i<tablesize;i++){
  rhs.array[i]=array[i];
 }
}
template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>&UnorderedMap<KEY, T, H>::operator=(const UnorderedMap& rhs){
}
template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::~UnorderedMap(){
for(int i=0;i<tablesize;i++){
   Entry* r1=array[i]->next;
   Entry* s;
 while(r1!=NULL){
  s=r1;
  r1=r1->next;
  delete s;
  }delete array[i];
 }delete [] array;
}
template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::insert(const KEY & newkey, const T & data){
 std::size_t key=H()(newkey); 
 int n1=key%tablesize;
 int loadfactor=entrysize/tablesize;
 if(loadfactor>=2){
  rehash();
 n1=key%tablesize;
}if(find(newkey)==end()){
  if(array[n1]->next==NULL){
  array[n1]->next = new Entry(newkey,data,tablesize,array,true);
  array[n1]->next->next = NULL;
}else{
  Entry *t1=new Entry(newkey,data,tablesize,array,true);
  t1->next=array[n1]->next;
  array[n1]->next=t1;
}entrysize++;
 return true;
}return false;
}
template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::erase(const KEY& x1){
 std::size_t key=H()(x1);
 int n1=key%tablesize;
 Iterator it=find(x1);
 if(it!=end()){
  Entry* r1=array[n1];
  Entry* s=array[n1]->next;
  while( array[n1]->key!=x1){
    array[n1]=array[n1]->next;
 }array[n1]->activate=false;
 entrysize--;
 return true;
}return false;
}
template <typename KEY, typename T, typename H>
void UnorderedMap<KEY, T, H>::rehash( ){
 int size=tablesize;
 tablesize=nextPrime(tablesize*2);
 Entry ** k=array;
 array=new Entry*[tablesize];
 for(int i=0;i<tablesize;i++){
	 array[i]=new Entry();
	 array[i]->next = NULL;
  }entrysize = 0;
 for(int i=0;i<size;i++){
   Entry* z=k[i];
   while(z!=NULL){
	insert(z->key,z->data);
	z=z->next;
}
}for(int i=0;i<size;i++){
  Entry* r1=k[i];
  Entry* s;
  while(r1!=NULL){
    s=r1;
   r1=r1->next;
   delete s;
 }
}delete [] k;
}
template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::find( const KEY & x ) const{
 std::size_t key=H()(x)%tablesize; 
 Entry *a=array[key];
 while(a){
  if(x==a->key){
     break;
 }else{
  a=a->next;
 }
}if(a!=NULL){
  return Iterator(a);
}else{
 return end();	
}
} 
template<typename KEY, typename T, typename H>
T& UnorderedMap<KEY, T, H>::operator[](const KEY & k){
 static T t1;
 UnorderedMap::Iterator x2=find(k);
 if(x2!=end()){
  return x2->data;
 }
 insert(k,t1);
 x2=find(k);
 return x2->data;
}
template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::Iterator::operator++(int){
 std::size_t key=H()(_cur->key); 
 int n1=key%_cur->_tablesize;
 if(_cur->next!=NULL){
  _cur=_cur->next;
 }else{
  if(_cur->arr[n1]!=NULL){
    return Iterator(_cur->arr[n1]);
}
}return Iterator(NULL);
}
template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::begin() const{
 if(entrysize>0){
 for(int i=0;i<tablesize;i++){
 if(array[i]!=NULL){
   return Iterator(array[i]);
}
}
}return Iterator(NULL);
}
template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::end() const{
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
