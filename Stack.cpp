#include <iostream>
#define STACKSIZE 10
class Stack
{
    char stack[STACKSIZE];
    int16_t top = -1;

public:
    bool push(char i)
    {
        if (top == STACKSIZE - 1)
            return false;

        stack[++top] = i;
        return true;
    }
    char pop()
    {
        if (top == -1)
        {
            return ' ';
        }
        return stack[top--];
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    char atTop()
    {
        if (top == -1)
        {
            return ' ';
        }
        return stack[top];
    }
};
class StackInt
{
    int16_t stack[STACKSIZE];
    int16_t top = -1;

public:
    bool push(int16_t i)
    {
        if (top == STACKSIZE)
            return false;

        top++;
        stack[top] = i;
        return true;
    }
    int16_t pop()
    {
        if (top == -1)
        {
            return 0;
        }
        return stack[top--];
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    int16_t atTop()
    {
        if (top == -1)
        {
            return 0;
        }
        return stack[top];
    }
};