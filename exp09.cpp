#include <iostream>
#include <cstring>
#include "Stack.cpp"
#include "helpers.cpp"
using namespace std;

Stack stk = Stack();

bool Checker(char c)
{
    switch (c)
    {
    case '(':
    case '{':
    case '[':
        return stk.push(c);

    case ')': // ASCII  40  41
        return (stk.pop() - c == -1);
    case '}': // ASCII 123 125
    case ']': // ASCII  91  93
        return (stk.pop() - c == -2);

    default:
        return true;
    }
}
int main()
{
    char expr[64];
    printStyled("45m");
    cout << "--------------------------------------------------------------------------------\n";

    cout << "Enter Expression : ";
    cin >> expr;
    cout << "\n--------------------------------------------------------------------------------";
    int exprLen = strlen(expr);
    bool flag = true;
    for (int16_t i = 0; i < exprLen; i++)
    {
        if (!Checker(expr[i]))
        {
            printStyled("41m\n\ngiven expression is not well parenthesized\n\n");
            endStyled();
            return 0;
        }
    }
    if (stk.isEmpty())
    {
        printStyled("42m\n\ngiven expression is well parenthesized\n\n");
        endStyled();
    }
    else
    {
        printStyled("41m\n\ngiven expression is not well parenthesized\n\n");
        endStyled();
    }

    return 0;
}
