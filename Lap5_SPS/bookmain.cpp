#include <iostream>
#include <fstream>
#include <string>
#include "book.cpp"
using namespace std;

/*
CIS22B
Name: Stefano Pinna Segovia
Date: 11/22/2023
Lab 5: Classes and Objects
Program Description: Using a book class, the main file creates an array of 10 book objects.
It then takes an inputfile with the attributes of 10 books and inserts it into the array. The 
program then outputs the array onto the console. 

Pseudocode:
The main function begins by attempting to open a file named "bookdata.txt" using an input file 
stream (ifstream). If the file fails to open, an error message is displayed, and the program
returns with an error code. Assuming the file is successfully opened, an array of Book objects 
named books is created. The function then enters a loop that reads data for 10 books from the 
input file, line by line. For each book, the relevant information (ISBN, title, author, etc.) is 
read from the file, and a new Book object is constructed using the parameterized constructor. The
constructed Book object is then assigned to the corresponding element in the array. After reading 
all book data, the input file is closed. The program then enters another loop to iterate through
the array of Book objects and print out the details of each book (ISBN, title, author, etc.) 
to the console. Finally, the program pauses before returning 0 to the operating system. In
summary, this program reads book data from a file, creates Book objects with the provided 
information, stores them in an array, and then prints out the details of each book to the console.
*/

int main() {

    ifstream inputFile("bookdata.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    Book books[10]; 

    for (int i = 0; i < 10; i++) 
    {
        string bookISBN, bookTitle, bookAuthor, bookPublisher, bookDate, bookQuantity, bookWholesaleCost, bookRetailPrice;

        getline(inputFile, bookISBN);
        getline(inputFile, bookTitle);
        getline(inputFile, bookAuthor);
        getline(inputFile, bookPublisher);
        getline(inputFile, bookDate);
        getline(inputFile, bookQuantity);
        getline(inputFile, bookWholesaleCost);
        getline(inputFile, bookRetailPrice);
        inputFile.ignore();

        books[i] = Book(bookISBN, bookTitle, bookAuthor, bookPublisher, bookDate, bookQuantity, bookWholesaleCost, bookRetailPrice);
    }

    inputFile.close(); 

    for (int i = 0; i < 10; i++) 
    {
        cout << "ISBN: " << books[i].getISBN() << endl;
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "Author: " << books[i].getAuthor() << endl;
        cout << "Publisher: " << books[i].getPublisher() << endl;
        cout << "Date: " << books[i].getDate() << endl;
        cout << "Quantity: " << books[i].getQuantity() << endl;
        cout << "Wholesale Cost: " << books[i].getWholesaleCost() << endl;
        cout << "Retail Price: " << books[i].getRetailPrice() << endl;

        cout << endl; 
    }

    system("pause");
    return 0;
}
