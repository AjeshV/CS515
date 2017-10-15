/* CS515 Lab 2
 * File: debug1.cpp
 * Name: Ajesh Vijay Vijayaragavan
 * Section: 2
 * Date: 09/17/2017
 * Collaboration Declaration: 
 *           Assistance received from TA, PAC and online resources etc.
 */

#include<iostream>
using namespace std;
 
/******************************************************************
 *   Calculate the factorial of a number input from keyboard.  
 ******************************************************************/ 
 
long factorial(int n); // function declaration
 
int main(){
    int n;
    cin >> n;
    cout << "The factorial of " << n << " is " << factorial(n);
    cout << endl;
}
 
long factorial(int n){
    long result = 1;
    for (int i=1; i<=n; ++i)
    {  
      result *= i;
    }
    return result;
}

