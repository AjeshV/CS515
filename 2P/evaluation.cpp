/* CS515 Assignment 2
File: evaluation.cpp
Name: Ajesh Vijay Vijayaragavan
Section: 01
Date: 09/19/2017
Collaboration Declaration: Assistance received from TA, PAC, online resources.
*/

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

string infixToPostfix( string exp );
bool operandcheck( char c );
bool operatorcheck( char c );
int prioritycheck( string c );

stack<int> Stack;
string result = " ";
int calculatePostfix(string expression);

int main( int argc, char **argv )
{
		string userinput;
		string holder = "";
		while((userinput.empty() || userinput != "exit") && !cin.eof())
		{
			cout << "Expression:";
		        getline( cin, userinput);
			int i;
			for(i  = 0; i < userinput.length(); ++i){
                                 if(isspace(userinput[i])){
                                     userinput.erase(i,1);
  }
}

				//cout << userinput;
			if (userinput!="exit" && !cin.eof())
			{
				while (userinput.empty())
				{
					//cin.ignore();
					if (!cin.eof())
					{
					getline(cin,userinput);
					}
					else
					{
						return 0;
					}
				
					//cout << userinput;
				}	
			stringstream stream(userinput);
			int count;
			stream >> count;

			string ans = infixToPostfix(userinput);
			//cout << ans << endl;
			int iii = calculatePostfix( ans );
			cout << "Answer: " << iii << endl;
			
			}
			else 
			{
                           return 0;
			}
		}
	
		return 0;
}
string infixToPostfix( string expp )
{
	stack <string> S;
	//int i;
	//cout << expp.length();
	for(int i = 0; i < expp.length(); i++ )
	{
		if( expp[i] <= '9' && expp[i] >= '0')
		{
			int j = i;
			while( j < expp.length() && ( expp[j] >= '0' && expp[j] <= '9' ) )
			{
				result += string(1,expp[j]);

				j=j+1;
				//cout << result;
			}

			result += " ";
			i = j-1;			
		}
		else if( operatorcheck( expp[i]) )
		{
		while( !S.empty() && ( prioritycheck( string(1,expp[i]))  <= prioritycheck(S.top())   ) &&  ( S.top() != "("  || S.top() != "{"  || S.top() != "[" ) )
			{
				if( prioritycheck(string(1,expp[i])) ==  prioritycheck(S.top()) )
				{
				 break;
				}
				result += S.top() + " ";
				S.pop();
			}
			Stack.push( expp[i] );
			S.push( string(1,expp[i])); 
		}
		else if( string(1,expp[i]) == "(" || string(1,expp[i]) == "{" || string(1,expp[i]) == "[" )
		{
			S.push( string( 1,expp[i]) );
		}
		else if( string(1,expp[i]) == ")" || string(1,expp[i]) == "}" || string(1,expp[i]) == "]" )
		{
			while( !S.empty() &&  ( S.top() != "(" && S.top() != "{" && S.top() != "[" ) )
			{
				result += S.top() + " ";
				S.pop();
			}
			S.pop();
		}
	}
	while( !S.empty() )
	{
		result += S.top() + " ";
		S.pop();
	}
	//cout << "Postfix expression:" << result << endl;
	return result;
}
int calculatePostfix( string expression )
{
	stack<int> Stack;
	int i;
	for(i = 0; i < expression.length(); i++ )
	{
		if( operatorcheck( expression[i] ) )
		{
			int second = Stack.top();
			Stack.pop();
			int first = Stack.top();
			Stack.pop();
			//cout << first << second << endl;
			int resultt;
			if( expression[i] == '+' )
			{
				resultt = first + second;
				//cout << resultt << endl;
			}
			else if( expression[i] == '-' )
			{
				resultt = first - second;
				//cout << resultt << endl;

			}
			else if( expression[i] == '*' )
			{
				resultt = first * second;
				//cout << resultt << endl;

			}
			else if (expression[i] == '/')
			{
				resultt = first / second;
				//cout << resultt << endl;
			}
			Stack.push(resultt);
			//cout << resultt << endl;
		}
		else if( expression[i] <= '9' && expression[i] >= '0')
		{
			int t = 0;
			int q = i;
			while( q < expression.length() && ( expression[q] >= '0' && expression[q] <= '9' ) )			
			{
													
			  t = ( t * 10 ) + (expression[q] - '0' );
				q=q+1;
			}
			i = q;
			Stack.push( t );
		}
	}
	return Stack.top();
}

bool operandcheck( char c )
{
	if( c >= '0' && c <= '9' )
	{
		return true;
	}
	if( c >= 'a' && c <= 'z')
	{
		return true;
	}
	if( c >= 'A' && c <= 'Z')
	{
		return true;
	}
	return false;
}

bool operatorcheck( char c )
{
	if( c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )
	{
		return true;
	}
	return false;
}
					
int prioritycheck( string c )
{

	int order = 0;
	if( c == "+" || c == "-" )
	{
		order = 1;
	}
	if( c == "*" || c == "/" )							
	{
		order =  2;
	}
	return order;	
}
