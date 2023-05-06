#include "../headers/directory.h"

int dirExists(const char* const path) {
    struct stat info;

    int statRC = stat( path, &info );
    return (statRC == 0) ? 1 : 0; // 1 if exists, 0 if not
}

long getFileSize(File file){
    // stat method of checking filesize
    // struct stat info;
    // int rc = stat(filename.c_str(), &info);
    // return rc == 0 ? info.st_size : -2;

    std::string fileName = file.getFileName();
    std::fstream& filePointer = file.getData();
    filePointer.open(fileName.c_str(), std::ios::binary | std::ios::ate);
    return static_cast<long>(filePointer.tellg());
}

Directory::Directory(std::string directoryName) : directoryName(directoryName){}

int Directory::createDirectory(){ // getpwuid, getuid, c_str()
    std::string homeDir = (getenv("HOME")) ? getenv("HOME") : getpwuid(getuid())->pw_dir; // sets the home directory if there isn't a default

    path = homeDir + "/" + directoryName;

    if (dirExists(path.c_str())) { // checks if directory already exists
        printf("Loading existing directory\n\n");
        return 1;
    }

    // creates directory
    int status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (status == 0) {
        printf("Directory created.\n\n");
        return 0;
    }
    else {
        printf("Error creating directory.\n\n");
        return 1;
    }
}

// doesn't order .. and . properly
int Directory::displayDirectoryContent(){
    //

    // opens local directory and gets file size
    // DIR *dir = opendir (path.c_str());
    // struct dirent *entry;

    // // couldn't open directory
    // if (dir == NULL) { return 1; }

    // // print directory name
    // printf("%s\n", directoryName.c_str()); // better than printf(directoryName.c_str()) bc it's more secure

    // // print all files in directory
    // int i = 1;
    // while ((entry = readdir(dir)) != NULL) {
    //     long fileSize = getFileSize(path + "/" + entry->d_name);
        
    //     printf("\t%i. %s %li bytes\n", i, entry->d_name, fileSize);
    //     i++;
    // }
    // printf("\t%i. %s\n\n", i, "Nevermind");

    // closedir(dir); // closes the directory
    // return 0;

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

int Directory::addFile(){
    return 0;
}

int Directory::updateFilesInDirectory(){
    return 0;
}

// ofstream (open, close), mkdir
int Directory::constructFileSystem(){
    return 0;
}

