/* CS515 Assignment 0
File: hello.cpp
Name: Ajesh Vijay Vijayaragavan
Section: 1
Date: 02/02/2017
Collaboration Declaration:
          Assistance received from TA, PAC and online resources etc.
*/  

#include <iostream> // for cin and cout
#include <string> // for string type
using namespace std;

int main(int argc, char ** argv) {
    string name;
    cout << "What is your name?" << endl;
    getline (cin,name);
    while(name.size()==0)
    {
      if (name.empty())
    {
	  cout << "What is your name?" << endl;
          getline (cin,name);
    }
    
    }
       	cout << "Hello World!" << endl;
        cout << "Welcome to CS515, " << name << "!" << endl;
   
   
    return 0;
}

