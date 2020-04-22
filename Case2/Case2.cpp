
/*Name of the program:finding the formula for given expression.
and write the program for Input.
filename:Case2.cpp
date:08-04-2020
Author:Ch.Gopi Chand
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
/*function name:calculate
input parameter:int
output parameter:int
*/
int calculate(int iN)
{
	int iCal;
	iCal=(iN*(iN+1)*(2*iN+1))/6;	
	return iCal;					//return iCal;
}

int main(int argc, char *argv[])
{
	int iSum,iNum;
	//this is to dispaly the usage of program
	if(argc>=2)
    	{
	    	if(strcmp(argv[1],"-h")==0)		//For comparing input string through command line is -h
	    {
            cout<<"This program is to calculate the expression for given sequence program takes input from the user "<<endl;
			cout<<" value should be int"<<endl;
	    }
    }
	else
	{
		cout<<"Enter a Number to calculate the sum of squares of that number "<<endl;
		cout<<"Number should be int from 0-99 and should not be negetive"<<endl;
   		cin>>iNum;	
		iSum=calculate(iNum);		//calling Caluculate function
		cout<<"Value:"<<iSum<<endl;		//for displaying the output
	}
}
