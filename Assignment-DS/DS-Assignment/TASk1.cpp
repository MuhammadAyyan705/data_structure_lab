#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int flightNumber;
    string destination;
    string time;
    Node* left;
    Node* right;

    Node(int fn, string dest, string t) {
        flightNumber = fn;
        destination = dest;
        time = t;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* insert(Node* root, int fn, string dest, string t) {
        if (!root) return new Node(fn, dest, t);
        if (fn < root->flightNumber)
            root->left = insert(root->left, fn, dest, t);
        else if (fn > root->flightNumber)
            root->right = insert(root->right, fn, dest, t);
        return root;
    }

    Node* search(Node* root, int fn) {
        if (!root || root->flightNumber == fn) return root;
        if (root->flightNumber < fn) return search(root->right, fn);
        return search(root->left, fn);
    }

    Node* findMin(Node* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    Node* findMax(Node* root) {
        while (root && root->right) root = root->right;
        return root;
    }

    Node* deleteNode(Node* root, int fn) {
        if (!root) return root;
        if (fn < root->flightNumber)
            root->left = deleteNode(root->left, fn);
        else if (fn > root->flightNumber)
            root->right = deleteNode(root->right, fn);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->flightNumber = temp->flightNumber;
            root->destination = temp->destination;
            root->time = temp->time;
            root->right = deleteNode(root->right, temp->flightNumber);
        }
        return root;
    }

    void inOrder(Node* root) {
        if (root) {
            inOrder(root->left);
            cout << root->flightNumber << " ";
            inOrder(root->right);
        }
    }

    void preOrder(Node* root) {
        if (root) {
            cout << root->flightNumber << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(Node* root) {
        if (root) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->flightNumber << " ";
        }
    }

    int countFlights(Node* root) {
        if (!root) return 0;
        return 1 + countFlights(root->left) + countFlights(root->right);
    }

    int height(Node* root) {
        if (!root) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        return max(leftH, rightH) + 1;
    }
};

int main() {
    BST tree;
    Node* root = nullptr;

    root = tree.insert(root, 500, "Dubai", "10:00");
    root = tree.insert(root, 300, "London", "12:00");
    root = tree.insert(root, 700, "New York", "14:00");
    root = tree.insert(root, 200, "Paris", "15:00");
    root = tree.insert(root, 400, "Tokyo", "16:00");
    root = tree.insert(root, 600, "Berlin", "17:00");
    root = tree.insert(root, 800, "Sydney", "18:00");
    root = tree.insert(root, 100, "Rome", "19:00");
    root = tree.insert(root, 250, "Madrid", "20:00");
    root = tree.insert(root, 350, "Cairo", "21:00");
    root = tree.insert(root, 450, "Beijing", "22:00");
    root = tree.insert(root, 900, "Seoul", "23:00");

    cout << "In-order Traversal: ";
    tree.inOrder(root);
    cout << "\nPre-order Traversal: ";
    tree.preOrder(root);
    cout << "\nPost-order Traversal: ";
    tree.postOrder(root);
    
    Node* minNode = tree.findMin(root);
    Node* maxNode = tree.findMax(root);
    if(minNode) cout << "\nMin Flight: " << minNode->flightNumber;
    if(maxNode) cout << "\nMax Flight: " << maxNode->flightNumber;
    
    cout << "\nTotal Flights: " << tree.countFlights(root);
    cout << "\nTree Height: " << tree.height(root);

    Node* searchResult = tree.search(root, 400);
    if(searchResult) cout << "\nFound Flight 400 to " << searchResult->destination;

    cout << "\nDeleting 300 (Node with two children)...\n";
    root = tree.deleteNode(root, 300);
    
    cout << "Final In-order Traversal: ";
    tree.inOrder(root);
    cout << endl;

    return 0;
}