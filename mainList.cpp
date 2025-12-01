// File: mainList.cpp
// Title: Employee Attendance Management System using Singly Linked List
// Author: [Sarah Abdelmoaty/ID: 202300338]
// Course: Data Structures (CS505)

#include <iostream>
#include <string>
#include "List.h" 
#include <iomanip> // For formatting output
using namespace std;

// Function: GetStatusName
// Description: Translates the attendance status character code into a descriptive string.
// Input: 'code' (char) - The status character ('P', 'L', 'E', 'A').
// Output: string - The full description of the status.
string getStatusName(char code) {
    switch(code) {
        case 'P': return "Present (On Time)";
        case 'L': return "Late Arrival";
        case 'A': return "Absent";
        case 'E': return "Excused Leave";
        default:  return "STATUS ERROR";
    }
}

// Function: PrintAttendanceLog
// Description: Traverses the entire linked list and prints the log in a structured, chronological format.
// Precondition: The List object 'L' must contain attendance records.
void PrintAttendanceLog(List &L) {
    int id;
    char status;
    int recordNumber = 1;

    cout << "\n==================================================" << endl;
    cout << "           DAILY ATTENDANCE LOG (CHRONOLOGICAL)" << endl;
    cout << "==================================================" << endl;
    
    // Reset cursor to the beginning of the list for full traversal
    L.toFirst(); 
    while (!L.curIsEmpty()) {
        // Retrieve key (ID) and data (Status) of the current node
        L.retrieveData(status, id); 
        
        cout << setw(3) << recordNumber << ". ";
        cout << "Employee ID: " << setw(5) << id 
             << " | Status: " << getStatusName(status) << endl;
        
        // Move to the next node in the sequence
        L.advance(); 
        recordNumber++;
    }
    cout << "--------------------------------------------------" << endl;
}

int main() {
    List todayAttendanceLog; // Instantiate the Linked List object

    cout << "=== Linked List Application: Employee Attendance System ===" << endl;
    
    // 1. Initial Data Population: Simulating Employee Arrivals (FIFO - First In, First Out)
    // The insertEnd() method ensures the list maintains the chronological order of check-ins.
    cout << "\n[1. INITIAL CHECK-IN SEQUENCE]" << endl;
    
    // ID 1001: Arrived On Time
    todayAttendanceLog.insertEnd(1001, 'P'); 
    
    // ID 1005: Arrived On Time
    todayAttendanceLog.insertEnd(1005, 'P');
    
    // ID 1003: Arrived Late
    todayAttendanceLog.insertEnd(1003, 'L');
    
    // ID 1002: Marked as Excused (e.g., pre-approved)
    todayAttendanceLog.insertEnd(1002, 'E'); 
    
    // Display the initial log to demonstrate chronological order
    PrintAttendanceLog(todayAttendanceLog);

    // 2. Data Retrieval: Searching for a Specific Employee
    int searchID = 1005;
    cout << "\n[2. DATA RETRIEVAL] Searching for Employee ID " << searchID << "..." << endl;
    
    // The search() function moves the cursor to the matching node if found.
    if (todayAttendanceLog.search(searchID)) { 
        char s; int k;
        todayAttendanceLog.retrieveData(s, k);
        cout << "   -> SUCCESS: Employee " << k << " found. Current Status: " << getStatusName(s) << endl;
    } else {
        cout << "   -> ERROR: Employee " << searchID << " not found in the log." << endl;
    }
    
    // 3. Data Correction: Updating a Record Status (Demonstrating Pointer Manipulation)
    // Employee 1003 was mistakenly marked Late. Correcting status to Present.
    int correctionID = 1003;
    cout << "\n[3. DATA CORRECTION] Correcting status for Employee ID " << correctionID << "..." << endl;
    
    if(todayAttendanceLog.search(correctionID)) {
        // The cursor is now pointing at Employee 1003. We use updateData().
        todayAttendanceLog.updateData('P'); 
        cout << "   -> SUCCESS: Status for " << correctionID << " updated to PRESENT." << endl;
    }
    
    // 4. Final System State Analysis
    cout << "\n[4. FINAL LOG & STATISTICS]" << endl;
    PrintAttendanceLog(todayAttendanceLog); // Display the updated log
    
    cout << "Total Records Processed (List Size): " << todayAttendanceLog.listSize() << endl;
    cout << "Note: List size reflects the total count of check-in events." << endl;

    // Optional: Demonstrate deletion (e.g., removing a double-entry, deleting first entry of the day)
    // todayAttendanceLog.deleteFirst(); 
    // cout << "\nFirst entry removed. New size: " << todayAttendanceLog.listSize() << endl;

    todayAttendanceLog.makeListEmpty(); // Proper cleanup using the destructor/utility function

    return 0;
}
