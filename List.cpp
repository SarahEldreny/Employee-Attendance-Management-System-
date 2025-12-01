// File: List.cpp
#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
    head = NULL; cursor = NULL; prev = NULL;
}

List::~List()
{
    makeListEmpty();
}

bool List::listIsEmpty() const { return (head == NULL); }
bool List::curIsEmpty() const { return (cursor == NULL); }

void List::toFirst()
{
    cursor = head; prev = NULL;
}

bool List::atFirst() const { return (cursor == head); }

void List::advance()
{
    prev = cursor;
    cursor = cursor->next;
}

void List::toEnd()
{
    toFirst();
    if (!listIsEmpty())
        while (cursor->next != NULL) advance();
}

bool List::atEnd() const
{
    if (listIsEmpty()) return true;
    else if (curIsEmpty()) return false;
    else return (cursor->next == NULL);
}

int List::listSize() const
{
    NodePointer q = head;
    int count = 0;
    while (q != NULL)
    {
        count++; q = q->next;
    }
    return count;
}

void List::updateData(const char &d) { cursor->data = d; }

void List::retrieveData(char &d, int &k) const
{
    if (cursor != NULL) {
        d = cursor->data;
        k = cursor->key;
    }
}

void List::retrieveKey(int &k) const
{
    if (cursor != NULL) k = cursor->key;
}

void List::insertFirst(const int &k, const char &d)
{
    NodePointer pnew = new node;
    pnew->key = k; pnew->data = d;
    pnew->next = head;
    head = pnew;
    cursor = head;
    prev = NULL;
}

void List::insertAfter(const int &k, const char &d)
{
    NodePointer pnew = new node;
    pnew->key = k; pnew->data = d;
    pnew->next = cursor->next;
    cursor->next = pnew;
    prev = cursor;
    cursor = pnew;
}

void List::insertBefore(const int &k, const char &d)
{
    NodePointer pnew = new node;
    pnew->key = k; pnew->data = d;
    pnew->next = cursor;
    prev->next = pnew;
    cursor = pnew;
}

void List::insertEnd(const int &k, const char &d)
{
    if (listIsEmpty()) insertFirst(k, d);
    else { toEnd(); insertAfter(k, d); }
}

void List::deleteNode()
{
    NodePointer q;
    if (!curIsEmpty())
    {
        if (atFirst())
        {
            q = cursor;
            cursor = cursor->next;
            head = cursor;
            delete q;
        }
        else
        {
            q = cursor;
            cursor = cursor->next;
            prev->next = cursor;
            delete q;
        }
    }
}

void List::deleteFirst()
{
    if (!listIsEmpty()) { toFirst(); deleteNode(); }
}

void List::deleteEnd()
{
    if (!listIsEmpty()) { toEnd(); deleteNode(); }
}

void List::makeListEmpty()
{
    toFirst();
    while (!listIsEmpty())
        deleteNode();
}

bool List::search(const int &k)
{
    bool found = false;
    toFirst();
    while ((!found) && (cursor != NULL))
        if (k == cursor->key) found = true;
        else advance();
    return found;
}

void List::orderInsert(const char &d, const int &k)
{
    toFirst();
    while ((cursor != NULL) && (k > cursor->key))
        advance();
    if (prev == NULL) insertFirst(k, d);
    else insertBefore(k, d);
}

void List::traverse()
{
    toFirst();
    while (!curIsEmpty())
    {
        cout << "ID: " << cursor->key << " | Grade: " << cursor->data << endl;
        advance();
    }
}

int List::getMiddle()
{
    NodePointer q = head;
    int count = listSize();
    for (int i = 0; i < (count / 2); i++)
        q = q->next;
    return q->key;
}

void List::reverse()
{
    NodePointer nextNode;
    toFirst();
    while (!curIsEmpty())
    {
        nextNode = cursor->next;
        cursor->next = prev;
        prev = cursor;
        cursor = nextNode;
    }
    head = prev;
}

bool List::Sortedlist()
{
    int d1, d2;
    if (listIsEmpty()) return true;
    
    toFirst();
    while (cursor->next != NULL)
    {
        retrieveKey(d1);
        advance();
        retrieveKey(d2);
        if (d1 > d2) return false;
    }
    return true;
}

void List::selectionSort()
{
    node *p, *smallptr, *q;
    int tempKey;
    char tempData;
    
    p = head;
    while (p != NULL)
    {
        smallptr = p;
        q = p->next;
        while (q != NULL)
        {
            if (q->key < smallptr->key)
                smallptr = q;
            q = q->next;
        }
        // Swap Data
        tempKey = p->key; p->key = smallptr->key; smallptr->key = tempKey;
        tempData = p->data; p->data = smallptr->data; smallptr->data = tempData;
        
        p = p->next;
    }
}

void List::insertionSort()
{
    // Simplified insertion sort logic (swapping values for simplicity in linked list)
    if(head == NULL || head->next == NULL) return;
    
    node* current = head->next;
    while(current != NULL) {
        node* ptr = head;
        while(ptr != current) {
            if(ptr->key > current->key) {
                // Simple swap of data/key
                int tempK = ptr->key; char tempD = ptr->data;
                ptr->key = current->key; ptr->data = current->data;
                current->key = tempK; current->data = tempD;
            }
            ptr = ptr->next;
        }
        current = current->next;
    }
}

int List::Recursive_List_Size() { return List_Size2(head); }

int List::List_Size2(NodePointer h)
{
    if (h == NULL) return 0;
    else return 1 + List_Size2(h->next);
}

void List::DispalyList() { Display(head); }

void List::Display(NodePointer h)
{
    if (h == NULL) return;
    else cout << h->key << " " << h->data << endl;
    Display(h->next);
}
