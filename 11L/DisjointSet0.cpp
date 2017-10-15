#include "DisjointSet0.h"

/**
 * Creates a singleton set from the parameter.
 */
void DisjointSet::createSet(int aj){
	parents[aj] = aj;
	depths[aj] = 0;
}
    
/**
 * Finds and returns the representative of the set which contains the
 * parameter. Implements path compression.
 */
int DisjointSet::findSet(int p){
	
	if( p != parents[p]){
		parents[p] = findSet(parents[p]);
	}
	return parents[p];
}
    
/**
 * Combines the sets which contain the parameters. Return false if two 
 * parameters are already in the same set; otherwise, union the two sets
 * by rank and return true. Implements union by rank
 */
bool DisjointSet::unionSets(int p, int q){
	
	int x = findSet(p);
	int y = findSet(q);
	
	if(x == y){
		return false;
	}
	
	if(depths[x] > depths[y]){
		parents[y] = x;
	}
	
	else{
		parents[x] = y;
		
		if(depths[x] == depths[y]){
			depths[y]++;
		}
	}
	return true;
	
}