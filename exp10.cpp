#include <iostream>
#include <cstring>
#include "Stack.cpp"
using namespace std;

Stack stk;
StackInt nums;
int16_t calc(int16_t a, int16_t b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:  return 0;
    }
}

string eval(string str) {
    string output = "";
    for(char& c : str) {
        switch (c) {
            case '/':
            case '*':
                while (stk.atTop() == '*' ||stk.atTop() == '/') {
                    char op = stk.pop();
                    nums.push(calc(nums.pop(),nums.pop(),op));

                    output+= op;
                    output+=" ";
                }
                stk.push(c);
                break;
                    
            case '+':
            case '-':
                while (!stk.isEmpty()) {
                    char op = stk.pop();
                    nums.push(calc(nums.pop(),nums.pop(),op));

                    output+= op;
                    output+=" ";
                }
                stk.push(c);
                break;

            case ' ':
                break;

            default:
                output+= c;
                output+=" ";
                nums.push(c-'0');
                break;
        }
    }
    while (!stk.isEmpty()) {
        char op = stk.pop();
        nums.push(calc(nums.pop(),nums.pop(),op));

        output+= op;
        output+=" ";
    }
    return output;
}
int main(){
    string expr;
    cout<<"Enter Expression : ";
    getline(cin,expr);

    cout<<"\n\n POSTFIX EXPRESSION : "<<eval(expr)<<"\n\n EVALUATION : "<<nums.pop()<< "\n";
    
    return 0;
}