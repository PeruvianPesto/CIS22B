#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void SelectionSort(std::string array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        std::swap(array[i], array[min]);
    }
}

int BinarySearch(std::string array[], int length, std::string &word) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == word) {
            return mid;
        }

        if (array[mid] < word) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::string inputPath;
    std::string outputPath;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string stringArray[1024];
    int wordCount = 0;

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

    while (inputFile >> stringArray[wordCount]) {
        if (stringArray[wordCount].size() > 1) {
            wordCount++;
        }
    }

    SelectionSort(stringArray, wordCount);

    bool continueSearching = true;
    while (continueSearching) {
        std::string searchWord;
        std::cout << "Enter the word to be searched (case sensitive)" << endl;
        outputFile << "Enter the word to be searched (case sensitive)" << endl;
        std::cin >> searchWord;
        outputFile << searchWord;
        int result = BinarySearch(stringArray, wordCount, searchWord);

        std::cout << "Search word: " << searchWord << endl;
        outputFile << "Search word: " << searchWord << endl;

        if (result != -1) {
            std::cout << "The word '" << searchWord << "' was found at index " << result << endl;
            outputFile << "The word '" << searchWord << "' was found at index " << result << endl;
        }
        else {
            std::cout << "The word '" << searchWord << "' was not found in the array" << endl;
            outputFile << "The word '" << searchWord << "' was not found in the array" << endl;
        }

        std::cout << "Do you want to search again? (y/n)" << endl;
        outputFile << "Do you want to search again? (y/n)" << endl;
        char choice;
        std::cin >> choice;
        outputFile << choice;
        std::cout << "User choice: " << choice << endl;
        outputFile << "User choice: " << choice << endl;

        if (choice != 'y' && choice != 'Y') {
            continueSearching = false;
        }
    }

    outputFile.close();
    inputFile.close();
    system("pause");
    return 0;
}
