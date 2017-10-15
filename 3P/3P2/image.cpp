/* CS515 Assignment 3
  File: image.cpp
  Name: Ajesh Vijay Vijayaragavan
  Section: 1
  Date: 09/26/2017
  Collaboration Declaration: Assistance received from TA, PAC, Online resources.
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char**argv) {
     int row = 0;
     ifstream infile(argv[1]);
     ofstream outfile(argv[(1+1)]);
     ofstream outfile1(argv[1+1+1]);
     stringstream a;
     int col = 0;
     string inputLine = "";
     int numrows = 0;
     int numcols = 0;
     int max;
     int k=0;
     if (infile.is_open() && ((argc>3) && (argc<5))){	     
       getline(infile,inputLine);       
        if(inputLine.compare("P2")!= 0){ 
	     cerr << "Version error" << endl;
        }else if (inputLine.compare("P2")==0){
             a << infile.rdbuf();
	     a >> numrows >> numcols;   
             a >> max;
	     //cout << "Version : " << inputLine << endl;
             //cout << "Width : " << numrows << endl;
	     //cout << "Height: " << numcols << endl;
	     //cout << "Max Value: " << max << endl;
	     int** x = new int*[numcols];
	     for (int i = 0; i<=(numcols-1); i++){
		     x[i]=new int[numrows];
		     for (int j = 0; j<=(numrows-1);j++){
			     a >> x[i][j];
		     }
	     }x,numrows,numcols,max;
	     //cout << x << endl;
             int** y = new int*[numcols];
	     for (int i=0; i<=(numcols-1);i++){
		     y[i]=new int[numrows];
		     for (int j=0;j<=(numrows-1);j++){
			     y[i][j] = max-(x[i][j])-k;
		     }
             }int numrowsadv=numrows;
	     int numcolsadv=numcols;
	     //y,outfile,numrows,numcols,inputLine,max;
             outfile << inputLine << endl;
	     outfile << numrowsadv << " " << numcolsadv << endl;
	     outfile << max << endl;
	     for (int i=0;i<=(numcols-1);i++){
		     for (int j=0;j<=(numrows-1);j++){
			     outfile<<y[i][j]<<" ";
		     }outfile<<endl;
             }outfile.close();
             //outfile1
	     outfile1 << inputLine << endl;
             outfile1 << numcolsadv << " " << numrowsadv << endl;
             outfile1 << max << endl;
	     int** z = new int*[numrowsadv];
	     for(int i =0;i<=(numrowsadv-1);i++){
		     z[i]=new int[numcolsadv];
		     for(int j=0;j<=(numcolsadv-1);j++){
			     z[i][j]=x[numcolsadv-j-k-1][i];
			     outfile1<<z[i][j]<<" ";
		     }outfile1<<endl;
	     }outfile1.close();	     
     }
  }else if (!infile.is_open()){
       cout << "Can not open " << argv[1] << " for input" << endl;
     }else{
	cout << "Usage: image <input image> <neg image> <rotate image>" << endl;      }
}     
