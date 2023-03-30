#include "musicLibraryV2.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void songEntry::setInfo(string s, string art, string alb){
    songTitle = s;
    artistName = art;
    albumName = alb;
    char fin;
    bool done = false;
    ofstream musicLibraryFile; //create ofstream object
    musicLibraryFile.open ("musicLibraryFile.txt", fstream :: app); //open file
    //enter song infomation
    while(done != true)
    {
    cout<<"Song: ";
    cin.ignore();
    getline(cin, s);
    musicLibraryFile <<"Song: "<< s << endl;
    cout<<"Artist: ";
    getline(cin, art);
    musicLibraryFile <<"Artist: "<< art << endl;
    cout<<"Album: ";
    getline(cin, alb);
    musicLibraryFile << "Album: "<< alb << endl;
    cout<< "Add another song? Y/N"<<" ";
    cin>>fin;
    cout<<endl;
    if(fin == 'N'|| fin == 'n')//sentinel value to end while loop
        {
        done = true;
        musicLibraryFile.close();
        }
    }
}

void songEntry::getInfo(){
    return setInfo(songTitle, artistName, albumName);
}

void songEntry::readSongLibrary(){ 
    ifstream musicLibraryFile; // create ifstream object
    musicLibraryFile.open("musicLibraryFile.txt");
    string line; // create string variable to store string data
    cout<<endl<<"****__Your Music__****"<< endl<<endl;
    if (musicLibraryFile.is_open()) // check if file is open
    {
        while (musicLibraryFile) // "is good"
        {
            getline(musicLibraryFile, line);
            cout<< line << '\n';

        }
    }
}

void songEntry::searchLibrary(){
    string searchItem, txtLine;
    int line = 1; //line count to traverse file
    bool found = false;
    cout<<"Search library for a song: ";
    cin >> searchItem; // enter search item
    cout<< endl;
    ifstream libraryFile; //file variable
    libraryFile.open("musicLibraryFile.txt");
    if(libraryFile.is_open())
    {
        while(getline(libraryFile, txtLine))
        {
            if(txtLine.find(searchItem,0) != string::npos) // obtain the line in which the search item is found and print next two lines
            {
                cout<< txtLine << endl;
                getline(libraryFile, txtLine);
                cout<< txtLine << endl;
                getline(libraryFile, txtLine);
                cout<< txtLine << endl << endl;
                found = true;
            }
            line++;

        }
        libraryFile.close();
    }
    else cout<<"Cannot open file.";
    if(found!=true)
    {
    cout<<"search item is not in library."<<endl;
    }
}


songEntry::songEntry(){
    //initalize object to empty strings
    songTitle =" ";
    artistName=" ";
    albumName=" ";
}

songEntry::~songEntry(){
    cout<<"Exiting music library..."<<endl;
}