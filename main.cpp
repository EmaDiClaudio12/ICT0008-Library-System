// main.cpp
// Minimal Assessment 3 test application: three test books and sorting evidence.

#include "Book.h"
#include <iostream>
#include <algorithm>
#include <cstddef>

// Sort helper: ascending by ISBN using getISBN()
void sortBooks(Book arr[], std::size_t size)
{
    std::sort(arr, arr + size, [](const Book& a, const Book& b) {
        return a.getISBN() < b.getISBN();
    });
}

int main()
{
    // --- Individual test instances ---
    Book correct;
    correct.setBookDetails("Cien años de soledad", "Gabriel García Márquez", "978-0307474728", true);

    Book missingTitle;
    missingTitle.setBookDetails("", "Unknown Author", "111-1111111111", true); // missing title

    Book missingISBN;
    missingISBN.setBookDetails("Unnamed Book", "Author X", "", true); // missing ISBN

    std::cout << "=== Individual test instances ===\n\n";
    std::cout << "Correct book:\n"; correct.displayBookDetails(); std::cout << '\n';
    std::cout << "Incorrect (missing title):\n"; missingTitle.displayBookDetails(); std::cout << '\n';
    std::cout << "Incorrect (missing ISBN):\n"; missingISBN.displayBookDetails(); std::cout << "\n\n";

    // --- Three arrays of 3 books each (realistic Assessment 2 data) ---
    // Ascending array (already in ascending ISBN order)
    Book asc[3];
    asc[0].setBookDetails("El principito", "Antoine de Saint-Exupéry", "978-0156012195", true);
    asc[1].setBookDetails("Cien años de soledad", "Gabriel García Márquez", "978-0307474728", true);
    asc[2].setBookDetails("1984", "George Orwell", "978-0451524935", true);

    // Descending array (ISBN in descending order)
    Book desc[3];
    desc[0].setBookDetails("Don Quijote de la Mancha", "Miguel de Cervantes", "978-8491050295", true);
    desc[1].setBookDetails("Rayuela", "Julio Cortázar", "978-8437604183", true);
    desc[2].setBookDetails("1984", "George Orwell", "978-0451524935", true);

    // Mixed array (unordered)
    Book mixed[3];
    mixed[0].setBookDetails("Rayuela", "Julio Cortázar", "978-8437604183", true);
    mixed[1].setBookDetails("El principito", "Antoine de Saint-Exupéry", "978-0156012195", true);
    mixed[2].setBookDetails("Don Quijote de la Mancha", "Miguel de Cervantes", "978-8491050295", true);

    // Print BEFORE sorting
    std::cout << "=== Before sorting ===\n\n";
    std::cout << "-- Ascending array (initial) --\n";
    for (int i = 0; i < 3; ++i) { asc[i].displayBookDetails(); std::cout << '\n'; }

    std::cout << "-- Descending array (initial) --\n";
    for (int i = 0; i < 3; ++i) { desc[i].displayBookDetails(); std::cout << '\n'; }

    std::cout << "-- Mixed array (initial) --\n";
    for (int i = 0; i < 3; ++i) { mixed[i].displayBookDetails(); std::cout << '\n'; }

    // Sort arrays by ISBN ascending
    sortBooks(asc, 3);
    sortBooks(desc, 3);
    sortBooks(mixed, 3);

    // Print AFTER sorting
    std::cout << "=== After sorting by ISBN (ascending) ===\n\n";
    std::cout << "-- Ascending array (sorted) --\n";
    for (int i = 0; i < 3; ++i) { asc[i].displayBookDetails(); std::cout << '\n'; }

    std::cout << "-- Descending array (sorted) --\n";
    for (int i = 0; i < 3; ++i) { desc[i].displayBookDetails(); std::cout << '\n'; }

    std::cout << "-- Mixed array (sorted) --\n";
    for (int i = 0; i < 3; ++i) { mixed[i].displayBookDetails(); std::cout << '\n'; }

    return 0;
}