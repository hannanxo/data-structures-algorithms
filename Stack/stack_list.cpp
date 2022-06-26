#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;
};

class stack
{
    struct Node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push()
    {
        int value;
        Node *ptr;
        cout << "\n Enter the no.. ";
        cin >> value;
        ptr = new Node;
        ptr->data = value;
        ptr->next = NULL;
        if (top != NULL)
        {
            ptr->next = top;
            //top = ptr;
        }
        top = ptr;
    }
    void pop()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "\n Empty stack";
            return;
        }
        temp = top;
        top = top->next;
        cout << "\n popped element is " << temp->data;
        delete temp;
    }
    void printer()
    {
        Node *temp1 = top;
        cout << "\n The stack is ";
        while (temp1 != NULL)
        {
            cout << temp1->data << " ";
            temp1 = temp1->next;
        }
        cout << "\n";
    }
};

int main()
{
    stack s;
    int n;
    cout << "\n how many elements";
    cin >> n;
    for (int i = 0; i < n; i++)
        s.push();
    s.printer();
    cout << "\n how many elements to pop?";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s.pop();
    }
    s.printer();
    return 0;
}