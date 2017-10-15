#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cstring>
using namespace std;

int priority(char a) {
    int temp;
        if (a == '^')
		temp = 1;
	else  if (a == '*' || a == '/')
		temp = 2;
	else  if (a == '+' || a == '-')
		temp = 3;
	return temp;
}

bool isOperator(char ch)
{
	if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
		return true;
	else
		return false;
}

int performOperation(int op1, int op2, char op)
{
	int ans;
	switch(op){
		case '+':
			ans = op2 + op1;
			break;
		case '-':
			ans = op2 - op1;
			break;
		case '*':
			ans = op2 * op1;
			break;
		case '/':
			ans = op2 / op1;
			break;
	}
	cout << "ans" << endl;
}


int main() {
    string infix;
        Label:
        cout << "Input:" << endl;
	getline(cin, infix);
	stack<char> operator_stack;
	stringstream output;

     for (unsigned i = 0; i < infix.length(); i++) {
      if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
	      while (!operator_stack.empty() && priority(operator_stack.top()) <= priority(infix[i])) {
                   output << operator_stack.top();
                   operator_stack.pop();
        }
          operator_stack.push(infix[i]);
      } else if (infix[i] == '(') {
    	      operator_stack.push(infix[i]);
           } else if (infix[i] == ')') {
               while (operator_stack.top() != '(') {
           output << operator_stack.top();
           operator_stack.pop();
         }
        operator_stack.pop();
         } 
      else {
	output << infix[i];
	 }
     }
      while (!operator_stack.empty()) {
            output << operator_stack.top();
	            operator_stack.pop();
       }
      
    cout << output.str() << endl;
    goto Label;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int i, op1, op2, len, x;
    stack<int> s;
    char exp[1000], buffer[15];
    
    std::strcpy(exp, output.str());
    cout << exp[0] << endl;
    len = sizeof(exp);
    int j=0;
    for (i=0; i<len; i++)
    {
	    while (!s.empty())
	    {    
	    if (exp[i]>='0' && exp[i]<='9')
	    {
		    buffer[j++] = exp[i];
		    cout << "ans1" << endl;
	    }
	    else if (exp[i]==' '){
		    if (j>0){
			    buffer[j] = '\0';
			    x = atoi(buffer);
			    s.push(x);
			    j=0;
			    cout << "ans2" << endl;
		    }
	    }
	    else if (isOperator(exp[i]))
	    {
		    op1 = s.top();
		    s.pop();
		    op2 = s.top();
		    s.pop();
		    s.push(performOperation(op1, op2, exp[i]));
     	    cout << "ans3" << endl;
	    }
	    }
    }

    return 0;
    
}
