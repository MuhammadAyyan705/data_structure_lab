#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node* next;
};

int main()
{
    Node* head;
    Node* second;
    Node* third;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = "P101";
    second->data = "P205";
    third->data = "P310";

    head->next = second;
    second->next = third;
    third->next = NULL;

    
    string productID;
    cout << "Enter New Product ID: ";
    cin >> productID;

    Node* newNode = new Node();
    newNode->data = productID;
    newNode->next = NULL;
    third->next = newNode;

   
    Node* current = head;

    cout << "\nShopping Cart: ";

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    
    string removeProduct;
    cout << "\n\nRemove Product: ";
    cin >> removeProduct;

    current = head;
    Node* previous = NULL;

    while (current != NULL)
    {
        if (current->data == removeProduct)
        {
            
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            delete current;
            break;
        }

        previous = current;
        current = current->next;
    }

    
    current = head;

    cout << "Updated Cart: ";

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}

