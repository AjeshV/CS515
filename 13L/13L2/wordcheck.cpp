/** CS515 Lab 13
  * File: wordcheck.cpp
  * Name: Ajesh Vijay Vjayaragavan
  * Section: 1
  * Date: 05/09/2017
  * Collaboration Declaration: Assistance received from TA, PAC, online resources. 
*/ 
#include <iostream>
#include <sstream>
#include <cstring>
#include <set>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
using namespace std;
bool isChar( string s );
int main(int argc, char**argv){
  ifstream file;
  file.open("/usr/share/dict/words");	
  string input;
   string input1;
   stringstream str;
  string a0;
  string a1;
  string a2;
  string a3;
   string b0;
   string b1;
   string b2;
   string b3;
   int total;
    map< string, set< string > > map2[4];
	set<string> set2;
	while(file>>input){
	 transform (input.begin(),input.end(),input.begin(),::tolower);
    if(input.length()==4&&!isChar(input)){
 	  a0=input;
	  a0.erase(0,1);
	  map2[0][a0].insert(input);
	  a1=input;
	  a1.erase(1,1);
	  map2[1][a1].insert(input); 
	  a2=input;
	  a2.erase(2,1);
	  map2[2][a2].insert(input); 
	  a3=input;
	  a3.erase(3,1);
	  map2[3][a3].insert(input);}
	}while(!cin.eof()){
	cout << "Please input a 4 letter words: " << flush;
	cin >> input1;
	transform (input1.begin(),input1.end(),input1.begin(),::tolower);
	if (cin.eof()==1){
		exit(1);
	}else if(input1.length()==4){
 	  b0=input1;
	  b0.erase(0,1);
     for(set<string>::iterator it=map2[0][b0].begin();it!=map2[0][b0].end();it++){
	  if(input1!=*it){
		cout << *it << " ";
		total++;
		}
	  }b1=input1;
   b1.erase(1,1);
  for(set<string>::iterator it=map2[1][b1].begin();it!=map2[1][b1].end();it++){
	if(input1!=*it){
	  cout << *it << " ";
	  total++;}
 }b2=input1;
  b2.erase(2,1);
  for(set<string>::iterator it=map2[2][b2].begin();it!=map2[2][b2].end();it++){
	if(input1!=*it){
	  cout << *it << " ";
	  total++;}
 }b3=input1;
  b3.erase(3,1);
  for(set<string>::iterator it=map2[3][b3].begin();it!=map2[3][b3].end();it++){
	if(input1!=*it){
	  cout << *it << " ";
 	total++;
	}
}cout << endl;
 cout << "Total " << total << " words." << endl;
 }else{
 cout << "wrong length!" << endl;
}total = 0;
}
}bool isChar(string s){
  for(int i=0;i<s.length();i++){
  if(!isalpha(s[i])){
	return true;
	}
 }
}