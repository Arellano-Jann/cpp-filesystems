#include "../headers/file.h"
#include "../headers/directory.h"

// getline()
int getUserInput(){
    return 0;
}

void createFile(){
    
}

void deleteFile(){
    
}

void addContents(){
    
}

void overwriteFile(){
    
}

void displayDirectory(){
    
}

void displayFile(){
    
}

void displayMenu(){
    
}

int main(){
    // int i = 1;
    // char d_name[256] = "stuff";
    // unsigned short d_reclen = 10;
    // printf("\t%i. %s %i bytes\n", i, d_name, d_reclen);
    // i++;
    // printf("\t%i. %s\n\n", i, "Nevermind");

    std::string path = "test";
    Directory d(path);
    d.createDirectory();
    d.displayDirectoryContent();

}