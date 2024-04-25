#include <iostream>
#include <string>
using namespace std;

class book {
public:
    string title;
    int number;
    
    book(string t, int n) {
        title = t;
        number = n;
    }
};

bool compare(const book* book1, const book* book2) {
    return book1->title < book2->title;
}

int search(const book* books, int size, const string& title) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (books[mid].title == title) {
            return books[mid].number;
        } else if (books[mid].title < title) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    book library[] = {
        {"cat diary", 1},
        {"awesome person", 2},
        {"happy mode", 3},
        {"sad days", 4},
        {"travel history", 5},
    };
    int size = sizeof(library) / sizeof(library[0]);
    string searchT;
    cout << "Enter The Book Title You Want To Search For: ";
    getline(cin, searchT);
    int number = search(library, size, searchT);
    if (number != -1) {
        cout << "\nThe Book \"" << searchT << "\" is Located On Shelf Number " << number << endl;
    } else {
        cout << "\nSORRY, The Book \"" << searchT << "\" Was Not Found In The Library" << endl;
    }
    return 0;
}


