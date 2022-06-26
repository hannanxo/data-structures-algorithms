#include<iostream>
#include<stdlib.h>
#include<conio.h>
		
struct node
  {
	char info[15];
  };

class trial
{
   private :
		node obj1, *temp1, *temp2, *temp3;
		int I, length;
		char *p,*q;
   public :
		trial();
		~trial();   // Prototype
		void startin();
};
int main()
{
  system("cls");
  trial lnk;
  lnk.startin();

  getch();
}//----------------------------------------------------------------------
trial :: trial()
{
	temp1 = temp2 = temp3 = NULL;

}//--------------------------------------------------------------------
trial :: ~trial()
{
   delete temp1;
   delete temp2, temp3;
   delete[] p;          // delete 10 chars
}
void trial :: startin()
{
   std::cout<<"\n Making use of \"new\" and \"delete\" is as follows.\n";
   std::cout<<"\n ---------------------------------------------------\n\n";
   temp1 = new node;
   temp2 = new node;
   std::cout<<"\n Enter information about temp1.\n";
   std::cin>>temp1->info;
   std::cout<<"\n Enter information about temp2.\n";
   std::cin>>temp2->info;

   temp3 = &obj1;
   std::cout<<"\n Enter information about temp3.\n";
   std::cin>>temp3->info;

   std::cout<<"\n Showing information of temp1.\n";
   std::cout<<temp1->info;
   std::cout<<"\n Showing information of temp2.\n";
   std::cout<<temp2->info;
   std::cout<<"\n Showing information of temp3.\n";
   std::cout<<temp3->info;
   std::cout<<"\n ---------------------------------------------------\n\n";
   
std::cout<<" Now enter the length of character array.\n";
    std::cin>>length;

    p = new char[length];    //  allocate 10 chars
    q = p;
     std::cout<<" Now enter "<<length<<" characters to fill an array.\n";
     for( int i=0;i<length; i++ )
     {
       std::cin>>*p;
       p = p + 1;
     }
    p = q;
    
 std::cout<<" \nElements of array are as follows.\n";
    for( int i=0;i<length; i++ )
    {
      std::cout<<*p<<", ";
      p = p + 1;
    }
   p = q;

}

