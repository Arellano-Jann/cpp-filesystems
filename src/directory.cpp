#include "../headers/directory.h"

int dirExists(const char* const path) {
    struct stat info;

    int statRC = stat( path, &info );
    return (statRC == 0) ? 1 : 0; // 1 if exists, 0 if not
}

int Directory::createDirectory(){ // getpwuid, getuid, c_str()
    std::string homeDir = (getenv("HOME")) ? getenv("HOME") : getpwuid(getuid())->pw_dir; // sets the home directory if there isn't a default

    path = homeDir + "/" + directoryName;

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
    DIR *dir = opendir (path.c_str());
    struct dirent *entry;

    // couldn't open directory
    if (dir == NULL) { return 1; }

    // print directory name
    printf("%s", directoryName.c_str()); // better than printf(directoryName.c_str()) bc it's more secure

    // print all files in directory
    int i = 1;
    while ((entry = readdir(dir)) != NULL) {
        printf("\t%i. %s %i bytes\n", i, entry->d_name, entry->d_reclen);
        i++;
    }
    printf("\t%i. %s\n\n", i, "Nevermind");

    closedir(dir); // closes the directory
    return 0;

    // this seems like youre finding a specific file
    // int len = strlen(name);
    // DIR *dirp = opendir(".");
    // struct dirent *dp;
    // while ((dp = readdir(dirp)) != NULL)
    //         if (dp->d_namlen == len && !strcmp(dp->d_name, name)) {
    //                 (void)closedir(dirp);
    //                 return 0; // found
    //         }
    // (void)closedir(dirp);
    // return 1; // not found
    
}


