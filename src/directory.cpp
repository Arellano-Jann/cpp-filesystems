#include "../headers/directory.h"

int dirExists(const char* const path) {
    struct stat info;

    int statRC = stat( path, &info );
    return (statRC == 0) ? 1 : 0; // 1 if exists, 0 if not
}

int Directory::createDirectory(std::string directoryName){ // getpwuid, getuid, c_str()
    std::string homeDir = (getenv("HOME")) ? getenv("HOME") : getpwuid(getuid())->pw_dir; // sets the home directory if there isn't a default

    std::string path = homeDir + "/" + directoryName;

    if (dirExists(path.c_str())) { // checks if directory already exists
        std::cout << "Directory already exists. Loading directory" << std::endl;
        return 1;
    }

    // creates directory
    int status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (status == 0) {
        std::cout << "Directory created." << std::endl;
        return 0;
    }
    else {
        std::cout << "Error creating directory." << std::endl;
        return 1;
    }
}

int Directory::displayDirectoryContent(){
    return 0;
}

