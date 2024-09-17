#include <iostream>
#include "Node.cpp"
#include "helpers.cpp"

class LinkedList
{
public:
    Node *head;
    Node **ptrToHead;

    LinkedList(int16_t lb, int16_t ub, int16_t duration);
    Node *fetchNode(int16_t nodeVal);
    Node *fetchNodeRecur(int16_t nodeVal, Node *tmp);
    void removeNode(int16_t nodeVal);
    void removeAfter(Node *node);
    void removeFirst();
    void removeLast();
    void insertAfter(Node *node);
    void insertAfter(Node *node, int16_t v);
    void insertNode(Node *node);
    void traverse();
    void sortPtr();
    void sort();

    void insertNodeRecur(Node *node, Node **tmp);
    void traverseRecur(Node *tmp);
    ~LinkedList();
};

LinkedList::LinkedList(int16_t lb, int16_t ub, int16_t duration)
{
    head = NULL;
    ptrToHead = &head;
    for (int16_t i = lb; i <= ub; i += duration)
        insertNode(new Node(i, duration));
    {
    }
}

Node *LinkedList::fetchNode(int16_t nodeVal)
{
    Node *tmp = head;
    while (tmp->data.val != nodeVal)
    {
        if (tmp->next == NULL)
            return NULL;
        tmp = tmp->next;
    }
    return tmp;
}

void LinkedList::removeNode(int16_t nodeVal)
{
    Node *prev = fetchNode(nodeVal - 1);
    removeAfter(prev);
}

void LinkedList::removeFirst()
{
    Node *toBeDeleted = head;
    head = head->next;
    toBeDeleted->next = NULL;
    delete toBeDeleted;
}
void LinkedList::removeLast()
{
    Node *tmp = head;
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    Node *toBeDeleted = tmp->next;
    tmp->next = NULL;
    delete toBeDeleted;
}
void LinkedList::removeAfter(Node *node)
{
    Node *prev = node;
    Node *toBeDeleted = prev->next;
    prev->next = toBeDeleted->next;
    toBeDeleted->next = NULL;
    delete toBeDeleted;
}

void LinkedList::insertAfter(Node *node)
{
    Node *prev = node;
    int16_t val = (prev->data.val + prev->data.val2);
    Node *newNode = new Node(val);
    newNode->next = prev->next;
    prev->next = newNode;
}
void LinkedList::insertAfter(Node *node, int16_t v)
{
    Node *prev = node;
    Node *newNode = new Node(v);
    newNode->next = prev->next;
    prev->next = newNode;
}

void LinkedList::insertNode(Node *node)
{
    if (!head)
    {
        head = node;
        return;
    }
    Node *tmp = head;
    while (tmp->next && tmp->data.val < node->data.val)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void LinkedList::traverse()
{
    Node *tmp = head;
    while (tmp->next)
    {
        printStyled("44m");
        cout << tmp->data.val << ":00 to " << (tmp->data.val + tmp->data.val2) << ":00 ";
        printStyled(tmp->data.state ? "47m - BOOKED" : "42m + FREE");
        endStyled();
        printf("\n");
        tmp = tmp->next;
    }
}

void LinkedList::sort()
{
    bool swapped;
    Node *i, *j = NULL;
    do
    {
        swapped = false;
        i = head;

        while (i->next != j)
        {
            if (i->next->data.val < i->data.val)
            {
                int temp = i->next->data.val;
                i->next->data.val = i->data.val;
                i->data.val = temp;

                swapped = true;
            }
            i = i->next;
        }
        j = i;
    } while (swapped);
}

void LinkedList::sortPtr()
{
    bool swapped;
    Node **i, *j = NULL;
    do
    {
        swapped = false;
        i = ptrToHead;

        while ((*i)->next != j)
        {
            if ((*i)->next->data.val < (*i)->data.val)
            {
                Node *temp = (*i)->next;
                (*i)->next = temp->next;
                temp->next = *i;
                *i = temp;

                swapped = true;
            }
            i = &(*i)->next;
        }
        j = *i;
    } while (swapped);
}

LinkedList::~LinkedList()
{
    delete head;
}

/*
void LinkedList::sort(){
    Node *i,*prev;
    Node *j = NULL;
    while(head->next!=j) {
        prev = head;
        i = prev->next;
        while (i->next!=j)
        {
            if (i->data.val < prev->data.val) {
                int temp = i->data.val;
                i->data.val = prev->data.val;
                prev->data.val = temp;
            }
            prev = i;
            i = prev->next;
        }
        j=i;
    }
}
*/

Node *LinkedList::fetchNodeRecur(int16_t nodeVal, Node *tmp)
{

    if (tmp->data.val == nodeVal || tmp == NULL)
        return tmp;
    else
    {
        fetchNodeRecur(nodeVal, tmp->next);
    }
    return NULL;
}

void LinkedList::insertNodeRecur(Node *node, Node **tmp)
{
    if (!(*tmp))
    {
        (*tmp) = node;
        return;
    }
    if (((*tmp)->data.val < node->data.val))
    {
        insertNodeRecur(node, &(*tmp)->next);
    }
    else
    {
        node->next = (*tmp)->next;
        (*tmp)->next = node;
    }
    return;
}

void LinkedList::traverseRecur(Node *tmp)
{
    if (tmp == NULL)
        return;

    printStyled("44m");
    cout << tmp->data.val << ":00 to " << (tmp->data.val + tmp->data.val2) << ":00 ";
    printStyled(tmp->data.state ? "47m - BOOKED" : "42m + FREE");
    endStyled();
    printf("\n");
    traverseRecur(tmp->next);
}