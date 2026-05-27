#include "Library.h"
#include <iostream>
#include <string>

int main()
{
    Library library;
    library.initSampleBooks();

    std::cout << "=== Library Management System ===\n";
    std::cout << "Sample books loaded.\n\n";

    library.displayAllBooks();

    std::string isbn;
    while (true) {
        std::cout << "\nEnter ISBN to borrow (0 to exit): ";
        std::cin >> isbn;

        if (isbn == "0") {
            break;
        }

        library.borrowByISBN(isbn);
    }

    std::cout << "\nProgram finished.\n";
    return 0;
}