#ifndef FileXML_h
#define FileXML_h

#include <iostream>
#include <fstream>

using namespace std;

class FileXML {
    const string FILE_NAME;

public:

    FileXML(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
    //bool isFileEmpty();
};

#endif // FileXML_h
