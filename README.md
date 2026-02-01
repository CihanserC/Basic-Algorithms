# Basic Algorithms Collection

A comprehensive collection of fundamental algorithms and data structures implemented in various programming languages including C, C#, Assembly (MIPS), and Arduino.

## 📁 Repository Structure

### Algorithms
Core algorithmic implementations in C:

#### Search Algorithms
- **Binary Search** (`Binary_search.c`) - Efficient O(log n) search algorithm for sorted arrays
- **Linear Search** (`Linear_search.c`, `Linear_search_functions.c`) - Simple sequential search through arrays

#### Sort Algorithms
- **Bubble Sort** (`Bubble_sort.c`, `Bubble_sort_function.c`) - Simple comparison-based sorting algorithm
- **Quick Sort** (`Quick_sort.c`, `generic_quicksort.c`) - Efficient divide-and-conquer sorting, including generic implementation
- **Merge Sort** (`merge_sort.c`) - Stable O(n log n) divide-and-conquer sorting algorithm
- **Selection Sort** (`selectionsort.c`) - In-place comparison sorting algorithm
- **General Sort Array** (`Sort_array.c`) - Array sorting utilities

### Misc - Additional Projects

#### Data Structures (C)
Advanced data structure implementations:
- **AVL Tree** (`Avl_Tree.c`) - Self-balancing binary search tree
- **Linked Tree** (`LinkedTree.c`) - Linked tree implementation with AVL balancing
- **Binary Search Tree Traversal** (`BST_Traverse.c`) - Tree traversal algorithms
- **Linked List** (`linkedlist2.c`) - Singly linked list implementation
- **Key-Value Store** (`Key-Value.c`) - Simple key-value data structure
- **Post-Order Traversal** (`PostOrder.C`) - Post-order tree traversal
- **Student Record System** (`Student_record.c`) - Database-like student management
- **Towers of Hanoi** (`towers_of_hanoi.c`) - Classic recursive puzzle solution

#### Algorithms in C#
C# programming exercises and implementations:
- **Final Exercises** (`FinalExercise1.cs`, `FinalExercise2.cs`) - Comprehensive programming exercises
- **Homework Solutions** (`Hw1.cs`, `Hw2.cs`, `Hw3.cs`, `Hw4.cs`) - Various algorithm implementations
- **Lab Exercises** (`lab7-Q8.cs`, `lab8.cs`, `lab9.cs`, `lab10.cs`) - Laboratory assignments
- Notable: `Hw4.cs` contains a sophisticated string search program with wildcard matching

#### Assembly (MIPS)
MIPS assembly language programs:
- **Factorial** (`factorialcall.asm`) - Factorial calculation with function calls
- **Loop Examples** (`C1.asm`, `C2.asm`) - Loop constructs and control flow
- **Homework Solutions** (`Hw2.asm`) - Array manipulation and function implementations
- **Lab Exercises** (`L8e1.asm` through `L8e6.asm`, `L9e1.asm` through `L9e3.asm`) - Various MIPS exercises
- **Examples** (`e1.asm`, `e2.asm`, `e3.asm`, `e4.asm`) - Basic MIPS programming examples
- **Q Series** (`Q2.asm`, `Q3.asm`) - Question solutions
- **MIPS Reference** (`MIPS syscall functions available in MARS.html`) - System call documentation

#### Arduino Projects
- **Random Number Generator** (`Random_NumGen.ino`) - Hardware random number generator using:
  - Midsquare algorithm
  - Linear Congruential Generator (LCG)
  - 7-segment display output
  - Multiple operation modes

#### Mathematical Algorithms (C)
- **Collatz Conjecture** (`collatz_conjecture.c`) - Implementation of the 3n+1 problem
- **Trinity Hall Prime** (`Trinity_hall_prime_number.c`) - Prime number generation
- **Prime Numbers** (`Prime numbers while.c`) - Prime number finder
- **Pi Calculator** (`pi_calculator.c`) - Mathematical constant calculation
- **Digit Counter** (`digit_counter1.c`) - Counts digits in numbers
- **Palindrome Checker** (`palindrom.c`) - Checks if a string is a palindrome
- **Iterative Power** (`iterativePower.c`) - Power calculation without recursion

#### Utility Programs (C)
- **Dynamic Arrays** (`DynamicArray.c`, `DynamicArray2.c`) - Dynamic memory management
- **File Operations** (`FileOps1.c`) - File I/O operations
- **Number Guessing Games** (`Number_guessing1.c`, `Number_guessing750.c`) - Interactive games
- **Random Generator from Binary** (`RandomGeneratorfromBinary.c`) - Binary-based RNG
- **Yates Sort** (`yates sort algorithm.c`) - Fisher-Yates shuffle algorithm
- **Largest Finder** (`largest.c`) - Finds largest element in array
- **Pincher** (`Pincher.c`) - Utility program

#### Maze Solver
Pathfinding implementation using stack-based algorithms:
- **Maze Solver v2** (`maze_code_v2.c`) - Complete maze pathfinding program
- **Maze Functions** (`maze_functions.h`) - Stack and position data structures
- **Maze Last** (`maze_last.c`) - Alternative maze implementation

Features:
- Linked stack implementation
- Position tracking
- Path marking and backtracking
- Dead-end detection

#### Embedded Systems
- **Embedded Codes** (`Embedded_codes.c`) - Various embedded system implementations

## 🛠️ Technologies Used

- **C** - Primary language for algorithm implementations
- **C#** - Object-oriented programming exercises
- **Assembly (MIPS)** - Low-level programming and computer architecture
- **Arduino** - Hardware programming and interfacing
- **MARS Simulator** - MIPS assembly development and testing

## 📚 Topics Covered

### Algorithms
- Searching (Linear, Binary)
- Sorting (Bubble, Quick, Merge, Selection)
- Recursion and Iteration
- Backtracking (Maze solving)
- Mathematical algorithms

### Data Structures
- Arrays (Static and Dynamic)
- Linked Lists
- Stacks
- Trees (Binary Search Trees, AVL Trees)
- Key-Value Stores

### Programming Concepts
- Function calls and recursion
- Pointer manipulation
- Memory management
- File I/O operations
- String manipulation
- Hardware interfacing

### Computer Architecture
- MIPS assembly programming
- Function calls and stack management
- Register usage
- System calls
- Low-level memory operations

## 🚀 Getting Started

### C Programs
```bash
gcc filename.c -o output
./output
```

### C# Programs
```bash
csc filename.cs
./filename.exe
```

### MIPS Assembly
Use MARS (MIPS Assembler and Runtime Simulator):
1. Open `.asm` file in MARS
2. Assemble the code
3. Run in simulator

### Arduino
1. Open `.ino` file in Arduino IDE
2. Select appropriate board
3. Upload to Arduino device

## 📖 Educational Value

This repository serves as:
- **Learning Resource** - Fundamental algorithms and data structures
- **Reference Implementation** - Well-commented code examples
- **Practice Problems** - Homework and lab exercises
- **Multi-language Examples** - Same concepts in different languages

## 🎓 Course Work

This collection represents coursework and exercises from various computer science courses including:
- Data Structures and Algorithms
- Computer Organization and Assembly Language
- Object-Oriented Programming (C#)
- Embedded Systems
- Hardware Programming

## 📝 Code Quality

- Implementations include comments explaining logic
- Multiple approaches to similar problems
- Both iterative and recursive solutions provided
- Real-world applications (maze solving, random number generation)

## 🔍 Notable Implementations

### AVL Tree with Full Balancing
Complete self-balancing AVL tree with insertion, deletion, and all rotation cases handled.

### Maze Pathfinder
Stack-based maze solver with backtracking, path marking, and obstacle avoidance.

### Arduino Random Number Generator
Hardware-based RNG with multiple algorithms and visual 7-segment display output.

### String Search with Wildcards
Advanced pattern matching supporting both `*` (wildcard) and `-` (single character) operators.

## 📄 License

This is an educational repository. Feel free to use for learning purposes.

## 👤 Author

Cihanser Çalışkan

---

*This repository demonstrates fundamental computer science concepts through practical implementations across multiple programming paradigms and languages.*
