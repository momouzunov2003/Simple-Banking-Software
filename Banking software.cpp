/**
*
* Solution to course project #9
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Momchil Uzunov
* @idnumber 1MI0600146
* @compiler VC
*
* file containing the main code for the banking software
*
*/

#include "printMenus.h"
#include "inputVerifications.h"
#include "logInAndRegisterFunctions.h"
#include "fileFunctions.h"
#include "bankingFunctions.h"
using namespace std;

const string FILE_NAME = "users.txt";

int main()
{
START:

	int fileLength = getFileLength(FILE_NAME);

	string* usernames = new string[fileLength];
	size_t* passwords = new size_t[fileLength];
	long float* balances = new long float[fileLength];

	fillArraysWithInfo(FILE_NAME, usernames, passwords, balances);



	printHomeMenu();
	char startInput = ' ';
CHAR_INPUT:
	cin >> startInput;
	cout << endl;
	if (!isValidCharInput(startInput))
	{
		cout << "Please, enter a valid character:" << endl;
		goto CHAR_INPUT;
	}
	if (startInput != 'L' && startInput != 'l' && startInput != 'R' && startInput != 'r' && startInput != 'Q' && startInput != 'q')
	{
		cout << "Wrong letter was entered, please try again!" << endl;
		goto CHAR_INPUT;
	}

	string username = "";
	string password = "";

	//Login
	if (startInput == 'L' || startInput == 'l')
	{
		if (logInSuccessful(fileLength, usernames, passwords, username, password))
		{
			int rowIndex = getUsernameIndex(usernames, username, fileLength);
			clearConsole();
			printMainMenu(username, balances[rowIndex]);
			goto MAIN_MENU;
		}
	}

	//Register
	else if (startInput == 'R' || startInput == 'r')
	{
		if (registerSuccessful(fileLength, FILE_NAME, usernames, passwords, username, password))
		{
			cout << "Successful registration! Press C to go back to the home menu or press Q to quit!" << endl;
			char choice = ' ';
		CHOICE_INPUT:
			cin >> choice;
			if (choice == 'C' || choice == 'c')
			{
				clearConsole();
				delete[]usernames;
				delete[]passwords;
				delete[]balances;
				goto START;
			}
			else if (choice == 'Q' || choice == 'q')
			{
				quit();
			}
			else
			{
				cout << "Please enter a valid letter: " << endl;
				goto CHOICE_INPUT;
			}
		}
	}
	//Quit
	else if (startInput == 'Q' || startInput == 'q')
	{
		quit();
	}

MAIN_MENU:

	char mainInput = ' ';

MAIN_CHAR_INPUT:


	cout << endl;
	cin >> mainInput;

	int rowIndex = getUsernameIndex(usernames, username, fileLength);

	//Cancel
	if (mainInput == 'C' || mainInput == 'c')
	{

		cancelAccount(FILE_NAME, balances, rowIndex);

		cout << endl << "Successfully canceled account!";
		quit();
	}

	else if (mainInput == 'D' || mainInput == 'd')
	{
		long float amount;

		cout << endl << "How much do you want to deposit?" << endl;

	FLOAT_INPUT:

		cin >> amount;
		if (cin.fail())
		{

			cout << "Invalid value! Try again!" << endl;
			cin.clear();
			cin.ignore();
			goto FLOAT_INPUT;
		}

		if (depositSuccessful(usernames, username, passwords, balances, amount, rowIndex))
		{

			cout << "Successful deposit! Press C to go back to the start menu or press Q to quit!" << endl;
			char choice = ' ';

		CHOICE_INPUT2:

			cin >> choice;
			if (choice == 'C' || choice == 'c')
			{
				clearConsole();
				delete[]usernames;
				delete[]passwords;
				delete[]balances;
				goto START;
			}
			else if (choice == 'Q' || choice == 'q')
			{
				quit();
			}
			else
			{
				cout << "Please enter a valid letter: " << endl;
				goto CHOICE_INPUT2;
			}
		}
	}

	else if (mainInput == 'L' || mainInput == 'l')
	{
		clearConsole();
		delete[]usernames;
		delete[]passwords;
		delete[]balances;
		goto START;
	}

	else if (mainInput == 'T' || mainInput == 't')
	{
		long float amount;

		cout << endl << "How much do you want to transfer?" << endl;

	FLOAT_INPUT2:

		cin >> amount;
		if (cin.fail())
		{

			cout << "Invalid value! Try again!" << endl;
			cin.clear();
			cin.ignore();
			goto FLOAT_INPUT2;
		}

		string beneficient = "";

	BENEFICIENT_INPUT:

		cout << "Please enter the user to whom you want to transfer: " << endl;

		cin >> beneficient;

		if (doesUsernameExist(usernames, beneficient, fileLength))
		{
			if (beneficient.compare(username) == 0)
			{
				cout << "You can't make a transfer to yourself!\nIf you want to try again press R!\nIf you want to quit press Q!" << endl;
				char option = ' ';

			OPTION_INPUT:

				cin >> option;
				if (option == 'R' || option == 'r')
				{
					goto BENEFICIENT_INPUT;
				}
				else if (option == 'Q' || option == 'q')
				{
					quit();
				}
				else
				{
					cout << "Wrong letter was entered, please try again!" << endl;
					goto OPTION_INPUT;
				}


			}

			int usernameIndex = getUsernameIndex(usernames, username, fileLength);
			int beneficientIndex = getUsernameIndex(usernames, beneficient, fileLength);

			if (transferSuccessful(usernames, username, beneficient, passwords, balances, amount, usernameIndex, beneficientIndex))
			{
				cout << "Successful transfer! Press C to go back to the start menu or press Q to quit!" << endl;
				char choice = ' ';

			CHOICE_INPUT3:

				cin >> choice;
				if (choice == 'C' || choice == 'c')
				{
					clearConsole();
					delete[]usernames;
					delete[]passwords;
					delete[]balances;
					goto START;
				}
				else if (choice == 'Q' || choice == 'q')
				{
					quit();
				}
				else
				{
					cout << "Please enter a valid letter: " << endl;
					goto CHOICE_INPUT3;
				}
			}
		}

		else
		{
			cout << "This user does not exist!\nIf you want to try again press R!\nIf you want to quit press Q!" << endl;
			char option = ' ';

		OPTION_INPUT2:

			cin >> option;
			if (option == 'R' || option == 'r')
			{
				goto BENEFICIENT_INPUT;
			}
			else if (option == 'Q' || option == 'q')
			{
				quit();
			}
			else
			{
				cout << "Wrong letter was entered, please try again!" << endl;
				goto OPTION_INPUT2;
			}
		}
	}


	else if (mainInput == 'W' || mainInput == 'w')
	{
		long float amount;

		cout << endl << "How much do you want to withdraw?" << endl;

	FLOAT_INPUT3:

		cin >> amount;
		if (cin.fail())
		{

			cout << "Invalid value! Try again!" << endl;
			cin.clear();
			cin.ignore();
			goto FLOAT_INPUT3;
		}

		if (withdrawalSuccessful(usernames, username, passwords, balances, amount, rowIndex))
		{
			cout << "Successful withdrawal! Press C to go back to the start menu or press Q to quit!" << endl;
			char choice = ' ';

		CHOICE_INPUT4:

			cin >> choice;
			if (choice == 'C' || choice == 'c')
			{
				clearConsole();
				delete[]usernames;
				delete[]passwords;
				delete[]balances;
				goto START;
			}
			else if (choice == 'Q' || choice == 'q')
			{
				quit();
			}
			else
			{
				cout << "Please enter a valid letter: " << endl;
				goto CHOICE_INPUT4;
			}
		}
	}

	delete[]usernames;
	delete[]passwords;
	delete[]balances;
}