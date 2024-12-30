#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isBorrowed; // true if the book is borrowed, false if available
};

int main() {
    vector<Book> library;  // Vector to store the books
    int numBooks = 0; // Counter for the number of books in the library
    int choice;

    while(true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a book\n";
        cout << "2. Display all books\n";
        cout << "3. Borrow a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Add a book
            Book newBook;
            cout << "Enter book title: ";
            cin.ignore(); // to ignore the newline character left in the buffer
            getline(cin, newBook.title);
            cout << "Enter book author: ";
            getline(cin, newBook.author);
            cout << "Enter book ISBN: ";
            getline(cin, newBook.ISBN);
            newBook.isBorrowed = false;  // By default, a new book is available
            library.push_back(newBook);
            numBooks++;
            cout << "Book added successfully!\n";
        }
        else if (choice == 2) {
            // Display all books
            if (numBooks == 0) {
                cout << "No books available in the library.\n";
            } else {
                cout << "\nBooks in the Library:\n";
                for (int i = 0; i < numBooks; i++) {
                    cout << i + 1 << ". " << library[i].title << " by " << library[i].author;
                    cout << " (ISBN: " << library[i].ISBN << ")";
                    if (library[i].isBorrowed) {
                        cout << " - Borrowed\n";
                    } else {
                        cout << " - Available\n";
                    }
                }
            }
        }
        else if (choice == 3) {
            // Borrow a book
            cout << "Enter the number of the book you want to borrow: ";
            int bookChoice;
            cin >> bookChoice;
            if (bookChoice >= 1 && bookChoice <= numBooks) {
                if (!library[bookChoice - 1].isBorrowed) {
                    library[bookChoice - 1].isBorrowed = true;  // Mark as borrowed
                    cout << "You have successfully borrowed: " << library[bookChoice - 1].title << endl;
                } else {
                    cout << "Sorry, the book is already borrowed.\n";
                }
            } else {
                cout << "Invalid choice.\n";
            }
        }
        else if (choice == 4) {
            // Return a book
            cout << "Enter the number of the book you want to return: ";
            int returnChoice;
            cin >> returnChoice;
            if (returnChoice >= 1 && returnChoice <= numBooks) {
                if (library[returnChoice - 1].isBorrowed) {
                    library[returnChoice - 1].isBorrowed = false;  // Mark as available
                    cout << "You have successfully returned: " << library[returnChoice - 1].title << endl;
                } else {
                    cout << "This book was not borrowed.\n";
                }
            } else {
                cout << "Invalid choice.\n";
            }
        }
        else if (choice == 5) {
            // Exit the program
            cout << "Exiting the system. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
