#include <iostream>
#include "Queue.cpp"
using namespace std;
int main(){
    PriorityQueue<int16_t> pq;
    int i;
    do
    {
        endStyled();
        cout<<"1 insert\n2 remove\n3 traverse\n4 Sort\n5 quit\n";
        cin>>i;
        switch(i) {
            case 1:
                printStyled("45m\n\nEnter priority : ");
                int16_t pr;
                cin>>pr;
                endStyled();
                pq.insert(pr);
                break;
            case 2:
            cout<<pq.remove().data<<"\n\n";
            break;
            case 3:
            pq.traverse();
            break;
            case 4:
            pq.sortByPriority();
            break;
            default:
                return 0;
        }
    } while (true);
    
    return 0;
}