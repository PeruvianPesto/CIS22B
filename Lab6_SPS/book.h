#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
CIS 22B
Name: Stefano Pinna Segovia
Date: 12/1/2023
Lab 6: Operator Overloading in Classes
Program Description: An add-on for Lab 5. Adds 5 operator overloads, including an assignment 
operator, int casting operator, a comparison operator, an input stream operator, and an output 
stream operator.

Pseudocode:
Class Book:
Private Members: ISBN, Title, Author, Publisher, Date, Quantity, WholesaleCost, RetailPrice

Public Methods:
Constructor Book():
Initialize all members to empty strings.

Constructor Book(ISBN, Title, Author, Publisher, Date, Quantity, WholesaleCost, RetailPrice):
Set members with provided values.

Copy Constructor Book(otherBook):
Copy values of otherBook's members to current object.

Destructor ~Book():
No dynamic memory, so nothing to release.

Setter and Getter methods for all private members

Operator Overload = (otherBook):
Check for self-assignment.
Copy values of otherBook's members to current object.
Return current object.

Operator Overload int():
Convert ISBN to integer and return.

Operator Overload == (otherBook):
Compare all members for equality.
Return true if all are equal, otherwise false.

Friend Operator Overload >> (input, book):
Read input for all members.
Ignore newline.
Return input.

Friend Operator Overload << (output, book):
Print all members to output.
Return output.

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

        Book& operator=(const Book& otherBook);
        operator int() const;
        bool operator==(const Book& otherBook) const;

        friend istream& operator >> (istream& input, Book& book);
        friend ostream& operator << (ostream& output, const Book& book);

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

Book& Book::operator=(const Book& otherBook) {
    
    if (this != &otherBook)
    {
        ISBN = otherBook.ISBN;
        title = otherBook.title;
        author = otherBook.author;
        publisher = otherBook.publisher;
        date = otherBook.date;
        quantity = otherBook.quantity;
        wholesaleCost = otherBook.wholesaleCost;
        retailPrice = otherBook.retailPrice;        
    }

    return *this;
}

Book::operator int() const {

    return stoi(ISBN);
}

bool Book::operator==(const Book& otherBook) const {
    
    return (ISBN == otherBook.ISBN &&
            title == otherBook.title &&
            author == otherBook.author &&
            publisher == otherBook.publisher &&
            date == otherBook.date &&
            quantity == otherBook.quantity &&
            wholesaleCost == otherBook.wholesaleCost &&
            retailPrice == otherBook.retailPrice);
}

ostream& operator << (ostream& output, const Book& book)
{
    output << "ISBN: " << book.ISBN << endl;
    output << "Title: " << book.title << endl;
    output << "Author: " << book.author << endl;
    output << "Publisher: " << book.publisher << endl;
    output << "Date: " << book.date << endl;
    output << "Quantity: " << book.quantity << endl;
    output << "Wholesale Cost: " << book.wholesaleCost << endl;
    output << "Retail Price: " << book.retailPrice << endl;
    output << endl;
    return output;
}

istream& operator >> (istream& input, Book& book)
{
    getline(input, book.ISBN);
    getline(input, book.title);
    getline(input, book.author);
    getline(input, book.publisher);
    getline(input, book.date);
    getline(input, book.quantity);
    getline(input, book.wholesaleCost);
    getline(input, book.retailPrice);
    input.ignore();
    return input;
}


Book::~Book()
{
    
}
