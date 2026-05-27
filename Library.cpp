#include "Library.h"

void Library::initSampleBooks() {
    books[0].setBookDetails("Cien anos de soledad", "Gabriel Garcia Marquez", "978-0307474728", true);
    books[1].setBookDetails("El principito", "Antoine de Saint-Exupery", "978-0156012195", true);
    books[2].setBookDetails("1984", "George Orwell", "978-0451524935", false);
    books[3].setBookDetails("Don Quijote de la Mancha", "Miguel de Cervantes", "978-8491050295", true);
    books[4].setBookDetails("Rayuela", "Julio Cortazar", "978-8437604183", true);
}

void Library::displayAllBooks() const {
    std::cout << "=== Book List ===\n";
    for (int i = 0; i < 5; ++i) {
        books[i].displayBookDetails();
        std::cout << '\n';
    }
}

void Library::borrowByISBN(const std::string& isbn) {
    for (int i = 0; i < 5; ++i) {
        if (books[i].getISBN() == isbn) {
            if (books[i].isAvailable()) {
                books[i].borrowBook();
            }
            else {
                std::cout << "Book with ISBN " << isbn << " is not available.\n";
            }
            return;
        }
    }
    std::cout << "Error: ISBN " << isbn << " not found.\n";
}
