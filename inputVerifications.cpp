#include "inputVerifications.h"

bool isValidCharInput(char a)
{
	if ((a > 65 && a < 90) || (a > 97 && a < 122))
	{
		return true;
	}
	else return false;
}

bool isDigit(char a)
{
	if (a >= '0' && a <= '9')
	{
		return true;
	}
	else return false;
}

bool isLatinLetter(char a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
	{
		return true;
	}
	else return false;
}

bool isSymbol(char a)
{
	if ((a >= '!' && a <= '/') || (a >= ':' && a <= '@') || (a >= '[' && a <= '`') || (a >= '{' && a <= '~'))
	{
		return true;
	}
	else return false;
}

bool isSpecialSymbol(char a)
{
	if (a == '!' || a == '@' || a == '#' || a == '$' || a == '%' || a == '^' || a == '&' || a == '*')
	{
		return true;
	}
	else return false;
}

int countBigLetters(string a)
{
	int counter = 0;
	int index = 0;
	while (a[index] != '\0')
	{
		if (a[index] >= 'A' && a[index] <= 'Z')
		{
			counter++;
		}
		index++;
	}
	return counter;
}

int countSmallLetters(string a)
{
	int counter = 0;
	int index = 0;
	while (a[index] != '\0')
	{
		if (a[index] >= 'a' && a[index] <= 'z')
		{
			counter++;
		}
		index++;
	}
	return counter;
}

int countSymbols(string a)
{
	int counter = 0;
	int index = 0;
	while (a[index] != '\0')
	{
		if (isSymbol(a[index]))
		{
			counter++;
		}
		index++;
	}
	return counter;
}

int countSpecialSymbols(string a)
{
	int counter = 0;
	int index = 0;
	while (a[index] != '\0')
	{
		if (isSpecialSymbol(a[index]))
		{
			counter++;
		}
		index++;
	}
	return counter;
}

bool isValidUsername(string username)
{
	int index = 0;
	while (username[index] != '\0')
	{
		if (username[index] == ':')
		{
			return false;
		}
		if (!isLatinLetter(username[index]) && !isSymbol(username[index]))
		{
			return false;
			break;
		}
		index++;
	}
	return true;
}

bool isRegisterUsernameCorrect(string username)
{
	return isValidUsername(username);
}

bool isRegisterPassCorrect(string password)
{
	int length = password.length();
	if (length < 5 || countSmallLetters(password) < 1 || countBigLetters(password) < 1 || countSpecialSymbols(password) < 1)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (!isLatinLetter(password[i]) && !isDigit(password[i]) && !isSpecialSymbol(password[i]))
		{
			return false;
		}
	}
	return true;
}
