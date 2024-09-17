#include <iostream>
#include "Queue.cpp"
using namespace std;
int main()
{
    PriorityQueue<int16_t> pq;
    int i;
    do
    {
        endStyled();
        printStyled("43m");
        cout << "--------------------------------------------------------------------------------";
        cout << "\n1 insert\n2 remove\n3 Sort\n4 traverse\n5 quit\n";
        cout << "--------------------------------------------------------------------------------";

        printStyled("45m");
        cout << "\n\nENTER CHOICE : ";
        cin >> i;
        cout << "\n--------------------------------------------------------------------------------\n";
        endStyled();
        switch (i)
        {
        case 1:
            printStyled("45m\n\nEnter priority : ");
            int16_t pr;
            cin >> pr;
            endStyled();
            pq.insert(pr);
            break;
        case 2:
            cout << pq.remove().data << "\n\n";
            break;
        case 3:
            pq.sortByPriority();
        case 4:
            pq.traverse();
            break;
        default:
            return 0;
        }
    } while (true);

    return 0;
}