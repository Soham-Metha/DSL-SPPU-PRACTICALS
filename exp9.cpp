#include <iostream>
#include <cstring>
#include "Stack.cpp"
using namespace std;

Stack stk = Stack();

bool Checker(char c) {
    switch (c) {
        case '(':
        case '{':
        case '[':
            return stk.push(c);
        
        case ')': //ASCII  40  41
        case '}': //ASCII 123 125
        case ']': //ASCII  91  93
            return (stk.pop()-c <= 2);

        default:
            return true;
    }
}
int main(){
    char expr[64];
    cout<<"Enter Expression : ";
    cin>>expr;

    int exprLen = strlen(expr);
    bool flag = true;
    for (int16_t i = 0; i < exprLen; i++)
    {
        if (!Checker(expr[i]))
        {
            cout<<"given expression is not well parenthesized\n";
            return 0;
        }
        
    }
    if (stk.isEmpty())
        cout<<"given expression is well parenthesized\n";
    else
        cout<<"given expression is not well parenthesized\n";
    
    return 0;
}

