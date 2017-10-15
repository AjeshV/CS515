/**CS515 Lab 11
 * File: connectChecker.cpp
 * Name: Ajesh Vijay Vijayaragavan
 * Section: 1
 * Date: 04/26/2017
 * Collaboration Declaration: Assistance received from TA, PAC, Online resources.
 */
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

void printGraph(map<char, list<char> > &graph)
{
    map<char, list<char> >::iterator graph_it;
    list<char>::iterator it;

    for (graph_it = graph.begin();
         graph_it != graph.end(); graph_it++)
    {
        cout << (*graph_it).first << ": "; 
        for (it = (*graph_it).second.begin();
             it != (*graph_it).second.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

int main() {
    
    // build the graph 
    map<char, list<char> > graph;
    char v1, v2, start, end;

    //Process graph input
    while((cin >> v1) && v1 != '?')
    {
        //if (!(cin >> v2))
        //    break;
        //REPLACE WITH CODE TO STORE EDGE IN GRAPH
        map<char, list<char> >::iterator it1=graph.find(v1);
	if (it1==graph.end()){
		graph[v1];
	}cin>>v2;
	graph[v1].push_back(v2);}
   // display stored graph if compiled with -DDEBUG_PRINT
#ifdef DEBUG_PRINT
    printGraph(graph);
#endif

    //Process queries
    map<char, list<char> > cr1 = graph;
    while (cin >> start >> end)
    {
        //REPLACE WITH CODE TO STORE OR PROCESS QUERIES
        //cin >> v1; //grab the next '?'
        //if (v1 != '?')
        //break;
	string path="";
	queue<char> queue;
	queue.push(start);
      while(!queue.empty()&&queue.front()!=end){
	v1=queue.front();
	path=path+v1+" ";
        queue.pop();
       int total=graph[v1].size();
   for(int j=0;j<total;j++){
    map<char, list<char> >::iterator it2=graph.find(graph[v1].front());
       if(graph[v1].front()==end){
	 while(!queue.empty()){
	queue.pop();
        }queue.push(graph[v1].front());
	 total=0;
	  }else if(it2==graph.end()){
	graph[v1].pop_front();}
       else{queue.push(graph[v1].front());
	  graph[v1].pop_front();}
        }}if (queue.front()==end){
	  cout<<"from "<<start<<" to "<<end<<" : path found."<<endl;
	  cout<<path<<end<<endl;
	}else{
	  cout<<"from "<<start<<" to "<<end<<" : path not found."<<endl;
	}graph=cr1;
	char ch1;
	cin>>ch1; 
     }
  }

