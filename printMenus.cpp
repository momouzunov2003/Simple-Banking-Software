#include "printMenus.h"

void clearConsole()
{
	system("cls");
}

void printAtMiddle(string a)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	int stringLength = a.length();

	cout << setw(columns / 2 + stringLength / 2) << a << endl;
}

void printLogo()
{
	printAtMiddle("_  _ ____ _  _    ___  ____ _  _ _  _");
	printAtMiddle("|\\/| |___ |  |    |__] |__| |\\ | |_/  ");
	printAtMiddle("|  | |___ |__|    |__] |  | | \\| | \\_ ");
}

void printHeader()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	printLogo();
	for (int i = 0; i < columns; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << endl;
}

void printHomeMenu()
{
	printHeader();
	printAtMiddle("Welcome to MEU BANK! Please, choose an option below!");
	cout << endl << endl;
	printAtMiddle("Press L on your keyboard to log in the bank system!");
	cout << endl;
	printAtMiddle("Press R on your keyboard to make a new profile in the bank system!");
	cout << endl;
	printAtMiddle("Press Q on your keyboard to exit from the bank system!");
}

void printMainMenu(string username, long float balance)
{
	printHeader();
	cout << "Hello, " << username << "! You have " << fixed << setprecision(2) << balance << " BGN. You can choose one of the folowing options : " << endl;
	cout << "Press C to cancel your account in our bank system!" << endl;
	cout << "Press D to make a deposit in our bank!" << endl;
	cout << "Press L to log out from your account in our bank system!" << endl;
	cout << "Press T to transfer money from your account to another account that exists in our banking system!" << endl;
	cout << "Press W to withdraw money from your bank account!" << endl;
}
