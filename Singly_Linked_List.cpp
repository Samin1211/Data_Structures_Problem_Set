#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void insert_first(int value)
{
    node *newNode;

    newNode = new node;
    newNode->data = value;
    newNode->next = head;

    head = newNode;

    cout << value << " inserted at the beginning successfully." << endl;
}

void insert_last(int value)
{
    node *newNode, *temp;

    newNode = new node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        cout << value << " inserted at the end successfully." << endl;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << value << " inserted at the end successfully." << endl;
}

void insert_position(int pos, int value)
{
    node *newNode, *temp;
    int i;

    if (pos == 1)
    {
        insert_first(value);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid Position!" << endl;
        return;
    }

    newNode = new node;
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << value << " inserted at position " << pos << " successfully." << endl;
}

void insert_value(int afterValue, int value)
{
    node *newNode, *temp;

    temp = head;

    while (temp != NULL && temp->data != afterValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found." << endl;
        return;
    }

    newNode = new node;
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << value << " inserted after " << afterValue << " successfully." << endl;
}

void delete_first()
{
    node *temp;

    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    temp = head;
    head = head->next;

    cout << temp->data << " deleted from the beginning successfully." << endl;
    delete temp;
}

void delete_last()
{
    node *temp, *prev;

    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    if (head->next == NULL)
    {
        cout << head->data << " deleted from end successfully." << endl;
        delete head;
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    cout << temp->data << " deleted from end successfully." << endl;
    delete temp;
}

void delete_position(int pos)
{
    node *temp, *prev;
    int i;

    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    if (pos == 1)
    {
        delete_first();
        return;
    }

    temp = head;

    for (i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;

        if (temp == NULL)
        {
            cout << "Invalid Position." << endl;
            return;
        }
    }

    prev->next = temp->next;

    cout << temp->data << " deleted from position " << pos << " successfully." << endl;
    delete temp;
}

void delete_value(int value)
{
    node *temp, *prev;

    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    if (head->data == value)
    {
        delete_first();
        return;
    }

    temp = head->next;
    prev = head;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found." << endl;
        return;
    }

    prev->next = temp->next;

    cout << value << " deleted successfully." << endl;
    delete temp;
}

void printing()
{
    node *temp;

    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void searching(int value)
{
    node *temp;
    int position = 1;

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Found at position " << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Not Found" << endl;
}

void last_node()
{
    node *temp;

    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    cout << "Last Node = " << temp->data << endl;
}

void previous_of_last_node()
{
    node *temp;

    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    if (head->next == NULL)
    {
        cout << "Previous node does not exist." << endl;
        return;
    }

    temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    cout << "Previous of Last Node = " << temp->data << endl;
}

void list_size()
{
    node *temp;
    int count = 0;

    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "List Size = " << count << endl;
}

void reversePrint(node *temp)
{
    if (temp == NULL)
        return;

    reversePrint(temp->next);

    cout << temp->data << " ";
}

int main()
{
    int choice;
    int value;
    int pos;
    int afterValue;

    cout << "1. Insert First" << endl;
    cout << "2. Insert Last" << endl;
    cout << "3. Insert by Position" << endl;
    cout << "4. Insert by Value" << endl;
    cout << "5. Delete First" << endl;
    cout << "6. Delete Last" << endl;
    cout << "7. Delete by Position" << endl;
    cout << "8. Delete by Value" << endl;
    cout << "9. Print List" << endl;
    cout << "10. Search" << endl;
    cout << "11. Last Node" << endl;
    cout << "12. Previous of Last Node" << endl;
    cout << "13. List Size" << endl;
    cout << "14. Reverse Print" << endl;
    cout << "15. Exit" << endl;

    while (true)
    {
        cout << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            insert_first(value);
            break;

        case 2:
            cout << "Enter Value: ";
            cin >> value;
            insert_last(value);
            break;

        case 3:
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter Value: ";
            cin >> value;
            insert_position(pos, value);
            break;

        case 4:
            cout << "Insert After Value: ";
            cin >> afterValue;
            cout << "Enter New Value: ";
            cin >> value;
            insert_value(afterValue, value);
            break;

        case 5:
            delete_first();
            break;

        case 6:
            delete_last();
            break;

        case 7:
            cout << "Enter Position: ";
            cin >> pos;
            delete_position(pos);
            break;

        case 8:
            cout << "Enter Value: ";
            cin >> value;
            delete_value(value);
            break;

        case 9:
            printing();
            break;

        case 10:
            cout << "Enter Value: ";
            cin >> value;
            searching(value);
            break;

        case 11:
            last_node();
            break;

        case 12:
            previous_of_last_node();
            break;

        case 13:
            list_size();
            break;

        case 14:
            cout << "Reverse List: ";
            reversePrint(head);
            cout << endl;
            break;

        case 15:
            return 0;

        default:
            cout << "Invalid Choice." << endl;
        }
    }

    return 0;
}