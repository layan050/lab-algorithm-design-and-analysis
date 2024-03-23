#include <iostream>
using namespace std;

class student {
private:
    string studentname;
    int studentNPM;
public:
    void setstudentname(string n) {
        studentname = n;
    }
    void setstudentNPM(int p) {
        studentNPM = p;
    }
    string getstudentname() {
        return studentname;
    }
    int getstudentNPM() {
        return studentNPM;
    }
};

int main() {
    string name;
    int number;
    student students[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nENTER STUDENT " << i + 1 << " NAME: ";
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, name);
        students[i].setstudentname(name);

        cout << "\nENTER STUDENT " << i + 1 << " NPM: ";
        cin >> number;
        students[i].setstudentNPM(number);
    }

    cout << "\nSTUDENT DATA: \n";
    for (int i = 0; i < 5; i++) {
    	cout<<"\nstudent "<<i+1;
        cout << "\nstudent name: " << students[i].getstudentname() << endl;
        cout << "student NPM:  " << students[i].getstudentNPM() << endl;
    }

    return 0;
}

