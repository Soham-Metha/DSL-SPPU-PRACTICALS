#include <iostream>
#include "Job.cpp"
#include "helpers.cpp"
#define QUEUESIZE 10
using namespace std;
/*
START => ELEMENT TO BE DELETED
END => LAST INSERTED ELEMENT
INSERT :
IF START IS 1ST & WND IS LAST THEN QUEUE IS FULL
QUEUE WILL BE EITHER FULL OR EMPTY WHEN START = END+1
IF START = END+1 AFTER INSERTING ELEMENT THEN QUEUE IS FULL
IF START = END+1 WHEN REMOVING ELEMENT THEN QUEUE IS EMPTY
CONSIDER MOD OF END+1 TO HANDLE EDGE CASE I.E. WHEN END IS LAST ELEMENT

WHEN INSERTING FIRST ELEMENT, CHANGE START & END TO 0
DELETE:
WHEN DELETING ELEMENT, IF THE ELEMENT DELETED IS THE LAST INSERTED ELEMENT,THEN SET START & END TO -1 I.E EMPTY QUEUE
*/
template <typename U>
class CircularQueue
{
    Job<U> queue[QUEUESIZE];
    int16_t start = -1;
    int16_t end = -1;

public:
    CircularQueue() {};
    void insert()
    {

        if ((start == 0 && end == QUEUESIZE - 1) || (end + 1) % QUEUESIZE == start)
        {
            printStyled("41m\n\nQUEUE FULL\n\n");
            return;
        }
        else if (end == -1)
        {
            start = end = 0;
        }
        else if (end == QUEUESIZE - 1 && start != 0)
        {
            end = 0;
        }
        else
            end++;

        queue[end] = Job<U>(Job<U>::fetchJobId() * 11);
        printStyled("42m\n\nOPERATION PERFORMED\n\n");
        cout << "START : " << start << " END : " << end << "\n\n";
    }
    Job<U> remove()
    {

        if (start == -1)
        {
            printStyled("41m\n\nQUEUE EMPTY\n\n");
            return Job<U>(-1);
        }

        Job<U> tmp = queue[start];
        queue[start].data = 0;

        if (start == end)
            start = end = -1;
        else if (start == QUEUESIZE - 1)
            start = 0;
        else
            start++;

        printStyled("42m\n\nOPERATION PERFORMED\n\n");
        cout << "START : " << start << " END : " << end << "\n\n";
        return tmp;
    }
    void traverse()
    {
        if (start == -1)
        {
            printStyled("41m\n\nQUEUE EMPTY\n\n");
            return;
        }
        printStyled("4;44m\n\n");
        if (end >= start)
        {
            for (int i = start; i <= end; i++)
                cout << queue[i].data << "\t";
        }
        else
        {
            for (int i = start; i < QUEUESIZE; i++)
                cout << queue[i].data << "\t";

            for (int i = 0; i <= end; i++)
                cout << queue[i].data << "\t";
        }
        cout << "\n\n";
    }
};

template <typename U>
class PriorityQueue
{
    Job<U> queue[QUEUESIZE];
    int16_t start = -1;
    int16_t end = -1;

public:
    void insert(int16_t priority)
    {

        if (end == QUEUESIZE - 1)
        {
            printStyled("41m\n\nQUEUE FULL\n\n");
            return;
        }
        else if (end == -1)
        {
            start = end = 0;
        }
        else
            end++;

        queue[end] = Job<U>(Job<U>::fetchJobId() * 11, priority);
        printStyled("42m\n\nOPERATION PERFORMED\n\n");
        cout << "START : " << start << " END : " << end << "\n\n";
    }
    Job<U> remove()
    {

        if (start == -1)
        {
            printStyled("41m\n\nQUEUE EMPTY\n\n");
            return Job<U>(-1);
        }

        Job<U> tmp = queue[start];
        queue[start].data = 0;

        if (start == end)
            start = end = -1;
        else
            start++;

        printStyled("42m\n\nOPERATION PERFORMED\n\n");
        cout << "START : " << start << " END : " << end << "\n\n";
        return tmp;
    }
    void traverse()
    {
        if (start == -1)
        {
            printStyled("41m\n\nQUEUE EMPTY\n\n");
            return;
        }
        printStyled("4;44m\n\n");
        for (int i = start; i <= end; i++)
            queue[i].disp();
        cout << "\n\n";
    }
    void sortByPriority()
    {
        for (int i = start + 1; i <= end; i++)
        {
            Job<U> key = queue[i];
            int j = i - 1;

            while (j >= 0 && queue[j] < key)
            {
                queue[j + 1] = queue[j];
                j--;
            }
            queue[j + 1] = key;
        }
    }
};

template <typename U>
class DEQueue
{
    Job<U> queue[QUEUESIZE];
    int16_t start = -1;
    int16_t end = -1;

public:
    void insert(int16_t *ptr)
    {
        if ((*ptr) == getLimit(ptr))
        {
            printStyled("41m\n\nLIMIT REACHED\n\n");
            return;
        }
        else if ((*ptr) == -1)
        {
            start = end = 0;
        }
        else
            (*ptr) += getIncr(ptr);

        queue[(*ptr)] = Job<U>(Job<U>::fetchJobId() * 13);
        printStyled("42m\n\nOPERATION PERFORMED\n\n");
        cout << "START : " << start << " END : " << end << "\n\n";
    }
    Job<U> remove(int16_t *ptr)
    {
        if ((*ptr) == -1)
        {
            printStyled("41m\n\nQUEUE EMPTY\n\n");
            return Job<U>(-1);
        }

        Job<U> tmp = queue[(*ptr)];
        queue[(*ptr)].data = 0;

        if (start == end)
            start = end = -1;
        else
            (*ptr) -= getIncr(ptr);

        printStyled("42m\n\nOPERATION PERFORMED\n\n");
        cout << "START : " << start << " END : " << end << "\n\n";
        return tmp;
    }
    void traverse()
    {
        if (start == -1)
        {
            printStyled("41m\n\nQUEUE EMPTY\n\n");
            return;
        }
        printStyled("4;44m\n\n");
        for (int i = 0; i < QUEUESIZE; i++)
            cout << queue[i].data << "\t";
        cout << "\n\n";
    }

    int16_t *getStart()
    {
        return &start;
    }
    int16_t *getEnd()
    {
        return &end;
    }

    int16_t getLimit(int16_t *ptr)
    {
        return (ptr == &start) ? 0 : (QUEUESIZE - 1);
    }
    int16_t getIncr(int16_t *ptr)
    {
        return (ptr == &start) ? -1 : 1;
    }
};
