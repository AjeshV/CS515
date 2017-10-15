#include <iostream>
#include <cstdlib>
using namespace std;

/*  Interprets an integer value in a byte string pointed to by str.
    Function discards any whitespace characters until first non-whitespace
    character is found. Then it takes as many characters as possible to
    form a valid integer number representation and converts them to integer value.
    The valid integer value consists of the following parts:
        (optional) plus or minus sign
        numeric digits
 
    Parameters
        str	 -	 pointer to the null-terminated char string to be interpreted 
    
    Return value: Integer value corresponding to the contents of str on success. 
        If the converted value falls out of range of corresponding return type, 
        the return value is undefined. 
        If no conversion can be performed, 0 is returned.
 
*/

int myatoi(const char * ptr){
    return 0;
} 


// DO NOT ADD MAIN() FUNCTION IN THIS FILE