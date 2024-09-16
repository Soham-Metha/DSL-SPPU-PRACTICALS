#include <iostream>
#include "Stack.cpp"
using namespace std;
int main(){
    Stack stk = Stack();
    stk.push(10);
    cout<<stk.pop();
    return 0;
}