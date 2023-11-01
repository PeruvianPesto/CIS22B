#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* 
CIS 22B
Lab 1: File Copy
Author: Stefano Pinna Segovia
Program Description: Asks the user for the full path of a file to be read - path should include the folder and filename.
Asks the user for the full path of a file to be written - path should include the folder and filename.
Opens the input and output files.
Copies the contents of input file exactly into an output file.

Pseudocode:
Creates string variables for the file paths and ifstream/ofstream vars for the files themselves
Asks the user to paste the path of their input file; Sets it to filePath
Asks the user to paste the path of their output file; Sets it to outputPath
Opens the input file and checks if it can even be opened or not
Opens the output file and checks if it can even be opened or not
Copies each character of the input file into the output file
Closes the 2 files
*/

int main(){
    
    std::string filePath; //Input Path variable 
    std::string outputPath; //Output Path variable

    std::ifstream inputFile; //Input File
    std::ofstream outputFile; //Output File

    char character;


    //Asks the user to paste the path of their input file; Sets it to filePath
    std::cout << "Paste full path of file to be read" << endl;
    std::getline(std::cin, filePath);

    //Asks the user to paste the path of their output file; Sets it to outputPath
    std::cout << "Paste full path of output file" << endl;
    std::getline(std::cin, outputPath);

    //Opens the input file and checks if it can even be opened or not
    inputFile.open(filePath);
    if (!inputFile.is_open()){
        cout << "Input file could not be opened" << endl;
        system("pause");
        return 1;
    }

    //Opens the output file and checks if it can even be opened or not
    outputFile.open(outputPath);
    if (!outputFile.is_open()){
        cout << "Output file could not be opened" << endl;
        system("pause");
        return 1;
    }

    //Copies each character of the input file into the output file
    while (inputFile.get(character))
    {
        outputFile.put(character);
    }

    cout << "Successful copy" << endl;

    //Closes the 2 files
    inputFile.close();
    outputFile.close();

    system("pause");
    return 0;
}