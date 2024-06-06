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
* file containing functions that print separate menus
*
*/

#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

void clearConsole();
void printAtMiddle(string a);
void printLogo();
void printHeader();
void printHomeMenu();
void printMainMenu(string username, long float balance);