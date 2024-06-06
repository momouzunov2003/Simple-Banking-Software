#include "fileFunctions.h"

void quit()
{
	exit(0);
}

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

void fillArraysWithInfo(string fileName, string* usernames, size_t* passwords, long float* balances)
{
	ifstream fileReader(fileName);
	string input;

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
					balances[j] = stof(currentString);
				}

				i++;
			}
			j++;
		}
		fileReader.close();
	}
}

void appendToFile(string fileName, string username, string password, long float balance)
{
	ofstream fileWriter(fileName, ios::app);
	int fileLength = getFileLength(fileName);
	if (!fileWriter.is_open())
	{
		cout << "Error reading file!" << endl;
		quit();
	}

	hash<string> stringHashingMethod;
	size_t currentPassHashValue = stringHashingMethod(password);
	if (fileLength == 0)
	{
		fileWriter << username << ":" << currentPassHashValue << ":" << balance;
		fileWriter.close();
	}
	else
	{
		fileWriter << endl << username << ":" << currentPassHashValue << ":" << balance;
		fileWriter.close();
	}
}

void deleteLineFromFile(string fileName, int removeLine)
{
	string line;
	ifstream inFile(fileName);
	ofstream outFile("output.txt");

	if (!outFile.is_open())
	{
		cout << endl << "Unable to open temp file!" << endl;
		quit();
	}

	int currentLine = 1;

	if (removeLine == 1)
	{
		currentLine = 0;
		while (getline(inFile, line))
		{
			currentLine++;

			if (currentLine != 1)
			{
				outFile << line << endl;
			}
		}
	}
	else
	{
		while (getline(inFile, line))
		{
			if (currentLine == 1)
			{
				outFile << line;
			}
			else if (currentLine != removeLine)
			{
				outFile << endl << line;
			}
			currentLine++;
		}
	}

	inFile.close();
	if (remove("users.txt") != 0)
	{
		cout << endl << "Unable to delete file!" << endl;
		quit();
	}
	outFile.close();
	rename("output.txt", "users.txt");
}

bool rewriteBalance(string usernames[], string username, size_t passwords[], long float balances[], long float amount, int rowIndex)
{
	ifstream inFile("users.txt");
	ofstream outFile("output.txt");

	int fileLength = getFileLength("users.txt");
	long float currentBalance = balances[rowIndex];

	if (!inFile.is_open() || !outFile.is_open())
	{
		cout << "Unable to open file!" << endl;
		quit();
	}

	string line;
	int lineNumber = 0;

	while (getline(inFile, line))
	{

		lineNumber++;

		if (lineNumber == rowIndex + 1)
		{
			outFile << username << ":" << passwords[rowIndex] << ":" << amount + currentBalance << endl;
		}
		else
		{
			outFile << line << endl;
		}
	}

	outFile.close();
	inFile.close();

	remove("users.txt");
	rename("output.txt", "users.txt");
	return true;
}
