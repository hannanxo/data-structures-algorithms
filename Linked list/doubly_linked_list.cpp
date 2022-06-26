#include <iostream>
using namespace std;

struct node
{
  int info;
  node *next;
  node *previous;
};
class list
{
private:
  node *head;
  node *temp, *temp1;

public:
  list()
  {
    head = temp = temp1 = NULL;
  }
  void add()
  {
    if (head == NULL)
    {
      cout << endl;
      temp = new node;
      cout << "Enter info part of element" << endl;
      cin >> temp->info;
      temp->next = NULL;
      head = temp;
      return;
    }

    int key;
    int count = 0;
    int afterwhich;
    cout << "Afterwhich " << endl;
    cin >> afterwhich;
    temp = head;
    cout << "Enter where you want to insert node" << endl;
    cin >> key;

    while (temp != NULL)
    {
      if (temp->info == key)
      {
        if (count == afterwhich)
        {
          temp1 = new node;
          cout << "Enter data of node" << endl;
          cin >> temp1->info;
          temp1->next = temp->next;
          temp->next = temp1;
          break;
        }
      }
      count++;

      temp = temp->next;
    }
    if (temp == NULL)
    {
      cout << "Key not found" << endl;
    }
  }

  void del()
  {
    if (head == NULL)
    {
      cout << "Linked list is empty" << endl;
      return;
    }
    int key;
    int count = 0;
    int afterwhich;
    cout << "Afterwhich" << endl;
    cin >> afterwhich;
    cout << "Enter what you want to delete" << endl;
    cin >> key;
    temp = head;
    while (temp != NULL)
    {
      if (temp->next->info == key)
      {
        if (count == afterwhich)
        {
          temp1 = new node;
          temp1 = temp->next;
          temp->next = temp1->next;
          delete temp1;
          break;
        }
        count++;
      }
      temp = temp->next;
    }
    if (temp == NULL)
    {
      cout << "Key not found" << endl;
    }
  }

  void search()
  {
    if (head == NULL)
    {
      cout << "Linked list is empty" << endl;
    }
    else
    {
      temp = head;
      int key;
      cout << "Enter data to be searched" << endl;
      cin >> key;

      while (temp != NULL)
      {
        if (temp->info == key)
        {
          cout << "Match found" << endl;
          break;
        }
        temp = temp->next;
      }
      if (temp == NULL)
      {
        cout << "Key not found" << endl;
      }
    }
  }

  void print()
  {
    temp = head;
    if (head == NULL)
    {
      cout << "Linked list is empty" << endl;
      return;
    }
    {
      cout << "Displaying elements of the linked list" << endl;

      while (temp != NULL)
      {

        cout << temp->info << endl;
        temp = temp->next;
      }
    }
  }
  void empty()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
    }
    else
    {
      cout << "List is not empty" << endl;
    }
  }
};

int main()
{

  list obj;
  int option;

  cout << "Doubly linked list code" << endl;
  cout << "Select from the following options" << endl;
  cout << "Select 1 to add element to the linked list" << endl;
  cout << "Select 2 to delete element from the linked list" << endl;
  cout << "Select 3 to search an element from the linked list" << endl;
  cout << "Select 4 to print the elements of the linked list" << endl;
  cout << "Select 5 to exit" << endl;
  bool condition = true;

  while (condition != false)
  {
    cin >> option;
    switch (option)
    {
    case 1:
      obj.add();
      cout << endl;
      break;

    case 2:
      obj.del();
      cout << endl;
      break;

    case 3:
      obj.search();
      cout << endl;
      break;

    case 4:
      obj.print();
      cout << endl;
      break;

    case 5:
      condition = false;
    default:
      break;
    }
  }

  return 0;
}