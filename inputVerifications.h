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
* file containing functions that validate inputs
*
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
using namespace std;

bool isValidCharInput(char a);
bool isDigit(char a);
bool isLatinLetter(char a);
bool isSymbol(char a);
bool isSpecialSymbol(char a);
int countBigLetters(string a);
int countSmallLetters(string a);
int countSymbols(string a);
int countSpecialSymbols(string a);
bool isValidUsername(string username);
bool isRegisterUsernameCorrect(string username);
bool isRegisterPassCorrect(string password);