#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

class linked_list
{
public:
  node *head, *tail;
  int count = 0;
  linked_list()
  {
    head = NULL;
    tail = NULL;
  }

  void add_node(int n)
  {
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if (head == NULL)
    {
      head = tmp;
      tail = tmp;
    }
    else
    {
      tail->next = tmp;
      tail = tail->next;
    }
  }

  void reverseprint(node *head)
  {

    if (head == NULL)
    {
      return;
    }
    reverseprint(head->next);
    cout << " " << head->data;
  }

  int reverselenght(node *head)
  {
    if (head == NULL)
    {
      return 0;
    }
    return 1 + reverselenght(head->next);
  }
};

int main()
{
  linked_list a;
  a.add_node(1);
  a.add_node(2);
  a.add_node(3);
  a.add_node(4);
  a.reverseprint(a.head);
  cout << endl;
  cout << "Lenght " << a.reverselenght(a.head);
  return 0;
}