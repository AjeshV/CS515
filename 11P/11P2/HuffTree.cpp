/** CS515 Assignment 11
  * File: HuffTree.cpp
  * Name: Ajesh Vijay Vijayaragavan
  * Section: 1
  * Date: 04/27/2017
  * Collaboration Declaration: Assistance received from TA,PAC,online resources. 
*/
#include "HuffTree.h"
string HuffTree::getCode(char c){
  string code="";
  return calculate(c,_root->left,code);
}
string HuffTree::calculate(char c,HuffNode * h,string code){
 if(h==NULL){
	 return "FAIL";
 } if(h->data==c){
		return code;
 }else if(h){
  if(h->right){
	string right=calculate(c,h->right,code + "1");
  if(right!="FAIL"){
 	return right;
	}
}string left=calculate(c,h->left,code + "0");
  if(left!="FAIL"){
	return left;
	}
}return "FAIL";
}

void HuffTree::printTree(ostream& out, int level, HuffNode *p){
  int i;
  if (p){
   if (p->right){
	printTree(out, level+1,p->right);}
 //   for(i=0;i<level;i++){
 //   out << "\t";
 //  }
 //   cout << p->data << "(" << p->freq << ")" << endl;
   printTree(out,level+1,p->left);
   }
}

ostream& HuffTree::dump(ostream &out){
    if (_root==_root->left) {
        return out;
    }printTree(out,0,_root->left);
}
void HuffTree::buildTree(char * chs, int * freqs, int size){
  _root=new HuffNode();
  PQueue< HuffNode*, 100> queue;
  for(int i=0;i<size;i++){
   HuffNode * charNode=new HuffNode();;
   int frequency=freqs[i];
   charNode->freq=frequency;
   charNode->data=chs[i];
   queue.insert(charNode);
 }HuffNode * newRoot;
	while(queue.size() > 1){
     HuffNode * min=queue.findMin();
	int minFreq=min->freq;
	char minChar=min->data;
	   queue.deleteMin();
	   HuffNode * secMin=queue.findMin();
	int secFreq=secMin->freq;
	char secChar=secMin->data;
	   queue.deleteMin();
		
	 int newRootFreq=minFreq + secFreq;
	   newRoot=new HuffNode();
	   newRoot->freq=newRootFreq;
	   newRoot->left=min;
	   newRoot->right=secMin;
	   queue.insert(newRoot);
	}_root->left=newRoot;
	dump(cout);
}
