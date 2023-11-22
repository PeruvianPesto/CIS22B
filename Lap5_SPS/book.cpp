#include <iostream>
#include <string>
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
The Book class is a representation of a book with private member variables such as ISBN, title, author,
etc. It provides three constructors: a default constructor that initializes the member variables to empty
strings, a parameterized constructor that takes values for each member variable, and a copy constructor 
that creates a new Book object by copying the values from an existing Book object. The class also includes 
getter and setter methods for each member variable, allowing access and modification of the private data.  
The destructor is empty in this case, as there is no dynamic memory allocation that needs to be explicitly 
managed.
*/

class Book {
    
    private:
        string ISBN;
        string title;
        string author;
        string publisher;
        string date;
        string quantity;
        string wholesaleCost;
        string retailPrice;
    
    public:
        Book(); 
        Book(string bookISBN, string bookTitle, string bookAuthor, string bookPublisher, string bookDate, string bookQuantity, string bookWholesaleCost, string bookRetailPrice);
        Book(const Book& otherBook);

        ~Book();

        void setISBN(string bookISBN) {ISBN = bookISBN;}
        void setTitle(string bookTitle) {title = bookTitle;}
        void setAuthor(string bookAuthor) {author = bookAuthor;}
        void setPublisher(string bookPublisher) {publisher = bookPublisher;} 
        void setDate(string bookDate) {date = bookDate;}
        void setQuantity(string bookQuantity) {quantity = bookQuantity;}
        void setWholesaleCost(string bookWholesasleCost) {wholesaleCost = bookWholesasleCost;}
        void setRetailPrice(string bookRetailPrice) {retailPrice = bookRetailPrice;}
        string getISBN() {return ISBN;}
        string getTitle() {return title;}
        string getAuthor() {return author;}
        string getPublisher() {return publisher;}
        string getDate() {return date;}
        string getQuantity() {return quantity;}
        string getWholesaleCost() {return wholesaleCost;}
        string getRetailPrice() {return retailPrice;}
};

Book::Book() {
    ISBN = "";
    title = "";
    author = "";
    publisher = "";
    date = "";
    quantity = "";
    wholesaleCost = "";
    retailPrice = "";
}

Book::Book(string bookISBN, string bookTitle, string bookAuthor, string bookPublisher, string bookDate, string bookQuantity, string bookWholesaleCost, string bookRetailPrice) {
    ISBN = bookISBN;
    title = bookTitle;
    author = bookAuthor;
    publisher = bookPublisher;
    date = bookDate;
    quantity = bookQuantity;
    wholesaleCost = bookWholesaleCost;
    retailPrice = bookRetailPrice;
}

Book::Book(const Book& otherBook) {
    ISBN = otherBook.ISBN;
    title = otherBook.title;
    author = otherBook.author;
    publisher = otherBook.publisher;
    date = otherBook.date;
    quantity = otherBook.quantity;
    wholesaleCost = otherBook.wholesaleCost;
    retailPrice = otherBook.retailPrice;
}

Book::~Book()
{
    
}
