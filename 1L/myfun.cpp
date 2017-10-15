/* CS515 Lab 2
 * File: myfun.cpp
 * Name: Ajesh Vijay Vijayaragavan
 * Section: 4
 * Date: 09/17/2017
 * Collaboration Declaration:
 *           Assistance received from TA, PAC and online resources etc.
 */

#include <iostream>
#include <cstdlib>
#include <sstream>
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

int myatoi(const char * ptr)
{
{	
    int x = 0;
    int y = 1;
    while (*ptr == ' ' )
    {
	    ptr++;
    }
    if ( *ptr == '+' || *ptr == '-')
    {
	    if ( *ptr == '-') y = -1;
	    ptr++;
    }
    while ( isdigit( *ptr ) ) 
    {
	x *= 10;
        x += (int) (*ptr-'0');
        ptr++;
    }
    return x * y;
	
}    
  return 0;
}

/*  
	Compares up to num characters of the C string str1 to those of the C string str2 
	starting from the end of two strings (BACKWARDLY).
	This function starts comparing the LAST character of each string. 
	If they are equal to each other, it continues backward with the following pairs 
	until the characters differ or until num characters match in both strings. 

    Parameters
        str1 and str2	 -	 pointer to the null-terminated char string 
        size	-   number of chars for comparison, must not exceed the string length of 
        			either str1 or str2
    
    Return value: 	
		<0	indicates the first character that does not match has a lower value 
			in str1 than in str2
		0	indicates the contents of both strings are equal (BACKWARDLY)
		>0	indicates the first character that does not match has a greater value 
			in str1 than in str2
*/


int strncmpr(const char * str1, const char * str2, int size){
    
     string a = str1;
     string b = str2;
     for (int i=1; i<size+1; i++)
     {
       if (a[a.length()-i] == b[b.length()-i])
     {
       	 continue;	 
     }
       else 
     {
	return (a[a.length()-i] - b[b.length()-i]);      
     }     
     }
     return 0;
}


// DO NOT ADD MAIN() FUNCTION IN THIS FILE
