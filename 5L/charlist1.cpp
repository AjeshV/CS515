#include "charlist.h"


// insert char at the begining of the list
void CharList::insertFront(char value){
        Elem *p = new Elem;
        p->info = value;
        p->next = head;
        head = p;
}

// insert char at the end of the list
void CharList::insertRear(char value){
    if ( 0 == head){   // empty list
        head = new Elem;
        head->info = value;
        head->next = 0;
    } else {
       Elem *cur = head;    
       while ( cur -> next )
       cur = cur->next;
       cur->next = new Elem;
       cur->next->info = value;
       cur->next->next = 0;
    }
}

// convert to string
string CharList::toStr(){
    Elem * cur = head;
    string s; 
    while (cur) {
        s += cur->info;
        cur = cur->next;
    }
    return s; 
}

// common copy code
void CharList::copyCode(const CharList & v){
    Elem *cur1, *cur2;

    if ( 0 == v.head ){  // if empty list
        head = 0;
    } else {  
        head = new Elem;
        head->info = v.head->info;
        cur1 = head;
        cur2 = v.head->next;

        while (cur2) {
            cur1->next = new Elem;
            cur1->next->info = cur2->info;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        cur1->next = 0;
    }
}

// common code for deallocation 
void CharList::destructCode(){
    delete head;
}

// overloaded output operator
ostream& operator<<(ostream& out, CharList c){
     out << c.toStr(); 
     return out;
}
