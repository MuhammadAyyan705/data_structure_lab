#include <iostream>
using namespace std;

class Node
{
public:
    int data;
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

    head->data = 2502461;
    second->data = 2502482;
    third->data = 2502454;

    head->next = second;
    second->next = third;
    third->next = NULL;
    
    int rollno;
    cout<<"Enter New student roll number: ";
    cin>>rollno;
    Node* newNode=new Node();
    newNode->data = rollno;
    newNode->next = NULL;
    third->next=newNode;

    Node* current = head;

    cout << "\nLinked List: ";

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    int searchroll;
    cout<<"\nEnter the student roll no u want to search: ";
    cin>>searchroll;
    current=head;
    bool found=false;
    while(current!= NULL)
    {
    	if(current->data==searchroll)
    	{
    		found=true;
            break;
		}
		
		current=current->next;
	}
	if (found== true)
	{
		cout<<"Found";
	}
	else
		cout<<"Not Found";
    return 0;
}

