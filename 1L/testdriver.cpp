/* CS515 Lab 2
 * File: testdriver.cpp
 * Name: Ajesh Vijay Vijayaragavan
 * Section: 4
 * Date: 09/17/2017
 * Collaboration Declaration:
 *          Assistance received from TA, PAC and online resources etc.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int myatoi(const char * ptr);
int strncmpr(const char * str1, const char * str2, int size);

int main(){
    cout << "return zero: " << strncmpr("abcdefg", "g", 1) << endl;
    cout << "return zero: " << strncmpr("abcdefg", "fg", 1) << endl;
    cout << "return zero: " << strncmpr("abcdefg", "fg", 2) << endl;
    cout << "return zero: " << strncmpr("abcdefg", "abcdefg", 7) << endl;
    cout << "return zero: " << strncmpr("fg", "fg", 2) << endl << endl;
    
    cout << "return zero: " << strncmpr("a a", "a a", 3) << endl;
    cout << "return negative: " <<strncmpr("a", "b", 1) << endl;
    cout << "return negative: " <<strncmpr("aa", "b", 1) << endl;
    cout << "return negative: " <<strncmpr("aa", "ba", 2) << endl;
    cout << "return negative: " << strncmpr("abcdefg", "ffg", 3) << endl << endl;
    
    cout << "return negative: " <<strncmpr("abcdefg", "eefg", 4) << endl;
    cout << "return negative: " << strncmpr("defg", "ddkfg", 3) << endl;
    cout << "return negative: " <<strncmpr("defg", "abcgefg", 4) << endl;
    cout << "return positive: " <<strncmpr("b", "a", 1) << endl;
    cout << "return positive: " <<strncmpr("b", "aa", 1) << endl << endl;
    
    cout << "return positive: " <<strncmpr("ba", "aa", 2) << endl;
    cout << "return positive: " << strncmpr("ffg", "abcdefg", 3) << endl;
    cout << "return positive: " <<strncmpr("eefg", "abcdefg", 4) << endl;
    cout << "return positive: " << strncmpr("ddkfg", "defg", 3) << endl;
    cout << "return positive: " <<strncmpr("abcgefg", "defg", 4) << endl << endl;
    
    cout << myatoi("2") << " " << atoi("2") << endl;
	cout << myatoi("203") << " " << atoi("203") << endl;
	cout << myatoi("232345") << " " << atoi("232345") << endl;
	cout << myatoi("2.0") << " " << atoi("2.0") << endl;
	cout << myatoi("2.") << " " << atoi("2.") << endl << endl;
	
    cout << myatoi("23.2") << " " << atoi("23.2") << endl;
    cout << myatoi("23.8") << " " << atoi("23.8") << endl;
    cout << myatoi("0.002003") << " " << atoi("0.002003") << endl;
    cout << myatoi("    ") << " " << atoi("    ") << endl;
    cout << myatoi("  123") << " " << atoi("  123") << endl << endl;
    
    cout << myatoi("  12 3") << " " << atoi("  12 3") << endl;
    cout << myatoi("+28") << " " << atoi("+28") << endl;
    cout << myatoi("-28") << " " << atoi("-28") << endl;
    cout << myatoi("2b8a") << " " << atoi("2b8a") << endl;
    cout << myatoi("a98") << " " << atoi("a98") << endl << endl;
    
    cout << myatoi("11-a98") << " " << atoi("11-a98") << endl;
    cout << myatoi("+ 98") << " " << atoi("+ 98") << endl;
    cout << myatoi(" -28") << " " << atoi(" -28") << endl;
    cout << myatoi("--28") << " " << atoi("--28") << endl;
    cout << myatoi("-+28") << " " << atoi("-+28") << endl << endl;
    

   
    cout << "return zero: " << strncmpr("hello", "llo", 3) << endl;
    cout << "return zero: " << strncmpr("hzllo", "zzzllo", 4) << endl;
    cout << "return zero: " << strncmpr("zzllo", "szzllo", 5) << endl;
    cout << "return negative: " << strncmpr("hello", "olo", 3) << endl;
    cout << "return negative: " <<strncmpr("hello", "zlo", 3) << endl;
    cout << "return positive: " <<strncmpr("zzllo", "aaazllo", 5) << endl;
    
    cout << myatoi("98") << " " << atoi("98") << endl;
    cout << myatoi("  98123") << " " << atoi("  98123") << endl;
    cout << myatoi("+98") << " " << atoi("+98") << endl;
    cout << myatoi("98a") << " " << atoi("98a") << endl;
    cout << myatoi("a98") << " " << atoi("a98") << endl;
    cout << myatoi("1a98") << " " << atoi("1a98") << endl;
    cout << myatoi("+ 98") << " " << atoi("+ 98") << endl;
    cout << myatoi("    ") << " " << atoi("    ") << endl;
    
}

