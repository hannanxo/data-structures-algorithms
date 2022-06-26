#include <iostream>
using namespace std;

void swap(int &first, int &second)
{
    int swapper = first;
    first = second;
    second = swapper;
}

void merge(int arr[], int start, int middle, int end)
{
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    int leftArr[leftSize];
    int rightArr[rightSize];

    int i = 0;
    int j = 0;

    //storing left half in left Arr
    for (i; i < leftSize; i++)
        leftArr[i] = arr[start + i];

    //storing the right half in the right array
    for (j; j < rightSize; j++)
        rightArr[j] = arr[middle + j + 1];

    i = j = 0;     //reset the index
    int k = start; //indexing the original array

    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //in case still items left in left/right array, store them in the main array
    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        k++;
        i++;
    }

    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int middle = (start + end) / 2;
    mergeSort(arr, start, middle);
    //mergeSort(arr, middle + 1, end);
    merge(arr, start, middle, end);
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[5] = {5, 3, 4, 1, 2};

    print(arr, 5);
    mergeSort(arr, 0, 4);
    print(arr, 5);
    int a,b;
    a=1;
    b=2;
    int c=a/b;
    cout<<c;

    return 0;
}