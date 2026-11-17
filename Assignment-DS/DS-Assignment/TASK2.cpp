#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    int id;
    string location;
    int severity;
    Node* left;
    Node* right;
    int height;

    Node(int i, string loc, int sev) {
        id = i;
        location = loc;
        severity = sev;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
public:
    int height(Node* N) {
        if (!N) return 0;
        return N->height;
    }

    int getBalance(Node* N) {
        if (!N) return 0;
        return height(N->left) - height(N->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* insert(Node* node, int id, string loc, int sev) {
        if (!node) return new Node(id, loc, sev);

        if (id < node->id)
            node->left = insert(node->left, id, loc, sev);
        else if (id > node->id)
            node->right = insert(node->right, id, loc, sev);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && id < node->left->id) return rightRotate(node);
        if (balance < -1 && id > node->right->id) return leftRotate(node);
        if (balance > 1 && id > node->left->id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && id < node->right->id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
    
    Node* deleteNode(Node* root, int id) {
        if (root == nullptr) return root;

        if (id < root->id)
            root->left = deleteNode(root->left, id);
        else if (id > root->id)
            root->right = deleteNode(root->right, id);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node *temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->id = temp->id;
                root->location = temp->location;
                root->severity = temp->severity;
                root->right = deleteNode(root->right, temp->id);
            }
        }

        if (root == nullptr) return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* search(Node* root, int id) {
        if (!root || root->id == id) return root;
        if (root->id < id) return search(root->right, id);
        return search(root->left, id);
    }

    void inOrder(Node* root) {
        if (root) {
            inOrder(root->left);
            cout << root->id << " ";
            inOrder(root->right);
        }
    }

    void levelOrder(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            cout << current->id << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
            q.pop();
        }
    }
};

int main() {
    AVLTree tree;
    Node* root = nullptr;

    root = tree.insert(root, 10, "Sector F", 5);
    root = tree.insert(root, 20, "Sector G", 4);
    root = tree.insert(root, 30, "Sector H", 3);
    root = tree.insert(root, 40, "Sector I", 2);
    root = tree.insert(root, 50, "Blue Area", 1);
    root = tree.insert(root, 25, "DHA", 3);
    root = tree.insert(root, 15, "Bahria", 4);
    root = tree.insert(root, 5, "I-8", 5);
    root = tree.insert(root, 35, "G-11", 2);
    root = tree.insert(root, 45, "F-10", 3);
    root = tree.insert(root, 55, "E-11", 1);
    root = tree.insert(root, 60, "B-17", 4);

    cout << "AVL In-order Traversal: ";
    tree.inOrder(root);
    cout << "\nAVL Level-order (BFS): ";
    tree.levelOrder(root);
    
    Node* found = tree.search(root, 25);
    if (found) cout << "\nFound Emergency ID 25 at " << found->location;
    
    cout << "\nDeleting ID 30...\n";
    root = tree.deleteNode(root, 30);
    
    cout << "Final AVL In-order Traversal: ";
    tree.inOrder(root);
    cout << endl;

    return 0;
}