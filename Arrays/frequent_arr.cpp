#include <iostream>
using namespace std;

class arraylist
{
protected:
    int arr[8] = {2, 2, 3, 3, 3, 4, 5, 6};
    int *current, *last, *free, *head, *tail, *temp;
    int length, size, count;

public:
    arraylist()
    {
        current = last = free = head = tail = temp = NULL;
        length = 8;
        count = 0;
        last = (arr + (length - 1));
    }

    void mostfrequent(int left, int right, int frequency)
    {
        if ((0 <= left && left <= right && right < length) && (2 * frequency >= right - (left + 1)))
        {
            head = arr + left;
            tail = arr + right;
            int freqcount = 1;

            while (head != tail + 1)
            {
                temp = head + 1;
                //if (head != tail)
                {
                    while (temp != tail + 1)
                    {
                       if (*temp == *head)
                        {
                            freqcount++;
                        }
                        cout<<"LORU"<<*temp;
                        temp++;
                        cout<<"LALIT"<<*temp;
                        cout<<endl;
                    }
                }

                if (freqcount >= frequency)
                {
                cout << "Frequency :" << *head << endl;
                }

                head++;
                freqcount = 1;
            }
            head = tail = temp = NULL;
        }
        else
        {
            cout << "Condition is not met " << endl;
        }
    }
    void add(int x) // Adding elements in array by shifting the elements in indexes
    {
        cout << "Adding value" << endl;
        int *free = last;

        while (free != current)
        {
            *free = *(free - 1);
            free--;
        }
        count++;
        *current = x;
    }

    void display()
    {
        for (int i = 0; i < length; ++i)
        {
            cout << *(arr + i) << endl;
        }
    }

    void back() // Moves the current pointer to -1 position
    {
        if (current == arr)
        {
            cout << "Out of Bound" << endl;
        }
        else
        {
            current--;
            cout << "Move Back to " << *current << endl;
        }
    }

    void next() // Moves the current pointer to +1 position
    {
        if (current == last)
        {
            cout << "Out of Bound" << endl;
        }
        else
        {
            current++;
            cout << "Move Next to " << *current << endl;
        }
    }

    void get() // Gives the position of current pointer
    {
        cout << "Get current pointer " << *current << endl;
    }

    void start() // Moves to the current pointer to the start of array
    {
        current = arr;
        cout << "Current ptr is at: " << *current << endl;
    }

    void end() // Moves to the current pointer to the end of array
    {
        current = last;
        cout << "Current ptr is at: " << *current << endl;
    }
};

int main()
{
    arraylist obj;
    obj.display();
    obj.start();
    obj.get();
    obj.next();
    obj.next();
    obj.next();
    obj.next();
    obj.next();
    obj.get();
    obj.add(4);
    obj.next();
    obj.add(5);
    obj.next();
    obj.add(6);

    obj.display();
    obj.mostfrequent(0, 3, 1);
    return 0;
}