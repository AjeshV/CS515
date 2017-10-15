#include <iostream>
#include "PQueue.h"
#include "HuffTree.h"
#include <sys/stat.h>
#include <fstream>
#include <sstream>
int main (int argc, char * argv[])
{
  if (argc!=2){
  exit(-1);
  }ifstream infile(argv[1]); 
    if (!infile.is_open()){
     cout << "Error opening file" << endl;
     exit(-1);
  }char a1[]="abcdefghijklmnopqrstuvwxyz"; 
  int f[26]={0};
  char c;
  while(infile.get(c)){
   if (isalpha(c)){
    c=tolower(c);
    int i=0;
   while (a1[i]!=c){
     i++;
   }f[i]++;
   }
  }struct stat fstat;
  stat(argv[1],&fstat);
  int x=fstat.st_size*8;
  cout << x << "original bits\n";
  HuffTree h;
  h.buildTree(a1,f,26);
  int x1=0;
  int compbits=0;
  for (int i=0;i<26;i++){
  string s=h.getCode(a1[i]);
  x1+=s.length();
  compbits+=x1;
  }cout << "bits after compression:" << compbits << endl;
 double comprate;
  double a=x-compbits;
  comprate=((a/x)*100);
  cout << "compression rate:" << comprate <<"%" << endl;
}
