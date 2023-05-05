#include "../headers/directory.h"

int dirExists(const char* const path) {
    struct stat info;

    int statRC = stat( path, &info );
    return (statRC == 0) ? 1 : 0; // 1 if exists, 0 if not
}

int Directory::createDirectory(){ // getpwuid, getuid, c_str()
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
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("c:\\src\\")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            printf ("%s\n", ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }

    // this seems like youre finding a specific file
    // int len = strlen(name);
    // DIR *dirp = opendir(".");
    // struct dirent *dp;
    // while ((dp = readdir(dirp)) != NULL)
    //         if (dp->d_namlen == len && !strcmp(dp->d_name, name)) {
    //                 (void)closedir(dirp);
    //                 return 1; // found
    //         }
    // (void)closedir(dirp);
    // return 0; // not found
    
    return 0;
}


