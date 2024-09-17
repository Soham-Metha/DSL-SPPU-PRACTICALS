#include <iostream>
struct Data
{
    int16_t val;
    int16_t val2;
    bool state;
    std::string name;

    Data()
    {
        val = 0;
        val2 = 0;
        name = "";
        state = false;
    }
};

struct Node
{
public:
    Data data;
    Node *prev;
    Node *next;

    Node();
    Node(int16_t val);
    Node(int16_t val, int16_t val2);
    ~Node();
};

Node::Node()
{
    this->data.val = 0;
    this->prev = NULL;
    this->next = NULL;
}

Node::Node(int16_t val)
{
    this->data.val = val;
    this->data.val2 = 1;
    this->prev = NULL;
    this->next = NULL;
}
Node::Node(int16_t val, int16_t val2)
{
    this->data.val = val;
    this->data.val2 = val2;
    this->prev = NULL;
    this->next = NULL;
}

Node::~Node()
{
    delete this->next;
}
struct Node *swap(struct Node *ptr1, struct Node *ptr2)
{
    struct Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}