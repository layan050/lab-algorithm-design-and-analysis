#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual void display() const {
        cout << "..." << endl;
    }
};

class Info : public Student {
private:
    string name;
    int age;
    string major;
    string faculty;
    string status;

public:
    void display() const override {
        cout << "\nName: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Status: " << status << endl;
        cout << "Major: " << major << endl;
        cout << "Faculty: " << faculty << endl;
    }

    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Status: ";
        cin >> status;
        cout << "Enter Major: ";
        cin >> major;
        cout << "Enter Faculty: ";
        cin >> faculty;
    }
};

int main() {
    int n;
    cout << "Enter Data Amount: ";
    cin >> n;
    Info *students = new Info[n];

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        students[i].input();
    }

    cout << "\nStudent Information:" << endl;
    for (int i = 0; i < n; i++) {
        students[i].display();
    }



    return 0;
}

