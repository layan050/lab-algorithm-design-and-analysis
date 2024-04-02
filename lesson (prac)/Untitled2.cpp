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

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    math MyMath;
    int num[2];
    char again = 'y';
    string chosen;

    while (again == 'y') {
        cout << "Enter two numbers : ";
        cin >> num[0] >> num[1];

        quickSort(num, 0, 1);

        MyMath.setmath(num[0], num[1]);
        cout << "choose (+) plus , (-) minus , (x) multiply , (/)divide : ";
        cin >> chosen;

        if (chosen == "+") {
            cout << "\nPlus: " << MyMath.getplus() << endl;
        } 
		else if (chosen == "-") {
            cout << "Minus : " << MyMath.getminus() << endl;    
        } 
		else if (chosen == "x") {
            cout << "Multiply: " << MyMath.getmulti() << endl;            
        } 
		else if (chosen == "/") {
            if (MyMath.getdivide()) {
                cout << "Divide: " << MyMath.getdivide() << endl;
            } else {
                cout << "Division by zero is not possible." << endl;
            }
        } else {
            cout << "\nAnswer Not Available\n";
        }

        cout << "\nagain? y / n: ";
        cin >> again;
    }

    return 0;
}


