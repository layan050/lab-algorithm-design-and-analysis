#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (rear == NULL) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty..." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    int frontElement() {
        if (front == NULL) {
            cout << "Queue is empty...." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return (front == NULL);
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(9);

    cout << "Front element is: " << q.frontElement() << endl;
    q.dequeue();
    cout << "Front element is: " << q.frontElement() << endl;
    q.dequeue();

    return 0;
}

