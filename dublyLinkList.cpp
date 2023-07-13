#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *prev;
    doublyNode *next;
    doublyNode(int value)
    {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

int countSize(doublyNode *head)
{
    int count = 1;
    if (head == NULL)
    {
        return 0;
    }
    while (head->next != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

void display(doublyNode *head)
{

    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void insertionAtTail(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertionAtHead(doublyNode *&head, int value)
{
    doublyNode *newNode = new doublyNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void displayReverse(doublyNode *head)
{
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int main()
{

    doublyNode *head = NULL;
    int choice, value, position, res;
    cout << "Choice 22: Display" << endl;
    cout << "Choice 33: Display Reverse" << endl;
    cout << "Choice 1: Insertion at tail" << endl;
    cout << "Choice 2: Insertion at head" << endl;
    cout << "Your Choice: ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 33:
            cout << "List Size : " << countSize(head) << endl;

            break;
        case 22:
            display(head);
            break;
        case 44:
            displayReverse(head);
            break;
        case 1:
            cout << "Enter the value : ";
            cin >> value;
            insertionAtTail(head, value);
            break;
        case 2:
            cout << "Enter the value : ";
            cin >> value;
            insertionAtHead(head, value);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    return 0;
}