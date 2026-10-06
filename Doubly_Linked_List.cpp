#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *header = NULL;

void insert_first(int value)
{
    node *newNode = new node;

    newNode->data = value;

    if (header == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        header = newNode;
    }
    else
    {
        newNode->next = header;
        newNode->prev = NULL;
        header->prev = newNode;
        header = newNode;
    }
}

void insert_last(int value)
{
    node *newNode = new node;

    newNode->data = value;
    newNode->next = NULL;

    if (header == NULL)
    {
        newNode->prev = NULL;
        header = newNode;
    }
    else
    {
        node *ptr = header;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newNode;
        newNode->prev = ptr;
    }
}

void insert_by_position(int value, int pos)
{
    node *newNode = new node;
    newNode->data = value;

    if (pos == 1)
    {
        newNode->next = header;
        newNode->prev = NULL;

        if (header != NULL)
        {
            header->prev = newNode;
        }

        header = newNode;
    }
    else
    {
        node *ptr = header;

        for (int i = 1; i < pos - 1 && ptr != NULL; i++)
        {
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            cout << "Invalid position" << endl;
            delete newNode;
        }
        else
        {
            newNode->next = ptr->next;
            newNode->prev = ptr;

            if (ptr->next != NULL)
            {
                ptr->next->prev = newNode;
            }

            ptr->next = newNode;
        }
    }
}

void insert_by_value(int value, int target)
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *ptr = header;

    while (ptr != NULL && ptr->data != target)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    node *newNode = new node;
    newNode->data = value;

    if (ptr == header)
    {
        newNode->next = header;
        newNode->prev = NULL;
        header->prev = newNode;
        header = newNode;
    }
    else
    {
        newNode->next = ptr;
        newNode->prev = ptr->prev;
        ptr->prev->next = newNode;
        ptr->prev = newNode;
    }
}

void delete_first()
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        node *ptr = header;

        header = header->next;

        if (header != NULL)
        {
            header->prev = NULL;
        }

        delete ptr;
    }
}

void delete_last()
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *ptr = header;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr->prev == NULL)
    {
        header = NULL;
    }
    else
    {
        ptr->prev->next = NULL;
    }

    delete ptr;
}

void delete_by_position(int pos)
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (pos == 1)
    {
        node *ptr = header;

        header = header->next;

        if (header != NULL)
        {
            header->prev = NULL;
        }

        delete ptr;
    }
    else
    {
        node *ptr = header;

        for (int i = 1; i < pos - 1 && ptr->next != NULL; i++)
        {
            ptr = ptr->next;
        }

        if (ptr->next == NULL)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            node *ptr1 = ptr->next;

            ptr->next = ptr1->next;

            if (ptr1->next != NULL)
            {
                ptr1->next->prev = ptr;
            }

            delete ptr1;
        }
    }
}

void delete_by_value(int value)
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *ptr = header;

    while (ptr != NULL && ptr->data != value)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    if (ptr == header)
    {
        header = header->next;

        if (header != NULL)
        {
            header->prev = NULL;
        }

        delete ptr;
    }
    else
    {
        ptr->prev->next = ptr->next;

        if (ptr->next != NULL)
        {
            ptr->next->prev = ptr->prev;
        }

        delete ptr;
    }
}

void printingF()
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        node *ptr;

        for (ptr = header; ptr != NULL; ptr = ptr->next)
        {
            cout << ptr->data << " ";
        }

        cout << endl;
    }
}

void printingB()
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        node *ptr = header;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        for (; ptr != NULL; ptr = ptr->prev)
        {
            cout << ptr->data << " ";
        }

        cout << endl;
    }
}

void searching(int value)
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *ptr = header;
    int position = 1;

    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            cout << "Value found at position "
                 << position << endl;
            return;
        }

        ptr = ptr->next;
        position++;
    }

    cout << "Value not found" << endl;
}

void last_node()
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *ptr = header;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    cout << "Last node = " << ptr->data << endl;
}

void previous_of_last_node()
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *ptr = header;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr->prev == NULL)
    {
        cout << "There is no previous node" << endl;
    }
    else
    {
        cout << "Previous of last node = "
             << ptr->prev->data << endl;
    }
}

void list_size()
{
    int count = 0;

    node *ptr = header;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    cout << "List size = " << count << endl;
}

void reversePrint()
{
    if (header == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *ptr = header;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }

    cout << endl;
}

int main()
{
    int choice;
    int value;
    int pos;
    int target;

    cout << "1.  Insert First" << endl;
    cout << "2.  Insert Last" << endl;
    cout << "3.  Insert by Position" << endl;
    cout << "4.  Insert by Value" << endl;
    cout << "5.  Delete First" << endl;
    cout << "6.  Delete Last" << endl;
    cout << "7.  Delete by Position" << endl;
    cout << "8.  Delete by Value" << endl;
    cout << "9.  Printing Forward" << endl;
    cout << "10. Printing Backward" << endl;
    cout << "11. Searching" << endl;
    cout << "12. Last Node" << endl;
    cout << "13. Previous of Last Node" << endl;
    cout << "14. List Size" << endl;
    cout << "15. Reverse Print" << endl;
    cout << "0. Exit" << endl;

    while (true)
    {

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insert_first(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insert_last(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> pos;

            insert_by_position(value, pos);
            break;

        case 4:
            cout << "Enter value to insert: ";
            cin >> value;

            cout << "Insert before which value: ";
            cin >> target;

            insert_by_value(value, target);
            break;

        case 5:
            delete_first();
            break;

        case 6:
            delete_last();
            break;

        case 7:
            cout << "Enter position: ";
            cin >> pos;

            delete_by_position(pos);
            break;

        case 8:
            cout << "Enter value to delete: ";
            cin >> value;

            delete_by_value(value);
            break;

        case 9:
            printingF();
            break;

        case 10:
            printingB();
            break;

        case 11:
            cout << "Enter value to search: ";
            cin >> value;

            searching(value);
            break;

        case 12:
            last_node();
            break;

        case 13:
            previous_of_last_node();
            break;

        case 14:
            list_size();
            break;

        case 15:
            reversePrint();
            break;

        case 0:
            cout << "Program terminated." << endl;
            return 0;

        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}