#include <iostream>
using namespace std;

const int MAX = 20;

class queue {
private:
    int front;
    int rear;
    int arr[MAX];
public:
    queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int data) {
        if ((rear + 1) % MAX == front) {
            cout << "queue is full...." << endl;
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
            cout << "queue is empty..." << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    int frontElement() {
        if (front == -1) {
            cout << "queue is empty...." << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main() {
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "front element is : " << q.frontElement() << endl;
    q.dequeue();
    cout << "front element is : " << q.frontElement() << endl;
    q.dequeue();
    return 0;
}

