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
* file containing functions that work with the file which contains all the data
*
*/

#pragma once
#include "inputVerifications.h"
#include "logInAndRegisterFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;

void quit();

int getFileLength(string fileName);

void fillArraysWithInfo(string fileName, string* usernames, size_t* passwords, long float* balances);

void appendToFile(string fileName, string username, string password, long float balance);

void deleteLineFromFile(string fileName, int removeLine);

bool rewriteBalance(string usernames[], string username, size_t passwords[], long float balances[], long float amount, int rowIndex);
