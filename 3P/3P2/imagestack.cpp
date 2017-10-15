/* CS515 Assignment 3
  File: imagestack.cpp
  Name: Ajesh Vijay Vijayaragavan
  Section: 2
  Date: 09/26/2017
  Collaboration Declaration: Assistance received from TA, PAC, Online resources.
*/

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
int main(int argc, char**argv)
{
 int numrows;
 int numcols;
 int max;
 int t=1;
 int k = argc-(3-t);
 int*** a = new int**[k];
 int numrowsadv, numcolsadv = 0;
 int i;
 stringstream b;
 string inputLine;
 for (i=0;i<k;i++)
 {
  ifstream infile(argv[i]);
  stringstream b;
  getline(infile,inputLine);
  if (inputLine.compare("P2")==0)
  {
	  b << infile.rdbuf();
	  b >> numrows >> numcols;
	  b >> max;
          //cout << "Version : " << inputLine << endl;
          //cout << "Width : " << numrows << endl;
          //cout << "Height: " << numcols << endl;
          //cout << "Max Value: " << max << endl;
	  int** x = new int*[numcols];
          for (int i = 0; i<=(numcols-1); i++){
          x[i]=new int[numrows];
          for (int j = 0; j<=(numrows-1);j++){
            b >> x[i][j];
         }
  }
   ofstream outfile(argv[argc-(2-t)]);
   outfile << inputLine << endl;
   outfile << numcols << " " << numrows << endl;
   outfile << max << endl; 
//  outfile.close(); 
 }
}
}
