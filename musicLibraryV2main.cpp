/*
Name: Nathan Grasso

Date: December 7, 2022

Class: CSC 161

Purpose: The purpose of this program is to emulate a music library that takes in user input and stores that data
in a seperate txt file. The user should be able to browse the library by outputting the entire txt file. This
project is being used to display an understanding of core concepts learned in class.

Main concepts demostrated in this program are:
- Utilization of classes
- constructors and destructors
- exception handling
- encapsulation
- read, write, and search a txt file
- 
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "musicLibraryV2.h"
#include "musicLibraryV2imp.cpp"
using namespace std;

//
//Main Program
//
int main(){

int option; // variable for user option

cout << "Welcome to music library!"<< endl;
cout<< "please select a number for the option: "<<endl;
cout <<"1.) Add\n"<<"2.) Listen\n"<<"3.) Browse\n"<<"4.) Exit\n";

//exception handling for user input option
try
{
cin >> option;
if(option <= 0 || option > 4)
    {
    throw "Option must be an integer 1-4.";
    }
}
catch(const char* inputExceptionNum) //pointer
{
    cout<< "Exception: " << inputExceptionNum<< endl;
    cout<<"Please select an option from the menu: "<<endl;
    cin>>option;
}


songEntry songLibrary; //place object creation outside of switch because of scope issues

//switch statment to execute an option according to the user
switch(option){
    //song entry
    case 1:{
        songLibrary.getInfo();
        break;
    }
    //"listen" to song (more of a song search)
    case 2:{
        songLibrary.searchLibrary();
        break;
    }
    //outputs all information in the library(txt file)
    case 3:{
        songLibrary.readSongLibrary();
        break;
    }
    //exits the program
    case 4:{
        cout<<"Exiting your music library...";
        return 0;
        break;
    }
    }
return 0;
}