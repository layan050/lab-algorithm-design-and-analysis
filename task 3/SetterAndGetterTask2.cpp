#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool borrowed;

public:
    void setTitle(string t) {
        title = t;
    }

    void setAuthor(string a) {
        author = a;
    }

    void setBorrowed(bool b) {
        borrowed = b;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string isBorrowed() const {
        return borrowed ? "yes":"no";
    }
};

int main() {
    Book book;

    string title, author, borrowed;

    cout << "Enter the title of the book: ";
    getline(cin, title);
    book.setTitle(title);

    cout << "Enter the author of the book: ";
    getline(cin, author);
    book.setAuthor(author);

    cout << "Is the book borrowed? (Yes,No): ";
    cin >> borrowed;
    book.setBorrowed(borrowed == "yes");

    cout << "\nBook Information:\n";
    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "Borrowed: " << (book.isBorrowed()) << endl;

    return 0;
}



