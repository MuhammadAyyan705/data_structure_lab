#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == MAX - 1) {
            cout << "Queue is full! " << token << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = token;
        cout << " token " << token << " arrived.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Customer token " << arr[front] << " served.\n";
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No waiting customers.\n";
            return;
        }
        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void displayCount() {
        if (front == -1) {
            cout << "Total waiting customers: 0\n";
        } else {
            cout << "Total waiting customers: " << (rear - front + 1) << endl;
        }
    }
};

int main() {
    Queue b;

    b.enqueue(101);
    b.enqueue(102);
    b.enqueue(103);

    cout << endl;
    b.display();
    b.displayCount();

    cout << endl;
    b.dequeue();

    cout << endl;
    b.display();
    b.displayCount();

    return 0;
}