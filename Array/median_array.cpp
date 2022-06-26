#include<iostream>
using namespace std;
//The time complexity is Θ(N) as the mergeing of two sorted arrays will take n/2, n/2 time (means n) so it will be  Θ(N) combined complexity.
//No Recurrence Relation as no recursion is used.
double median_finder(int r1[], int r2[], int size1, int size2)
{// using double for precision 
        int size = size1 + size2;
        int i = 0;   
        int j = 0;   
        int check = 0;    
        int result = 0;    
        int even = 0;    
        int mid = 0;    
        
        if(size % 2 == 0)   // O(1)
        {
            even = 1;      
            mid = size / 2;    
        }
        else                 // O(1) 
        {
            mid = (size / 2) + 1;   
        }

        while(check < mid && i < size1 && j < size2)  // n + 1 times
        {
            if(r1[i] <= r2[j])
            {
                result = r1[i];         // n times
                i++;                    // n times
            }
            else
            {   
                result = r2[j];        // n times 
                j++;                   // n times
            }
            check++;   // n times
        }

        if(!even)    // O(1)		// If the number of elements in the combined array are even, then median will be average
        {
            return result;
        }
        else         // O(1)
        {               // Else it will be the sum of the two middle values(indetempes) divided by 2
            double temp;
            double temp1=result;
			
            if(i < size1 && j == size2)       // O(1) 
                temp = r1[i];          

            else if(j < size2 && i == size1)  // O(1)
                temp = r2[j];           

            else if(r1[i] <= r2[j])           // O(1)
                temp = r1[i];          

            else                             // O(1)
                temp = r2[j];          
            
            return double(temp + temp1)/2;
        }
    }

int main()
{
    int r1[] = {80,85,86,87,100};
    int r2[] = {2,60,69,70,86};
    // 2 60 69 70 80 85 86 86 87 100

    //int r1[]={1,2,4,5};
    //int r2[]={3,9,12};
    // 1 2 3 4 5 9 12

    //int r1[]={69,69,82,90,93,99};
    //int r2[]={33,47,88,100};
    //33 47 69 69 82 88 90 93 99 100

    int size1 = sizeof(r1) / sizeof(int);
    int size2 = sizeof(r2) / sizeof(int);
    cout<<"Median of the combined array is : "<<median_finder(r1,r2,size1,size2);

}
