#include <iostream>
using namespace std;

class shape {
public:
    virtual float area() = 0;
};

class rectangle : public shape {
private:
    float length, width;

public:
    rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float area() {
        return length * width;
    }
};

class triangle : public shape {
private:
    float base, height;

public:
    triangle(float b, float h) {
        base = b;
        height = h;
    }

    float area() {
        return 0.5 * base * height;
    }
};

int main() {

    float length, width, base, height;

    cout << "Enter the length of the rectangle : ";
    cin >> length;
    cout<<"width of the rectangle : ";
	cin>>width;
	shape* shape1 = new rectangle(length, width);
	
    cout << "Enter the base of a triangle : ";
    cin >> base;
    cout<<"Enter  height of the triangle: ";
    cin>>height;
    shape* shape2 = new triangle(base, height);

cout<<"\nArea Calculation \n";
    cout << "\nArea of the rectangle: " << shape1->area() << endl;
    cout << "Area of the triangle: " << shape2->area() << endl;

    delete shape1;
    delete shape2;

    return 0;
}

