//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <iomanip>
//#include <stdlib.h>
//#include <fstream>
#include "printMenus.h"
#include "inputVerifications.h"
#include "logInAndRegisterFunctions.h"
#include "fileFunctions.h"
using namespace std;

const string FILE_NAME = "users.txt";

int main()
{	
	START:
	
	int fileLength = getFileLength(FILE_NAME);

	string* usernames = new string[fileLength];
	size_t* passwords = new size_t[fileLength];
	long long int* balances = new long long int[fileLength];

	fillArraysWithInfo(FILE_NAME, usernames, passwords, balances);



	printHomeMenu();
	char firstInput = ' ';
	CHAR_INPUT:
	cin >> firstInput;
	cout << endl;
	if (!isValidCharInput(firstInput))
	{
		cout << "Please, enter a valid character:" << endl;
		goto CHAR_INPUT;
	}
	if (firstInput != 'L' && firstInput != 'l' && firstInput != 'R' && firstInput != 'r' && firstInput != 'Q' && firstInput != 'q')
	{
		cout << "Wrong letter was entered, please try again!" << endl;
		goto CHAR_INPUT;
	}

	string username = "";
	string password = "";

	//Login
	if (firstInput == 'L' || firstInput == 'l')
	{
		if (logInSuccessful(fileLength, usernames, passwords, username, password))
		{
			int rowIndex=getUsernameIndex(usernames, username, fileLength);
			clearConsole();
			printMainMenu(username,balances[rowIndex]);
			//mainMenuoperations();
	    }
	}

	else if (firstInput == 'R' || firstInput == 'r')
	{
		if (registerSuccessful(fileLength, FILE_NAME, usernames, passwords, username, password))
		{
			cout << "Successful registration! Press C to go back to the home menu or press Q to quit!" << endl;
			char choice = ' ';
			cin >> choice;
			if (choice == 'C' || choice == 'c')
			{
				clearConsole();
				goto START;
			}
		}
	}
}