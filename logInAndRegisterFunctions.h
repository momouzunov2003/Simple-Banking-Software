#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "inputVerifications.h"
#include "fileFunctions.h"
using namespace std;

const int STARTING_BALANCE = 0;

void quit()
{
	exit(0);
}

bool doesUsernameExist(string usernames[], string currentUsername, int usernamesSize)
{
	for (int i = 0; i < usernamesSize; i++)
	{
		if (currentUsername.compare(usernames[i]) == 0)
		{
			return true;
		}
	}
	return false;
}

bool doesPasswordsMatch(size_t passwords[], string currentPassword, int rowIndex)
{
	hash<string> stringHashingMethod;
	size_t currentPassHashValue = stringHashingMethod(currentPassword);
	if (currentPassHashValue == passwords[rowIndex])
	{
		return true;
	}
	else return false;
}

int getUsernameIndex(string usernames[], string currentUsername, int usernamesSize)
{
	for (int i = 0; i < usernamesSize; i++)
	{
		if (currentUsername.compare(usernames[i]) == 0)
		{
			return i;
		}
	}
}

bool logInSuccessful(int fileLength, string usernames[], size_t passwords[], string& username, string& password)
{	
	USERNAME_INPUT1:

	cout << "Please, enter your username: ";

	USERNAME_INPUT2:
	cin >> username;
	cout << endl;
	if (!isValidUsername(username))
	{
		cout << endl << "The username must contain only latin letters or symbols!" << endl << "Re-enter your username: ";
		goto USERNAME_INPUT2;
		cout << endl;
	}
	if (!doesUsernameExist(usernames, username, fileLength))
	{
		cout << "This username does not exist in our database!\n If you want to try again press R!\n If you want to quit press Q!" << endl;
		char option = ' ';

		CHAR_INPUT:

		cin >> option;
		if (option == 'R' || option == 'r')
		{
			goto USERNAME_INPUT1;
		}
		else if (option == 'Q' || option == 'q')
		{
			quit();
		}
		else
		{
			cout << "Wrong letter was entered, please try again!" << endl;
			goto CHAR_INPUT;
		}
	}
	int rowIndex = getUsernameIndex(usernames, username, fileLength);

	PASSWORD_INPUT1:

	cout << "Please, enter your password: " << endl;

	cin >> password;
	cout << endl;
	if (!doesPasswordsMatch(passwords, password, rowIndex))
	{
		cout << "Incorrect password!\n If you want to try again press R!\n If you want to quit press Q!" << endl;
		char option2 = ' ';

		CHAR_INPUT2:

		cin >> option2;
		if (option2 == 'R' || option2 == 'r')
		{
			goto PASSWORD_INPUT1;
		}
		else if (option2 == 'Q' || option2 == 'q')
		{
			quit();
		}
		else
		{
			cout << "Wrong letter was entered, please try again!" << endl;
			goto CHAR_INPUT2;
		}
	}
	else
	{
		cout << "Login successful!" << endl;
		return true;
	}
}

bool registerSuccessful(int fileLength,string fileName, string usernames[], size_t passwords[], string& username, string& password)
{
USERNAME_INPUT1:

	cout << "Please, enter your username: ";

USERNAME_INPUT2:
	cin >> username;
	if (!isValidUsername(username))
	{
		cout << endl << "The username must contain only latin letters or symbols!" << endl << "Re-enter your username: ";
		goto USERNAME_INPUT2;
		cout << endl;
	}
	if (doesUsernameExist(usernames, username, fileLength))
	{
		cout << "This username already exists in our database!\n If you want to try again press R!\n If you want to quit press Q!" << endl;

		char option3 = ' ';

		CHAR_INPUT:

		cin >> option3;
		if (option3 == 'R' || option3 == 'r')
		{
			goto USERNAME_INPUT1;
		}
		else if (option3 == 'Q' || option3 == 'q')
		{
			quit();
		}
		else
		{
			cout << "Wrong letter was entered, please try again!" << endl;
			goto CHAR_INPUT;
		}
	}
		
		PASSWORD_INPUT1:

		cout << "Please, enter your password: " << endl;		

		cin >> password;
		cout << endl;

		if (!isRegisterPassCorrect(password))
		{
			cout << "Your password must be at least 5 characters long, contain only latin letters, or the symbols !@#$%^&*" << endl;
			cout<<"It also has to contain at least 1 big, 1 small letter and 1 symbol!Please re - enter a valid password or quit!" << endl<<endl;
			cout<< "If you want to try again press R!\nIf you want to quit press Q!"<<endl;
			char option4 = ' ';

			CHAR_INPUT2:

			cin >> option4;

			if (option4 == 'R' || option4 == 'r')
			{
				goto PASSWORD_INPUT1;
			}
			else if (option4 == 'Q' || option4 == 'q')
			{
				quit();
			}
			else
			{
				cout << "Wrong letter was entered, please try again!" << endl;
				goto CHAR_INPUT2;
			}
		}
		else 
		{
			appendToFile(fileName, username, password, STARTING_BALANCE);
			return true;
		}
}


