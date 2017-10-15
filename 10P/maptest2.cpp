// tests for insert with []

#include "unorderedmap.h"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SIZE 1000


int main(){
	UnorderedMap<string, int> m;
    string str;
    stringstream ss;
    
    for (int i=0; i<SIZE; i++){
        ss << i << ' ';
        ss >> str;
        m[str] = i;
    }
    
    assert(m.size()==1000);
    for (int i=0; i<SIZE; i++){
        str = "";
        ss << i << ' ';
        ss >> str;
        assert(m[str]==i);
    } 
}