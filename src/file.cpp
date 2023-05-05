#include "../headers/file.h"

// cin.clear(), cin.ignore().
int File::createFile(){ // create empty file
    file.open(path + "/" + fileName, std::ios::out); // creates file in directory
    return 0;
}

int File::deleteFile(){
    return 0;
}

int File::addContentsToFile(){
    return 0;
}

int File::displayFileContents(){

    return 0;
}

int File::findFile(){
    return 0;
}

// cin.ignore()
int File::overwriteFile(){
    return 0;
}

// ofstream (open, close), mkdir
int File::constructFileSystem(){
    return 0;
}

void File::setPath(std::string newPath){
        path = newPath;
} 