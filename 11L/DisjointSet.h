/* Sets are disjoint if the sets are all pairwise disjoint.                  *
 * For example, the sets {1,2}, {3,6}, {1,0,41} are  disjoint,               *
 * whereas the sets {3,2}, {2,8} are not, due to the common element 2.       *
 * A disjoint set is a set containing disjoint sets. Another name   		 *
 * for this data structure is the union-find.                                *
 * 
 * This particular implementation uses an uptree that is built with an       *
 * underlying std::map. All elements are int type                            *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <map>
using namespace std;
template <typename T>
class DisjointSet{
private:
    std::map<T, T> parents;
    std::map<T, T> depths;
public:
    DisjointSet(){};
    void createSet(T a){	
     parents[a]=a;
     depths[a]=1;
    }T findSet(T r1){
   if(parents[r1]==r1){ 
     return r1;
    }else{
      parents[r1]=findSet(parents[r1]);
      depths[r1]=2;
      return parents[r1];
    }
}bool unionSets(T a,T v1){
  if(findSet(a)==findSet(v1)){
	  return false;
  }
	if(depths[a]<depths[v1]){
	depths[v1]+=depths[findSet(a)]; 
	parents[findSet(a)]=v1;
    }else{
	depths[a]+=depths[findSet(v1)]; 
	parents[findSet(v1)]=a;
	}return true;}
    };
