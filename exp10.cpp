#include <iostream>
#include "Stack.cpp"
#include "helpers.cpp"
using namespace std;
Stack stk;
StackInt nums;
int16_t calc(int16_t a, int16_t b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}
int getPriority(char c)
{
    switch (c)
    {
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    case ' ':
        return -1;
    default:
        return 0;
    }
}
string Helper(char c)
{
    string output = "";
    int p1 = getPriority(stk.atTop());
    int p2 = getPriority(c);
    switch (p2)
    {
    case 0:
        output += c;
        output += " ";
        nums.push(c - '0');
        break;

    case -1:
        break;

    default:
        while (!stk.isEmpty() && p1 >= p2)
        {
            char op = stk.pop();
            nums.push(calc(nums.pop(), nums.pop(), op));

            output += op;
            output += " ";
        }
        stk.push(c);
        break;
    }
    return output;
}
string eval(string str)
{
    string output = "";
    for (char &c : str)
        output += Helper(c);

    while (!stk.isEmpty())
    {
        char op = stk.pop();
        nums.push(calc(nums.pop(), nums.pop(), op));

        output += op;
        output += " ";
    }
    return output;
}
int main()
{
    string expr;
    printStyled("45m");
    cout << "--------------------------------------------------------------------------------\n";

    cout << "Enter Expression : ";
    getline(cin, expr);
    cout << "\n--------------------------------------------------------------------------------";

    printStyled("42m\n\n ");
    cout << "POSTFIX EXPRESSION : " << eval(expr) << "\n\n EVALUATION : " << nums.pop() << "\n\n";
    endStyled();

    return 0;
}