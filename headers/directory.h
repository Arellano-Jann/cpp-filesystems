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
    std::string directoryName;

public:
    Directory(std::string directoryName) : directoryName(directoryName){}

    int createDirectory();
    int displayDirectoryContent();

};