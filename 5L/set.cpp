/*CS515 Lab 5
  File: set.cpp     
  Name: Ajesh Vijay Vijayaragavan    
  Section: 2
  Date: 10/08/2017
  Collaboration Declaration: Assistance received from TA, PAC, Online resources.
 */
#include "set.h"

Set::Set()
{
  _head = new Elem;
  _head->prev = NULL;
  _tail = new Elem;
  _tail->next = NULL;
  _head->next = _tail;
  _tail->prev = _head;
  _size = 0;
}

Set::Set(const Set &s)
{
  Elem *newNode;
  Elem *nodePtr;
  Elem *pos;

  if( !s._head )
  {
    _head = NULL;
  }
  else
  {
     _head = new Elem;
     _tail = new Elem;
     nodePtr = s._head;
     pos = _head;
  }

  while(nodePtr->next!=s._tail)
  {
      nodePtr = nodePtr->next;
      newNode = new Elem;
      newNode->info = nodePtr->info;
      pos->next = newNode;
      pos = pos->next;
  }
  pos->next=_tail;
  _tail->prev = pos;
  _size = s._size;
}

Set::~Set()
{
  destructCode();		    
}

Set&Set::operator=(const Set &rhs )
{
   if( &rhs != this)
   {
     clear();
     Elem *temp;
     temp = rhs._head->next;
     while( temp != rhs._tail )
     {
	insert( temp->info );
	temp = temp->next;
     }
     _size = rhs._size;

   }
}

void Set::insert(ELEMENT_TYPE n)
{
   if(find(n))
   {
      return;
   }
   Elem *tmp = _tail->prev;
   Elem *str1 = new Elem;
   str1 -> info = n;

   if(_head->next == _tail)
   {
     _head->next = str1;
     str1->prev = _head;
     _tail->prev = str1;
     str1->next = _tail; 
   }
   else
   {
      while((tmp -> next != _tail) && (tmp->info < str1->info))														      {
        tmp = tmp -> next;
      }
      str1->next = tmp;
      str1->prev = tmp->prev;
      tmp->prev->next = str1;
      tmp->prev = str1;
   }
   _size++;
}

void Set::erase (ELEMENT_TYPE n )
{
    if( !find(n) )
    {
       return;
    }
    Elem* tmp = _head->next;
    while(tmp != _tail)
    {
       if( tmp->info == n )
       {
	  tmp -> prev -> next = tmp -> next;
	  tmp -> next -> prev = tmp -> prev;
	  _size--;
	  delete tmp;
       }
       tmp = tmp->next;
    }
}
    
void Set::clear()
{
   Elem *current;
   Elem *next;
   current = _head->next;
   while( current != _tail )
   {
     next = current->next;
     delete current;
     current = next;
   }
   _head->next = _tail;
   _tail->prev = _head;
   _size = 0;	
}

int Set::size() const
{
   return _size;
}

bool Set::find(ELEMENT_TYPE n) const 
{
    Elem* tmp = _head->next;
    while( tmp != _tail)
    {
      if( tmp -> info != n )
      {
	   tmp = tmp->next;	
      }
      else if(tmp->info ==n) 
      {
	   return true;
      }
    }
    return false;
}

void Set::copyCode( const Set & v )
{
   _head = new Elem;
   _head->prev = NULL;
   _tail = new Elem;
   _tail->next = NULL;
   _head->next = _tail;
   _tail->prev = _head;
   _size = 0;
   Elem *newl;
   Elem *node1;
   Elem *current;
   Elem *temp;
   _head->info = v._head->info;
   _size = v._size;
   node1 = v._head;
   current = _head;

while( node1->next != _tail )
{
    node1 = node1->next;
    newl = new Elem;
    newl->info = node1->info;
    newl->prev = current;
    current->next->prev = newl;
    newl->next = current->next;
    current->next = newl;
}
}

void Set::destructCode()
{
   clear();
   delete _head;
   delete _tail;
}

bool operator==(const Set& s1, const Set& s2)
{
   if((s1.size() == s2.size()) && (s1._head->info == s2._head->info))
   {
	 return true;
   }
   else
   {
	return false;
   }
}

ostream& operator<< (ostream& os, const Set& s)
{
   s.dump( os, s);
}

ostream& Set::dump(ostream& out, const Set &cur)const
{
   Elem *hold = cur._head;
   while( hold != _tail )
   {
      hold = hold->next;
      out << hold->info << " ";
   }
   return out;
}
