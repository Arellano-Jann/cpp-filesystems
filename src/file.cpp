#include "../headers/file.h"

std::string File::path; // define static variable

// cin.clear(), cin.ignore().
int File::createFile(){ // create empty file
    data.open(path + "/" + fileName, std::ios::out); // creates file in directory
    data.close();
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
int File::overwriteFile(std::string newData){
    std::cout << "overWritePath: " << path << "/" << fileName << std::endl;
    data.open(path + "/" + fileName, std::ios::out | std::ios::trunc); // creates file in directory
    data << newData;
    std::cout << "Overwriting with: " << newData << std::endl;

    // std::cout << "File contents: " << std::endl;
    // char c;
    // while (data.get(c)) {
    //     std::cout << c;
    // }

    data.close();
    return 0;
}
