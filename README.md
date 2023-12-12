# Teacher and Student Management System
This C program manages a system for teachers and students to handle grades, login functionality, grade uploads, editing, sorting, viewing, and statistical calculations.

## Contents
- [Overview](#overview)
- [File Structure](#file-structure)
- [Features](#features)
- [Usage](#usage)
- [How to Run](#how-to-run)
- [Additional Information](#additional-information)

## Overview
The program contains functions and structures for managing teachers and students. It includes login authentication for both teachers and students, with options for teachers to upload grades, edit them, sort them, view them, calculate statistics, and perform student searches. Students have the ability to view their individual grades and log out.

## File Structure
The main program is contained within a single source file named rec.c. It includes several functions and data structures for managing teachers and students.

## Features

### Teacher Features:
#### Teacher login authentication
- Grade upload
- Grade editing
- Grade sorting
- Grade viewing
- Statistical calculations
- Student search

### Student Features:
#### Student login authentication
- Viewing individual information

## Usage
### Functions:
1. teacherLogin: Validates teacher login credentials.
2. studentLogin: Validates student login credentials.
3. Read Teacher's Login Information from Files: Reads login information for teachers from separate text files.
4. Read Student's Login Information from Files: Reads login information for students from separate text files.
5. uploadGrades: Allows teachers to upload grades for students.
6. editGrades: Enables teachers to edit specific student grades.
7. sortGrades: Sorts student grades based on marks.
8. viewGrades: Allows teachers to view all student grades.
9. calculateStatistics: Calculates statistics like average, minimum, and maximum grades.
10. studentSearch: Provides the ability to search for students by name or student number.

## How to Run
To run the program:
Compile the main.c file using a C compiler (e.g., gcc).
Execute the compiled file in the command line or terminal.

