/* CS515 Assignment 1
   File: calSpan.cpp 
   Name: Ajesh Vijay Vijayaragavan
   Section: 1
   Date: 09/08/2017
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
#include <type_traits>
using namespace std;

int main(int argc, char *argv[])
{
vector<string> str1;
ifstream in(argv[1]);
if (argc < 2 || argc > 2)
{
	cout << "Wrong number of arguments" << endl;
	exit(1);
}
else if (!in.is_open())
{
	cout << "Error opening file" << endl;
        exit(1);
}
string str2;
while (in >> str2)
{
  str1.push_back(str2);
}
in.close();

//cout << str1[0] << str1[1] << str1[2];

LOOP:
string n;
cout << "Which minute to query?";
getline (cin,n);

while(n.size()==0)
{
	if (n.empty())
	{
		cout << "Which minute to query?";
		getline (cin,n);
   	}
}
/*
string n1 (n);
size_t found1 = n1.find_first_of(" ");
if (found1!=string::npos)
{
 found1=n1.find_first_of(" ", found1+1);	
 cout << "Wrong number of arguments" << endl;
 goto LOOP;
}
*/
string n3 (n);
size_t found2 = n3.find_first_of("xiXI");
if (found2!=string::npos)
{
 found2=n3.find_first_of("xiXI", found2+1);
 //cout << "Exit" << endl;
 exit(1);
}

string n4 (n);
size_t found3 = n4.find_first_of("a.");
if (found3!=string::npos)
{
 found3=n4.find_first_of("a.", found3+1);
 cout << " Wrong query input." << endl;
 goto LOOP;
}

int n2 = stoi(n);
while (str1.size()<=n2)
{
     cout << " Query minute out of range" << endl;
     goto LOOP;
}


for (int i=n2; i<str1.size(); i++)
{
  string str4 (str1[i]);
for (int j=0; j<20; j++)
{
  string list[20] = {"100.1", "-100.1", "50", "-101", "200", "10", "-1", "139.1"};  
   if (str4 == list[j])
   {
	cout << " Data at minute " << n2 << " is corrupted." << endl;
        goto LOOP;	
   }	   
}
}

for (int i=n2; i<str1.size(); i++)
 {
  string str (str1[i]);
  size_t found = str.find_first_of("abcdfghjklmnopqrsuvwyz*+");
   if (found!=string::npos)
   { 
     found=str.find_first_of("abcdfghjklmnopqrsuvwyz*+",found+1);   
     cout << " Data at minute " << n2 << " is corrupted." << endl;
     goto LOOP; 
   }
   else
   {
    float num1 = atof(str1[i].c_str());
    if (num1 < -100 || num1 > 100)
    {
      cout << " Data at minute " << n2 << " is corrupted." << endl;
      goto LOOP;
    }
   }
 }
 
int k = 0;
for (int i=n2; i>=0; i--)
{
  if (i==0)
  {
   k++;  
   cout << " Data at minute " << n2 << " is a " << k << "-minute(s) high." << endl;
   goto LOOP;
  }
  else
  {
   float num2 = atof(str1[n2].c_str());
   float num3 = atof(str1[i].c_str());
   if (num2 < num3)
   {
     cout << " Data at minute " << n2 << " is a " << k << "-minute(s) high." << endl;
     goto LOOP;
   }
  }
/*  
   else if (str1[n2] < str1[i])
   {	    
   cout << " Data at minute " << n2 << " is a " << k << "-minute(s) high." << endl;
      //cout << i;
   goto LOOP;
  }
  */
 k++;
     //cout << k;
}
   
  
return 0;
}

