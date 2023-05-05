#pragma once
#define FILE_H

class File{
    int num;

public:
    File(){

    }

    // cin.clear(), cin.ignore().
    int createFile();
    int deleteFile();
    int addContentsToFile();
    int displayFileContents();
    int findFile();
    // cin.ignore()
    int overwriteFile();
    // ofstream (open, close), mkdir
    int constructFileSystem();    
};