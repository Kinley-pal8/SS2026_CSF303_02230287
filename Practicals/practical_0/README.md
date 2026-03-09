# CSF303 C++ Programming Practicals: A Comprehensive Report

**Kinley Palden** | Student ID: 2230287  
BSc Software Engineering  
March 4, 2026

---

## Executive Summary

This report documents the completion of the first practical assignment series for CSF303, comprising ten progressive exercises in C++ programming. The practicals are structured to build foundational competencies gradually, beginning with basic input/output operations and progressing toward object-oriented design principles. Through this series of exercises, fundamental programming concepts including variable management, control structures, data structures, and object-oriented programming paradigms have been explored and implemented.

---

## Practical Exercises

### Q01: Personal Introduction Output

This introductory exercise established familiarity with fundamental I/O operations in C++. The program demonstrates basic string variable declaration and output using the `cout` stream. While straightforward in implementation, this exercise ensures proper understanding of syntactic requirements and console output mech banisms.

![Q01 Output](screenshots/Q1.png)

---

### Q02: Arithmetic Operations and Number Analysis

This exercise introduced algorithmic thinking through digit manipulation. The program accepts a student identification number and performs multiple computational analyses, including digit summation, odd-even classification, and modulo operations. The implementation employs iterative logic using while loops to systematically extract and process individual digits, reinforcing loop-based algorithmic design.

![Q02 Output](screenshots/Q2.png)

---

### Q03: String Manipulation and Text Processing

The third practical explores C++ string library functionality, a critical component for text-based applications. The exercise demonstrates various string operations including length calculation, case conversion, and substring extraction. These operations are essential for developing robust text processing capabilities and understanding string manipulation patterns in modern C++.

![Q03 Output](screenshots/Q3.png)

---

### Q04: Interactive Input and Type Conversion

This practical introduces interactive programming through user input handling with `cin`. The program demonstrates type conversion between numeric types and conditional calculation logic. The exercise illustrates how user input can be captured, validated, and processed to perform meaningful computations, laying groundwork for user-facing applications.

![Q04 Output](screenshots/Q4.png)

---

### Q05: Conditional Logic and Grade Classification

The fifth exercise applies conditional branching to solve a real-world classification problem. The program implements a comprehensive grade classification system using if-else chains, incorporating input validation to ensure data integrity. The personalized feedback mechanism demonstrates how control structures can be leveraged to create responsive applications.

![Q05 Output](screenshots/Q5.png)

---

### Q06: Iterative Pattern Generation

This practical reinforces loop fundamentals through pattern generation tasks. The exercise demonstrates nested loop structures to create various text-based patterns, including name repetition, triangular asterisk formations, and multiplication tables. Mastering nested loops is essential for tackling more complex algorithmic challenges requiring multi-dimensional processing.

![Q06 Output](screenshots/Q6.png)

---

### Q07: Array Operations and Statistical Analysis

The seventh exercise introduces array-based data structures and statistical computation. The program implements functionality to store multiple values and calculate fundamental statistics including minimum, maximum, and average. Additionally, a visual representation using ASCII characters demonstrates how data visualization can be implemented in console environments.

![Q07 Output](screenshots/Q7.png)

---

### Q08: Function Design and Modular Programming

This practical emphasizes code organization through function decomposition. The exercise involves implementing multiple specialized functions including digit sum calculation, prime number detection, vowel counting, and string reversal. This functional approach promotes code reusability and maintainability, fundamental principles of professional software development.

![Q08 Output](screenshots/Q8.png)

---

### Q09: Dynamic Collections and Advanced STL Usage

The ninth exercise introduces the Standard Template Library through vector containers. This practical demonstrates dynamic memory management and collection operations including sorting, statistical analysis, and filtering using functional programming constructs (lambda expressions). The use of `remove_if` with lambda functions showcases modern C++ capabilities for expressive, concise code.

![Q09 Output](screenshots/Q9.png)

---

### Q10: Object-Oriented Programming and Class Design

The final exercise represents the culmination of the practical series, implementing a complete object-oriented solution. The `Student` class encapsulates related data and functionality, employing principles of encapsulation through private attributes and public interfaces. The implementation of constructors and member functions demonstrates how OOP concepts translate into practical code structures.

![Q10 Output](screenshots/Q10.png)

---

## Learning Outcomes

This practical series has systematically developed the following competencies:

- **Fundamental I/O Operations**: Console-based input and output handling
- **Data Type Management**: Working with primitive types, strings, and composite data structures
- **Control Flow**: Conditional branching and iterative constructs
- **Data Structures**: Arrays, vectors, and their respective applications
- **Procedural Decomposition**: Function design and modular code organization
- **Object-Oriented Design**: Class design, encapsulation, and member functionality
- **Standard Library Utilization**: Practical application of STL containers and algorithms

---

## Technical Implementation

All exercises have been implemented in ISO C++ and are organized in individual source files with corresponding executable programs. The modular structure facilitates independent testing and review of each practical component.

## How to Compile

```bash
g++ Q0X.cpp -o Q0X && ./Q0X
```
