//Homework 14

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to read the name of
 *                      students from a text file in the format last name, 
 *      `               first name, and middle name. The program will read 
 *                      each students name into a string variable. The string 
 *                      variable will be passed to a function that convert 
 *                      the name to the proper format and returns the 
 *                      converted name. The results of each converted name 
 *                      will be printed to the screen.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/30/2017 22:46 PST
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

// Converts the string name to the proper formate
 string convertName(string name); 

int main(int argc, char** argv)
{
    //Declare variables to read in names
    string name_Formal, name_Full;
    
    //File stream variables
    ifstream inFile;
     
    //Open input file
    inFile.open("Students.txt");

    //If file not present
    if(!inFile)
    {
        cout << "The input file could not be opened." << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    //While loop to cycle through text file, convert name, and display name
    while(!inFile.eof())
    {
        getline(inFile, name_Formal);
        name_Full = convertName(name_Formal);
        cout << name_Full << endl;
    }
    //Close inFile
    inFile.close();
    //Terminate upon successful completion.
    exit(EXIT_SUCCESS);
}

string convertName(string name)
{
    string name_First, name_Middle, name_Last, name_Final;
    int pos_comma, pos_Name1, pos_end, length;
    
    //Find Length of String
    length = name.length();
    //Find First Comma
    pos_comma = name.find(",");
    //Substring up to comma is last name
    name_Last = name.substr(0, pos_comma);
    //First (and Middle) names start after space
    pos_Name1 = name.find(" ");
    //Substring First and Middle name
    name_First = name.substr((pos_Name1 + 1),(length -pos_Name1 - 1));
    //Convert to one string
    name_Final = name_First + " " + name_Last;
    //Return String
    return name_Final;
}