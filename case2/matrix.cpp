
/*Name of the program:To design  a print a pattern in row coloums and diagonal .

filename:main.cpp
date:16-05-2020
Author:Ch.Gopi Chand
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

/*Function Name :row
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to do row check */

void Row()
{
	int i,j,m,n,b,c;
	int d,e;
	char a[10][10];
	char f[10][10];
	int index[n];
	cout<<"enter the matrix size rows and colloums "<<endl;
	cin>>m;
	cin>>n;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"enter "<<i<<j<<" value"<<endl;
			cout<<" value should be 0 and 1 only"<<endl;
			cin>>a[i][j];
			
		}
	}
	
	
	
	for(i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			index[j] = j;
			
		}
		for (j=0;j<n-1;j++)
		{
			b = i;
			c = i;
			d = index[j+1];
			e = index[j];
			
			if (a[b][e] == a[c][d])
			{
				index[j+1] = j;
			}
			
		}
	
	int row =0;
	for(j=0;j<n;j++)
	{
		if (index[j] == j)
		{
			f[i][row] = a[i][j];
			row ++;
		}
	}
	while(row != n)
	{
		f[i][row] = '*';
		row++;	
	}
}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<f[i][j];
		}
		cout<<"\n"<<endl;
	}
	
	
}

/*Function Name :coloumn
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to do coloumn check  */

void coloumn()
{
	int i,j,m,n,b,c;
	int d,e;
	char a[10][10];
	char f[10][10];
	char in[10][10];
	int index[n];
	cout<<"enter the matrix size rows and colloums "<<endl;
	cin>>m;
	cin>>n;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"enter "<<i<<j<<" value"<<endl;
			cout<<" value should be 0 and 1 only"<<endl;
			cin>>in[i][j];
			
		}
	}
	
		for(i=0;i<m;i++)
		{
		for(j=0;j<n;j++)
		{
			
			a[j][i] = in[i][j];
			
		}
		}
	
	
	
	for(i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			index[j] = j;
			
		}
		for (j=0;j<n-1;j++)
		{
			b = i;
			c = i;
			d = index[j+1];
			e = index[j];
			
			if (a[b][e] == a[c][d])
			{
				index[j+1] = j;
			}
			
		}
	
	int row =0;
	for(j=0;j<n;j++)
	{
		if (index[j] == j)
		{
			f[i][row] = a[i][j];
			row ++;
		}
	}
	while(row != n)
	{
		f[i][row] = '*';
		row++;	
	}
}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			in[j][i] = f[i][j];
		}
		cout<<"\n"<<endl;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<in[i][j];
		}
		cout<<"\n"<<endl;	
	}
	
	
 } 
 
 
 int main(int argc,char* argv[])
 {
 
	if(argc>=2)
    	{
	    	//For comparing input string through command line is -h
			if(strcmp(argv[1],"-h")==0)	
	    {
            cout<<" This program is to print paticular pattern depend on input   "<<endl;
	    }
    }
	else
	{
	
	int option;
        while(1)
        { 
            cout<<"-------------------------------------------------"<<endl;
        	cout<<"1.row operation 2.coloumn operation 3.exit"<<endl;
            cout<<"enter your option: "<<endl;
            cin>>option;
            cout<<"--------------------------------------------------"<<endl;
		    switch(option)
            {
                         case 1:
                                cout<<"Row operation \n ";
								Row();
                                break;
                         case 2:
                                cout<<"coloumn operation \n ";
								coloumn();
                                break;
                         case 3:
                         		exit(1);               
            }
        }
	}
}	

