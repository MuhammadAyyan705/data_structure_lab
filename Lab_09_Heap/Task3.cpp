#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class OrderNode {
public:
    int orderID;
    string customer;
    int amount;
    OrderNode* left;
    OrderNode* right;
    OrderNode(int id, string name, int value) {
        orderID = id; customer = name; amount = value;
        left = NULL; right = NULL;
    }
};

class OrderMaxHeap {
private:
    OrderNode* root;
    int size;

    OrderNode* getNode(int index) {
        if (root == NULL) return NULL;
        OrderNode* current = root;
        int path[32], length = 0;
        while (index > 1) { path[length++] = index % 2; index /= 2; }
        for (int i = length - 1; i >= 0; i--) {
            if (path[i] == 0) current = current->left;
            else current = current->right;
        }
        return current;
    }

    void swapOrder(OrderNode* a, OrderNode* b) {
        int id = a->orderID, amount = a->amount;
        string name = a->customer;
        a->orderID = b->orderID; a->customer = b->customer; a->amount = b->amount;
        b->orderID = id; b->customer = name; b->amount = amount;
    }

    void heapifyUp(int index) {
        while (index > 1) {
            OrderNode* child = getNode(index);
            OrderNode* parent = getNode(index / 2);
            if (child->amount > parent->amount) { swapOrder(child, parent); index /= 2; }
            else break;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            OrderNode* current = getNode(index);
            OrderNode* left = getNode(index * 2);
            OrderNode* right = getNode(index * 2 + 1);
            if (left != NULL && left->amount > getNode(largest)->amount) largest = index * 2;
            if (right != NULL && right->amount > getNode(largest)->amount) largest = index * 2 + 1;
            if (largest == index) break;
            swapOrder(current, getNode(largest)); index = largest;
        }
    }

public:
    OrderMaxHeap() { root = NULL; size = 0; }

    void insert(int id, string customer, int amount) {
        OrderNode* node = new OrderNode(id, customer, amount);
        size++;
        if (size == 1) root = node;
        else {
            OrderNode* parent = getNode(size / 2);
            if (size % 2 == 0) parent->left = node; else parent->right = node;
        }
        heapifyUp(size);
    }

    void display() {
        queue<OrderNode*> q;
        if (root == NULL) return;
        q.push(root);
        while (!q.empty()) {
            OrderNode* o = q.front(); q.pop();
            cout << "Order " << o->orderID << " - " << o->customer << " - Rs. " << o->amount << "\n";
            if (o->left != NULL) q.push(o->left);
            if (o->right != NULL) q.push(o->right);
        }
    }

    // Remove and return the largest order amount (root of Max Heap).
    int deleteMaximum() {
        if (root == NULL) return -1;
        int deletedAmount = root->amount;
        if (size == 1) { delete root; root = NULL; size = 0; return deletedAmount; }
        OrderNode* last = getNode(size);
        root->orderID = last->orderID; root->customer = last->customer; root->amount = last->amount;
        OrderNode* parent = getNode(size / 2);
        if (size % 2 == 0) parent->left = NULL; else parent->right = NULL;
        delete last; size--;
        heapifyDown(1);
        return deletedAmount;
    }
};

int main() {
    OrderMaxHeap orders;
    orders.insert(1, "Ayan", 2500);
    orders.insert(2, "Sara", 1200);
    orders.insert(3, "Ali", 4500);
    orders.insert(4, "Hina", 1800);
    orders.insert(5, "Usman", 3200);
    orders.insert(6, "Zara", 900);

    cout << "Orders in Max Heap (Level Order):\n";
    orders.display();

    // Repeatedly delete the maximum and save each amount.
    vector<int> deletedAmounts;
    while (true) {
        int amount = orders.deleteMaximum();
        if (amount == -1) break;
        deletedAmounts.push_back(amount);
    }

    // Max Heap gives descending order, so reverse it for ascending order.
    reverse(deletedAmounts.begin(), deletedAmounts.end());
    cout << "\nOrder amounts in ascending order (Heap Sort):\n";
    for (int i = 0; i < deletedAmounts.size(); i++)
        cout << deletedAmounts[i] << " ";
    cout << endl;
    return 0;
}
