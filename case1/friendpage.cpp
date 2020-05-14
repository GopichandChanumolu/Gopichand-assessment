
/*Name of the program:To designa friendpage ehich make a add delete edit search and adding friends. 

filename:friendpage.cpp
date:13-05-2020
Author:Ch.Gopi Chand
*/

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<stdlib.h>
#include <map>
#include<string.h>
using namespace std;
// creating map and defining key and value both as string data types
	map<string,string> Smain;
	map<string,string> Ssub; 
// creating iterator 
	map<string, string>::iterator itr;
	map<string, string>::iterator itr1;
class friendpage
{ 
	private:
	string Sname;
	string Smailid;
		
};

/*Function Name :add
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to add user name and mailid */

	void add()
	{
		//allocating memorey dynamicaly for name and emailid 
		string *Sname = new string();
		string *Smailid = new string();
		cout<<"Enter name  "<<endl;
		cin.ignore();
		getline(cin,*Sname);
		// to check weather the user is already existed or not
		itr = Smain.find(*Sname);
		if(itr == Smain.end() )
		{	
			cout<<"Enter emailid "<<endl;
			cin>>*Smailid;
			// inserting data into the map
			Smain.insert({*Sname,*Smailid});
			
		}
		else
		{				
		cout<<" User name is already existed "<<endl;
		cout<<" try to add with different user name "<<endl;
		}
		
		//deallocating memorey dynamicaly for name and emailid 
		delete Sname;
		delete Smailid;
	}

/*Function Name :display
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to display name and mailid */
	
	void display()
	{
	// for loop to iterate map from starting to end 
	for (itr =  Smain.begin(); itr !=  Smain.end(); ++itr)
	 { 
    	// printing the name and emailid
		cout<<"name: "<< itr->first<<endl; 
    	cout<< "mailid: " << itr->second << endl; 
     }
	}
	
/*Function Name :edit
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to edit the user emailid with the help of user name */
  
  
	void edit()
	{
		//allocating memorey dynamicaly for name and emailid 
		string *newemailid = new string();
		string *search = new string();
		//string *newname = new string();
		cout<<"enter name to edit your details "<<endl;
		cin.ignore();
		getline(cin,*search);
		//cin>>*search;
		// find is used in map to search given data is presen or not
		itr = Smain.find(*search);
		if(itr == Smain.end()) 
		{
		
		cout << "entered name is not present  check and try again "<<endl ; 
		}
		
		else
		{
		
		cout << "Entered name is present : "<<endl;
		cout<<"enter new emailid "<<endl;
		//modifying the emailid
		cin>>*newemailid;
		//cout>>"enter new name: "<<endl;
		//cin>>*newname;
		//clearing the previous data from the record
		Smain.erase(*search);
		// enterin the new updated data into the records
		Smain.insert({*search,*newemailid});
		cout<<"Data updated succesfully"<<endl;
		}
		//deallocating memorey dynamicaly for name and emailid 
		delete newemailid;
		delete search;
		//delete newname;
	}
	
/*Function Name :remove
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to delete the user emailid and user name with the help of user name */
	void remove()
	{
		//allocating memorey dynamicaly for name and emailid 
		string *search = new string();
		cout<<"enter name to remove  details "<<endl;
		cin.ignore();
		getline(cin,*search);
		//cin>>*search;
		itr = Smain.find(*search);
		// if condition to check given data is present in map or not
		if(itr == Smain.end())
		{
		  
		cout << "entered name is not present  check and try again"<<endl; 
		}
		else
		{
		//if the data is present the data has been removed from the records
		Smain.erase(*search);
		cout<<"deleted succesfully"<<endl;	
		}
		//deallocating memorey dynamicaly for name and emailid 
		delete search;
	}

/*Function Name :search
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to edit the user emailid with the help of user name */	
	
	void search()
	{
		//allocating memorey dynamicaly for name and emailid
		string *search = new string();
		bool b=false;
		cout<<"enter name or emailid to search  details "<<endl;
		cin.ignore();
		getline(cin,*search);
		//cin>>*search;
		// for loop to iterate the loop from starting to the ending
		for (itr =  Smain.begin(); itr !=  Smain.end(); ++itr)
	 { 
    	
		//if loop to check given data is present or not
		if(itr->first==*search || itr->second==*search )
		{
		
		//cout<<"given details has been existed "<<endl;
		 b=true;
		 break;
		}
		
     }
     if (b==false)
     {
     cout<<"Entered details has no account"<<endl;
     }
     else
     {
     cout<<"Entered details has an account"<<endl;
 	 }
 	 //deallocating memorey dynamicaly for name and emailid
		delete search;
	}

/*Function Name :addingfriend
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to edit the user emailid with the help of user name */
	
	void addingfriend()
	{
		
		//allocating memorey dynamicaly for name and emailid
		string *friendname = new string();
		string *friendemailid = new string();
		string *newname = new string();
		string *newemailid = new string();
		string *search = new string();
		char moreRecords;
		cout<<"first enter your detils to add friends "<<endl;
		cout<<"enter name"<<endl;
		cin.ignore();
		getline(cin,*newname);
		//cin>>*newname;
		cout<<"enter emailid"<<endl;
		cin>>*newemailid;
		//cout<<"your details "<<endl;
		//Ssub.insert({*newname,*newemailid});
		do 
		{
		   bool t=false;
		   cout<<" select the name whom you whant to be friend \n "<<endl;
		
		for (itr =  Smain.begin(); itr !=  Smain.end(); ++itr)
	 { 
    	cout<<"name: "<< itr->first<<endl; 
    	cout<< "emailid: " << itr->second << endl; 
     }
		
		cin.ignore();
		getline(cin,*search);
		//cin>>*search;
	
		for (itr =  Smain.begin(); itr !=  Smain.end(); ++itr)
	 { 
    	
		if(itr->first==*search )
		{
		//cout<<"check1"<<endl;
			itr1 = Ssub.find(*search);
			//cout<<"check2"<<endl;
			if(itr1 == Ssub.end())
			{
		  
			//cout << "check3"<<endl; 
		
			t=true;
		 	Ssub.insert({itr->first,itr->second});
		 	cout<<"friend added succesfully \n "<<endl;
		 	itr1 == Ssub.begin();
		 	break;
		}
		
		
		else
		{
	
		cout<<"entered name is already friend \n "<<endl;	
		t=true;
		}
		
		 //t=true;
		 //Ssub.insert({itr->first,itr->second});
		 //cout<<"friend added succesfully \n "<<endl;
		 //break;
		}
	}
	
		
     
     if (t==false)
     {
     cout<<"entered name is not present \n"<<endl;
     cout<<endl;
     }
     else
     {
	 
     cout<<*newname<<" is friend with this people \n "<<endl;
     for (itr =  Ssub.begin(); itr !=  Ssub.end(); ++itr)
	 { 
    	cout<<"name: "<< itr->first<<endl; 
    	cout<< "emailid: " << itr->second << endl; 
    	cout<<endl;
     }
     
    
     }
	 cout<<"do you want to add more friends? (Y/N)"<<endl;
     cin>>moreRecords;   
     }while(moreRecords=='y');
     
     	//deallocating memorey dynamicaly for name and emailid
		delete friendname;
		delete friendemailid;
		delete newname;
		delete newemailid;
		delete search;
 	}
	
	
	
int main(int argc,char* argv[])
{
	
	if(argc>=2)
    	{
	    	//For comparing input string through command line is -h
			if(strcmp(argv[1],"-h")==0)	
	    {
            cout<<" This program is to add delete edit search and adding some friends  "<<endl;
            cout<<" you have to choose the options regardingly you want "<<endl;
	    }
    }
	else
	{
	
	int option;
        friendpage f;
        while(1)
        { 
            cout<<"-------------------------------------------------"<<endl;
        	cout<<"1.add 2.display 3.edit 4.delete  5.search 6. add friends 7.exit"<<endl;
            cout<<"enter your option: "<<endl;
            cin>>option;
            cout<<"--------------------------------------------------"<<endl;
		    switch(option)
            {
                         case 1:
                                add();
                                break;
                         case 2:
                                display();
                                break;
                         case 3:
                         		edit();
                         		break;
                         case 4:
                         		remove();
                         		break;
                         case 5:
                         		search();
                         		break;
                         case 6:
                         		addingfriend();
                         		break;
                         case 7:
                                exit(1);
                            
            }
        }
	}
}
