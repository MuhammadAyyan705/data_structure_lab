#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string actions[10];
    int top;
public:
    Stack() { top = -1; }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is full.\n";
            return;
        }
        actions[++top] = action;
    }

    void pop() {
        if (top == -1) {
            cout << "Nothing to undo.\n";
            return;
        }
        cout << "Undo action: " << actions[top--] << "\n";
    }

    void display() {
        if (top == -1) {
            cout << "No actions.\n";
            return;
        }
        for (int i = top; i >= 0; --i)
            cout << actions[i] << "\n";
    }

    void showTop() {
        if (top == -1) cout << "No current action.\n";
        else cout << actions[top] << "\n";
    }
};

int main() {
    Stack editor;
    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");

    cout << "Actions (TOP to bottom):\n";
    editor.display();
    editor.pop();
    editor.pop();
    cout << "Current TOP action: ";
    editor.showTop();
    cout << "Remaining actions:\n";
    editor.display();
    return 0;
}