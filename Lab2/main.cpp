/*
CIS22B
Author: Stefano Pinna Segovia
Lab 2 - Output Reverse File
Program Description: Asks the user for an input and output file. The program 
will read the input file by word into the array. It will then print the 
output file to both screen and file.

Pseudocode:
Creates 5 variables: 2 strings for the input and output paths, 1 ifstream for the input file,
1 ofstream for the output file, and a string array with a size of 1024. Program will ask the user
to paste the path of their input file and their output file, which will be stored in inputPath
and outputPath. Next, the program will open both files using the path that the user inputed. If 
the file does not exist, the program will give a message and end. If they both do exist, the 
program will continue. First, the program will read the file and insert it into the stringArray.
Then, using a reversing for loop, it will insert the strings from the array backwards onto both 
the screen and file. The program then closes the files and returns.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    std::string inputPath;
    std::string outputPath;
    std::string stringArray[1024];
    std::ifstream inputFile;
    std::ofstream outputFile; 

    std::cout << "Paste full path of file to be read" << endl;
    std::getline(std::cin, inputPath);

    std::cout << "Paste full path of output file" << endl;
    std::getline(std::cin, outputPath);

    inputFile.open(inputPath);
    if (!inputFile.is_open()) {
        std::cout << "Input file could not be opened" << endl;
        system("pause");
        return 1;
    }

    outputFile.open(outputPath);
    if (!outputFile.is_open()) {
        std::cout << "Output file could not be opened" << endl;
        system("pause");
        return 1;
    }

    int x = 0;
    while (x < 1024 && inputFile >> stringArray[x]) {
        x++;
    }

    for (int i = x - 1; i >= 0; i--) {
        std::cout << stringArray[i] << " ";
        outputFile << stringArray[i] << " ";  
    }


    inputFile.close();
    outputFile.close();

    system("pause");
    return 0;  
}
