// tests for iteration 

#include "unorderedmap.h"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;
#define SIZE 10


int main(){
	UnorderedMap<string, int> m;
	string str;
	stringstream ss;

	for (int i=0; i<SIZE; i++){
		ss << i << ' ';
		ss >> str;
		assert( m.insert(str, i)==true);
	}

	set<string> v1;
	set<int> v2;

	UnorderedMap<string, int>::Iterator it = m.begin();
	while(it !=m.end() ){
		v1.insert(it->key);
		v2.insert(it->data); 
		it++;
	}
   assert(v1.size()==SIZE); 
   assert(v2.size()==SIZE); 
}
