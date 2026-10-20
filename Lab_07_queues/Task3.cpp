#include <iostream>
using namespace std;

#define MAX 5

struct Patient {
    int id;
    int priority; // 1 = Highest Urgency
};

class PriorityQueue {
private:
    Patient arr[MAX];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void enqueue(int id, int priority) {
        if (count == MAX) {
            cout << "Queue is full! Cannot add patient " << id << endl;
            return;
        }
        arr[count].id = id;
        arr[count].priority = priority;
        count++;
        cout << "Patient P" << id << " with Priority " << priority << " added.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty! No patients to treat.\n";
            return;
        }

        // Highest priority (smallest priority number) wala patient dhoondhna
        int highestPriorityIdx = 0;
        for (int i = 1; i < count; i++) {
            if (arr[i].priority < arr[highestPriorityIdx].priority) {
                highestPriorityIdx = i;
            }
        }

        cout << "Treating Patient P" << arr[highestPriorityIdx].id 
             << " (Priority " << arr[highestPriorityIdx].priority << ")\n";

        // Array Shift karna
        for (int i = highestPriorityIdx; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "Waiting Patients:\n";
        for (int i = 0; i < count; i++) {
            cout << "Patient ID: P" << arr[i].id << " | Priority: " << arr[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue hospital;

    hospital.enqueue(101, 3);
    hospital.enqueue(102, 1); // High priority
    hospital.enqueue(103, 2);

    cout << endl;
    hospital.display();

    cout << endl;
    hospital.dequeue(); // Patient P102 pehle treat hoga

    cout << endl;
    hospital.display();

    return 0;
}