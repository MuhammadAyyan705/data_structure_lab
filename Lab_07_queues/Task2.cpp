#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int packetID) {
        if ((rear + 1) % MAX == front) {
            cout << "Buffer is full! Packet " << packetID << " dropped.\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = packetID;
        cout << "Packet " << packetID << " inserted in buffer.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Buffer is empty! No packet to transmit.\n";
            return;
        }
        cout << "Transmitting packet: " << arr[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Buffer is empty.\n";
            return;
        }
        cout << "Packets waiting for transmission: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue netQueue;

    netQueue.enqueue(201);
    netQueue.enqueue(202);
    netQueue.enqueue(203);

    cout << endl;
    netQueue.display();

    cout << endl;
    netQueue.dequeue();

    cout << endl;
    netQueue.display();

    // Reusing empty space
    cout << endl;
    netQueue.enqueue(204);
    netQueue.display();

    return 0;
}