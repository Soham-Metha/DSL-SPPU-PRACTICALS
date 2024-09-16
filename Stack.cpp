#include <iostream>

class Stack {
    int16_t stack[100];
    int16_t top = 0;
public:
    void push(int16_t i) {
        stack[top]=i;
        top++;
    }
    int16_t pop(){
        return top--;
    }
};