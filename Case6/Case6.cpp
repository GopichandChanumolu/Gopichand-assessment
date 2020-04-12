
/*Name of the program:To demonstrate a class has a two private member vairables int* and char[20]. 
Complete the class declaration and definition with all the necessary constructors/destructor/operator
overloading/member functions.

filename:Case6.cpp
date:11-04-2020
Author:Ch.Gopi Chand
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class Hcl{
private:
    int *iEmpid;
    char cEmpname[20];
public:
    Hcl()
    {
        cout<<"Constructor is created"<<endl;
    }
    Hcl(int *iEmpno,char *cName)
    {
        cout<<"Parameterized Constructor is created"<<endl;
        iEmpid=iEmpno;
        strcpy(cEmpname,cName);
    }

/*Function Name :Initialize
  Parameters    :int*,char
  Return Type   :no return type
  Usage         :to assign value to private variables*/

    void Initialize(int *iEmpno,char cName[])
    {
        iEmpid=iEmpno;
        strcpy(cEmpname,cName);
    }

/*Function Name :display
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to display private variables*/

    void display()
    {
        cout<<"Employee ID:"<<*iEmpid<<endl<<"Employee Name:"<<cEmpname<<endl;
        cout<<endl;
    }

    void operator ++()  //increment operator overloading
    {
        ++(*iEmpid);
    }
    ~Hcl()
    {
        cout<<"Destructor is called"<<endl;
    }
};

int main(int argc,char* argv[])
{
    if(argc>=2)
    {
        //For comparing input string through command line is -h
		if(strcmp(argv[1],"-h")==0)     
        {
            cout<<"This program is to take two private member vairables int* and char[20]."<<endl;
            cout<<"have to use constructors/destructor/operator overloading/member functions"<<endl;
            cout<<"Enter employee id as integer and employee name as characters"<<endl;
        }
    }
    else
    {
        Hcl obj;
        int iEmpid;
        char cEmpname[20];
        cout<<"Enter ID of Employee:"<<endl;;
        cin>>iEmpid;
        cout<<"Enter Name of Employee:"<<endl;
        getchar();
        cin.get(cEmpname,20,'\n');
        cout<<endl<<"Using Parameterized Constructor"<<endl;
        //parameterized constructor
        Hcl obj2(&iEmpid,cEmpname);    
        obj2.display();
        cout<<"After Operator Overloading"<<endl;
        //calling of increment operator overloading
        ++obj2;     
        cout<<"Using Member Function"<<endl;
        //calling of member function
        obj.Initialize(&iEmpid,cEmpname);    
        obj.display();
    }
    return 0;
}




