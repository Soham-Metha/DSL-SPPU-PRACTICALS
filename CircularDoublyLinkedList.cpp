#include <iostream>
#include "Node.cpp"
#include "helpers.cpp"

class CircularDoublyLinkedList
{
public:
    Node *head, *tail;

    CircularDoublyLinkedList(int16_t n);
    void insertNode(Node *node);
    void traverse();
    Node *fetchNode(int16_t nodeVal);
    ~CircularDoublyLinkedList();
};

CircularDoublyLinkedList::CircularDoublyLinkedList(int16_t n)
{
    head = NULL;
    for (int16_t i = 0; i <= n; i++)
        insertNode(new Node(i + 1));
}

void CircularDoublyLinkedList::insertNode(Node *node)
{
    if (!head)
    {
        node->next = node->prev = node;
        head = node;
        return;
    }
    tail = head->prev;

    node->next = head;
    head->prev = node;
    node->prev = tail;
    tail->next = node;
}

void CircularDoublyLinkedList::traverse()
{
    Node *tmp = head;
    while (tmp->next != head)
    {
        printStyled(tmp->data.state ? "4;47m - " : "4;42m + ");
        tmp = tmp->next;
    }
}

Node *CircularDoublyLinkedList::fetchNode(int16_t nodeVal)
{
    Node *tmp = head;
    while (tmp->data.val != nodeVal)
    {
        if (tmp->next == head)
            return NULL;
        tmp = tmp->next;
    }
    return tmp;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
    delete head;
}