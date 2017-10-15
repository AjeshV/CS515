template<class T,int MAX_SIZE>
PQueue< T, MAX_SIZE >::PQueue(){
   _size = 0;
} 
template<class T,int MAX_SIZE>
void PQueue< T, MAX_SIZE >::insert(T x1){
   _size++;
   _array[_size]=x1;
   moveUp();
} 
template< class T,int MAX_SIZE >
T PQueue< T, MAX_SIZE>::findMin(){
   return _array[1];
} 
template< class T,int MAX_SIZE >
void PQueue< T, MAX_SIZE>::deleteMin(){
	_array[1]=_array[_size];
	_size--;
	moveDown(1);
}
template< class T,int MAX_SIZE >
bool PQueue< T, MAX_SIZE>::isEmpty(){
  if(_size==0){
  return true;}
   return false;
}
template< class T,int MAX_SIZE >
int PQueue< T, MAX_SIZE>::size(){
	return _size;
}
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE>::moveDown(int a1){
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
template<class T,int MAX_SIZE>
void PQueue< T,MAX_SIZE>::moveUp(){
 int pos=_size;
 while(pos>1&&*_array[pos]<*_array[pos/2]){
  T end=_array[pos];
  _array[pos]=_array[pos/2];
  _array[pos/2]=end;
  pos=pos/2;
	}
}