#include <iostream>
using namespace std;

class Book {
private:
    string bookName;
    string writer;
    int year;

public:
    Book() { // Constructor
        bookName = "-";
        writer = "-";
        year = 0;
    }

    void set(string a, string b, int c) {
        bookName = a;
        writer = b;
        year = c;
    }

    void display() {
        cout << "\nBook information\n" << endl;
        cout << "Title : " << bookName << endl;
        cout << "Writer: " << writer << endl;
        cout << "Published Year: " << year << endl;
    }
};

int main() {
    int n;
    cout << "How many books will you add? ";
    cin >> n;
    cin.ignore(); // Clear input buffer

    Book books[n]; // Array of Book objects

    for (int i = 0; i < n; i++) {
        string title;
        string writer;
        int year;
        cout << "\nEnter Book Title: ";
        getline(cin, title);
        cout << "Enter Writer Name: ";
        getline(cin , writer);
        cout << "Enter Published Year: ";
        cin >> year;
        cin.ignore(); // Clear input buffer

        books[i].set(title, writer, year);
    }

    // Display all the books
    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i+1 << ":\n";
        books[i].display();
    }

    return 0;
}

