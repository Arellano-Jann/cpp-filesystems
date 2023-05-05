#include "../headers/directory.h"


int Directory::createDirectory(std::string directoryName){ // getpwuid, getuid, c_str()
    const char *homedir = (getenv("HOME")) ? getenv("HOME") : getpwuid(getuid())->pw_dir; // sets the home directory if there isn't a default

    return 0;
}

int Directory::displayDirectoryContent(){
    return 0;
}