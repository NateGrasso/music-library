#ifndef SONGENTRY_H
#define SONGENTRY_H
#include<string>
#include<fstream>
using namespace std;

class songEntry{
    private:
    string songTitle;
    string artistName;
    string albumName;
    public:
    void setInfo(string s, string art, string alb);
    //function to set song information and write that information into a seperate txt file
    void getInfo();
    //function to get song information
    void readSongLibrary();
    //function to output the contents of the music library txt file
    void searchLibrary();
    //function to search library
    songEntry();
    //constructor for songEntry object
    ~songEntry();
    //destructor for songEntry object
};

#endif