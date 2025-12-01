// File: List.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List
{
private:
    // Node Class definition
    class node
    {
    public:
        int key;        // Student ID
        char data;      // Student Grade (A, B, C...)
        node *next;
    };
    
    typedef node * NodePointer;

    // Pointers
    NodePointer head, cursor, prev;

    // Helper functions for recursion
    int List_Size2(NodePointer h);
    void Display(NodePointer h);

public:
    // Constructor & Destructor
    List();
    ~List();

    // Basic Operations
    bool listIsEmpty() const;
    bool curIsEmpty() const;
    void toFirst();
    bool atFirst() const;
    void advance();
    void toEnd();
    bool atEnd() const;
    int listSize() const;
    
    // Data Manipulation
    void updateData(const char &);
    void retrieveData(char &, int &) const;
    void retrieveKey(int &) const;
    
    // Insertion
    void insertFirst(const int &, const char &);
    void insertAfter(const int &, const char &);
    void insertBefore(const int &, const char &);
    void insertEnd(const int &, const char &);
    void orderInsert(const char &, const int &); // Insert sorted by Key
    
    // Deletion
    void deleteNode();
    void deleteFirst();
    void deleteEnd();
    void makeListEmpty();
    
    // Search & Display
    bool search(const int &);
    void traverse();
    
    // Advanced Operations & Sorting
    int getMiddle();
    void reverse();
    bool Sortedlist();
    void selectionSort();
    void insertionSort();
    
    // Recursive Functions
    int Recursive_List_Size();
    void DispalyList();
};

#endif // LIST_H
