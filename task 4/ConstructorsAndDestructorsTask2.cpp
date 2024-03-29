#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string name;
    int number;

public:
    Contact() {
        name = " ";
        number = 0;
    }
    
 
    void setContact(string a, int u) {
        name = a;
        number = u;
    }
    
    void display() {
        cout << "\nContact Name: " << name;
        cout << "\nContact Phone Number: " << number;
        cout << "\nContact Added Successfully.\n";
    }
};

int main() {
    char add = 'y'; 
    string name;
    int number;
    Contact contacts[100]; 
    
    int count = 0; 
    
    while (add == 'y') {
        cout << "\nEnter Contact Name: ";
        getline(cin, name); 
        cout << "Enter Contact Phone Number: ";
        cin >> number;
        cin.ignore();
        
        contacts[count].setContact(name, number); 
    
        
        count++; 
        
        cout << "\nDo you want to add another contact? (y/n): ";
        cin >> add;
        cin.ignore();
    }

    
    for (int i = 0; i < count; i++) {
    	cout<<"\nContact"<<i<<endl;
        contacts[i].display();
    }

    return 0;
}

