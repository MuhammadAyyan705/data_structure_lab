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
    second->data = "P102";
    third->data = "P103";

    head->next = second;
    second->next = third;
    third->next = NULL;

    
    string patientID;
    cout << "Enter New Patient ID: ";
    cin >> patientID;

    Node* newNode = new Node();
    newNode->data = patientID;
    newNode->next = NULL;
    third->next = newNode;

    Node* current = head;

    cout << "\nWaiting Patients: ";

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    
    cout << "\n\nPatient " << head->data << " is being served.";

    Node* temp = head;
    head = head->next;
    delete temp;

    
    current = head;

    cout << "\nUpdated Queue: ";

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}

