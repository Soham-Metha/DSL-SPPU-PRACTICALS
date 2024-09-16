#include <iostream>
#include "Queue.cpp"
using namespace std;
int main(){
    CircularQueue<int16_t> cq;
    int i;
    do
    {
        endStyled();
        cout<<"1 insert\n2 remove\n3 traverse\n4 quit\n";
        cin>>i;
        switch(i) {
            case 1:
            cq.insert();break;
            case 2:
            cout<<cq.remove().data<<"\n\n";
            break;
            case 3:
            cq.traverse();
            break;
            default:
                return 0;
        }
    } while (true);
    
    return 0;
}