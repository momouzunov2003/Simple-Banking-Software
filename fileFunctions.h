#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "inputVerifications.h"
using namespace std;

int getFileLength(string fileName)
{
	int numberOfLines = 0;
	string line;
	ifstream myFile(fileName);

	while (getline(myFile, line))
	{
		numberOfLines++;
	}

	return numberOfLines;
}

void fillArraysWithInfo(string fileName, string* usernames, size_t* passwords, long long int* balances)
{
	ifstream fileReader(fileName);
	string input;
	//stringstream inputCopy;
	if (fileReader.is_open())
	{
		int j = 0;
		while (!fileReader.eof())
		{

			input = " ";
			getline(fileReader, input);
			stringstream inputCopy;
			inputCopy.str(input);
			string currentString;
			int i = 0;

			while (getline(inputCopy, currentString, ':'))
			{
				if (i == 0)
				{
					usernames[j] = currentString;
				}
				if (i == 1)
				{
					stringstream passwordCopy(currentString);
					passwordCopy >> passwords[j];
				}
				if (i == 2)
				{
					balances[j] = stoi(currentString);
				}

				i++;
			}
			j++;
		}
		fileReader.close();
	}
}

void appendToFile(string fileName, string username, string password, long long int balance)
{
	ofstream fileWriter(fileName, ios::app);

	if (!fileWriter.is_open())
	{
		cout << "Error reading file!" << endl;
		return;
	}

	hash<string> stringHashingMethod;
	size_t currentPassHashValue = stringHashingMethod(password);
	fileWriter << endl << username << ":" << currentPassHashValue << ":" << balance;
	fileWriter.close();
}
