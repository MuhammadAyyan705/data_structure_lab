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
            cout << "No requests to handle.\n";
            return;
        }
        Node* temp = top;
        cout << "Handled request: " << temp->id << "\n";
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "No requests.\n";
            return;
        }
        for (Node* current = top; current != nullptr; current = current->next)
            cout << current->id << "\n";
    }

    void showTop() {
        if (top == nullptr) cout << "No current request.\n";
        else cout << top->id << "\n";
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack requests;
    requests.push("P101");
    requests.push("P102");
    requests.push("P103");
    requests.push("P104");

    cout << "Emergency requests (TOP to bottom):\n";
    requests.display();
    requests.pop();
    cout << "New TOP request: ";
    requests.showTop();
    cout << "Remaining requests:\n";
    requests.display();
    return 0;
}