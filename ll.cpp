#include "ll.h"

void insertNode(node *&head, int index, int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr; // Initialize the prev pointer to nullptr

    if(index == 0)
    {
        newNode->next = head;
        if(head != nullptr) // Check if the list is not empty
        {
            head->prev = newNode; // Set prev pointer of the old head to the new node
        }   
        head = newNode;
    }
    else
    {
        node* walker = head;
        int wIndex = 0;
        while(walker != NULL && wIndex < index-1)
        {
            walker = walker->next;
            wIndex++;
        }
        if(walker == nullptr)
        {
            cout << "Index is too large, can't insert" << endl;
            return;
        }
        else
        {
            newNode->next = walker->next;
            newNode->prev = walker; // Set the prev pointer of new node to the current walker node
            if(walker->next != nullptr) // Check if we're not inserting at the end of the list
            {
                walker->next->prev = newNode; // Set the prev pointer of the next node to the new node
            }
            walker->next = newNode;
        }

    }
}

void deleteNode(node *&head, int index) 
{
    // Check if the list is empty and there's nothing to delete
        
        // Write your code here!
    if(head == nullptr) // Check to see if the list is empty
    {
        cout << "List is empty, nothing to delete" << endl; // prints message
        return; // Exit the function
    }

    // Check if were are deleting at index 0 and handle accordingly
    if(index == 0)
    {
        // Write your code here!
        node* temp = head; // Store the current head node to delete
        head = head->next; // Move head to the next node
        if(head != nullptr) // Check if the new head is not nullptr
        {
            head->prev = nullptr; // Update the new head's prev pointer to nullptr
        }
        delete temp; // Deletes the old head node
    }
    // Handle other index deletions
    else
    {
        // Write your code here!
        node* walker = head; // Start from the head of the list
        int wIndex = 0; // A counter to keep track of the current index
        while(walker->next != nullptr && wIndex < index-1) // Traverse through the list
        {
            walker = walker->next; // Move to the next node
            wIndex++; // Increment the index counter
        }
        if(walker->next == nullptr) // Check if the next node is nullptr
        {
            cout << "Index is too large, can't delete" << endl; // Prints message
            return; // Exit function
        }
        else
        {
            node* temp = walker->next; // Store the node to be deleted
            walker->next = walker->next->next; // Bypass the node to be deleted
            if(walker->next != nullptr) // Check if we're not deleting the last node
            {
                walker->next->prev = walker; // Update the prev pointer of the next node to point back to the current node
            }
            delete temp; // Delete the node that was removed from the list
        }
    }
}

void displayList(node *head) 
{
    node* walker = head;

    while(walker != nullptr)
    {
        cout << walker->data<<" ";
        walker = walker->next;
    }
    cout<<endl;
}

void reverseList(node *&head)
{
    node* prev = nullptr; // Initialize previous node to nullptr
    node* current = head; // Start with the head of the list
    node* next = nullptr; // Initialize next node to nullptr

    while(current != nullptr) // Traverse the list until the end
    {
        next = current->next; // Stores next node
        current->next = prev; // Flips the next pointer to point to the previous node
        prev = current;       // Move prev to current
        current = next;       // Moves to next node
    }
    head = prev; // Update head to new first node
}

node* searchNode(node *head, int key)
{
    node* walker = head; // Start from the head of the list

    while(walker != nullptr) // Traverse the list until the end
    {
        if(walker->data == key) // If the key is found, return the node
            return walker; // Return the node containing the key
        walker = walker->next; // Move to the next node in the list
    }

    return nullptr; // not found
}
