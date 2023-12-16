#include <iostream>
#include <fstream>
#include <string>
#include "book.h"
using namespace std;

/*
Name: Stefano Pinna Segovia
Date: 12/1/2023
Lab 6: Operator Overloading in Classes
Program Description: An add-on for Lab 5. Adds 5 operator overloads, including an assignment 
operator, int casting operator, a comparison operator, an input stream operator, and an output 
stream operator.

Pseudocode:
2 ifstream files are created that end up taking in the same .txt file. Code then checks if the 
both are able to be opened, ending if one of them is not able to be opened. 2 Book arrays are 
created, books and originalBooks. The books array is made from the inputFile, using the input 
stream operator overload, while the originalInput array is made from the originalInput file, using
the original code from lab 5. Then, the first 50% of the books are read from books array using the
output method from lab 5. The final 50% are read from originalBooks using the output stream operator
overload. Next, I created new Book objects using the constructors from book.h and demonstrated the
use of the 3 class members. These include printing the default constructor, a parameterized constructor, and 
copy constructor. It then prints an object that uses the assignment operator, and int that uses the casting 
operator, and the comparison operator. 
*/

int main() {

    ifstream inputFile("bookdata.txt");
    ifstream originalInput("bookdata.txt");

    if (!inputFile.is_open() || !originalInput.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    Book books[10];
    Book originalBooks[10];

    for (int i = 0; i < 10; i++)
    {
        inputFile >> books[i];
    }

    for (int i = 0; i < 10; i++) 
    {
        string bookISBN, bookTitle, bookAuthor, bookPublisher, bookDate, bookQuantity, bookWholesaleCost, bookRetailPrice;

        getline(originalInput, bookISBN);
        getline(originalInput, bookTitle);
        getline(originalInput, bookAuthor);
        getline(originalInput, bookPublisher);
        getline(originalInput, bookDate);
        getline(originalInput, bookQuantity);
        getline(originalInput, bookWholesaleCost);
        getline(originalInput, bookRetailPrice);
        originalInput.ignore();

        originalBooks[i] = Book(bookISBN, bookTitle, bookAuthor, bookPublisher, bookDate, bookQuantity, bookWholesaleCost, bookRetailPrice);
    }

    inputFile.close();
    originalInput.close();

    for (int i = 0; i < 5; i++)
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

    for (int i = 5; i < 10; i++)
    {
        cout << originalBooks[i];

    }

    Book defaultBook();
    Book parameterBook("1234567890", "Random Title", "Billy Bob", "Some Publisher", "2023-01-01", "50", "10.00", "20.00");
    Book copyBook(parameterBook);
    
    Book copyBook2 = parameterBook;
    int intBook = parameterBook;
    bool isEqual = (parameterBook == copyBook);

    cout << "Constructor Demonstration" << endl << endl;

    cout << "DefaultBook: " << endl;
    cout << defaultBook << endl;;

    cout << "Parameterized Book: " << endl;
    cout << parameterBook;

    cout << "Copied Book: " << endl;
    cout << copyBook;

    cout << "Copied Book 2: " << endl;
    cout << copyBook2;

    cout << "ISBN int: " << endl;
    cout << intBook << endl;;

    cout << "Is Equal: " << endl;

    if (isEqual = true)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    

    system("pause");
    return 0;
}
