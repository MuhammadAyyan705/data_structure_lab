#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MedicineNode {
public:
    string name;
    int medicineID;
    int expiryDate; // Date is stored as YYYYMMDD, for example 20271215.
    MedicineNode* left;
    MedicineNode* right;
    MedicineNode(string n, int id, int date) {
        name = n; medicineID = id; expiryDate = date;
        left = NULL; right = NULL;
    }
};

class MedicineMinHeap {
private:
    MedicineNode* root;
    int size;

    MedicineNode* getNode(int index) {
        if (root == NULL) return NULL;
        MedicineNode* current = root;
        int path[32], length = 0;
        while (index > 1) { path[length++] = index % 2; index /= 2; }
        for (int i = length - 1; i >= 0; i--) {
            if (path[i] == 0) current = current->left;
            else current = current->right;
        }
        return current;
    }

    void swapMedicine(MedicineNode* a, MedicineNode* b) {
        string name = a->name; int id = a->medicineID, date = a->expiryDate;
        a->name = b->name; a->medicineID = b->medicineID; a->expiryDate = b->expiryDate;
        b->name = name; b->medicineID = id; b->expiryDate = date;
    }

    void heapifyUp(int index) {
        while (index > 1) {
            MedicineNode* child = getNode(index);
            MedicineNode* parent = getNode(index / 2);
            if (child->expiryDate < parent->expiryDate) {
                swapMedicine(child, parent); index /= 2;
            } else break;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int smallest = index;
            MedicineNode* current = getNode(index);
            MedicineNode* left = getNode(index * 2);
            MedicineNode* right = getNode(index * 2 + 1);
            if (left != NULL && left->expiryDate < getNode(smallest)->expiryDate) smallest = index * 2;
            if (right != NULL && right->expiryDate < getNode(smallest)->expiryDate) smallest = index * 2 + 1;
            if (smallest == index) break;
            swapMedicine(current, getNode(smallest)); index = smallest;
        }
    }

public:
    MedicineMinHeap() { root = NULL; size = 0; }

    void insert(string name, int id, int date) {
        MedicineNode* node = new MedicineNode(name, id, date);
        size++;
        if (size == 1) root = node;
        else {
            MedicineNode* parent = getNode(size / 2);
            if (size % 2 == 0) parent->left = node; else parent->right = node;
        }
        heapifyUp(size);
    }

    void display() {
        queue<MedicineNode*> q;
        if (root == NULL) { cout << "No medicines.\n"; return; }
        q.push(root);
        while (!q.empty()) {
            MedicineNode* m = q.front(); q.pop();
            cout << m->name << " (ID " << m->medicineID << ", Expiry " << m->expiryDate << ")\n";
            if (m->left != NULL) q.push(m->left);
            if (m->right != NULL) q.push(m->right);
        }
    }

    void deleteNearestExpiry() {
        if (root == NULL) return;
        cout << "Medicine to check first: " << root->name
             << " (Expiry " << root->expiryDate << ")\n";
        if (size == 1) { delete root; root = NULL; size = 0; return; }
        MedicineNode* last = getNode(size);
        root->name = last->name; root->medicineID = last->medicineID; root->expiryDate = last->expiryDate;
        MedicineNode* parent = getNode(size / 2);
        if (size % 2 == 0) parent->left = NULL; else parent->right = NULL;
        delete last; size--;
        heapifyDown(1);
    }
};

int main() {
    MedicineMinHeap store;
    store.insert("Panadol", 301, 20271215);
    store.insert("Brufen", 302, 20261130);
    store.insert("Cough Syrup", 303, 20280110);
    store.insert("Vitamin C", 304, 20270520);
    store.insert("Antibiotic", 305, 20261205);
    store.insert("Eye Drops", 306, 20270301);

    cout << "Medicine Min Heap (Level Order):\n";
    store.display();
    cout << "\nDeleting medicine with nearest expiry date:\n";
    store.deleteNearestExpiry();
    cout << "\nUpdated Min Heap after Heapify Down:\n";
    store.display();
    return 0;
}
