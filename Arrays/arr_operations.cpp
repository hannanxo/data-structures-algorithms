#include<iostream>
using namespace std;

class Arrayadt
{
protected:

int arr[5]={1,2,3};
int *current=NULL;
int size=0;
int len=5;
int *last=NULL;
int count=0;

public:
Arrayadt()
{
    last=(arr+(len-1));
}

void get()
{
cout<<"Get current pointer "<<*current<<endl;
}

void update(int x)
{
cout<<"Updating the value"<<endl;
*current=x;
}

void length()
{
}

void back()
{
if(current==arr)
{
    cout<<"Out of Bound"<<endl;
}
else
{
current--;
cout<<"Move Back to "<<*current<<endl;
}
}

void next()
{
if(current==last)
{
 cout<<"Out of Bound"<<endl;   
}
else
{
current++;
cout<<"Move Next to "<<*current<<endl;
}
}

void start()
{
current=arr;
cout<<"Current ptr is at: "<<*current<<endl;


}

void end()
{
current=last;
cout<<"Current ptr is at: "<<*current<<endl;

}

void remove()
{
cout<<"Deleting value"<<endl;

int *free2=current;

while(free2!=last)
{ 
 *free2=*(free2+1);
  *free2++;

}
*free2=0;
count--;
}

void add(int x)
{
    cout<<"Adding value"<<endl;
    int *free=last;

    while(free!=current)
{
    *free=*(free-1);
    free--;
    
}
     count++;
    *current=x;
}

void display()
{
    for (int i = 0; i < len; ++i)
{
    cout<<*(arr+i)<<endl;
}
}

};

int main()
{
Arrayadt obj;
obj.display();
cout<<endl;
obj.end();        //move to end
obj.length();
//obj.start();
obj.add(69);
obj.display();
obj.back();
obj.add(33);
obj.display();
cout<<endl;

 obj.get();       //get pointer 
 cout<<endl;
 obj.update(22);
 cout<<endl;
 //obj.length();
 obj.display();
 obj.length();
 obj.add(57);
 cout<<endl;
 obj.display();
 obj.length();
 obj.back();
 obj.get();
 obj.remove();
 obj.get();
 obj.display();
 obj.start();      //move to start
 obj.next();       //move next
 //obj.length();
 obj.display();
 obj.next();
 obj.next();
 obj.next();
// obj.next();
return 0;


}