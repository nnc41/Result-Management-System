#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 50
#define MAX_PASSWORD 50
#define MAX_USERNAME 50
#define MAX_SAMESTUDENTS_MAXMARKS 100
#define MAX_SAMESTUDENTS_MINMARKS 100

void listDirectoryContents(void) {
    printf("\nListing contents of the current directory:\n");
    system("ls"); // Execute 'ls' command
}

void readFromFile(const char *filename) {
    char command[100];
    snprintf(command, sizeof(command), "cat %s", filename); // Create the Unix command

    printf("Reading from file %s using Unix command 'cat':\n", filename);
    system(command); // Execute the 'cat' command to display the file content
}

void writeToFile(const char *filename) {
    char command[100];
    snprintf(command, sizeof(command), "echo 'Hello, Unix commands!' > %s", filename); // Create the Unix command

    printf("Writing to file %s using Unix command 'echo':\n", filename);
    system(command); // Execute the 'echo' command to write to the file
}

// Define data structures
struct Student {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char name[MAX_NAME];
    int number;
    int marks;
};

struct Teacher {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
};

// Function to check teacher login
int teacherLogin(struct Teacher* teachers, int numTeachers, char* username, char* password) {
    
    for (int i = 0; i < numTeachers; i++) {
        if (strcmp(teachers[i].username, username) == 0 && strcmp(teachers[i].password, password) == 0) {
            return i;  // Return the index of the teacher
        }
    }
    return -1;  // Invalid login
}
    
    

// Function to check student login
int studentLogin(struct Student* students, int numStudents, char* username, char* password) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].username, username) == 0 && strcmp(students[i].password, password) == 0) {
            return i;  // Return the index of the student
        }
    }
    return -1;  // Invalid login
}

// Function to upload grades
void uploadGrades(struct Student* students, int numStudents) {

    for (int i = 0; i < numStudents; i++) {
        printf("Enter grade for %s (Student %d): ", students[i].name, students[i].number);
        scanf("%d", &students[i].marks);
        printf("%s %d %d\n", students[i].name, students[i].number, students[i].marks);
    }

}

// Function to edit grades
void editGrades(struct Student* students, int numStudents) {
    // Ask for the student ID
    int id;
    printf("Enter student ID: ");
    scanf("%d", &id);

    // Find the student with the given ID
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].number == id) {
            printf("\nEditing grades for %s with ID %d:",students[i].name, id);
            printf("\nEnter new grade: ");
            scanf("%d", &students[i].marks);
            found = 1;
            break;
        }
        if (found == 0){
            printf("\nNo student found with ID %d.\n", id);
        }
    }
}

/*
 The function compares the marks values:
 If marksP is less than marksQ, it returns -1. This indicates to qsort that p should come before q.
 If marksP is greater than marksQ, it returns 1. This indicates that p should come after q.
 If marksP is equal to marksQ, it returns 0, indicating that the order between p and q does not matter since they have the same value.
 */
int comparator(const void* p, const void* q) {
    int marksP = ((struct Student*)p)->marks;
    int marksQ = ((struct Student*)q)->marks;

    if (marksP < marksQ) return -1;
    else if (marksP > marksQ) return 1;
    else return 0;
}


// Function to sort grades
void sortGrades(struct Student* students, int numStudents) {
    // Sort the structure based on the specified comparator
    qsort(students, numStudents, sizeof(struct Student), comparator);
  
    // Print the Sorted Structure
    printf("\n\nSORTED BY MARKS:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent's Name: %s\nStudent's ID: %d \nStudent's Grade: %d\n", students[i].name, students[i].number, students[i].marks);
    }
}

    

// Function to view grades
void viewGrades(struct Student* students, int numStudents) {
    printf("\nDISPLAY STUDENTS' GRADES:");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent's Name: %s\nStudent's ID: %d \nStudent's Grade: %d\n", students[i].name, students[i].number, students[i].marks);
    }
}


// Function to calculate statistics
// Implement this function to calculate average, minimum, and maximum marks. (JUST UPDATE)
void calculateStatistics(struct Student* students, int numStudents) {
    int total = 0;
    int average;
    int min = students[0].marks;
    int max = students[0].marks;
    int indexmin = 0;
    int indexmax = 0;
    char studentsWithMin[MAX_SAMESTUDENTS_MAXMARKS] = "";
    char studentsWithMax[MAX_SAMESTUDENTS_MINMARKS] = "";
    
    
    printf("\nSTATISTICS RECORD:");
    // Calculate the average marks and display
    for (int i = 0; i < numStudents; i++) {
        total += students[i].marks;
    }
    average = total/numStudents;
    printf("\nAverage mark of %d students is: %d", numStudents, average);
    
    // Calculate the minimum and maximum marks and display
    for (int i = 0; i < numStudents ; i++) {
        if (students[i].marks < min) {
            min = students[i].marks;
            indexmin = i;
            strcpy(studentsWithMin, students[i].name); // Update student with min marks
        }
        if (min == students[0].marks){
            strcpy(studentsWithMin, students[0].name);
        }
        if (students[i].marks > max) {
            max = students[i].marks;
            indexmax = i;
            strcpy(studentsWithMax, students[i].name); // Update student with max marks
        }
        if (max == students[0].marks){
            strcpy(studentsWithMax, students[0].name);
        }
    }
        
        for (int i = 0; i < numStudents ; i++) {
            if (students[i].marks == min && students[i].name != students[indexmin].name) {
                strcat(studentsWithMin, ", ");
                strcat(studentsWithMin, students[i].name); // Append student with min marks
                
            }
            if (students[i].marks == max && students[i].name != students[indexmax].name){
                strcat(studentsWithMax, ", ");
                strcat(studentsWithMax, students[i].name); // Append student with max marks
            }
        }
        
        printf("\nMinimum mark: %d (Students with minimum marks: %s)", min, studentsWithMin);
        printf("\nMaximum mark: %d (Students with maximum marks: %s)", max, studentsWithMax);
    }



// Function for student search
void studentSearch(struct Student* students, int numStudents) {
    int choice;

    //Promt user to search student using name or number
    printf("\nSTUDENT SEARCH:");
    printf("\nSearch by: \n1. Student Name \n2. Student Number \nEnter your choice: ");
    scanf("%d", &choice);

    // Search student by name
    if (choice == 1) {
        char searchName[MAX_NAME];
        printf("Enter student name: ");
        scanf("%s", searchName);

        for (int i = 0; i < numStudents; i++) {
            if (strcmp(students[i].name, searchName) == 0) {
                printf("Student Found!\n\nStudent's Info:\nStudent's Name: %s\nStudent's ID: %d \nStudent's Grade: %d\n", students[i].name, students[i].number, students[i].marks);
                return;
            }
        }
        printf("Student not found!\n");
    }

    // Search student by number
    else if (choice == 2) {
        int searchNumber;
        printf("Enter Student Number: ");
        scanf("%d", &searchNumber);

        for (int i = 0; i < numStudents; i++) {
            if (students[i].number == searchNumber) {
                printf("Student Found!\n\nStudent's Info:\nStudent's Name: %s\nStudent's ID: %d \nStudent's Grade: %d\n", students[i].name, students[i].number, students[i].marks);
                return;
            }
        }

        printf("Student not found!\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}



// MAIN FUNCTION
int main(void) {
    
    listDirectoryContents();
        
    // Define the number of teachers and students
    int numTeachers = 3;
    int numStudents = 4;

    // Sample teacher and student data
    struct Teacher teachers[3] = {
        {"teacher1", "password1"},
        {"teacher2", "password2"},
        {"teacher3", "password3"}

    };

    struct Student students[4] = {
        {"student1", "password1", "A", 111, 0},
        {"student2", "password2", "B", 222, 0},
        {"student3", "password3", "C", 333, 0},
        {"student4", "password4", "D", 444, 0},
    };


    int loggedInTeacher;
    int loggedInStudent;

    while (1) {
        int exit;
        int choice;
        printf("\nMAIN MENU:\n1. Teacher login\n2. Student login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        
        // Choice 1 for teacher
        if (choice == 1) {
            char username[MAX_USERNAME];
            char password[MAX_PASSWORD];
            printf("Enter teacher username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            
            loggedInTeacher = teacherLogin(teachers, numTeachers, username, password);
            
            //Login Teacher Success
            if (loggedInTeacher != -1) { // if loggedInTeacher return -1 means fail
                                         // if loggedInTeacher return index means success
                printf("Teacher login successful!\n");
                // Implement the teacher menu here
                while (1) {
                    exit  = 0;
                    // Implement the teacher menu options
                    int teacherChoice;
                    printf("\n\nTEACHER MENU:\n");
                    printf("1. Upload grades\n");
                    printf("2. Edit grades\n");
                    printf("3. Sort grades\n");
                    printf("4. View grades\n");
                    printf("5. Calculate statistics\n");
                    printf("6. Student search\n");
                    printf("7. Logout\n");
                    
                    // query teacher input in teachr menu
                    printf("Enter your choice: ");
                    scanf("%d", &teacherChoice);
                    
                    switch (teacherChoice) {
                        case 1:
                            uploadGrades(students, numStudents);
                            break;
                            
                        case 2:
                            editGrades(students, numStudents);
                            break;
                            
                        case 3:
                            // Call the sortGrades function to sort student grades
                            sortGrades(students, numStudents);
                            break;
                            
                        case 4:
                            viewGrades(students, numStudents);
                            break;
                            
                        case 5:
                            calculateStatistics(students, numStudents);
                            break;
                            
                        case 6:
                            // Call the studentSearch function to search for students
                            studentSearch(students, numStudents);
                            break;
                            
                        case 7:
                            // Logout and return to the main menu
                            loggedInTeacher = -1;
                            printf("Logged out successfully.\n");
                            exit = 1;
                            break;
                            
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                    
                    // Make case 7 logout return to main menu
                    if (exit == 1)
                        break;
                }
                
                // Login Teacher Fail (Return -1)
            } else {
                printf("Invalid login credentials. Try again.\n");
            }
            
            
        }
        
        // Choice 2 for Student
        else if (choice == 2) {
            char username[MAX_USERNAME];
            char password[MAX_PASSWORD];
            printf("Enter student's username: ");
            scanf("%s", username);
            printf("Enter student's password: ");
            scanf("%s", password);
            
            loggedInStudent = studentLogin(students, numStudents, username, password);
            
            // Login Student Success
            if (loggedInStudent != -1) {
                printf("Student login successful!\n");
                // Implement the student menu here
                while (1) {
                    exit  = 0;
                    int studentChoice;
                    printf("\nSTUDENT MENU:\n");
                    printf("1. View grades\n");
                    printf("2. Logout\n");
                    printf("Enter your choice: ");
                    scanf("%d", &studentChoice);
                    
                    switch (studentChoice) {
                        case 1:
                            // Implement the viewGrades function to view individual student grades
                            printf("Your grade: %d\n", students[loggedInStudent].marks);
                            break;
                            
                        case 2:
                            // Logout and return to the main menu
                            loggedInStudent = -1;
                            printf("Logged out successfully.\n");
                            exit = 1;
                            break;
                            
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                    
                    // Make case 2 logout return to main menu
                    if (exit == 1)
                        break;
                }
                
                // Login Student Fail
            } else {
                printf("Invalid login credentials. Try again.\n");
            }
            
        }
        // Choice 3 for Exist
         else if (choice == 3) {
            break;  // Exit the program
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


