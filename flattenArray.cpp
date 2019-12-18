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

    cout << "Please enter your array of integers in the following format, \nusing the comma as a delimter and square brackets to indicate array closure. (e.g. [1,2,...,n]) \nYour Array: ";
    getline(cin, arrayString);

    string errorMessage = "";
    bool temp = validateArrayString(arrayString, errorMessage);

    return getArrayStringInputRequestLoop(temp, arrayString);
}

string getArrayStringInputRequestLoop(bool temp, string & arrayString)
{
    int i = 0;
 
    do 
    {
        if(temp == 1)
            return arrayString;
        else
        {
            cout << "Please enter a non-empty array: ";
            getline(cin, arrayString);
            string errorMessage = "";
            bool temp = validateArrayString(arrayString, errorMessage);
            i++;
            if((i >= 2) && arrayString == "")
                break;
        }
    } while(temp != 1);

    return arrayString;
}

bool validateArrayString(string & arrayString, string & errorMessage)
{
    if(arrayString.empty() == false) 
    {
        bool validArray = processArrayString(arrayString, errorMessage);
        
        cout << "The array is: " << arrayString << endl;

        if(validArray)
            return 1;
        else
        {
            cout << "This array is not valid. " << errorMessage;
            return 0;
        }
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

bool processArrayString(string & arrayString, string & errorMessage)
{
    if(arrayString[0] != '[')
    {
        errorMessage = "The first character is not an open bracket ([).\n";
        return 0;
    }
    else if(arrayString[arrayString.length() - 1] != ']')
    {
        errorMessage = "The last character is not a closing bracket (]).\n";
        return 0;
    }
    else
    {
        errorMessage = "";
        flattenArray(arrayString);
        return 1;
    }
    
}

void flattenArray(string & arrayString)
{
    
}