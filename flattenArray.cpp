//**************************************************
// Name:            flattenArray.cpp
// Author:          ND Guthrie
// Date:            15 December 2019
// Description:     This is an interactive C++ 
//                  application for flattening an 
//                  array of integers.
//**************************************************

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include "flattenArray.h"

using namespace std;

int main()
{
    doAllThings();

    return 0;
}

void doAllThings()
{
    std::cout << "Welcome to the Flatten Array program!" << endl;

    string temp = getArrayStringFromUser();

    masterControlLoop(temp);

}

void masterControlLoop(string aString)
{
    while(aString.empty())
    {
        string choice = "";
        cout << "You have not entered an array. Would you like to quit? (Y/n - Default: Yes) ";
        getline(cin, choice);
        if((strcmp(choice.c_str(), "n")))
        {
            cout << "\nQuitting...\n\n";
            return;
        }
        else
        {
            aString = getArrayStringFromUser();
        }
    }
}

string getArrayStringFromUser()
{
    string arrayString = "";

    cout << "Please enter your array: ";
    getline(cin, arrayString);

    bool temp = validateArrayString(arrayString);

    int i = 0;

    do 
    {
        if(temp == 1)
            return arrayString;
        else
        {
            cout << "Please enter a non-empty array: ";
            getline(cin, arrayString);
            bool temp = validateArrayString(arrayString);
            i++;
            if(i >= 4)
                break;
        }
    } while(arrayString == "");

    return arrayString;
}

bool validateArrayString(string arrayString)
{
    // bool temp = isStringEmpty(arrayString);

    if(arrayString.empty() == false) 
    {
        cout << "The array is: " << arrayString << endl;
        return 1;
    }
    else if(arrayString.empty() == true) 
    {
        cout << "The array is empty." << endl;
        return 0;
    }
    else
    {
        cout << "Not enough information. Terminating...";
        return 0;
    }

    return 0;
}