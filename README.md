# Event Inventory Management System

This is a menu-driven C program designed to manage inventory for events.
It helps keep track of items, vendors, stock purchases(stock in), and stock usage(stock out).

-----------------------------------------------------------------------

##  Program Description

The Event Inventory Management System allows users to:
- Add, view, search, and delete event items
- Manage vendor information
- Record stock-in (items purchased from vendors)
- Record stock-out (items used in events)
- View all records using simple menus

The program runs in the terminal and uses structures and functions for better organization.

-----------------------------------------------------------------------

## Features

- Item inventory management
- Vendor management
- Stock-in records with date
- Stock-out records with date
- Menu-based user interface
- Structured and modular C code

---

## Technologies Used

- Programming Language: C
- Compiler: GCC
- Concepts Used:
  - Structures
  - Arrays
  - Functions
  - Header files
  - Conditional statements
  - Loops

-----------------------------------------------------------------------

##  Project Structure
event-inventory-management-system/
│── README.md
│── .gitignore
│
├── src/
│ ├── main.c
│ ├── item.c
│ ├── vendor.c
│ ├── stockin.c
│ ├── stockout.c
│ └── date.h
│
└── docs/
└── project_description.pdf

-----------------------------------------------------------------------

## How to Run this Program

1. Open terminal in project folder
2. Compile the program:
gcc src/main.c -o inventory
3. Run the program:
./inventory

-----------------------------------------------------------------------

##  Main Menu Options

- Event Items Inventory
- Vendor Management
- Stock In (Purchase)
- Stock Out (Event Usage)
- Exit

Each option opens its own sub-menu.

-----------------------------------------------------------------------

## Team Members

- Menmber 1(Team Leader): Maleeha Laeeq
- Member 2: Alizmah Sufyan
- Member 3: Amnah Sattar

-----------------------------------------------------------------------

## Purpose

This project is developed for academic purposes to demonstrate basic C programming and GitHub collaboration.




