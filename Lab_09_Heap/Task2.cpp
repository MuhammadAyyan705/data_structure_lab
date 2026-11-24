#include <iostream>
#include <queue>
#include <string>
using namespace std;

class PatientNode {
public:
    string name;
    int patientID;
    int priority;
    PatientNode* left;
    PatientNode* right;

    PatientNode(string n, int id, int p) {
        name = n; patientID = id; priority = p;
        left = NULL; right = NULL;
    }
};

class PatientMaxHeap {
private:
    PatientNode* root;
    int size;

    PatientNode* getNode(int index) {
        if (root == NULL) return NULL;
        PatientNode* current = root;
        int path[32], length = 0;
        while (index > 1) { path[length++] = index % 2; index /= 2; }
        for (int i = length - 1; i >= 0; i--) {
            if (path[i] == 0) current = current->left;
            else current = current->right;
        }
        return current;
    }

    void swapPatient(PatientNode* a, PatientNode* b) {
        string name = a->name; int id = a->patientID, p = a->priority;
        a->name = b->name; a->patientID = b->patientID; a->priority = b->priority;
        b->name = name; b->patientID = id; b->priority = p;
    }

    void heapifyUp(int index) {
        while (index > 1) {
            PatientNode* child = getNode(index);
            PatientNode* parent = getNode(index / 2);
            if (child->priority > parent->priority) {
                swapPatient(child, parent); index /= 2;
            } else break;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            PatientNode* current = getNode(index);
            PatientNode* left = getNode(index * 2);
            PatientNode* right = getNode(index * 2 + 1);
            if (left != NULL && left->priority > getNode(largest)->priority) largest = index * 2;
            if (right != NULL && right->priority > getNode(largest)->priority) largest = index * 2 + 1;
            if (largest == index) break;
            swapPatient(current, getNode(largest)); index = largest;
        }
    }

public:
    PatientMaxHeap() { root = NULL; size = 0; }

    void insert(string name, int id, int priority) {
        PatientNode* node = new PatientNode(name, id, priority);
        size++;
        if (size == 1) root = node;
        else {
            PatientNode* parent = getNode(size / 2);
            if (size % 2 == 0) parent->left = node;
            else parent->right = node;
        }
        heapifyUp(size);
    }

    void display() {
        queue<PatientNode*> q;
        if (root == NULL) { cout << "No patients.\n"; return; }
        q.push(root);
        while (!q.empty()) {
            PatientNode* p = q.front(); q.pop();
            cout << p->name << " (ID " << p->patientID << ", Priority " << p->priority << ")\n";
            if (p->left != NULL) q.push(p->left);
            if (p->right != NULL) q.push(p->right);
        }
    }

    void treatHighestPriority() {
        if (root == NULL) return;
        cout << "Patient treated: " << root->name << " (Priority " << root->priority << ")\n";
        if (size == 1) { delete root; root = NULL; size = 0; return; }
        PatientNode* last = getNode(size);
        root->name = last->name; root->patientID = last->patientID; root->priority = last->priority;
        PatientNode* parent = getNode(size / 2);
        if (size % 2 == 0) parent->left = NULL; else parent->right = NULL;
        delete last; size--;
        heapifyDown(1);
    }
};

int main() {
    PatientMaxHeap hospital;
    hospital.insert("Ahmed", 201, 3);
    hospital.insert("Bilal", 202, 5);
    hospital.insert("Noor", 203, 2);
    hospital.insert("Fatima", 204, 4);
    hospital.insert("Hamza", 205, 1);
    hospital.insert("Mariam", 206, 5);

    cout << "All Patients (Level Order):\n";
    hospital.display();
    cout << "\nHighest priority patient: " << "\n";
    hospital.treatHighestPriority();
    cout << "\nNext patient after Heapify Down:\n";
    hospital.display();
    return 0;
}
