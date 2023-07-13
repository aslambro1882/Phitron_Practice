#include <bits/stdc++.h>
using namespace std;
// Counting the Size-------------------------------------------------done
// Display List------------------------------------------------------done
// Insertion at Head-------------------------------------------------done
// Insertion at Tail-------------------------------------------------done
// Insertion at Specific Position------------------------------------done
// Search a value(Unique List)---------------------------------------done
// Search a value(Duplication enabled List)--------------------------done
// Insertion after a specific value(Unique List)---------------------done
// Insertion after a specific value(Duplication enabled List)--------done
// Deletion at Head--------------------------------------------------done
// Deletion at Tail--------------------------------------------------done
// Deletion at a Specific Position-----------------------------------done
// Deletion by Value(Unique List)------------------------------------done
// Deletion by Value(Duplication enabled List)-----------------------done

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct Array
{
    int position[1000];
};

int countSize(Node *head)
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

void display(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertionAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void insertionAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertionAtSpecificPosition(Node *&head, int data, int position)
{
    Node *newNode = new Node(data);
    int i = 0;
    if (head == NULL)
        return;
    if (position == countSize(head) + 1)
        insertionAtTail(head, data);
    else if (position == 1)
        insertionAtHead(head, data);
    else
    {
        if (position > countSize(head))
            cout << "Invalid range!" << endl;
        else
        {
            Node *temp = head;
            while (i < position - 2)
            {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

int searchByValueUniqueList(Node *head, int data)
{

    int position = 1;
    Node *temp = head;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->data != data)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        temp = temp->next;
        position++;
    }
    return position;
}

Array searchByValueDuplicateListPositionsReturn(Node *head, int data)
{
    Array P;
    int k = 1, position = 1;
    while (head != NULL)
    {
        if (head->data == data)
        {
            P.position[k] = position;
            k++;
        }
        head = head->next;
        position++;
    }
    P.position[0] = k;
    return P;
}

void insertionAfterSpecificValue(Node *&head, int data, int insertData)
{
    int position = searchByValueUniqueList(head, data);
    insertionAtSpecificPosition(head, insertData, position + 1);
}

void insertionAfterSpecificValueDuplication(Node *&head, int data, int insertData)
{
    Array P;
    P = searchByValueDuplicateListPositionsReturn(head, data);
    int size = P.position[0];
    for (int i = 1; i < size; i++)
    {
        insertionAtSpecificPosition(head, insertData, P.position[i] + i);
    }
}

void deletionAtHead(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *delNode = head;
    head = head->next;
    delete delNode;
}

// not working at last node
void deletionAtTail(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *delNode = temp->next;
    temp->next = NULL;
    delete delNode;
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    int i = 1;
    if (position == countSize(head))
    {
        deletionAtTail(head);
    }
    else if (position == 1)
    {
        deletionAtHead(head);
    }
    else
    {
        cout << "check" << endl;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
}

void deletionBySpecificValue(Node *&head, int data)
{
    int position = searchByValueUniqueList(head, data);
    if (position == countSize(head))
    {
        deletionAtTail(head);
        return;
    }
    else if (position == 1)
    {
        deletionAtHead(head);
        return;
    }
    {
        deletionAtSpecificPosition(head, position);
        return;
    }
}

void deletionBySpecificValueDuplicate(Node *&head, int data)
{
    Array P;
    P = searchByValueDuplicateListPositionsReturn(head, data);
    for (int i = 1; i < P.position[0]; i++)
    {
        deletionBySpecificValue(head, data);
    }
}

void reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "The Linked List is Empty" << endl;
        return;
    }

    Node *next = head->next;
    while (1)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (current == NULL)
            break;
        next = next->next;
    }

    head = prev;
}

Node *reverseRecursive(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        if (head == NULL)
            cout << "The Linked List is Empty" << endl;
        return head;
    }
    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{

    Node *head = NULL;
    int choice, value, position, res;
    cout << "Choice 22: Display" << endl;
    cout << "Choice 1: Insertion at tail" << endl;
    cout << "Choice 2: Insertion at head" << endl;
    cout << "Choice 3: Insertion at specific position" << endl;
    cout << "Choice 4: Search a value (Unique List)" << endl;
    cout << "Choice 5: Search a value (Duplication enabled list)" << endl;
    cout << "Choice 6: Insertion after specific value" << endl;
    cout << "Choice 7: Insertion after specific value (Duplication enabled)" << endl;
    cout << "Choice 8: Deletion at head" << endl;
    cout << "Choice 9: Deletion at tail" << endl;
    cout << "Choice 10: Deletion at Specific position" << endl;
    cout << "Choice 11: Deletion Specific value" << endl;
    cout << "Choice 12: Deletion value (Duplication enabled)" << endl;
    cout << "Choice 13: Reverse (Non Recursive)" << endl;
    cout << "Choice 14: Reverse (Recursive)" << endl;
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
        case 3:
            cout << "Enter the position : ";
            cin >> position;
            cout << "Enter the value : ";
            cin >> value;
            insertionAtSpecificPosition(head, value, position);
            break;
        case 4:
            cout << "Enter the value for search : ";
            cin >> value;
            position = searchByValueUniqueList(head, value);
            if (position == -1)
                cout << "The value is not found" << endl;
            else
                cout << "Position of the value is : " << position << endl;
            break;
        case 5:
            cout << "Enter the value for search : ";
            cin >> value;
            searchByValueDuplicateListPositionsReturn(head, value);
            break;
        case 6:
            cout << "Enter the value of previous insertion : ";
            cin >> value;
            res = searchByValueUniqueList(head, value);
            if (res == -1)
            {
                cout << "The value is not found" << endl;
                break;
            }
            cout << "Enter the value for insertion : ";
            // position using as insertValue
            cin >> position;
            insertionAfterSpecificValue(head, value, position);
            break;
        case 7:
            cout << "Enter the value of previous insertion : ";
            cin >> value;
            res = searchByValueUniqueList(head, value);
            if (res == -1)
            {
                cout << "The value is not found" << endl;
                break;
            }
            cout << "Enter the value for insertion : ";
            // position using as insertData
            cin >> position;
            insertionAfterSpecificValueDuplication(head, value, position);
            break;
        case 8:
            deletionAtHead(head);
            break;
        case 9:
            deletionAtTail(head);
            break;
        case 10:
            cout << "Enter the positon : ";
            cin >> position;
            if (position > countSize(head))
            {
                cout << "Invalid position!" << endl;
                break;
            }
            deletionAtSpecificPosition(head, position);
            break;
        case 11:
            cout << "Enter the value : ";
            cin >> value;
            deletionBySpecificValue(head, value);
            break;
        case 12:
            cout << "Enter the value : ";
            cin >> value;
            deletionBySpecificValueDuplicate(head, value);
            break;
        case 13:
            reverseNonRecursive(head);
            break;
        case 14:
            head = reverseRecursive(head);
            break;
        default:
            break;
        }
        cout << "Your Choice: ";
        cin >> choice;
    }
    display(head);
    return 0;
}