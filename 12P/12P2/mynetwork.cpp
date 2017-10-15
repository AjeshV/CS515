/** CS515 Assignment 12
  * File: mynetwork.cpp
  * Name: Ajesh Vijay Vjayaragavan
  * Section: 1
  * Date: 05/04/2017
  * Collaboration Declaration: Assistance received from TA, PAC, online resources. 
*/  
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <stack>
#include <list>
#include "DisjointSet.h"
using namespace std;
DisjointSet< string > forests;
map< pair< string, string >, int > graph;
map< string, list< string > > mst;
list< pair< string, string > > vertices;
void findPath(string output,string v,string end,map< string, bool> visited ){
 if(v==end){
	cout<< output << endl;
 }
  list<string>::iterator neighbor=mst[v].begin();
  for(neighbor=mst[v].begin();neighbor!=mst[v].end();neighbor++){
    string neigh=*neighbor;
     if(visited[neigh]==false){
	visited[neigh]=true;
    findPath(output + "\n" + "   To: " + neigh, neigh, end, visited);}
 }
}void kruskal(){
 list< pair< string, string > >::iterator it;
 while(!vertices.empty( )){
 	pair< string, string > minimal=vertices.front( );
  for(it=vertices.begin( );it!=vertices.end( );it++){
   if(graph[*it]<graph[minimal]){
     minimal=*it;}
  }
  vertices.remove(minimal);
  string first=minimal.first;
  string second=minimal.second;
  if(forests.findSet(first)!=forests.findSet(second)){
   mst[first].push_back(second);
   mst[second].push_back ( first );
   forests.unionSets(first,second);}
  }
}void printErr(){
   cout << "Cannot find node. ";
   cout << " Available nodes are:" <<endl;
   map< string, list<string> >::iterator strs = mst.begin();	
   while(strs!=mst.end()){
   cout<< "  " << strs->first <<endl;
   strs++;}
}
void ping( string start, string find ){
   string defStart=forests.findSet( start );
   string path=forests.findSet( find );		
   if(path==defStart){
	   map<string, bool> visited;
  visited[start]=true;
  string out="";
  cout << " From: ";
  findPath(start,start,find,visited);
   }else{
  printErr();
 }
}int main(int argc,char *argv[ ]){
  ifstream infile(argv[1]);
  if(!infile){
    cout << "Input file doesn't exist" << endl;
    return 1;
   }string input="";
   string start="";
   int count=0;
while(getline(infile,input)){
  stringstream ss(input);
  string router1;
  string router2;
  int weight=0;
  ss >> router1;
  ss >> router2;
  ss >> weight;
   if(count==0){
	start=router1;
   }  forests.createSet(router1);
   forests.createSet(router2);
     pair< string, string > ins( router1, router2 );
    graph[ins]=weight;
   vertices.push_front(ins);
     count++;
  }kruskal( );
     string cmdLine="";
   //cout << endl;
   stack<string> shell;
   shell.push(start);
   cout<<"<" << shell.top() << "># ";
   while( getline(cin,cmdLine)){
   	   stringstream stream(cmdLine);
       string cmd="";
    stream >> cmd;
	 if(cmd=="ping"){
		string find;
	stream >> find;
        	ping(shell.top( ),find);
	}if(cmd=="ssh"){
		string find;
	  stream >> find;
  if(mst.find(find)!=mst.end( )){
    shell.push(find);
   }else{
   printErr( );}
   }	if(cmd=="exit") {
	shell.pop( );
	if(shell.empty()){
        	return 0;
	}
	}cout<< "<" << shell.top( ) << "># ";
	}
	return 0;
}
