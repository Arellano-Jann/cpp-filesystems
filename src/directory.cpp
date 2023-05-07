#include "../headers/directory.h"

int dirExists(const char* const path) {
    struct stat info;

    int statRC = stat( path, &info );
    return (statRC == 0) ? 1 : 0; // 1 if exists, 0 if not
}

long getFileSize(File* file){
    // stat method of checking filesize
    // struct stat info;
    // int rc = stat(filename.c_str(), &info);
    // return rc == 0 ? info.st_size : -2;

    // std::string fileName = file->getFileName();
    // std::fstream& filePointer = file->getData();
    // filePointer.open(fileName.c_str(), std::ios::binary | std::ios::ate);
    // return static_cast<long>(filePointer.tellg());
    return file->getFileSize();
}

// 
Directory::Directory(std::string directoryName) : directoryName(directoryName){
    std::string homeDir = (getenv("HOME")) ? getenv("HOME") : getpwuid(getuid())->pw_dir; // sets the home directory if there isn't a default

    path = homeDir + "/" + directoryName;
}

int Directory::createDirectory(){ // getpwuid, getuid, c_str()

    if (dirExists(path.c_str())) { // checks if directory already exists
        printf("Loading existing directory\n\n");
        // printf("here\n");
        loadExistingDir();
        // printf("here\n");
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

// must be -1 on the .. and . files
int Directory::displayDirectoryContent(){
    // displays fileLIst content

    printf("%s\n", directoryName.c_str()); // better than printf(directoryName.c_str()) bc it's more secure

    // printf("\t%i. %s %i bytes\n", 1, "..", 1);
    // printf("\t%i. %s %i bytes\n", 2, ".", -1);
    for (int i = 0; i < 1000; i++) {
        // if (fileList[i]->getFileName() == "..") {
        //     printf("\t%i. %s\n\n", i+3, "Nevermind");
        //     break;
        // } else 
        if (fileList[i] != NULL){
            printf("\t%i. %s %li bytes\n", i+1, fileList[i]->getFileName().c_str(), getFileSize(fileList[i]));
        } else {
            printf("\t%i. %s\n\n", i+1, "Nevermind");
            break;
        }
    }
    return 0;

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

int Directory::addFile(File file){
    fileList[numFiles+2] = fileList[numFiles+1];
    fileList[numFiles+1] = fileList[numFiles];
    fileList[numFiles] = &file;
    return 0;
}

int Directory::removeFile(int fileNum){
    for (int i = fileNum-1 ; i < numFiles+2; i++) {
        fileList[i] = fileList[i+1];
    }
    return 0;
}

// ofstream (open, close), mkdir
int Directory::constructFileSystem(){
    return 0;
}

// directory pointer, dirent, opendir, readdir, seekg, tellg, closedir
int Directory::loadExistingDir(){
    // opens local directory and gets file size
    DIR *dir = opendir (path.c_str());
    struct dirent *entry;
    // printf("here\n");

    // couldn't open directory
    if (dir == NULL) { return 1; }

    // iterate through all files in the directory
    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
        // printf("here%i%s\n", i, entry->d_name);
        // std::string temp = path + "/" + entry->d_name;
        // printf(temp.c_str());

        std::ifstream inputFile(path + "/" + entry->d_name);
        // inputFile.open((entry->d_name));
        // std::cout << entry->d_name << " File contents: " << std::endl;
        // char c;
        // while (inputFile.get(c)) {
        //     std::cout << c << std::endl;
        // }

        std::string contents;
        std::string line;
        while (std::getline(inputFile, line)) {
            contents += line;
            // contents += line + "\n";
        }
        printf("Contents: %s\n", contents.c_str()); // might have an error here with saving the contents to the file. 

        fileList[i] = new File(entry->d_name);
        fileList[i]->overwriteFile(contents);
        // fileList[i]->overwriteFile("testing");
        i++;
        numFiles++;
        if (entry->d_name == ".." || entry->d_name == ".") {
            numFiles--;
        }
    }
    // printf("here\n");
    
    // std::string test = "stuff";
    // printf("%s", test.c_str());

    closedir(dir); // closes the directory
    return 0;
}

// cin.clear(), cin.ignore().
int Directory::createFile(File file){ // create file from fileLIst
    std::fstream outFile(path + "/" + file.getFileName(), std::ios::out); // creates file in directory
    outFile << file.getData();
    outFile.close();
    return 0;
}

int Directory::addToFile(int fileNum, std::string contents){
    fileList[fileNum]->addContentsToFile(contents);
    return 0;
}

int Directory::overwriteFile(int fileNum, std::string contents){
    fileList[fileNum]->overwriteFile(contents);
    return 0;
}
