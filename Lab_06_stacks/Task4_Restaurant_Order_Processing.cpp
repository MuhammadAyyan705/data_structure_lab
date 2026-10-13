#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    struct Node {
        string id;
        Node* next;
        Node(string value) : id(value), next(nullptr) {}
    };
    Node* top;
public:
    Stack() { top = nullptr; }

    void push(string id) {
        Node* node = new Node(id);
        node->next = top;
        top = node;
    }

    void pop() {
        if (top == nullptr) {
            cout << "No orders to process.\n";
            return;
        }
        Node* temp = top;
        cout << "Processed order: " << temp->id << "\n";
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "No orders.\n";
            return;
        }
        for (Node* current = top; current != nullptr; current = current->next)
            cout << current->id << "\n";
    }

    void showTop() {
        if (top == nullptr) cout << "No current order.\n";
        else cout << top->id << "\n";
    }

    bool isEmpty() { return top == nullptr; }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack orders;
    orders.push("ORD-101");
    orders.push("ORD-102");
    orders.push("ORD-103");
    orders.push("ORD-104");

    cout << "Orders (TOP to bottom):\n";
    orders.display();
    orders.pop();
    orders.pop();
    cout << "Current TOP order: ";
    orders.showTop();
    cout << "Remaining orders:\n";
    orders.display();
    cout << "Is stack empty? " << (orders.isEmpty() ? "Yes" : "No") << "\n";
    return 0;
}