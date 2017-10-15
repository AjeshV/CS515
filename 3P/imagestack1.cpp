/* CS515 Assignment 3
  File: imagestack.cpp
  Name: Ajesh Vijay Vijayaragavan
  Section: 2
  Date: 02/24/2017
  Collaboration Declaration: Assistance received from TA, PAC, Online resources.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
int main( int argc, char**argv )
{
 int col, row, g = 0;
 int arglen = argc - 2;
 string input1 = "";
 int*** b = new int**[arglen];
 for( int i = 1; i <= arglen; i++ )
 {
    ifstream input( argv[i] );
    getline( input, input1 ); 
    stringstream stream;
    stream << input.rdbuf();
    stream >> col >> row;
    stream >> g;
    int** arr = new int*[col];
    for( int c = 0; c < col; c++ )
    {
     arr[c] = new int[row];
     for( int r = 0; r < row; r++ )
     {
 	stream >> arr[c][r];
    }
    }
	b[i-1] = arr;
 }

 ofstream outputFile( argv[argc-1] );	
 outputFile << input1 << endl;
 outputFile << col << " " << row << endl;
 outputFile << g << endl;

 float** result = new float*[col];
 int** temp;
 for( int i = 0; i < col; i++ )
 {
   result[i] = new float[row];
   for( int j = 0; j < row; j++ )
 {
    int sum = 0;
    int mean = 0;
    for( int k = 0; k < argc - 2; k++ )
    {
      int condition = arglen / 2;
      condition += 1;
      for( int jj = 0; jj < condition; jj++ )
      {
       int min = jj;
       for( int l = jj; l < arglen; l++ )
      {	
     if( b[l][i][j] < b[min][i][j] )
      {
       min = l;
      }
    }
    if( jj != min )
    {
      temp = b[jj];
      b[jj] = b[min];
      b[min] = temp;
    }
    }
   }	
if( arglen % 2 == 1)
{
   result[i][j] = b[arglen/2][i][j];
}
else
{
  float f = 0.0;
  int i1 = 0;
  int i2 = 0;
  i1 = b[(arglen/2)][i][j];
  i2 = b[(arglen/2-1)][i][j];
  f = (i1 + i2)/2;
  result[i][j] = f;
}
outputFile << (int)result[i][j] << " ";
}
}
outputFile.close();
for( int j = 0; j < col; j++ )
{
  delete[] result[j];
}
  delete[] result;

  for(int i = 0; i < arglen; i++ )
{
   for(int j = 0; j < col; j++ )
   {
    delete[] b[i][j];
   }
    delete[] b[i];
}
 delete[] b;
 return 0;	
}
