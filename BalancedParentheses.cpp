#include<iostream>
#include<string>
#include<memory>
#include<stack>
using namespace std;

string balancedParen(string expr){
    stack<char> s;

    //for loop traverses entire expression
    for(int i = 0; i < expr.length(); i++){

        //if the expression at i contains any open parentheses, add it to the stack
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '['){
            s.push(expr[i]);
        }

        //if the expression contains a closed parenthesis with no open to check for, it is automatically not balanced
        if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']'){
            if(s.size() == 0)
                return "Not Balanced";
        }

        //if the expression at i closes the most recent open parenthesis (top of stack), remove it from the stack
        if(expr[i] == ')' && s.top() == '('){
            s.pop();
        }
        if(expr[i] == '}' && s.top() == '{'){
            s.pop();
        }
        if(expr[i] == ']' && s.top() == '['){
            s.pop();
        }
    }

    //if all parenthesis are balanced, the stack should be empty.
    if(s.size() != 0)
        return "Not Balanced";
    else
        return "Balanced";
}

int main() {
    string expr;
    cout << "Enter your expression: ";
    cin >> expr;
    cout << balancedParen(expr);
}
