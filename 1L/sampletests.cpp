#include <iostream>
#include <cstdlib>
using namespace std;

int myatoi(const char * ptr);
int strncmpr(const char * str1, const char * str2, int size);

int main(){
    cout << "return zero: " << strncmpr("hello", "llo", 3) << endl;
    cout << "return zero: " << strncmpr("hzllo", "zzzllo", 4) << endl;
    cout << "return zero: " << strncmpr("zzllo", "szzllo", 5) << endl;
    cout << "return negative: " << strncmpr("hello", "olo", 3) << endl;
    cout << "return negative: " <<strncmpr("hello", "zlo", 3) << endl;
    cout << "return positive: " <<strncmpr("zzllo", "aaazllo", 5) << endl;
	// ADD YOUR OWN TEST CASES HERE

    cout << myatoi("98") << " " << atoi("98") << endl;
    cout << myatoi("  98123") << " " << atoi("  98123") << endl;
    cout << myatoi("+98") << " " << atoi("+98") << endl;
    cout << myatoi("98a") << " " << atoi("98a") << endl;
    cout << myatoi("a98") << " " << atoi("a98") << endl;
    cout << myatoi("1a98") << " " << atoi("1a98") << endl;
    cout << myatoi("+ 98") << " " << atoi("+ 98") << endl;
    cout << myatoi("    ") << " " << atoi("    ") << endl;
	// ADD YOUR OWN TEST CASES HERE
	
}



