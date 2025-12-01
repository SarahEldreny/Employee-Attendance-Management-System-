#🔗 Data Structures Project: Singly Linked List Implementation

## 📝 1. Project Overview: Employee Attendance Management System

This project implements a **Singly Linked List** in C++ structured into modular files (`.h` and `.cpp`). The primary goal is to demonstrate a robust, real-world application of this fundamental data structure through an **Employee Attendance Management System**.

### 1.1 Data Structure Mapping
The Linked List nodes are defined to store attendance records:
* **`int key`**: Maps to the **Employee ID** (Unique Identifier).
* **`char data`**: Maps to the **Attendance Status Code** (e.g., 'P' for Present, 'L' for Late, 'E' for Excused).

### 1.2 Core Functionality Demonstrated

The application scenario highlights the list's capabilities in a practical context:
* **Chronological Ordering (FIFO)**: The use of the `insertEnd()` method simulates employees checking in sequentially, which is crucial for preserving the **First In, First Out (FIFO)** order of arrival.
* **Data Retrieval and Correction**: The `search()` function is used to quickly locate a specific employee by their ID, allowing for immediate correction of the attendance status using the `updateData()` method.

---

## 🏗️ 2. Modular File Structure

The project follows the standard C++ practice of **modular programming**, separating the interface (specification) from the implementation (definition) for enhanced maintainability and reusability.

| File Name | Role | Content Summary |
| :--- | :--- | :--- |
| **`List.h`** | **Header/Interface** | Contains the `List` class definition, the private `node` structure, and all function prototypes (declarations). |
| **`List.cpp`** | **Implementation** | Contains the detailed definition and logic for all member functions declared in `List.h`, including complex methods like sorting and recursion. |
| **`mainList.cpp`** | **Application/Main** | Contains the `main()` function, setting up the Attendance System scenario, instantiating the `List` object, and calling its methods to test the required functionality. |

---

## 💻 3. Building and Running the Project

### Prerequisites
* C++ Compiler (e.g., GCC, bundled with **Dev-C++**).
* The three source files (`List.h`, `List.cpp`, `mainList.cpp`) must be included in a single C++ **Project** file.

### Execution Steps (Using Dev-C++)

1.  **Create Project**: Open Dev-C++ and create a **New Console Application Project**.
2.  **Add Files**: Add `List.h`, `List.cpp`, and `mainList.cpp` to the project tree.
3.  **Compile & Run**: Press **F11** to build and execute the Attendance Management System simulation.

---

## 🛠️ 4. Key Linked List Methods Included

The implemented `List` class provides comprehensive functionality, including the following methods:

* `insertFirst`, `insertAfter`, `insertEnd`
* `deleteNode`, `deleteFirst`, `deleteEnd`, `makeListEmpty`
* `search`, `traverse`
* `listSize`, `listIsEmpty`, `atFirst`, `atEnd`
* **Advanced Features**: `selectionSort`, `insertionSort`, `reverse`, `Recursive_List_Size`.

