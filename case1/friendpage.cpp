#include<iostream>
#include<fstream>
#include<unordered_map>
#include<stdlib.h>
#include <map>
#include<string.h>
using namespace std;
		map<string,string> Smain;
		map<string,string> Ssub; 
		map<string, string>::iterator itr;
class friendpage
{ 
	private:
	string Sname;
	string Smailid;
	public:
	 void add();
	 void display();
	 void edit();
	 void remove();
	 void search();
	 void addingfriend();
		
};

	void add()
	{
		
		string *Sname = new string();
		string *Smailid = new string();
		cout<<"enter name without space "<<endl;
		cin>>*Sname;
		cout<<"enter emailid"<<endl;
		cin>>*Smailid;
		Smain.insert({*Sname,*Smailid});
		delete Sname;
		delete Smailid;
	}

	
	void display()
	{
	for (itr =  Smain.begin(); itr !=  Smain.end(); ++itr)
	 { 
    	cout<<"name: "<< itr->first<<endl; 
    	cout<< "mailid: " << itr->second << endl; 
     }
	}
	
	void edit()
	{
		string *newemailid = new string();
		string *search = new string();
		cout<<"enter name to edit your details "<<endl;
		cin>>*search;
		itr = Smain.find(*search);
		if(itr == Smain.end()) 
		cout << "entered name is not present plss check and try again " ; 
	else
		cout << "Entered name is present : "<<endl;
		cout<<"enter new emailid "<<endl;
		cin>>*newemailid;
		Smain.erase(*search);
		Smain.insert({*search,*newemailid});
		cout<<"Data updated succesfully"<<endl;
		delete newemailid;
		delete search;
	}
	
	
	void remove()
	{
		string *search = new string();
		cout<<"enter name to remove  details "<<endl;
		cin>>*search;
		itr = Smain.find(*search);
		if(itr == Smain.end()) 
		cout << "entered name is not present plss check and try again" ; 
	else
		Smain.erase(*search);
		cout<<"deleted succesfully"<<endl;	
		delete search;
	}
	
	
	void search()
	{
		string *search = new string();
		bool b=false;
		cout<<"enter name to edit your details "<<endl;
		cin>>*search;
		for (itr =  Smain.begin(); itr !=  Smain.end(); ++itr)
	 { 
    	
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
     cout<<"Entered details has an account"<<endl;
		delete search;
	}
	
	void addingfriend()
	{
		//string friend;
		string *friendname = new string();
		string *friendemailid = new string();
		string *newname = new string();
		string *newemailid = new string();
		string *search = new string();
		
		
		char moreRecords;
		cout<<"first enter your detils to add friends "<<endl;
		cout<<"enter name"<<endl;
		cin>>*newname;
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
		cin>>*search;
	
		for (itr =  Smain.begin(); itr !=  Smain.end(); ++itr)
	 { 
    	
		if(itr->first==*search || itr->second==*search )
		{
		
		
		 t=true;
		 Ssub.insert({itr->first,itr->second});
		 cout<<"friend added succesfully \n "<<endl;
		 break;
		}
		
     }
     if (t==false)
     {
     cout<<"entered name is not present"<<endl;
     }
     else
     {
	 
     cout<<*newname<<" is friend with this people \n "<<endl;
     for (itr =  Ssub.begin(); itr !=  Ssub.end(); ++itr)
	 { 
    	cout<<"name: "<< itr->first<<endl; 
    	cout<< "emailid: " << itr->second << endl; 
     }
     
    
     }
	 cout<<"do you want to add more friends? (Y/N)"<<endl;
     cin>>moreRecords;   
     }while(moreRecords=='y');
     
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
