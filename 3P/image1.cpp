/* CS515 Assignmment 3
 File: image.cpp
 Name: Ajesh Vijay Vijayaragavan
 Section: 1
 Date: 02/24/2017
 Collaboration Declaration: Assistance Received from TA, PAC, Online resources.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

int** readImage( stringstream &st ,int qr, int qt, int grey );
int** processImageToNegative( int** in, int r, int c, int grey );
void rotateImage( int **rotate, ofstream &file, int row, int col, int w, int h, string s, int g );
void writeToPgmFile( int** write, ofstream &file, int row, int col, int w, int h, string s, int g );

int main( int argc, char**argv )
{
 ifstream input( argv[1] );

 if( input.is_open() && argc == 4 )
 { 
   string input1 = "";
   string sdata = "";
   int w, h, save, savee, idata, grey = 0;
   getline( input, input1 );
   stringstream ss;
   ss << input.rdbuf();			
   ss >> w >> h;
   save = w;
   savee = h;
   ss >> grey;

   int** rImage = readImage( ss, w, h, grey );	
   int** NewImage = processImageToNegative( rImage, w, h, grey ); 
   ofstream outputFile( argv[2] );	
   writeToPgmFile( NewImage, outputFile, w, h, save, savee, input1, grey ); //write new image to pgm file
   outputFile.close();
   ofstream rotatedFile( argv[3] );
   rotateImage( rImage, rotatedFile, w, h, save, savee, input1, grey); //90-degree clock-wise rotation

   rotatedFile.close();

   for( int i = 0; i < h; i++ )
   {
	   delete []rImage[i];
   }
   for( int i = 0; i < h; i++ )
   {
	   delete []NewImage[i];
   }
   delete []rImage;
   delete []NewImage;
 }
 else if (!input.is_open())
 {   
	cout << "Can not open " << argv[1] << " for input" << endl;
 }
 else
 {
	 cout << "Usage: image <input image> <neg image> <rotate image>" << endl;
 }
 return 0;
}
int** readImage( stringstream &st, int qr, int qt, int grey  )

{
   int** arr = 0;
   arr = new int*[qt];

   for( int col = 0; col < qt; col++ )
   {
	   arr[col] = new int[qr];		
	   for ( int row = 0; row < qr; row++ )
	   {
		   st >> arr[col][row]; 
	   }
   }
   return arr;
}

int** processImageToNegative( int** in, int r, int c, int grey )
{	
     int j, i = 0;
     int** temp = 0;
     temp = new int*[c];
     for( i = 0; i < c; i++ )
     {
	temp[i] = new int[r];
	for( j = 0; j < r; j++ )
	{
		temp[i][j] = -(in[i][j]) + grey;
	}
	}
     return temp;
}

void writeToPgmFile( int** write, ofstream &file, int row, int col, int w, int h, string s, int g )
{
    file << s << endl;
    file << w << " " << h << endl;
    file << g << endl;
    int i, j = 0;
    //Write new image to pgm file
    for( i = 0; i < col; i++ )
    {
	    for( j = 0; j < row; j++ )
	    {
		    file << write[i][j]<<" ";
	    }
	    file << endl;
    }
}

void rotateImage( int **rotate, ofstream &file, int row, int col, int w, int h, string s, int g )
{
   file << s << endl;
   file << h << " " << w << endl;
   file << g << endl;
   int** newArray = 0;
   newArray = new int*[w];
   int i, j = 0;
   //90-degree clockwise rotation
   for( i = 0; i < w; i++ )
   {
	   newArray[i] = new int[h];
	   for( j = 0; j < h; j++ )
	   {
		   newArray[i][j] = rotate[h-j-1][i];
		   file << newArray[i][j] << " ";
	   }
	   file << endl;
   }
   for( int i = 0; i < w; i++ )
   {
	   delete []newArray[i];
   }
   	   delete []newArray;
}




