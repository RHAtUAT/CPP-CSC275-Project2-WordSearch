//// CPP-CSC275-Project2 Word Search.cpp : Defines the entry point for the console application.
//
////Read in a file that contains a list of 10 words. 
////
////Then, scan another file that contains at least 3 paragraphs from your favorite book.
////Count the number of the words from the first file that are contained in the second.
////
////Write the results to a file in the format of :
////
////Word1 – Found x times
////Word2 – Found y times
////(repeat for all 10 words)
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


const unsigned short MAX_IWORDS = 10;
const unsigned short MAX_WORDS = 1024;

//string exampleWords[MAX_IWORDS] = {
//
//	"hello",
//	"there",
//	"I",
//	"will",
//	"be",
//	"submitting",
//	"my",
//	"assignment",
//	"this",
//	"week"
//};


void ReadFile()
{

	string strInWordFile[MAX_IWORDS];
	string strInParaFile[MAX_WORDS];
	ofstream outputFile("Files/Output.txt");
	ifstream wordsFile("Files/Words.txt");


	// Read 1 string at a time
	//populate array with words from Words.txt
	for (int i = 0; i < MAX_IWORDS && !wordsFile.eof(); i++) {
		wordsFile >> strInWordFile[i];
	}

	//populate array with words from Paragraph.txt
	ifstream paragraphFile("Files/Paragraph.txt");
	for (int i = 0; i < MAX_WORDS && !paragraphFile.eof(); i++){
		paragraphFile >> strInParaFile[i];
	}


	//count how many of each element from array1 is in array2 

	cout << "----------------------------------------------------" << endl;

	//loop through every element of first array
	for (int i = 0; i < sizeof(strInWordFile)/sizeof(strInWordFile[0]); i++)
	{
		int match = 0;

		//loop through every element of second array
		for (int e = 0; e < sizeof(strInParaFile) / sizeof(strInParaFile[0]); e++)
		{
			//compare the 2 indexes to see if the elements match
			if (strInWordFile[i] == strInParaFile[e]) { match++; }
		}
		cout << strInWordFile[i] << " : " << match << endl;
		outputFile << strInWordFile[i] << " : " << match << endl;
	}
	cout << "----------------------------------------------------" << endl;
		cout << "     --------|Output.txt Rewritten|-------" << endl;
}


//Get List of Text Files in given directory
//void read_directory(const string& name, vector<string>& v)
//{
//	std::string pattern(name);
//	pattern.append("\\*");
//	WIN32_FIND_DATA data;
//	HANDLE hFind;
//	if ((hFind = FindFirstFile((LPCWSTR)pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
//		do {
//
//			//convert from wide char to narrow char array
//			char ch[260];
//			char DefChar = ' ';
//			WideCharToMultiByte(CP_ACP, 0, data.cFileName, -1, ch, 260, &DefChar, NULL);
//
//			//A std:string  using the char* constructor.
//			string ss(ch);
//
//			v.push_back(data.cFileName);
//			cout << ss;
//		} while (FindNextFile(hFind, &data) != 0);
//		FindClose(hFind);
//	}
//}


int main()
{
	//cout << "Would you like to input words yourself or use an example?" << endl;
	ReadFile();
		
	system("pause");
    return 0;
}
