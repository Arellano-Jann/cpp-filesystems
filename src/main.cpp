#include "../headers/file.h"
#include "../headers/directory.h"

// getline()
std::string getUserInput(std::string prompt = ""){
    printf("%s", prompt.c_str());
    std::string input;
    std::cin >> input; 
    return input;
}

void createFile(Directory& d){
    std::string fileName = getUserInput("Enter the name of the file you'd like to add: \n");
    if (fileName == ""){
        printf("Invalid file name\n");
        return;
    }
    for (int i = 0; i < d.getNumFiles(); i++){
        if (fileName == d.getFileList()[i]->getFileName()){
            printf("File already exists\n");
            return;
        }
    }
    File* newFile = new File(fileName);
    std::string contentFlag = getUserInput("Would you like to write anything to the file?\nY. Yes\nN. No\n");
    // above needs to persist if y or n is not entered
    if (contentFlag == "y" || contentFlag == "Y"){
        std::string contents = getUserInput("Enter the information you'd like to write to the file: \n");
        printf("\n");
        newFile->overwriteFile(contents);
    }
    d.addFile(*newFile);
    // File** newFileList = d.getFileList();
    // // prints new filesystem
    // for (int i = 0; i < d.getNumFiles(); i++){
    //     printf("%i. %s\n", i, newFileList[i]->getFileName().c_str());
    // }
}

void deleteFile(Directory& d){
    printf("Which file would you like to delete?\n");
    d.displayDirectoryContent();
    int fileNum = std::stoi(getUserInput()) - 1;
    printf("\n");
    if (fileNum == d.getNumFiles()+2){
        return;
    }
    d.removeFile(fileNum);
}

void addContents(Directory& d){
    printf("\nWhich file would you like to display?\n");
    d.displayDirectoryContent();
    int fileNum = std::stoi(getUserInput()) - 1;
    printf("\n");
    if (fileNum == d.getNumFiles()+2){
        return;
    }
    std::string contents = getUserInput("Enter the contents to add: ");
    d.addToFile(fileNum, contents);
}

void overwriteFile(Directory& d){
    printf("\nWhich file would you like to overwrite?\n");
    d.displayDirectoryContent();
    int fileNum = std::stoi(getUserInput()) - 1;
    printf("\n");
    if (fileNum == d.getNumFiles()+2){
        return;
    }
    std::string contents = getUserInput("Enter the content to overwrite the file with: ");
    d.overwriteFile(fileNum, contents);
}

void displayDirectory(Directory& d){
    printf("\n");
    d.displayDirectoryContent(0);
}

void displayFile(Directory& d){
    printf("\nWhich file would you like to display?\n");
    d.displayDirectoryContent();
    int fileNum = std::stoi(getUserInput()) - 1;
    printf("\n");
    if (fileNum == d.getNumFiles()+2){
        return;
    }
    d.displayFileContents(fileNum);
}

void displayMenu(Directory& d){
    while (true){
        printf("\n1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Add Contents to File\n");
        printf("4. Overwrite File\n");
        printf("5. Display Directory Contents\n");
        printf("6. Display File Contents\n");
        printf("0. Exit\n");

        printf("\nWhat would you like to do? ");
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
}

int main(){
    // int i = 1;
    // char d_name[256] = "stuff";
    // unsigned short d_reclen = 10;
    // printf("\t%i. %s %i bytes\n", i, d_name, d_reclen);
    // i++;
    // printf("\t%i. %s\n\n", i, "Nevermind");

    printf("\nLet's create a directory!\n");
    // std::string directoryName = getUserInput("Enter directory name: ");
    std::string path = "test";
    Directory d(path);
    d.createDirectory();
    displayMenu(d);

}