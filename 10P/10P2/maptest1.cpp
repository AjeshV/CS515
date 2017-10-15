// tests for insert()

#include "unorderedmap.h"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	UnorderedMap<string, int> m;
    string str;
    stringstream ss;
    int n = 1000;
    
    for (int i=0; i<n; i++){
        ss << i << ' ';
        ss >> str;
        assert( m.insert(str, i)==true);
    }
    assert(m.size()==1000);
}