#include <iostream>
using namespace std;

#define MAX 5

class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    void insertRear(int val) {
        if (rear == MAX - 1) {
            cout << "Deque is full at Rear!\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
        cout << val << " inserted at Rear.\n";
    }

    void insertFront(int val) {
        if (front == 0) {
            cout << "Cannot insert at Front (Space full at start)!\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            front--;
        }
        arr[front] = val;
        cout << val << " inserted at Front.\n";
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Deque is empty!\n";
            return;
        }
        cout << arr[front] << " removed from Front.\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (front == -1) {
            cout << "Deque is empty!\n";
            return;
        }
        cout << arr[rear] << " removed from Rear.\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty!\n";
            return;
        }
        cout << "Front -> ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "<- Rear" << endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(301);
    dq.insertRear(302);

    
    dq.deleteFront(); 
    dq.insertRear(301);
    dq.insertFront(300); 

    cout << endl;
    dq.display(); 

    return 0;
}