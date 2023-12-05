#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 50
#define MAX_PASSWORD 50
#define MAX_USERNAME 50


// Define data structures
struct Student {
    char name[MAX_NAME];
    int number;
    int marks;
};

struct Teacher {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int access_level;
};

// Function to check teacher login
int teacherLogin(struct Teacher* teachers, int numTeachers, char* username, char* password) {
    
    // Take datas from file "datas" (JUST EDIT)
    FILE* file = fopen("datas.txt", "r");
    if (file == NULL){
        printf("Error openning files datas for reading.\n"); // use fprintf for std error messeges
        return 1;
    }
    
    for (int i = 0; i < numTeachers; i++) {
        if (fscanf(file, "%50s %50s", teachers[i].username, teachers[i].password) != 2) {
            printf("Error reading data from the file.\n");
            break;
        }
        if (strcmp(teachers[i].username, username) == 0 && strcmp(teachers[i].password, password) == 0) {
            return i;  // Return the index of the teacher
        }
    }
    return -1;  // Invalid login
}
    
    

// Function to check student login (why atoi(password))
int studentLogin(struct Student* students, int numStudents, char* username, char* password) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, username) == 0 && students[i].number == atoi(password)) {
            return i;  // Return the index of the student
        }
    }
    return -1;  // Invalid login
}

// Function to upload grades (this is when open file and write on it)
void uploadGrades(struct Student* students, int numStudents) {
    // Open a file for writing (you can specify the file name)
    FILE* file = fopen("student_grades.txt", "w");

    if (file == NULL) {
        printf("Error opening the file for writing.\n"); // use fprintf for std error messeges
        return;
    }

    // Input the student grades and write them to the file (how many grades each student)
    for (int i = 0; i < numStudents; i++) {
        printf("Enter grade for %s (Student %d): ", students[i].name, students[i].number);
        scanf("%d", &students[i].marks);
        fprintf(file, "%s %d %d\n", students[i].name, students[i].number, students[i].marks);
    }

    // Close the file
    fclose(file);

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
            found = 1;
            break;
        }
    }

    // If the student is found, allow the teacher to edit their grades (why i < 5)
    if (found) {
        printf("Editing grades for student with ID %d.\n", id);
        for (int i = 0; i < 5; i++) {
            printf("Enter grade %d: ", i + 1);
            scanf("%d", &students[i].marks);
        }
    }
    // If the student is not found, inform the teacher
    else {
        printf("No student found with ID %d.\n", id);
    }
}

// Function to sort grades
void sortGrades(struct Student* students, int numStudents) {
    // Implement a sorting algorithm to sort the students based on their marks.
}



// Function to view grades (JUST EDIT)
void viewGrades(struct Student* students, int numStudents) {
    printf("DISPLAY STUDENTS' GRADES:\n");
    FILE* file = fopen("student_grades.txt", "r");
    
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        if (fscanf(file, "%s %d %d", students[i].name, &students[i].number, &students[i].marks) != 3) {
            printf("Error reading data from the file.\n");
            break;
        }
        printf("\n Student's Name: %s\nStudent's ID: %d \n Student's Grade: %d\n", students[i].name, students[i].number, students[i].marks);
    }
    fclose(file);
}


// Function to calculate statistics
void calculateStatistics(struct Student* students, int numStudents) {
    // Implement this function to calculate average, minimum, and maximum marks.
}

// Function for student search
void studentSearch(struct Student* students, int numStudents) {
    // Implement this function to allow the teacher to search for students based on name or number.
}

int main(void) {
    // Define the number of teachers and students
    int numTeachers = 2;
    int numStudents = 3;

    // Sample teacher and student data
    struct Teacher teachers[2] = {
        {"teacher1", "password1", 1},
        {"teacher2", "password2", 1}
    };

    struct Student students[3] = {
        {"StudentA", 1, 85},
        {"StudentB", 2, 92},
        {"StudentC", 3, 78}
    };

    int loggedInTeacher = -1;
    int loggedInStudent = -1;

    while (1) {
        int choice;
        printf("\nMAIN MENU:\n1. Teacher login\n2. Student login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char username[50];
            char password[50];
            printf("Enter teacher username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            loggedInTeacher = teacherLogin(teachers, numTeachers, username, password);
            if (loggedInTeacher != -1) {
                printf("Teacher login successful!\n");
                // Implement the teacher menu here
                while (1) {
                    // Implement the teacher menu options
                    int teacherChoice;
                    printf("\nTEACHER MENU:\n");
                    printf("1. Upload grades\n");
                    printf("2. Edit grades\n");
                    printf("3. Sort grades\n");
                    printf("4. View grades\n");
                    printf("5. Calculate statistics\n");
                    printf("6. Student search\n");
                    printf("7. Logout\n");
                    printf("Enter your choice: ");
                    scanf("%d", &teacherChoice);

                    switch (teacherChoice) {
                        case 1:
                            // Call the uploadGrades function to upload student grades
                            uploadGrades(students, numStudents);
                            break;

                        case 2:
                            // Call the editGrades function to edit student grades
                            editGrades(students, numStudents);
                            break;

                        case 3:
                            // Call the sortGrades function to sort student grades
                            sortGrades(students, numStudents);
                            break;

                        case 4:
                            // Call the viewGrades function to view all student grades
                            viewGrades(students, numStudents);
                            break;

                        case 5:
                            // Call the calculateStatistics function to calculate statistics
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
                            break;

                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                
            } else {
                printf("Invalid login credentials. Try again.\n");
            }
        } else if (choice == 2) {
            char username[50];
            char password[50];
            printf("Enter student name: ");
            scanf("%s", username);
            printf("Enter student number: ");
            scanf("%s", password);

            loggedInStudent = studentLogin(students, numStudents, username, password);
            if (loggedInStudent != -1) {
                printf("Student login successful!\n");
                // Implement the student menu here
                while (1) {
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
                            break;

                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
            } else {
                printf("Invalid login credentials. Try again.\n");
            }
        } else if (choice == 3) {
            break;  // Exit the program
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

