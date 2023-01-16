#include <iostream>
#include "printMenus.h"
#include "inputVerifications.h"
#include <string>
#include <Windows.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;

void logIn()
{
	cout << "Please, enter your username: ";
	string username ;
	USERNAME_INPUT:
	cin >> username;
	if (!isValidUsername(username))
	{
		cout << endl << "The username must contain only latin letters or symbols!" << endl << "Re-enter your username: ";
		goto USERNAME_INPUT;
		cout << endl;
	}
	cout << "Please, enter your password: ";
	//isValidLogInPassword();//da proveri direktno dali syvpada s failovata parola
}

int main()
{	
	printHomeMenu();
	char firstInput = ' ';
	CHAR_INPUT:
	cin >> firstInput;
	if (!isValidCharInput(firstInput))
	{
		cout << "Please, enter a valid character:" << endl;
		goto CHAR_INPUT;
	}

	if (firstInput == 'L' || firstInput == 'l')
	{
		logIn();
	}
	//....
}