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
    int numFiles = 0; // num files without . and ..

    int createFile(File &file); // create file into local directory
    int loadExistingDir(); // directory pointer, dirent, opendir, readdir, seekg, tellg, closedir

public:
    Directory(std::string directoryName);

    int createDirectory(); // getpwuid, getuid, c_str() // pulls from directoryName and makes a local directory
    int displayDirectoryContent(int flag = 1); // displays fileList
    int displayFileContents(int fileNum); // displays file contents
    int addFile(File &file); // addsFile to the fileList. dynamically moves . and ..
    int removeFile(int fileNum); // updates the fileList when removing a file. shifts everything over to the left
    int constructFileSystem(); // ofstream (open, close), mkdir // creates the file system locally

    int addToFile(int fileNum, std::string contents); // find file with int fileNum
    int overwriteFile(int fileNum, std::string contents); // find file with int fileNum

    std::string getPath(){ return path; }
    std::string getDirectoryName(){ return directoryName; }
    File** getFileList(){ return fileList; }
    int getNumFiles(){ return numFiles; }

};