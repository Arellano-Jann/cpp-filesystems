#include "../headers/file.h"

std::string File::path; // define static variable

// cin.clear(), cin.ignore().
int File::createFile(){ // create empty file
    data.open(path + "/" + fileName, std::ios::out); // creates file in directory
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
