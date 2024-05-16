#include <iostream>
using namespace std;

const int MAX = 20;

class Queue {
private:
    int front;
    int rear;
    int arr[MAX];
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int data) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue is full...." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = data;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty..." << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty...." << endl;
            return;
        }
        cout << "Participant numbers in the queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << arr[rear] << endl;
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main() {
    Queue q;
    int choice, num;

    cout << "1. Enter participant number into the queue.\n2. Remove the last participant number from the queue.\n3. Display all participant numbers in the queue.\n4. Exit the queue program." << endl;

    do {
        cout << "\nInput choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter participant number: ";
                cin >> num;
                q.enqueue(num);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Thank You...." << endl;
                break;
            default:
                cout << "INVALID CHOICE..\nPlease try again... " << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

