//**************************************************
// Name:            flattenArray.h
// Author:          ND Guthrie
// Date:            15 December 2019
// Description:     This is an interactive C++ 
//                  application for flattening an 
//                  array of integers.
//**************************************************

#include <stdio.h>
#include <iostream>

using namespace std;

void doAllThings();

void masterControlLoop(string aString);

string getArrayStringFromUser();

string getArrayStringInputRequestLoop(bool temp, string & arrayString);

bool validateArrayString(string arrayString, string & errorMessage);

bool processArrayString(string arrayString, string & errorMessage);