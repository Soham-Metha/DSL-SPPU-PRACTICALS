#include <iostream>
#include "Queue.cpp"
using namespace std;
int main()
{
    DEQueue<int16_t> dq;
    int i;
    do
    {
        endStyled();
        printStyled("43m");
        cout << "--------------------------------------------------------------------------------";
        cout << "\n1 insert at end\n2 insert at beginning\n";
        cout << "3 remove from beginning\n4 remove from end\n";
        cout << "5 traverse\n6 quit\n";
        cout << "--------------------------------------------------------------------------------";

        printStyled("45m");
        cout << "\n\nENTER CHOICE : ";
        cin >> i;
        cout << "\n--------------------------------------------------------------------------------\n";
        endStyled();
        switch (i)
        {
        case 1:
            dq.insert(dq.getEnd());
            break;
        case 2:
            dq.insert(dq.getStart());
            break;
        case 3:
            cout << dq.remove(dq.getStart()).data << "\n\n";
            break;
        case 4:
            cout << dq.remove(dq.getEnd()).data << "\n\n";
            break;
        case 5:
            dq.traverse();
            break;
        default:
            return 0;
        }
        endStyled();
    } while (true);

    return 0;
}