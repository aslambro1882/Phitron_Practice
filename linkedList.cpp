#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        this->value = val;
        this->Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *head);
int countLength(Node *&head);
void insertionAtSpecificPosition(Node *&head, int pos, int val);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void insertValueAfterSpecificValue(Node *&head, int val, int specValue);
void insertValueBeforeSpecificValue(Node *&head, int val, int specValue);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    newNode->Next = head;
    head = newNode;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->Next;
    }
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->Next;
        count++;
    }
    return count;
}

void insertionAtSpecificPosition(Node *&head, int pos, int val)
{
    int i = 0;
    Node *temp = head;
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    // checking if temp is initially null? then return -1
    if (temp == NULL)
        return -1;

    while (temp->value != key)
    {
        // checking if temp is in last element and not found the key yet. then return -1 before goto next temp and count ++
        if (temp->Next == NULL)
            return -1;

        temp = temp->Next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int count = 1, flag = 0, k = 1;
    int position[countLength(head) + 1];

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    cout << endl;
    if (!flag)
        cout << "The searched value is not yet in the list" << endl;
    else
    {
        position[0] = k;
        cout << "The number is found at Position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i] << " ";
        }
        cout << endl;
    }
}

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    int count = 1, k = 1;
    Test T;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    cout << endl;
    T.position[0] = k;
    return T;
}

void insertValueAfterSpecificValue(Node *&head, int val, int specValue)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        cout << "The list is empty, populate it first! " << endl;
        return;
    }

    Node *temp = head;
    while (temp->value != specValue)
    {
        temp = temp->Next;
    }
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void insertValueBeforeSpecificValue(Node *&head, int val, int specValue)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        cout << "The list is empty, populate it first! " << endl;
        return;
    }

    Node *temp = head;
    while (temp->Next->value != specValue)
    {
        temp = temp->Next;
    }
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void searchByValueUnique(Node *&head, int val, int specValue)
{
    int position = searchByValueUnique(head, specValue);

    insertionAtSpecificPosition(head, position, val);
}

void insertDuplicateValue(Node *&head, int val, int specValue)
{
    Test T = searchByValueDuplicateReturn(head, specValue);
    int size = T.position[0];
    int arr[size];
    for (int i = 1; i < size; i++)
    {
        insertionAtSpecificPosition(head, T.position[i] + i, val);
    }
}

void deleteAtHead(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *delNode = head;
    head = head->Next;
    delete delNode;
}

// not working at last node
void deleteAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->Next->Next != NULL)
    {
        temp = temp->Next;
    }
    Node *delNode = temp->Next;
    temp->Next = NULL;
    delete delNode;
}

void deleteAtSpecificPosition(Node *&head, int pos)
{
    int i = 1;
    Node *temp = head;
    if (pos == countLength(head))
    {
        deleteAtTail(head);
        return;
    }
    else if (pos == 1)
    {

        deleteAtHead(head);
        return;
    }
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }
    cout << "find value is " << temp->value << endl;
    Node *delNode = temp->Next;
    temp->Next = delNode->Next;
    delete delNode;
}

void deleteAlDuplicate(Node *&head, int key)
{
    Test T;
    T = searchByValueDuplicateReturn(head, key);
    int size = T.position[0];
    for (int i = 1; i < size; i++)
    {
        if (i == 1)
            deleteAtSpecificPosition(head, T.position[i]);
        else
            deleteAtSpecificPosition(head, T.position[i] - 1);
    }
}

int main()
{
    Node *head = NULL;

    int value, position;

    cout << "Choice 1: Insertion at Head" << endl;
    cout << "Choice 2: Insertion at Tail" << endl;
    cout << "Choice 3: Insertion at Specific Position" << endl;
    cout << "Choice 4: Search a value (unique list)" << endl;
    cout << "Choice 5: Search a value (Duplication enabled list)" << endl;
    cout << "Choice 6: Insertion a value after specific value" << endl;
    cout << "Choice 7: Insertion a value before specific value" << endl;
    cout << "Choice 8: Insertion a value after specific value" << endl;
    cout << "Choice 9: Insertion duplicate value after duplicate value" << endl;
    cout << "Choice 10: Deletion at head" << endl;
    cout << "Choice 11: Deletion at tail" << endl;
    cout << "Choice 12: Deletion at Specific position" << endl;
    cout << "Choice 13: Deletion all duplicate" << endl;
    cout << "Choice 0: Exit" << endl;
    cout << "Choice 20: Print current list" << endl;
    cout << "Your Choice: ";
    int choice;
    cin >> choice;
    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the Desired Position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
                cout << "The number is at Position: " << position << endl;
            else
                cout << "The number is not yet in the list" << endl;
            break;
        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            // searchByValueDuplicate(head, value);
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.position[0] == 1)
                cout << "The searched value is not yet in the list" << endl;
            else
            {
                int size = T.position[0];
                cout << "The number is found at Position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i] << " ";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "The value you want to add in the list : ";
            cin >> value;
            int specValue;
            cout << "The specific you that you want to put after :";
            cin >> specValue;
            insertValueAfterSpecificValue(head, value, specValue);
            break;
        case 7:
            cout << "The value you want to add in the list : ";
            cin >> value;
            specValue;
            cout << "The specific you that you want to put before :";
            cin >> specValue;
            insertValueBeforeSpecificValue(head, value, specValue);
            break;
        case 8:
            cout << "The value you want to add in the list : ";
            cin >> value;
            specValue;
            cout << "The specific you that you want to put before :";
            cin >> specValue;
            searchByValueUnique(head, value, specValue);
            break;
        case 9:
            cout << "The value you want to add in the list : ";
            cin >> value;
            specValue;
            cout << "The specific you that you want to put after :";
            cin >> specValue;
            insertDuplicateValue(head, value, specValue);
            break;
        case 20:
            display(head);
            cout << endl;
        case 10:
            deleteAtHead(head);
        case 11:
            deleteAtTail(head);
            break;
        case 12:
            cout << "Enter the position you want to delete :";
            cin >> position;
            deleteAtSpecificPosition(head, position);
            break;
        case 13:
            cout << "Enter the value you want to delete :";
            cin >> value;
            deleteAlDuplicate(head, value);
            break;
        default:

            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    display(head);

    return 0;
}