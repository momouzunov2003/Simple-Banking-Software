#include "bankingFunctions.h"

void cancelAccount(string fileName, long float balances[], int removeLine)
{	
		if (balances[removeLine] == 0)
		{
			if (removeLine == 0)
			{
				deleteLineFromFile(fileName, 1);
			}
			else
			{
				deleteLineFromFile(fileName, removeLine + 1);
			}

		}
		else
		{
			cout << endl << "To cancel your account you must have 0 balance!";
			quit();
		}
}

bool depositSuccessful(string usernames[], string username, size_t passwords[], long float balances[], long float amount, int rowIndex)
{
	if (rewriteBalance(usernames, username, passwords, balances, amount, rowIndex))
	{
		return true;
	}
}

bool transferSuccessful(string usernames[], string beneficier, string beneficient, size_t passwords[], long float balances[], long float amount, int beneficierIndex, int beneficientIndex)
{
	if (balances[beneficierIndex] - amount < MAXIMAL_OVERDRAFT)
	{
		cout << endl << "The maximal overdraft amount is 10000 BGN!" << endl;
	}
	else
	{
		rewriteBalance(usernames, beneficier, passwords, balances, -amount, beneficierIndex);
		rewriteBalance(usernames, beneficient, passwords, balances, amount, beneficientIndex);
		return true;
	}
}

bool withdrawalSuccessful(string usernames[], string username, size_t passwords[], long float balances[], long float amount, int rowIndex)
{
	if (balances[rowIndex] - amount >= MAXIMAL_OVERDRAFT)
	{
		if (rewriteBalance(usernames, username, passwords, balances, -amount, rowIndex))
		{
			return true;
		}

	}
	else if ((balances[rowIndex] - amount) < MAXIMAL_OVERDRAFT)
	{
		cout << endl << "The maximal overdraft amount is 10000 BGN!" << endl;
		quit();
	}
}
