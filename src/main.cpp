#include "../headers/file.h"
#include "../headers/directory.h"

// getline()
std::string getUserInput(std::string prompt = ""){
    printf("%s", prompt.c_str());
    std::string input;
    std::cin >> input; 
    return input;
}

void createFile(Directory d){
    std::string fileName = getUserInput("Enter the name of the file you'd like to add: \n");
    File* newFile = new File(fileName);
    std::string contentFlag = getUserInput("Would you like to write anything to the file?\nY. Yes\nN. No\n");
    // above needs to persist if y or n is not entered
    if (contentFlag == "y" || contentFlag == "Y"){
        std::string contents = getUserInput("Enter the information you'd like to write to the file: \n");
        newFile->overwriteFile(contents);
    }
    d.addFile(*newFile);
}

void deleteFile(Directory d){
    int fileNum = std::stoi(getUserInput());
    d.removeFile(fileNum);
}

void addContents(Directory d){
    int fileNum = std::stoi(getUserInput());
    std::string contents = getUserInput();
    d.addToFile(fileNum, contents);
}

void overwriteFile(Directory d){
    int fileNum = std::stoi(getUserInput());
    std::string contents = getUserInput();
    d.overwriteFile(fileNum, contents);
}

void displayDirectory(Directory d){
    d.displayDirectoryContent();
}

void displayFile(Directory d){
    int fileNum = std::stoi(getUserInput());
    d.displayFileContents(fileNum);
}

void displayMenu(Directory d){
    printf("1. Create File\n");
    printf("2. Delete File\n");
    printf("3. Add Contents to File\n");
    printf("4. Overwrite File\n");
    printf("5. Display Directory Contents\n");
    printf("6. Display File Contents\n");
    printf("0. Exit\n");

    printf("\nWhat would you like to do? \n");
    switch (std::stoi(getUserInput())){
        case 1:
            createFile(d);
            break;
        case 2:
            deleteFile(d);
            break;
        case 3:
            addContents(d);
            break;
        case 4:
            overwriteFile(d);
            break;
        case 5:
            displayDirectory(d);
            break;
        case 6:
            displayFile(d);
            break;
        case 0:
            d.constructFileSystem();
            exit(0);
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}

int main(){
    // int i = 1;
    // char d_name[256] = "stuff";
    // unsigned short d_reclen = 10;
    // printf("\t%i. %s %i bytes\n", i, d_name, d_reclen);
    // i++;
    // printf("\t%i. %s\n\n", i, "Nevermind");

    printf("\nLet's create a directory!\n");
    std::string directoryName = getUserInput("Enter directory name: ");
    std::string path = "test";
    Directory d(path);
    d.createDirectory();
    displayMenu(d);

}