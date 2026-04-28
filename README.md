# 💳 Banking System (C++ Terminal Application)

A fully functional console-based Banking System developed in C++, demonstrating Object-Oriented Programming (OOP), exception handling, and file operations.

---

## 🚀 Overview

This project simulates a simple banking system where users can manage their accounts through a terminal interface. It is designed to showcase clean code structure, modular programming, and real-world logic.

---

## ✨ Features

- Create and manage bank accounts
- Deposit money
- Withdraw money with validation
- View account details
- File handling for saving data
- Exception handling for safe operations
- Support for different account types

---

## 🧠 Concepts Used

- Object-Oriented Programming (OOP)
  - Classes & Objects
  - Inheritance
  - Encapsulation
  - Polymorphism
- Exception Handling (try-catch)
- File Handling (fstream)
- STL (vector)
- Modular programming

---

## 🏗️ System Design

The system is based on:

- Account (Base Class)
  - accountNumber
  - holderName
  - balance

- Derived Class:
  - SavingsAccount (with additional features like interest)

Each account supports:
- Deposit
- Withdraw
- Display details

---

## ▶️ How to Run

Compile:
g++ main.cpp -o banking_system

Run:
./banking_system

---

## 📸 Sample Output

============================================
|        BANKING SYSTEM - TERMINAL APP      |
|        Developed by Elif Nehir Özer       |
|         Object-Oriented in C++            |
============================================

Welcome To Your Secure Bank...

---

## ⚠️ Error Handling

- Prevents negative deposits
- Prevents withdrawing more than balance
- Handles invalid inputs

---

## 💡 Why This Project Matters

- Demonstrates real-world OOP usage
- Shows clean and maintainable code structure
- Applies backend logic in a practical way

---

## 👩‍💻 Author

Elif Nehir Özer  

---

## 📌 Notes

- Terminal-based application (no GUI)
- Built for learning and demonstration purposes
- Can be extended with GUI or database integration

