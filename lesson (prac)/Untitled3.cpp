#include <iostream>
#include <string> 
using namespace std;

class math {
private:
    int num[2], multiply, plus, minus;
    float divide;
public:
    void setmath(int n1, int n2) {
        num[0] = n1;
        num[1] = n2;
    }
    int getmulti() {
        multiply = num[0] * num[1];
        return multiply;
    }
    int getplus() {
        plus = num[0] + num[1];
        return plus;
    }
    int getminus() {
        minus = num[0] - num[1];
        return minus;
    }
    bool getdivide() {
        if (num[1] != 0) {
            divide = static_cast<float>(num[0]) / num[1];
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    math MyMath;
    int num1, num2;
    char again = 'y';

    while (again == 'y') {
        cout << "Enter number one : ";
        cin >> num1;
        cout<<"Enter number two: ";
        cin>>num2;

        MyMath.setmath(num1, num2);

        cout << "\nPlus: " << MyMath.getplus() << endl;
        cout << "Minus: " << MyMath.getminus() << endl;
        cout << "Multiply: " << MyMath.getmulti() << endl;
        if (MyMath.getdivide()) {
            cout << "Divide: " << MyMath.getdivide() << endl;
        } else {
            cout << "Division by zero is not possible." << endl;
        }

        cout << "\nagain? y / n : ";
        cin >> again;
    }

    return 0;
} 
