// CPP-CSC275-Project2 Word Search.cpp : Defines the entry point for the console application.

//Read in a file that contains a list of 10 words. 
//
//Then, scan another file that contains at least 3 paragraphs from your favorite book.
//Count the number of the words from the first file that are contained in the second.
//
//Write the results to a file in the format of :
//
//Word1 – Found x times
//Word2 – Found y times
//(repeat for all 10 words)

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
//using std::string;
//using std::cin;
//using std::cout;
//using std::endl;
//using std::ifstream;
//using std::ofstream;
//using std::fstream;

const unsigned short IWORD_MAX = 10;

string exampleWords[IWORD_MAX] = {

		"hello",
		"there",
		"I",
		"will",
		"be",
		"submitting",
		"my",
		"assignment",
		"this",
		"week"
	};
int ReadFile()
{
	ifstream file;
	ofstream outputFile("TextFile1.txt");
	file.open("TextFile.txt");




	//Read 1 line at a time
	string curLine;
	int lineWritten = 0;
	while (getline(file, curLine))
	{
		outputFile << curLine << endl;
		lineWritten++;
		system("");
		//cout << << endl;
	}
}

void CompareWords() {

	for(string word : exampleWords)
	{

	}
}
string ListFile()
{
	wchar_t buffer[MAX_PATH];

	DWORD a = GetCurrentDirectory(256, buffer);
	//GetModuleFileName(NULL, buffer, MAX_PATH);
	//return a;


}

void OutputContents(){

}


void read_directory(const std::string& name, vector<string>& v)
{
	std::string pattern(name);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile((LPCWSTR)pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {

			//convert from wide char to narrow char array
			char ch[260];
			char DefChar = ' ';
			WideCharToMultiByte(CP_ACP, 0, data.cFileName, -1, ch, 260, &DefChar, NULL);

			//A std:string  using the char* constructor.
			string ss(ch);

			v.push_back(ss);
			cout << ss;
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
}


int main()
{
	cout << ReadFile();

	/* read 1 string (word) each time */

	vector<string> fileList;
	//vector<array<char, 100>> fileList;
		read_directory(".", fileList);
		
		std::copy(fileList.begin(), fileList.end(),
		ostream_iterator<string>(cout, "\n"));
		
	system("pause");
    return 0;
}

