#include "../headers/file.h"

// std::string File::path; // define static variable

int File::addContentsToFile(std::string contents){
    data += contents;
    return 0;
}

int File::displayFileContents(){
    std::cout << data << std::endl;
    return 0;
}


// cin.ignore()
int File::overwriteFile(std::string newData){
    data = newData;

    // std::cout << "overWritePath: " << path << "/" << fileName << std::endl;
    // data.open(path + "/" + fileName, std::ios::in | std::ios::out | std::ios::trunc); // creates file in directory
    // std::cout << "Overwriting with: " << newData << std::endl;
    // data << newData;

    // std::cout << "File contents: " << std::endl;
    // char c;
    // while (data.get(c)) {
    //     std::cout << c;
    // }

    // data.close();
    return 0;
}
