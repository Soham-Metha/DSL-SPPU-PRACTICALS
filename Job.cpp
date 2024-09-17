#include <iostream>
using namespace std;
template <typename T>
class Job
{
private:
    static int16_t counter;

public:
    T data;
    int16_t priority;
    int16_t duration;
    Job() : data(0) {};
    Job(T data) : data(data), priority(5), duration(10) {}
    Job(T data, int16_t priority) : data(data), priority(priority), duration(10) {}
    static int16_t fetchJobId()
    {
        return counter++;
    }
    void disp()
    {
        cout << "DATA : " << data << "\t\tPRIORITY : " << priority << "\n";
    }
    bool operator<=(Job other)
    {
        return (priority <= other.priority);
    }

    bool operator<(Job other)
    {
        return (priority < other.priority);
    }
};
template <typename T>
int16_t Job<T>::counter = 111;