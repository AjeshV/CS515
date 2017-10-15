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
    void createSet(T p){	
     parents[p]=p;
     depths[p]=1;
    }T findSet(T p){
   if(parents[p]==p){ 
     return p;
    }else{
      parents[p]=findSet(parents[p]);
      depths[p]=2;
      return parents[p];
    }
}bool unionSets(T p,T q){
  if(findSet(p)==findSet(q)){
	  return false;
  }
	if(depths[p]<depths[q]){
	depths[q]+=depths[findSet(p)]; 
	parents[findSet(p)]=q;
    }else{
	depths[p]+=depths[findSet(q)]; 
	parents[findSet(q)]=p;
	}return true;}
    };
