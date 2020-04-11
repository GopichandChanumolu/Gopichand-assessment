//case 3:program to demonstrate the variable scope,modifier types and storage classes/
/*purpose	:Program to demonstrate the variable scope,modifier types and storage classes
  filename	:Case3
  Author 	:Ch.Gopi chand
  Date   	:09/04/2020*/
  
#include<iostream>
#include<string.h>
using namespace std;
 //global variable
int iA=10;                          
int iE;
extern int iEx=20;
 //variable scope function
void scope()                       
{
	int iB=20;                      //local variable
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"                     VARIABLE SCOPE                        "<<endl;
	cout<<"global variable a:"<<iA<<endl;   
	cout<<"local variable  b:"<<iB<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
}
//modifier types function
void modifier()                     
{
	//initialization of modifier types
	signed int iData=-30;
	unsigned int iUdata=40;
	long lData=12345678;
	short sData=100;
	cout<<"                     MODIFIER TYPES                         "<<endl;
	cout<<"signed int idata   : "<<iData<<endl;
	cout<<"unsigned int uidata: "<<iUdata<<endl;
	cout<<"long ldata         : "<<lData<<endl;
	cout<<"short sdata        : "<<sData<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
}
//storage class function
void storage()                      
{
	cout<<"                     STORAGE CLASSES                         "<<endl;
	int iX;
	
	cout<<"Enter a value for A: "<<endl;
	cin>>iX;
	
    //addition of two variable with auto storage class as return type
    auto float fZ=iX;                  
    
    cout<<"value of auto variable z                                  : "<<fZ<<endl;
    //register storage classes initialization
    register int iR=iX;             
    cout<<"address of register variable A is                         : "<<&iR<<endl;
    //extern storage class declaration
    extern int iE;                  
    cout<<"extern storage value before initialization is             : "<<iE<<endl;
    // intializing external storage value 
    iE=iX;
    cout<<"extern storage value after initialization is              : "<<iE<<endl;
    auto int iAe=iEx+iE;
    cout<<"value of ae after adding extern global & local variable is: "<<iAe<<endl;
    
}
//static storage class function
void staticstorage()                
{
    static int iS=100;          
    iS++;
    cout<<"static variable s is                                      :"<<iS<<endl;
}
//mutable class
class number                        
{
	mutable int iNum;
	public:
		//getdata function which is kept as const
		void getdata() const        
		{
			iNum=10;
			iNum++;
		}
		//display function for displaying the mutable number
		void display()              
		{
			getdata();
			cout<<"mutable num                                               :"<<iNum<<endl;
			cout<<"------------------------------------------------------------"<<endl;
		}
};
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    //if loop for comparing the input string with "-h"
		if(strcmp(argv[1],"-h")==0)	  				
	    {
            cout<<"                                     USAGE                                          "<<endl;
            cout<<"This program explains the usage of variable scope,modifier types & storage classes value of a should be int"<<endl;
	    }
    }
    else
    {
        //calling functions
	    scope();
	    modifier();
	    storage();
	    staticstorage();
	    cout<<"* staticstorage variable after incrementation is *"<<endl;
	    staticstorage();
	    number n;
	    n.display();
    }
}

