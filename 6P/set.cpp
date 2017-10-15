/**CS515 Assignment 6
 * File: set.cpp
 * Name: Ajesh Vijay Vijayaragavan
 * Section: 1
 * Date: 03/23/2017
 * Collaboration Declaration: Assistance received from TA, PAC and Online resources. 
*/
#include <iostream>
#include <string.h>
#include "set.h"

using namespace std;
Set::Set() //empty set constructor
{
  _head=new Elem;
  _tail=new Elem;
  _head->prev=NULL;
  _tail->next=NULL;
  _head->next=_tail;
  _tail->prev=_head;
  _size = 0;
}
Set::Set(const Set &rhs) //copy constructor
{
 if(!rhs._head)
 {
  _head=rhs._head;
  _tail=rhs._tail;
 }
 else
 {
  _head=new Elem;
  _head->prev=NULL;
  _tail=new Elem;
  _tail->next=NULL;
  _head->next=_tail;
  _tail->prev=_head;
 }
 copyCode(rhs);
}
Set::~Set() //destructor
{
  destructCode();
}

Set&Set::operator=(const Set &rhs) //assignment operator
{
 if(&rhs!=this)
 {
  clear();
  copyCode(rhs);
 }
 return *this;
}
//-----Basic operations-----
void Set::insert(ELEMENT_TYPE x1) // insert an element
{
 if(find(x1)!=end())
 {
  return;
 }
 Elem *a=new Elem;
 Elem *b=_tail->prev;
  a->info=x1;
  if(_head->next==_tail)
  {
	_head->next=a;
	a->prev=_head;
	_tail->prev=a;
	a->next=_tail; 
  }
  else
  {
  while(b->next!=_head && b->info > a->info )
  {
	b = b->prev;
  }
	a->next=b->next;
	a->prev=b;
	b->next->prev=a;
	b->next=a;
  }
 _size++;
}
void Set::erase (ELEMENT_TYPE x1) // remove an element from set
{
 if(find(x1)==end())
 {
  return;
 }
 Elem* b=_head->next;
 while(b!=_tail)
 {
  if(b->info==x1)
  {
	b->prev->next=b->next;
	b->next->prev=b->prev;
	_size--;
	delete b;
	return;
  }
  b = b->next;
  }	
}
void Set::clear() // remove all elements from set
{
 Elem *a;
 Elem *next;
 a = _head->next;
 while(a!=_tail)
  {
	next=a->next;
	delete a;
	a=next;
  }
  _head->next=_tail;
  _tail->prev=_head;
  _size=0;
}
int Set::size() const //return size of the set
{
 return _size;
}
//-----Iterators-----
Set::Iterator Set::find(ELEMENT_TYPE x1) const //return an iterator to the element if val is found, or set::end() otherwise. 
{
 Set::Iterator it=begin();
 while(it!=end())
 {
  if(*it==x1)
  {
   return it;
  }
 it++;
 }
return it;
}
Set::Iterator Set::begin() const //return an iterator pointing at the begining of the list
{
 Set::Iterator it(_head->next);
 return it;
}
Set::Iterator Set::end() const //return an iterator pointing at one element beyond the end of list
{
 Set tmp;
 Iterator it(_tail);
 return it;
}
Set::Reverse_Iterator Set::rbegin() const //return an reverse iterator pointing at the reverse beginning of the list
{
 Set::Reverse_Iterator it(_tail->prev);
 return it;  
}
Set::Reverse_Iterator Set::rend() const //return an reverse iterator pointing at one element beyond the beginning of list
{
 Set::Reverse_Iterator it(_head);
 return it;
}
//elements are output as a single white space delimited 
//
//-----Constructors-----
Set::Iterator::Iterator() //construct a null iterator
{
 _cur=NULL;
}
Set::Iterator::Iterator(Elem *cur) //construct an iterator given pointer to Elem 
{
 _cur=cur;
}
//-----Overloaded operators-----
ELEMENT_TYPE& Set::Iterator::operator*() //dereference
{
 return _cur->info;
}
Set::Iterator Set::Iterator::operator++(int) //post-increment operator
{
 Iterator it( _cur );
 _cur=_cur->next;
return it;
}   
Set::Iterator Set::Iterator::operator--(int) //post-decrement operator 
{
 _cur=_cur->prev;
 Iterator it(_cur);
 return it;
}
bool Set::Iterator::operator==(Iterator it) const //equality operator
{
 if(_cur == it._cur)
 {
  return true;
 }
 else
 {
  return false;
 }
}
bool Set::Iterator::operator!=(Iterator it) const //inequality operator
{
 if(_cur != it._cur)
 {
  return true;
 }
 else
 {
  return false;
 }
}
//-----Constructors-----
Set::Reverse_Iterator::Reverse_Iterator() //construct a null iterator
{
 _cur=NULL;
}
Set::Reverse_Iterator::Reverse_Iterator(Elem *cur) //construct an iterator given pointer to Elem
{
 _cur=cur;
}
ELEMENT_TYPE& Set::Reverse_Iterator::operator*() //dereference
{
 return _cur->info;
}
Set::Reverse_Iterator Set::Reverse_Iterator::operator++(int) //post-increment operator  
{
 _cur=_cur->prev;
 Reverse_Iterator it(_cur);
 return it;
}
Set::Reverse_Iterator Set::Reverse_Iterator::operator--(int) //post-decrement operator       
{
  _cur=_cur->next;
  Reverse_Iterator it(_cur);
  return it;
}
bool Set::Reverse_Iterator::operator==(Reverse_Iterator it) const //equality operator
{
 return _cur == it._cur;	
}
bool Set::Reverse_Iterator::operator!=(Reverse_Iterator it) const //inequality operator
{
 return _cur != it._cur;
}
void Set::copyCode(const Set & v)  //common code for copy constructor and assignment
{
 Set::Iterator it;
 for(it=v.begin();it!=v.end();it++)
 {
  insert(*it);
 }
 _size=v._size;
}
void Set::destructCode() //common code for deallocation
{
 clear();
 delete _head;
 delete _tail;
}
ostream& Set::dump(ostream& out, const Set& v) //output set elements
{
 Set::Iterator it;
 for(it=v.begin();it!=v.end();it++)
 {	
  out << *it << " ";
 }
 return out;
}
Set operator&(const Set& a, const Set& b) //set intersect
{
 Set::Iterator ity=a.begin();
 Set::Iterator itz=b.begin();
 Set x;
while(ity!=a.end()&&itz!=b.end())
 {
  if(*ity==*itz)
  {
   x.insert(*ity);		
  }
  ity++;
  itz++;
 }	
 return x;
}
Set operator|(const Set& a, const Set& b) //set union
{
 Set::Iterator ity=a.begin();
 Set::Iterator itz=b.begin();
 Set x;
 while(ity!=a.end()&&itz!=b.end())
 {
  x.insert(*ity);
  x.insert(*itz);		
  ity++;
  itz++;
 }
 return x;
}
Set operator-(const Set& a, const Set& b) //set difference
{
 Set intersection=a & b;
 Set::Iterator ity=a.begin();
 Set::Iterator it_intersect=intersection.begin();
 Set x;
 while(ity!=a.end())
 {
  while(it_intersect!=intersection.end())
  {
  if(*ity!=*it_intersect)
  {
   x.insert(*ity);	
  }
  it_intersect++;
 }	
 ity++;	
}
return x;
}

bool operator==(const Set& a, const Set& b) //set equality
{
 if(a.size()!=b.size())
 {
  return false;
 }
 Set::Iterator ity=a.begin();
 Set::Iterator itz=b.begin();
 while(ity!=a.end() && itz!=b.end())
 {
 if(*ity!=*itz)
 {
  return false;
 }
 ity++;
 itz++;
}
 return true;
}       
