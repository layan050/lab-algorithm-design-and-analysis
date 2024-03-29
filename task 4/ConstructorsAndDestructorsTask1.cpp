#include <iostream>
using namespace std;


class example {
    private:
        int score; // Private member variable to store a score

    public:
        // Constructor of the class "example" which takes an integer as input
        example(int n) {
            score = n; // Assigning the input integer to the score member variable
        }

        // Member function to get the score
        int getNum() {
            return score; // Returning the score
        }
};

int main() {
    // Creating an object of class "example" with initial score 10
    example obj(10);
    
    // Displaying the score using the getNum() member function
    cout << "Input Score: " << obj.getNum() << endl;
    
    return 0; 
}

