#include <iostream>
#include "helpers.cpp"
using namespace std;
template <typename T>
class Job
{
private:
    static int16_t counter;
public:
    T data;
    int16_t priority;
    int16_t Duration;
    Job() : data(fetchJobId()) {};
    Job(const T& data) : data(data), priority(5), Duration(10) { }
    Job(const T& data,int16_t priority) : data(data), priority(priority), Duration(10) { }
    static int16_t fetchJobId(){
        return counter++;
    }
    void disp(){
        printStyled("4;44m\n");
        cout<<"DATA : "<<data<<"\t\tPRIORITY : "<<priority;
        endStyled();
    }
    bool operator<=(const Job& other) {
        return priority <= other.priority;
    }

    bool operator<(const Job& other) {
        return priority < other.priority;
    }
};
template <typename T>
int16_t Job<T>::counter = 111;