
/*Name of the program:To demonstrate public private and protected access specifiers using example.
and write the program for Input.
filename:Case4.cpp
date:09-04-2020
Author:Ch.Gopi Chand
*/

#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class Declaration
{
	// Declaring iA as private
	private:
	int iA;
	// Declaring iB as public
	public:
	int iB;
	// Declaring iC as protected
	protected:
	int iC;
	public:

	void show()
	{
		cout<<"enter a,b and c values "<<endl;
		cin>>iA>>iB>>iC;
		//Every members can be access here, same class
		cout<<"\nAccessing variable within the class"<<endl;
		cout<<"Value of a: "<<iA<<endl;
		cout<<"Value of b: "<<iB<<endl;
		cout<<"Value of c: "<<iC<<endl;
	}
};

class Sub_class:public Declaration
{
	public:
	void show()
	{
		iB=12;
		iC=16;
		cout<<"\nAccessing variable in sub the class"<<endl;

		// a is not accessible here it is private
		cout<<"Value of a is not accesible it is private: "<<endl;
		//b is public so it is accessible any where
		cout<<"Value of b: "<<iB<<endl;
		//'c' is declared as protected, so it is accessible in sub class
		cout<<"Value of c: "<<iC<<endl;
	}
};

int main(int argc, char *argv[])
{

if(argc>=2)
    	{
	    	//For comparing input string through command line is -h
			if(strcmp(argv[1],"-h")==0)	
	    {
            cout<<"This program is to demonstrate how public private and protected acess specifiers works "<<endl;
			cout<<" value of a,b and c should be entered in int "<<endl;
	    }
    }
	else
	{
		// create object
		Declaration d; 
		d.show();
		
		// create object
		Sub_class s; 
		// Sub class show() function
		s.show();    

		cout<<"\nAccessing variable outside the class"<<endl;
		//'a' cannot be accessed as it is private
		cout<<"value of a is not accesible outside class because it is private "<<endl;

		//'b' is public as can be accessed from any where
		cout<<"value of b: "<<d.iB<<endl;

		//'c' is protected and cannot be accesed here
		cout<<"value of c is protected and cannot be accesed here "<<endl;
	}
}


