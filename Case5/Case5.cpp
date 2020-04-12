
/*Name of the program:To demonstrate Different way to initialize the private member variables in a class.
Order of the construction and destruction of objects with and without virtual.
filename:Case5.cpp
date:10-04-2020
Author:Ch.Gopi Chand
*/
#include <iostream>
#include<string.h>
using namespace std;
 
class Number
{
private:
    int a;
public:
    void getNum(int x);
    //declaration of friend function
    friend void printNum(Number NUM);
};
 
//class member function definitions
void Number::getNum(int x)
{
    a=x;
    
}
 
//friend function definition, no need of class name with SRO (::)
void printNum(Number NUM)
{
    cout << "Value of a (private data member of class Number): " << NUM.a<<endl;
 
}

class b {
   public:
      b() {
         cout<<"Constructing Called in main class "<<endl;
      }
      virtual ~b() {
         cout<<"Virtual Destructing called in main class "<<endl;
      }
};
class d: public b {
   public:
      d() {
         cout<<"Constructing called in derived class "<<endl;
      }
      ~d() {
         cout<<"Destructing called in derived class "<<endl;
      }
};
 
int main(int argc, char *argv[])
{

if(argc>=2)
    	{
	    	//For comparing input string through command line is -h
			if(strcmp(argv[1],"-h")==0)	
	    {
            cout<<"This program is to initialize private members in the class "<<endl;
			cout<<"also display the order of construction and destruction of objects with and without virtual"<<endl;
	    }
    }
	else
	{
    int iN;
    //Object declaration
	Number nObj; 
    cout<<"Enter a integer number"<<endl;
    cin>>iN;
    nObj.getNum(iN);
    printNum(nObj);
    d *derived = new d();
    b *bptr = derived;
    delete bptr;
	}
}

