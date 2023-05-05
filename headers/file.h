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
    int num;

public:
    File(){

    }

    // cin.clear(), cin.ignore().
    int createFile();
    int deleteFile();
    int addContentsToFile();
    int displayFileContents();
    int findFile();
    // cin.ignore()
    int overwriteFile();
    // ofstream (open, close), mkdir
    int constructFileSystem();    
};