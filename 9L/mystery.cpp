#include "mysterysorts.h"
#include <sys/time.h>
#include <vector>

int main()
{
 int arr [50] = {733,260,345,782,644,756,163,689,524,353,1,778,283,914,91,314,967,340,363,824,81,329,997,337,100,370,20,914,10,461,613,96,74,959,232,71,717,748,761,594,103,764,725,739,679,817,406,7,159,771};
 vector<int> v;
 for(int i=0; i < 50; i++){
  v.push_back( arr[i]);
 }
 timeval start, finish;
 double elapse;
 gettimeofday(&start, 0);
 cout<<"first trial"<<endl;
 for( int i=0; i< 50; i++){
  cout<<v[i]<< " ";
 }mysterySort4(v,7);
 cout<<"second trial"<<endl;
 for( int i=0; i< 50; i++){
 cout<<v[i]<< " ";
 }
 gettimeofday(&finish, 0);
 elapse = (double) finish.tv_usec-(double)start.tv_usec;
 cout<<"Elapse" << elapse <<endl;
}
