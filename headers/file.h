#pragma once
#define FILE_H

#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <dirent.h>
#include <pwd.h>
#include <unistd.h>
#include <limits>
#include <iostream>

class File{
    static std::string path; // full path to directory, set with the setter
    std::string fileName; // filename

public:
    File(std::string fileName) : fileName(fileName){}

    // cin.clear(), cin.ignore().
    int createFile(std::string fileName);
    int deleteFile();
    int addContentsToFile();
    int displayFileContents();
    int findFile();
    // cin.ignore()
    int overwriteFile();
    // ofstream (open, close), mkdir
    int constructFileSystem();  

    // setter for path
    static void setPath(std::string newPath);
};