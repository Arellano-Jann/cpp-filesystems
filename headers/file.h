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
    std::fstream data; // file stream

public:
    File(std::string fileName) : fileName(fileName){}

    int createFile();
    int deleteFile();
    int addContentsToFile();
    int displayFileContents();
    int findFile();
    int overwriteFile(std::string newData);

    static void setPath(std::string newPath){ path = newPath; } // setter for path
    std::string getPath(){ return path; }
    std::string getFileName(){ return fileName; }
    std::fstream& getData(){ return data; }
    long getFileSize(){ 
        data.open(fileName.c_str(), std::ios::binary | std::ios::ate);
        // return static_cast<long>(data.tellg());
        return data.tellg();
    }
};