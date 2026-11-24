#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Each node stores one student's information.
class StudentNode {
public:
    string name;
    int rollNo;
    int marks;
    StudentNode* left;
    StudentNode* right;

    StudentNode(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = NULL;
        right = NULL;
    }
};

class StudentMaxHeap {
private:
    StudentNode* root;
    int size;

    // Find a node by its position in the complete binary tree.
    StudentNode* getNode(int index) {
        if (root == NULL) return NULL;
        StudentNode* current = root;
        int path[32], length = 0;
        while (index > 1) {
            path[length++] = index % 2;
            index = index / 2;
        }
        for (int i = length - 1; i >= 0; i--) {
            if (path[i] == 0) current = current->left;
            else current = current->right;
        }
        return current;
    }

    void swapStudent(StudentNode* a, StudentNode* b) {
        string tempName = a->name;
        int tempRoll = a->rollNo, tempMarks = a->marks;
        a->name = b->name; a->rollNo = b->rollNo; a->marks = b->marks;
        b->name = tempName; b->rollNo = tempRoll; b->marks = tempMarks;
    }

    void heapifyUp(int index) {
        while (index > 1) {
            StudentNode* child = getNode(index);
            StudentNode* parent = getNode(index / 2);
            if (child->marks > parent->marks) {
                swapStudent(child, parent);
                index = index / 2;
            } else break;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            StudentNode* current = getNode(index);
            StudentNode* leftChild = getNode(index * 2);
            StudentNode* rightChild = getNode(index * 2 + 1);
            if (leftChild != NULL && leftChild->marks > getNode(largest)->marks)
                largest = index * 2;
            if (rightChild != NULL && rightChild->marks > getNode(largest)->marks)
                largest = index * 2 + 1;
            if (largest == index) break;
            swapStudent(current, getNode(largest));
            index = largest;
        }
    }

public:
    StudentMaxHeap() { root = NULL; size = 0; }

    void insert(string name, int roll, int marks) {
        StudentNode* newNode = new StudentNode(name, roll, marks);
        size++;
        if (size == 1) root = newNode;
        else {
            StudentNode* parent = getNode(size / 2);
            if (size % 2 == 0) parent->left = newNode;
            else parent->right = newNode;
        }
        heapifyUp(size); // Move the new student up if needed.
    }

    void display() {
        if (root == NULL) { cout << "Heap is empty.\n"; return; }
        queue<StudentNode*> q;
        q.push(root);
        while (!q.empty()) {
            StudentNode* current = q.front(); q.pop();
            cout << current->name << " (Roll " << current->rollNo
                 << ", Marks " << current->marks << ")\n";
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
    }

    void deleteHighest() {
        if (root == NULL) return;
        cout << "Deleted highest: " << root->name << " with " << root->marks << " marks\n";
        if (size == 1) { delete root; root = NULL; size = 0; return; }
        StudentNode* last = getNode(size);
        root->name = last->name; root->rollNo = last->rollNo; root->marks = last->marks;
        StudentNode* parent = getNode(size / 2);
        if (size % 2 == 0) parent->left = NULL;
        else parent->right = NULL;
        delete last;
        size--;
        heapifyDown(1); // Restore the Max Heap after deletion.
    }
};

int main() {
    StudentMaxHeap students;
    students.insert("Ayan", 101, 88);
    students.insert("Sara", 102, 95);
    students.insert("Ali", 103, 79);
    students.insert("Hina", 104, 91);
    students.insert("Usman", 105, 84);
    students.insert("Zara", 106, 97);

    cout << "Student Max Heap (Level Order):\n";
    students.display();
    cout << "\nAfter deleting the student with highest marks:\n";
    students.deleteHighest();
    students.display();
    return 0;
}
