/*Name of the program:finding the formula for given expression.
and write the program for Input.
filename:Case1.cpp
date:08-04-2020
Author:Ch.Gopi Chand
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)							//if loop for comparing the input string with "-h"
	    {
            cout<<"The main purpose of this program is to calculate the datatype,value and sizeof the value"<<endl;
            cout<<"user can give the input in integer,float/double,char and string"<<endl;
	    }
    else
    {
	    int iI;
	    cout<<argv[0]<<endl;								//printing the filename.exe by using argv[0]
	    cout<<"type"<<"\t"<<"value"<<"\t"<<"size"<<endl;
	    for(iI=1;iI<argc;iI++)								//For loop for checking the type of datatype and also for displaying the sizeof the value what user has given
	    {
		    int iA=atoi(argv[iI]);							//atoi function for converting string to int
		    if(iA==0)										//if the 'if' loop is true then char and string will be displayed
		    {
			    if(strlen(argv[iI])==1)
				    cout<<endl<<"char";
			    else
				    cout<<endl<<"string";
				    cout<<"\t"<<argv[iI]<<"\t"<<strlen(argv[iI]);
		    }
		    else											//else case for displaying int and float values
		    {
			    float fB=atof(argv[iI]);
			    if(iA==fB)
			    {
				    cout<<endl<<"int"<<"\t"<<iA<<"\t"<<sizeof(iA);
			    }
			    else
				    cout<<endl<<"float"<<"\t"<<fB<<"\t"<<sizeof(fB);
		    }
		}
    }
    }
}
