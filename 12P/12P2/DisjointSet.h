#include <map>
using namespace std;
template <typename T>
class DisjointSet{
private:
    std::map<T, T> parents;
    std::map<T, int> depths;
public:
    DisjointSet(){};
    void createSet(T);
    string findSet(T p);
    bool unionSets(T p, T q);
};
 template <typename T>
void DisjointSet<T>::createSet(T aj){
	parents[aj]=aj;
	depths[aj]=0;
}
template <typename T>
string DisjointSet<T>::findSet(T p){
	if(p!=parents[p]){		
		parents[p]=findSet(parents[p]);
	}return parents[p];
}
template <typename T>
bool DisjointSet<T>::unionSets(T p, T q){
	
  T x=findSet(p);
   T y=findSet(q);
	if(depths[x] > depths[y]){
		parents[y]=x;
	}else{
		parents[x]=y;
	if(depths[x]==depths[y]){
      	depths[y]++;
   }
  }
}
