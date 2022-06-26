#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};

class sll
{
public:
    node *head;
    node *curr;

    sll()
    {
        head = NULL;
        curr = NULL;
    }

    ~sll()
    {
        curr = head;
        while (curr != NULL)
        {
            curr = head->next;
            delete head;
            head = curr;
        }
    }

    void add(int v)
    {
        if (head == NULL)
        {
            head = new node;
            head->info = v;
            head->next = NULL;
        }
        else
        {
            curr = head;

            while (curr->next != NULL)
                curr = curr->next;

            node *temp = new node;
            temp->info = v;
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    void display()
    {
        curr = head;
        while (curr != NULL)
        {
            cout << curr->info << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
node *addingLists(node *first, node *second)
{
    int sum = 0, carry = 0;
    node *prev = NULL, *temp = NULL;
    node *curr1 = first, *curr2 = second;
    node *result = NULL;
    int count = 0;
    int firstsize = 0, secondsize = 0;

    while (curr1 != NULL)
    {
        firstsize++;
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        secondsize++;
        curr2 = curr2->next;
    }

    curr1 = first, curr2 = second;
    int difference = firstsize - secondsize;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (difference)
        {
            count++;
            if (difference > 0)
            {
                for (int i = 0; i < difference; i++)
                {
                    if (i == 0)
                    {
                        result = new node;
                        temp = result;
                        prev = result;
                        result->info = curr1->info;
                        result->next = NULL;
                        curr1 = curr1->next;
                    }
                    else
                    {
                        temp = new node;
                        temp->info = curr1->info;
                        if (prev != NULL)
                            prev->next = temp;
                        prev = temp;
                        temp->next = NULL;
                        curr1 = curr1->next;
                    }
                }
            }
            else
            {
                for (int i = 0; i < abs(difference); i++)
                {
                    if (i == 0)
                    {
                        result = new node;
                        temp = result;
                        prev = result;
                        result->info = curr2->info;
                        result->next = NULL;
                        curr2 = curr2->next;
                    }
                    else
                    {
                        temp = new node;
                        temp->info = curr2->info;
                        if (prev != NULL)
                            prev->next = temp;
                        prev = temp;
                        temp->next = NULL;
                        curr2 = curr2->next;
                    }
                }
            }
            difference = 0;
        }

        sum = curr1->info + curr2->info;
        if (sum > 9)
        {
            sum %= 10;
            carry = 1;
        }
        if (count)
        {
            temp = new node;
            temp->info = sum;
            prev->info += carry;
            prev->next = temp;
            prev = temp;
            temp->next = NULL;
        }
        else if (!count)
        {
            result = new node;
            result->info = sum;
            prev = result;
            temp = result;
            result->next = NULL;
        }

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return result;
}

int main()
{
    sll l1, l2, l3;
    node *h;
    l1.add(1);
    l1.add(2);
    l1.add(3);
    l1.add(4);

    l2.add(1);
    l2.add(1);
    l2.add(1);

    l1.display();
    l2.display();

    h = addingLists(l1.head, l2.head);
    l3.head = h;
    l3.display();

    return 0;
}