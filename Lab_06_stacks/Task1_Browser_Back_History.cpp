#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string pages[10];
    int top;
public:
    Stack() { top = -1; }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is full.\n";
            return;
        }
        pages[++top] = page;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Back button removed: " << pages[top--] << "\n";
    }

    void display() {
        if (top == -1) {
            cout << "No pages in history.\n";
            return;
        }
        for (int i = top; i >= 0; --i)
            cout << pages[i] << "\n";
    }

    void showTop() {
        if (top == -1) cout << "No current page.\n";
        else cout << pages[top] << "\n";
    }
};

int main() {
    Stack history;
    history.push("Google");
    history.push("YouTube");
    history.push("Facebook");
    history.push("GitHub");

    cout << "Browser history (TOP to bottom):\n";
    history.display();
    history.pop();
    cout << "Current TOP page: ";
    history.showTop();
    cout << "Remaining browsing history:\n";
    history.display();
    return 0;
}