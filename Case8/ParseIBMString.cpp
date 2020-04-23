

//filename:ParselIBMString.cpp
//date : 23-04-2020
// Last modified:Ch.Gopi Chand


// ParseIBMString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
using namespace std;

std::string FileName(const std::string& sStr)
{
	size_t found = sStr.find_last_of("/\\");
	std::string path = sStr.substr(found + 1); // check that is OK
	return path;
}

std::string dirnameOf(const std::string& sFname)
{
	size_t pos = sFname.find_last_of("\\/");
	return (std::string::npos == pos)
		? ""
		: sFname.substr(0, pos);
}
//bool hasibm  function to search in given string
bool HasIBM(string sStr, string sSearchString)
{
	// transforming the content present in string to upper case
	transform(sStr.begin(), sStr.end(), sStr.begin(), ::toupper);
	// transforming the search content present in string to upper case
	transform(sSearchString.begin(), sSearchString.end(), sSearchString.begin(), ::toupper);
	//is statment to check required word is present in user string or not
	if (sStr.find(sSearchString) != std::string::npos)
	{
		return true;
	}
	return false;
}
// copyright function to search paticular word
string Copyright(string sStr)
{
	//if statment to search confidential word prent in user string or not using hasibm function
	if (HasIBM(sStr, "Confidential"))
	{
		return "Copyright";
	}
	//if statment to search confidential and corp word prent in user string or not using hasibm function
	if (HasIBM(sStr, "Copyright") && HasIBM(sStr, "Corp"))
	{
		return "Copyright";
	}
	return "";
}
 // ismacro function to search paticular word
string isMacro(string sStr)
{
	//if statment to search define word prent in user string or not using hasibm function
	if (HasIBM(sStr, "#define"))
	{
		//if the above statment satisfies it search for .ibm in the string
		if (HasIBM(sStr, ".ibm.")) return "MacroWith.com";
		else if(HasIBM(sStr, "KEY")) return "MacroWithRegistry";
		else 
		return "Macro";
	}
	return "";
}
// url function to search paticular word
string url(string sStr)
{
	//if statment to search https: or https: prent in user string or not using hasibm function
	if (HasIBM(sStr, "http:") || HasIBM(sStr, "https:"))
	{		
		return "URL";
	}
	return "";
}
// servername function to search paticular word
string ServerName(string sStr)
{
	//if statment to search o=ibm and cn= prent in user string or not using hasibm function
	if (HasIBM(sStr, "O=IBM") && HasIBM(sStr, "CN=") )
	{
		return "ServerName";
	}
	return "";
}
// registery function to search paticular word
string registry(string sStr)
{
	//if statment to search hklm prent in user string or not using hasibm function
	if (HasIBM(sStr, "HKLM"))
	{
		return "Registry";
	}
	return "";
}
// os function to search paticular word
string os(string sStr)
{
	if (HasIBM(sStr, "IBMRT") || HasIBM(sStr, "IBMPC") ||
		HasIBM(sStr, "ibmOS390") || HasIBM(sStr, "IBMCP") || HasIBM(sStr, "ibmAS400")
		|| HasIBM(sStr, "OS2") || HasIBM(sStr, "IBMC") || HasIBM(sStr, "IBMRT"))
	{
		return "OS Specific";
	}
	return "";
}
// comment function to search paticular word
string comment(string sStr)
{
	// pattern is used to search for the paticular patttern present or not
	string pattern("(/\\*([^*]|[\r\n]|(\\*+([^*/]|[\r\n])))*\\*+/)|(//.*)");
	regex r(pattern, regex_constants::egrep);
	string s1("//");
	string s2("/*");
	string s3(" * ");
	// transforming the string into upper case
	transform(sStr.begin(), sStr.end(), sStr.begin(), ::toupper);
	for (sregex_iterator it(sStr.begin(), sStr.end(), r), end;
		it != end;
		++it)
	{		
		int pos = sStr.find(s1);
		int pos1 = sStr.find("IBM");
		int pos2 = sStr.find(s2);
		if (pos == 0 || (pos > 0 && pos1 > pos))
		{
			return "CommentedLine";
		}
		else if( pos2 >= 0)
		{
			return "CommentedLine";
		}		
	} 
	int pos = sStr.find(s2);
	int pos1 = sStr.find("IBM");
	if (pos == 0 || (pos > 0 && pos1 > pos))
	{
		return "CommentedLine";
	}
	pos = sStr.find(s3);
	if (pos == 0)
	{
		return "CommentedLine";
	}
	return "";
}

// debug function to search paticular word
string debug(string sStr)
{
	string str1("xprintf");
	int pos = sStr.find(str1);
	if (pos >= 0)
	{
		return "Debug";
	}
	return "";
}

string washType(string sStr)
{
	//declaring type as string
	string type;
	//appending the copyright function
	type.append(Copyright(sStr));
	//appending the ismacro function
	type.append(isMacro(sStr));
	//appending the os function
	type.append(os(sStr));
	//appending the registery function
	type.append(registry(sStr));
	//appending the servername function
	type.append(ServerName(sStr));
	//appending the url function
	type.append(url(sStr));
	//appending the coment function
	type.append(comment(sStr));
	//appending the debug function
	type.append(debug(sStr));
	return type;
}
//filetype function which holdes the filename and filepath
string fileType(string sFilename, string sFilepath)
{
	string filetype;
	// search for the ibm is present in given file name or not
	if (HasIBM(sFilename, "IBM"))
	{
		filetype = "FileNameHasIBM";
	}
	//search for the ibm is present in the given path or not
	if (HasIBM(sFilepath, "IBM"))
	{
		filetype = "PathNameHasIBM";
	}
	//search for the both filename and filepath ibm is present or not
	if (HasIBM(sFilename, "IBM") && HasIBM(sFilepath, "IBM"))
	{
		filetype = "File&PathNameHasIBM";
	}
	//check for the file format
	if (sFilename.substr(sFilename.length() - 3) == ".rc" || sFilename.substr(sFilename.length() - 4) == ".dlg")
	{
		filetype = "UI";
	}
	if (sFilename.substr(sFilename.length() - 4) == ".def")
	{
		filetype = "External API";
	}
	if (sFilename.substr(sFilename.length() - 3) == ".sh")
	{
		filetype = "Script";
	}
	return filetype;
}
// getibm function which gets the location as input
bool getIBM(string sFilename)
{

	//reading the file
	ifstream file(sFilename);
	//creating the myfile
	ofstream myfile;
	//creting the new file with existing filename.c_str
	string newFile = sFilename.c_str();
	//format is replaced to text file
	std::string toReplace(".txt");
	size_t pos = newFile.find(toReplace);
	// replacing file name to updated file
	newFile.replace(pos, toReplace.length(), "_updated.txt");
	// opening new file
	myfile.open(newFile);
	if (file.is_open()) {
		string line;
		string sFilename;
		string LineNumber;
		string sFilepath;
		string existingFormat;
		string filetype;
		string type;
		regex r("[0-9]: +");
		printf("\nFileName File Path LineNumber Existing Format\n");
		while (getline(file, line))
		{	
			cmatch results;
			if (regex_search(line.c_str(), results, r))
			{
				string delimiter = ":";
				size_t pos = 0;
				
				pos = line.find(delimiter);
				LineNumber = line.substr(0, pos);
				line.erase(0, pos + delimiter.length());
				existingFormat = line;
				type = washType(line);
				printf("\n%s^%s^%s^%s^%s^%s", filetype.c_str(), sFilename.c_str(), sFilepath.c_str(), LineNumber.c_str(), existingFormat.c_str(), type.c_str());
				myfile << filetype.c_str() << "^" << sFilename.c_str()
					   << "^" << sFilepath.c_str() << "^" << LineNumber.c_str() << "^"
					   << existingFormat.c_str() << "^" << type.c_str() << endl;
			}
			else
			{
				 filetype = "---";
				 sFilename = FileName(line.c_str());
				 sFilepath = dirnameOf(line.c_str());
				 if (sFilepath.empty())
				 {
					 sFilepath = "*****";
				 }
				 else
				 {
					 filetype = fileType(sFilename, sFilepath);
				 }
			}
			
		}
		//closing the myfile
		myfile.close();
		//closing file
		file.close();
	}
	return false;
}




int main(int argc, char *argv[])
{
	// if condition to display the help command
	if (argc <= 2)
	{
		printf("Usage PerselIBMString <<inputFileName>>\n");
		return -1;
	}
	// sending the file path to getibm function 
	getIBM(argv[2]);
	return 0;
}

//Hint:
// Input should be given in the format of Parselibmstring <Pathoftheinputfile>


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
