#include <iostream>
#include "CircularDoublyLinkedList.cpp"
using namespace std;

const int16_t ROWCOUNT = 10;
const int16_t SEATSINROW = 7;

class Cinemax
{
    public: 

    CircularDoublyLinkedList* rows[ROWCOUNT];

    Cinemax()
    {
        for (int16_t i = 0; i < ROWCOUNT; i++)
            rows[i] = new CircularDoublyLinkedList(SEATSINROW);
    }

    void CinemaxSeatBook(int16_t rowIndex,int16_t seatIndex,bool val)
    {
        Node* n = rows[rowIndex]->fetchNode(seatIndex);
        if (!n)
            return printStyled("41m\n\nENTER A VALID SEAT NUMBER!\n\n");
        
        if ((val && n->data.state) || (!val && !n->data.state))
            return printStyled("45m\n\nTRY OPERATION ON ANOTHER SEAT!\n\n");

        n->data.state = !n->data.state;

        return printStyled("44m\n\nOPERATION PERFORMED!\n\n"); 
    }

    void showSeatsAvailable()
    {
        Horzbound(SEATSINROW);
        for (int16_t i = 0; i < ROWCOUNT; i++) 
        {
            printf("\t\t  │ ");
            rows[i]->traverse();
            printf(" │ \n");
        }
        Horzbound(SEATSINROW);
        showScreen(SEATSINROW);
    }
};

int main()
{
    bool seats[] = {false,true,false};
    Cinemax cm = Cinemax();
    while (true) 
    {
        printf("-------------------------------------");
        printf("\n1.VIEW SEATS\t\t2.BOOK SEATS\n3.CANCEL BOOKING\t4.EXIT\n");

        int16_t ch,r,s;
        scanf("%d",&ch);

        switch (ch) 
        {
        case 1:
            cm.showSeatsAvailable();
            break;
        case 2:
            printf("Enter row no.(0-9) & seat no.(1-7) : ");
            scanf("%d %d",&r,&s);
            cm.CinemaxSeatBook(r%(ROWCOUNT+1),s%(SEATSINROW+1),true);                   //true to book seat & false to cancel
            break;
        case 3:
            printf("Enter row no.(0-9) & seat no.(1-7) : ");
            scanf("%d %d",&r,&s);
            cm.CinemaxSeatBook(r%(ROWCOUNT+1),s%(SEATSINROW+1),false);
            break;
        default:
            return 0;
        }
    }
}