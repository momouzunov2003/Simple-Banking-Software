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
* file containing functions that log users in the system and registers them
*
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "inputVerifications.h"
#include "fileFunctions.h"
using namespace std;

bool doesUsernameExist(string usernames[], string currentUsername, int usernamesSize);
bool doesPasswordsMatch(size_t passwords[], string currentPassword, int rowIndex);
int getUsernameIndex(string usernames[], string currentUsername, int usernamesSize);
bool logInSuccessful(int fileLength, string usernames[], size_t passwords[], string& username, string& password);
bool registerSuccessful(int fileLength, string fileName, string usernames[], size_t passwords[], string& username, string& password);