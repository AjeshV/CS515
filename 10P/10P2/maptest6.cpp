// tests cases for erase() method

#include "unorderedmap.h"
#include <cassert>
#include <limits>
#include <cstddef>
#include <iostream>
using namespace std;


int main(){
	UnorderedMap<int,int> m1;
    m1.insert(40,1);
    m1.insert(12,1);
    m1.insert(6,1);
    m1.insert(78,1);
    m1.insert(45,1);
    m1.insert(33,1);
    m1.insert(21,1);
    m1.insert(4,1);
    m1.insert(29,1);
    m1.insert(9,1);
    m1.insert(5,1);
    m1.insert(42,1);
    m1.insert(23,1);
    m1.insert(11,1);
    m1.insert(64,1);
    m1.insert(46,1);
    m1.insert(20,1);
    m1.insert(13,1);
    m1.insert(28,1);
    m1.insert(54,1);
    m1.insert(77,1);
    m1.insert(85,1);
    m1.insert(14,1);
    m1.insert(17,1);
    m1.insert(15,1);
    
    assert(m1.size()==25);
    
    // test output
    // cout << m1;
    
   
    UnorderedMap<int, int>::Iterator it;
   
    // erase elements not in the set
    
    m1.erase(62);
    assert(m1.size()==25);
    
    m1.erase(19);
    assert(m1.size()==25);
    
    m1.erase(100);
    assert(m1.size()==25);
    
    m1.erase(1);
    assert(m1.size()==25);
    
    m1.erase(numeric_limits<int>::max());
    assert(m1.size()==25);
    
    // erase elements in the set
    m1.erase(14);
    assert(m1.size()==24);
   
    m1.erase(17);
    assert(m1.size()==23);

    m1.erase(15);
    assert(m1.size()==22);
    
    m1.erase(5);
    assert(m1.size()==21);
   
    m1.erase(12);
    assert(m1.size()==20);
    
    m1.erase(85);
    assert(m1.size()==19);
    
    m1.erase(77);
    assert(m1.size()==18);
   
    m1.erase(54);
    assert(m1.size()==17);
    
    m1.erase(28);
    assert(m1.size()==16); 
    
    m1.erase(13);
    assert(m1.size()==15);
   
    m1.erase(20);
    assert(m1.size()==14);
   
    m1.erase(40);
    assert(m1.size()==13);
   
    m1.erase(46);
    assert(m1.size()==12);
    
    m1.erase(64);
    assert(m1.size() == 11);
    
    m1.erase(11);
    assert(m1.size() == 10);
    
    m1.erase(23);
    assert(m1.size() == 9 );
    
    m1.erase(9);
    assert(m1.size()==8);
    
    m1.erase(33);
    assert(m1.size()==7);
    
    m1.erase(78);
    assert(m1.size()==6);
   
    m1.erase(45);
    assert(m1.size()==5);
  
    m1.erase(21);
    assert(m1.size()==4);
    
    m1.erase(4);
    assert(m1.size()==3);
    
    m1.erase(29);
    assert(m1.size()==2);
   
    m1.erase(6);
    assert(m1.size() == 1);
    
    m1.erase(42);
    assert(m1.size() == 0);
 
}
