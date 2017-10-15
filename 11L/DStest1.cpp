#include "DisjointSet.h"
#include <iostream>
#include <cassert>
using namespace std;
int main(){
    DisjointSet<int> s;
     for(int j=1;j<10;j++){
		 s.createSet(j);
	 }s.unionSets(1,6);
	 s.unionSets(3,5);  
    assert(s.findSet(1)==s.findSet(6));// 1 and 6 are connected.
    assert(s.findSet(3)!=s.findSet(6));// 3 and 6 are not connected.
    assert(s.findSet(1)==s.findSet(1));// 1 and 1 are connected.
    assert(s.findSet(3)==s.findSet(5));// 3 and 5 are connected.
    assert(s.findSet(3)!=s.findSet(9));// 3 and 9 are not connected.
    DisjointSet<string> string1;
    string array1[8]={"gz","c","d","e","f","g","h","j"};
     for(int j=1;j<8;j++){
      string1.createSet(array1[j]); 
     }string1.unionSets("gz","f");
     string1.unionSets("g","h");
    assert(string1.findSet("gz")==string1.findSet("f"));// 1 and 6 are connected.
    assert(string1.findSet("g")!=string1.findSet("f"));// 3 and 6 are not connected.
    assert(string1.findSet("e")==string1.findSet("e"));// 1 and 1 are connected.
    assert(string1.findSet("g")==string1.findSet("h"));// 3 and 5 are connected.
    assert(string1.findSet("j")!=string1.findSet("gz"));// 3 and 9 are not connected.
    
}
