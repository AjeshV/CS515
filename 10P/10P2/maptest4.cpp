// tests for find()

#include "unorderedmap.h"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#define SIZE 100000

using namespace std;
int main(){
	UnorderedMap<string, int> m1;
	string str;
	for (int i = 0; i < SIZE; i++){
		stringstream ss;
		ss << i << ' ';
        ss >> str;
        m1.insert(str, i);
		assert(m1[str] == i);
	}
	
	assert(m1.size() == SIZE);
	for (int i = 0; i < m1.size(); i++){
		stringstream ss;
		ss << i << ' ';
        ss >> str;
		assert(m1.find(str) != m1.end());
	}
}