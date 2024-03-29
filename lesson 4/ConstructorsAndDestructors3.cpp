#include <iostream>
#include <string>
using namespace std;

class student {
public:
    student(string name, int age) : name_(name), age_(age) {
        cout << "\tStudent Constructor" << endl;
    }

    ~student() {
        cout << "\t==Student Destructor Example==" << endl;
    }

    void ShowBiodata() {
        cout << "Name: " << name_ << endl;
        cout << "Age: " << age_ << endl;
    }

private:
    string name_;
    int age_;
};

int main() {
    student mhs("Katarina", 20);
    mhs.ShowBiodata();
    return 0;
}


