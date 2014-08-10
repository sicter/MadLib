/***********************
Purpose: The purpose of this program is to take a file and carry out
		 a madLib game with a user, where a user inputs words, then those 
		 words are input to a string, which is then written to a file.

Edward Aryee, CS 171
Section 061, Assignment 5, 
February 25, 2014

***********************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
#include "eaa55.h"

using namespace std;

//PROTOTYPES for functions
void introduction();
string promptForFileName(string prompt);
string madLibString(string fileName);

string filledInMadLib(string madLibTemplate);
void outPutMadlib(string fileName, string madLib);

//MAIN
int main()
{
string madLibFileName, fullMadLibTemplate, completeMadLib; // defining string variables to be used

introduction(); // calls introfuction function

string askFileName("Please enter MadLib file name: (or enter ""quit"" to quit)");
madLibFileName = promptForFileName(askFileName); // calls promptForFileName function

fullMadLibTemplate = madLibString(madLibFileName); // calls madLibString function

completeMadLib = filledInMadLib(fullMadLibTemplate); // calls filledInMadLib function
cout << endl << completeMadLib << endl; // output complete madLib with user filled in descriptors

outPutMadlib(madLibFileName, completeMadLib);

system("PAUSE");
return 0;
}

void introduction()
{
	string answer;
	string askInstructions("Do you need instructions? (yes or no)");
	
	answer = promptForString(askInstructions); // calls prompt for string, which allows users to 
	string instructions("Instructions: Follow the console prompts, inputting the neccessary words and pressing enter until the end of the prompts");
	// Determining if use requires Instructions
	if(answer == "yes") 
	{
		cout << endl << instructions << endl; 
	}
	else if(answer == "no")
	{
		cout << endl;
	}	
}
// prompts for file name and returns the name of the file or a null string
string promptForFileName(string prompt)
{
	string answer;

	string name = promptForString(prompt);
	
	if(name == "quit")
	{
		answer = " ";
	}
	else
	{ 
		answer = name;
	}
	return answer;
}

//function takes a file name and opens the file, then concatenates its comments into one long string then returns that string
string madLibString(string fileName)
{
	string madLibParts, tempString;

	ifstream fin(fileName.c_str());
	if(fin.is_open())
		{
			cout << "File Opened" << endl;
		}
	else
		{
		cout << "File not found, program will now close" << endl;
		system("PAUSE");
		return 0;
		}

	fin >> madLibParts;

	while(! fin.eof())
	{
		fin >> tempString; 
		madLibParts = madLibParts + " " +tempString;
	}
	
	fin.close();
	return madLibParts;
}

//function takes a string, then finds all instances of despriptors and replaces them with user input words, and returns the finished string
string filledInMadLib(string madLibTemplate)
{
	string madLibTemplatePrompt;
	string asterisk("**");
	int asteriskStart = madLibTemplate.find(asterisk);
	int asteriskEnd = madLibTemplate.find(asterisk, asteriskStart+1);
	string fillIn, beforeAsterisk, afterAsterisk;
	bool fillingIn = true;

	cout << endl;
	cin.ignore();

	while(asteriskStart != -1)
	{
	madLibTemplatePrompt = madLibTemplate.substr(asteriskStart+asterisk.length(), (asteriskEnd-asteriskStart-asterisk.length()));
	cout << endl << "Please enter a " << madLibTemplatePrompt << ": ";
		getline(cin, fillIn);
	
	beforeAsterisk = madLibTemplate.substr(0, asteriskStart);
	afterAsterisk = madLibTemplate.substr(asteriskEnd+asterisk.length(), (madLibTemplate.length()-asteriskEnd+asterisk.length()));

	madLibTemplate = beforeAsterisk + " " + fillIn + " " + afterAsterisk;
	
	asteriskStart = madLibTemplate.find(asterisk);
	asteriskEnd = madLibTemplate.find(asterisk, asteriskStart+1);
	}

	return madLibTemplate;
}

//function outputs a string to a file, with a name relating to its original name
void outPutMadlib(string fileName, string madLib)
{
	string newFileName = fileName.substr(0,((fileName.find(".")))) + "_output.txt";
	ofstream fout(newFileName);
	fout << madLib;
	fout.close();
}