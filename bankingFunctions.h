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
* file containing functions that simulate transactions and other bank account functions
*
*/

#pragma once
#include <iostream>
#include <string>
#include "fileFunctions.h"
#include "logInAndRegisterFunctions.h"
using namespace std;

const int MAXIMAL_OVERDRAFT = -10000;

void cancelAccount(string fileName, long float balances[], int removeLine);
bool depositSuccessful(string usernames[], string username, size_t passwords[], long float balances[], long float amount, int rowIndex);
bool transferSuccessful(string usernames[], string beneficier, string beneficient, size_t passwords[], long float balances[], long float amount, int beneficierIndex, int beneficientIndex);
bool withdrawalSuccessful(string usernames[], string username, size_t passwords[], long float balances[], long float amount, int rowIndex);