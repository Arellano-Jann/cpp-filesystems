#pragma once
#define DIRECTORY_H

#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <dirent.h>
#include <pwd.h>
#include <unistd.h>
#include <limits>
#include <iostream>
#include "file.h"


class Directory{
    std::string directoryName; // stock directory name
    std::string path; // full path to directory, set in createDirectory()

    File* fileList[1000]; // array of files in the directory


public:
    Directory(std::string directoryName);

    int createDirectory(); // getpwuid, getuid, c_str() // pulls from directoryName and makes a local directory
    int displayDirectoryContent(); // displays fileList
    int addFile(); // addsFile to the fileList
    int updateFilesInDirectory(); // updates the fileList when removing a file
    int constructFileSystem(); // ofstream (open, close), mkdir // creates the file system locally
    int loadExistingDir(); // directory pointer, dirent, opendir, readdir, seekg, tellg, closedir

    std::string getPath(){ return path; }
    std::string getDirectoryName(){ return directoryName; }
    File** getFileList(){ return fileList; }

};