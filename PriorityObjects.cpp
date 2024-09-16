#include <iostream>
#include "helpers.cpp"

template <typename T>
class PriorityObjects
{
public:
    T data;
    int16_t priority;
    PrioritiyObjects(const T& data, int priority) : data(data), priority(priority) {}
    void disp(){
        printStyled("4;44m\n");
        cout<<"DATA : "<<data<<"\t\tPRIORITY : "<<priority;
        endStyled();
    }
    bool operator<=(const PrioritizedItem& other) {
        return priority <= other.priority;
    }
};
