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


class Directory{
    std::string directoryName; // stock directory name
    std::string path; // full path to directory, set in createDirectory()

public:
    Directory(std::string directoryName) : directoryName(directoryName){}

    int createDirectory();
    int displayDirectoryContent();

};