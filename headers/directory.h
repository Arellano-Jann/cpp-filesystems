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
    int num;

public:
    Directory(){

    }

    int createDirectory(std::string directoryName);
    int displayDirectoryContent();

};