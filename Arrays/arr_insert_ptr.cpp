#include<iostream>
using namespace std;
class list
{
protected:
  int arr[6]={};
  int *ptr=NULL;

public:
list()
{
  ptr=arr; 
}
void add(int n)
{
  for(int i=0;i<n;i++)
  {
    cin>>*(ptr+i);
  }
  ptr++;
  }

void display(int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<"Array "<<*(arr+i)<<endl;
  }
}
};

int main()
{
  list obj;
  int n=0;
  cout<<"Enter size"<<endl;
  cin>>n;
  obj.add(n);
  obj.display(n);

  return 0;

}