Readme -  cpp Projects " # Bank Management System in C++" " Student management System" " Simple Calculator # "

# Bank Management System in C++

This is a **simple Bank Management System** implemented in C++ to demonstrate **Object-Oriented Programming (OOP) concepts** such as **inheritance**, **polymorphism**, and **dynamic memory management**.

---

## 💡 Project Overview

- The project defines a **base class `Account`** with common attributes:
  - Account Number
  - Customer Name
  - Balance
- Two derived classes demonstrate inheritance:
  - `SavingsAccount` → includes **interest rate**
  - `CurrentAccount` → includes **overdraft limit**
- **Polymorphism** is used to call the appropriate `display()` function dynamically.
- **Dynamic memory management** via `new` and `delete` ensures proper cleanup.

---

## 🏷️ Features

- Add multiple types of accounts (Savings & Current)
- Display account details polymorphically
- Demonstrates OOP concepts:
  - **Encapsulation** (data members protected)
  - **Inheritance** (Savings & Current inherit from Account)
  - **Polymorphism** (virtual `display()` method)
- Proper memory management with virtual destructors

---


# Student Management System in C++

This is a **simple Student Management System** implemented in C++ to demonstrate **basic object-oriented programming (OOP)** and array handling. The program allows the user to **add, view, and search student records**.

---

## 💡 Project Overview

- The program defines a `student` class with attributes:
  - Roll Number
  - Name
  - Marks
- Functions in the class:
  - `set()` → input student details
  - `display()` → show student details
- Uses an **array of student objects** to store multiple student records.
- Menu-driven interface for user-friendly interaction.

---

## 🏷️ Features

1. **Add Student**
   - Input roll number, name, and marks.
2. **View All Students**
   - Display all stored student records.
3. **Search Student by Roll Number**
   - Find a student record by their roll number.
4. **Exit**
   - Close the program safely.
5. Demonstrates basic **OOP**, **arrays**, and **control structures** in C++.

---


# Simple Calculator in C++

This is a **basic console-based calculator** implemented in C++ that performs **addition, subtraction, multiplication, and division** of two numbers. The program demonstrates basic **control structures**, **loops**, and **user input handling** in C++.

---

## 💡 Project Overview

- Provides a **menu-driven interface** for performing calculations.
- Supports the following operations:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- User can **quit** the program by entering `q` or `Q`.
- Handles **division by zero** with a simple error message.

---

```bash
g++ Calculator.cpp -o Calculator

