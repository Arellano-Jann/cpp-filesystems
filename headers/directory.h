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

    int createDirectory(); // getpwuid, getuid, c_str()
    int displayDirectoryContent();
    int addFile();
    int updateFilesInDirectory();
    int constructFileSystem(); // ofstream (open, close), mkdir
    int loadExistingDir(); // directory pointer, dirent, opendir, readdir, seekg, tellg, closedir

    std::string getPath(){ return path; }
    std::string getDirectoryName(){ return directoryName; }
    File** getFileList(){ return fileList; }

};