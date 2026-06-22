# Bike Rental Management System 🚲

A CLI-based Bike Rental Management System built in **C++** using Object-Oriented Programming and file handling.

---

## About

This system simulates a real-world bike rental registry where bikes and riders can be registered, and rental logs are stored persistently in a file. Data is displayed in a formatted table with columns for Payment ID, Rider ID, Bike ID, Rental Status, Time, Day, and Price per Hour.

Built as part of my Object-Oriented Programming coursework at Lahore Garrison University.

---

## Features

- Register new bikes with full rental details (ID, day, time, price, status)
- Register new riders linked to payment records
- Display all rental logs in a formatted table
- Persistent data storage using file I/O (`rental_log.txt`)
- Auto-creates the log file if it doesn't exist
- Input validation with error handling
- Menu-driven CLI interface

---

## System Menu

```
===== Bike Rental Management =====
1. Display Rental Log
2. Add New Bike
3. Add New Rider
4. Load Rental Log
5. Exit
```

---

## OOP Concepts Used

- **Classes** — `Rentallog`, `Bike`, `Rider`
- **Inheritance** — `Bike` and `Rider` both extend `Rentallog`
- **Encapsulation** — protected file stream, public methods
- **File Handling** — `fstream` for persistent read/write storage

---

## How to Run

**Requirements:** A C++ compiler (g++ recommended)

```bash
g++ ObjectOrientedCCP_bsit-fall24-066_Asma_.cpp -o bike_rental
./bike_rental
```

On Windows:
```bash
g++ ObjectOrientedCCP_bsit-fall24-066_Asma_.cpp -o bike_rental.exe
bike_rental.exe
```

> A `rental_log.txt` file will be created automatically in the same directory on first run.

---

## Tech Stack

- Language: C++
- Paradigm: Object-Oriented Programming
- Storage: File I/O (txt)
- Interface: Command Line (CLI)

---

---

## A Note on Development Process

This project was developed using **AI-assisted development** as part of my learning workflow. I used AI tools to help structure ideas, debug logic, and improve code quality — however, all core decisions, modifications, testing, and understanding of the code were done by me personally.

I believe using AI as a thinking partner is a real and valuable skill in modern software development. My approach involved:
- Designing the class structure and system logic myself first
- Using AI to suggest improvements and help debug file handling issues
- Critically reviewing every suggestion before applying it
- Making my own modifications to meet the actual project requirements
- Testing and verifying all features including file creation and formatted output

This reflects how AI tools are actually used in real development environments — not as a replacement for thinking, but as a tool that makes thinking sharper.

---

## Author

**Asma Amin**
BSIT Student — Lahore Garrison University
