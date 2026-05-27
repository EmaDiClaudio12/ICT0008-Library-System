#include "Book.h"

Book::Book() {
    title = "";
    author = "";
    isbn = "";
    available = true;
}

void Book::setBookDetails(const std::string& t, const std::string& a, const std::string& i, bool avail) {
    title = t;
    author = a;
    isbn = i;
    available = avail;
}

void Book::displayBookDetails() const {
    std::cout << "title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "ISBN: " << isbn << "\n";
    std::cout << "Available: " << (available ? "Yes" : "No") << "\n";
}

bool Book::isAvailable() const {
    return available;
}

std::string Book::getISBN() const {
    return isbn;
}

void Book::borrowBook() {
    if (available) {
        available = false;
        std::cout << "Book borrowed successfully.\n";
    }
    else {
        std::cout << "Book is already borrowed.\n";
    }
}

void Book::returnBook() {
    available = true;
}
