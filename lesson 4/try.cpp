
#include <iostream>
#include <string>
using namespace std;

class data {
private:
    string name;
    string address;
    int age;
public:
    // Constructor definition
    data(string var1, int var2, string var3) {
        name = var1;
        age = var2;
        address = var3;
        cout << "Name: " << name << "\nAge: " << age << "\nAddress: " << address << endl;
    }
};

int main() {
    string name;
    int age;
    string address;
    
    cout << "ENTER YOUR DATA\t\n";
    cout << "Enter Your Name: ";
    getline(cin , name);
    cout << "Enter Your Age: ";
    cin >> age;
    cout << "Enter Your Address: ";
    cin.ignore();				//to use getline more than one time
    getline(cin , address);
	cout<<"\n\n";
    // Creating an object of the 'data' class by calling its constructor
    data datasome(name, age, address);

    return 0;
}


