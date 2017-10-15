/**CS515 Lab 6     
 * File: wordfreq.cpp     
 * Name: Ajesh Vijay Vijayaragavan    
 * Section: 1
 * Date: 03/22/2017
 * Collaboration Declaration: Assistance received from TA and PAC.
 **/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <set>
#include <map>

using namespace std;
int main( int argc, char**argv )
{
  ifstream input(argv[1]);
  string w;
  int y;
  int c;
  stringstream k;
  string word;
  int year;
  string s;
  k << input.rdbuf();
  map< string, set< pair< int, int > > > a;   
  while(k >> word >> year >> c >> s)
  {
    a[word].insert(make_pair(year, c));
  }
  while(!cin.eof())
  {
   cout << "Which word starting which year? " << flush;
   cin >> w;
   cin >> y;
 for (set< pair<int,int> >::iterator it = a[w].begin(); it != a[w].end(); ++it)
 {
   if(((it->first >= y || y < year)))
   {
    cout << it->first << " " << it->second << endl;
   }
 }
  }
}

