#include <iostream>
#include "LinkedList.cpp"
using namespace std;
#define STARTTIME 10
#define ENDTIME 18
#define MINTIME 1
#define MAXTIME 2

class AppointmentSchedule {
    LinkedList* appointments;
public:
    AppointmentSchedule(){
        appointments = new LinkedList(STARTTIME,ENDTIME,MINTIME);
    }
    void showAvailableSlots(){
        appointments->traverseRecur(appointments->head);
    }
    void bookAppointment(int16_t strt,int16_t dur)
    {
        Node* n = appointments->fetchNode(strt);
        if (!n)
            return printStyled("41m\n\nENTER A VALID TIME SLOT!\n\n");
        
        if (n->data.state)
            return printStyled("45m\n\nTRY OPERATION ON ANOTHER SEAT!\n\n");
        n->data.val2=dur;
        n->data.state = !n->data.state;
        if (dur==MAXTIME) appointments->removeAfter(n);

        return printStyled("44m\n\nOPERATION PERFORMED!\n\n"); 
    }
    void cancelAppointment(int16_t strt){
        Node* n = appointments->fetchNode(strt);
        if (!n)
            return printStyled("41m\n\nENTER A VALID TIME SLOT!\n\n");
        
        if (!n->data.state)
            return printStyled("45m\n\nTRY OPERATION ON ANOTHER SEAT!\n\n");

        n->data.state = !n->data.state;
        if (n->data.val2==MAXTIME) 
            appointments->insertAfter(n);
        n->data.val2=MINTIME;
        return printStyled("44m\n\nOPERATION PERFORMED!\n\n"); 
    }
    void sort(){
        appointments->insertAfter(appointments->fetchNode(15),4);
        appointments->insertAfter(appointments->fetchNode(17),1);
        appointments->insertAfter(appointments->fetchNode(14),5);
        appointments->insertAfter(appointments->fetchNode(10),222);
        printStyled("45m\n\nINSERTED RANDOM SLOTS TO MAKE LIST UNSORTED :\n\n");
        showAvailableSlots();
        appointments->sort();
        printStyled("45m\n\nAFTER SORTING :\n\n");
        showAvailableSlots();
        appointments->removeAfter(appointments->fetchNode(1));
        appointments->removeAfter(appointments->fetchNode(1));
        appointments->removeLast();
        appointments->removeFirst();
        printStyled("45m\n\nSUCCESSFULLY REMOVED THE TEST NODES\n\n");
    }
    void sortPtr(){
        appointments->insertAfter(appointments->fetchNode(15),4);
        appointments->insertAfter(appointments->fetchNode(17),1);
        appointments->insertAfter(appointments->fetchNode(14),5);
        appointments->insertAfter(appointments->fetchNode(10),222);
        printStyled("45m\n\nINSERTED RANDOM SLOTS TO MAKE LIST UNSORTED :\n\n");
        showAvailableSlots();
        appointments->sortPtr();
        printStyled("45m\n\nAFTER SORTING :\n\n");
        showAvailableSlots();
        appointments->removeAfter(appointments->fetchNode(1));
        appointments->removeAfter(appointments->fetchNode(1));
        appointments->removeLast();
        appointments->removeFirst();
        printStyled("45m\n\nSUCCESSFULLY REMOVED THE TEST NODES\n\n");
    }
    
};
int main(){
    AppointmentSchedule as = AppointmentSchedule();
    while (true) 
    {
        printf("-------------------------------------");
        printf("\n1.VIEW SLOTS\t\t2.BOOK APPOINTMENT\n3.CANCEL BOOKING\t4.SORT\n5.SORT WITH PTR\t6.EXIT\n");

        int16_t ch;
        int strt,dur;
        scanf("%d",&ch);

        switch (ch) 
        {
        case 1:
            as.showAvailableSlots();
            break;
        case 2:
            printf("Enter start time.(10-17) & duration.(1-2) : ");
            scanf("%d %d",&strt, &dur);
            as.bookAppointment(strt,dur);
            endStyled();
            break;
        case 3:
            printf("Enter start time.(10-17) : ");
            scanf("%d",&strt);
            as.cancelAppointment(strt);
            endStyled();
            break;
        case 4:
            as.sort();
            endStyled();
            break;
        case 5:
            as.sortPtr();
            endStyled();
            break;
        default:
            return 0;
        }
    }
}