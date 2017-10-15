/* CS515 Assignment 1
   File: calSpan.cpp 
   Name: Ajesh Vijay Vijayaragavan
   Section: 1
   Date: 02/09/2017
   Collaboration Declaration:
          Assistance received from TA, PAC and online resources etc.
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <cwctype>
#include <cstddef>
 using namespace std;

int main(int argc, char *argv[])
{
string n;	
vector<string> str1;
ifstream in(argv[1]);
if (!in.is_open())
{
	cout << "Error opening file" << endl;
}
string str2;
while (in >> str2)
{
  str1.push_back(str2);
}
in.close();

cout << "Which minute to query?" << endl;
getline (cin,n);

while(n.size()==0)
{
	if (n.empty())
	{
		cout << "Which minute to query?" << endl;
		getline (cin,n);
   
	}
}

while (n == "Exit\n")
{
	exit(1);
}

string n1 (n);
size_t found1 = n1.find_first_of(" ");
if (found1!=string::npos)
{
 found1=n1.find_first_of(" ", found1+1);	
 cout << "Wrong number of arguments" << endl;
 exit(1);
}




int n2 = stoi(n);

while (str1.size()<n2)
{
     cout << "Query minute out of range." << endl;
     break;
}

//for (int i=0; i<str1.size(); i++)
//{
//char j = stoc(str1[i]);	
//char f[i] = {j};
//cout << f[i] << endl;

/*
string str (str1[i]);
size_t found = str.find_first_of("abc*");
while (found!=string::npos)
{
	str[found]='&';
	found=str.find_first_of("abc*",found+1);
}
cout << str << endl;
}
*/
//string e = 00.0;
//string f = 99.9;
//int i=n2;
//string list[20] = {"100.1", "-100.1", "50"};

for (int i=n2; i<str1.size(); i++)
{
  string str4 (str1[i]);
for (int j=0; j<20; j++)
{
   string list[20] = {"100.1", "-100.1", "50", "-101", "200", "10"};  
   if (str4 == list[j])
   {
	cout << "Data at minute " << n2 << " is corrupted." << endl;
        exit(1);	
   }	   
}
}

 for (int i=n2; i<str1.size(); i++)
 {
  string str (str1[i]);
  size_t found = str.find_first_of("abcdefghijklmnopqrstuvwxyz*+");
   if (found!=string::npos)
   { 
     found=str.find_first_of("abcdefghijklmnopqrstuvwxyz*+",found+1);   
     cout << "Data at minute " << n2 << " is corrupted." << endl;
     exit(1); 
   }
   else
   {
   int x = i+1;	 
   cout << "Data at minute " << n2 << " is a " << x << "-minute(s) high." << endl;
   exit(1);
   }
 }
return 0;
}

