#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_USERNAME 20
#define MAX_PASSWORD 20

// Structure to represent a student
typedef struct {
    char name[50];
    int rollNumber;
    float marks;
} Student;

// Structure to represent a user (teacher or student)
typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char role;  // 'T' for Teacher, 'S' for Student
} User;

// Function prototypes
void login(User* users, int numUsers, char role);
void teacherMenu(Student* students, int* numStudents);
void studentMenu(Student* students, int numStudents);

int main() {
    User users[] = {
        {"teacher1", "password1", 'T'},
        {"student1", "password2", 'S'},
        // Add more users as needed
    };
    int numUsers = sizeof(users) / sizeof(users[0]);

    Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;
    char role;

    do {
        printf("\nMain Menu\n");
        printf("1. Teacher Login\n");
        printf("2. Student Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                role = 'T';
                login(users, numUsers, role);
                teacherMenu(students, &numStudents);
                break;

            case 2:
                role = 'S';
                login(users, numUsers, role);
                studentMenu(students, numStudents);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to perform login
void login(User* users, int numUsers, char role) {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int isValid = 0;

    printf("\nEnter credentials:\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; ++i) {
        if (users[i].role == role && strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            isValid = 1;
            break;
        }
    }

    if (!isValid) {
        printf("Invalid credentials. Exiting...\n");
        exit(1);
    }
}

// Function to display the teacher menu
void teacherMenu(Student* students, int* numStudents) {
    int choice;

    do {
        printf("\nTeacher Menu\n");
        printf("1. Upload Grades\n");
        printf("2. Edit Grades\n");
        printf("3. Sort Grades\n");
        printf("4. View Grades\n");
        printf("5. Statistics\n");
        printf("6. Student Search\n");
        printf("7. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // Implement teacher features here

            case 1:
                // Upload Grades
                break;

            case 2:
                // Edit Grades
                break;

            case 3:
                // Sort Grades
                break;

            case 4:
                // View Grades
                break;

            case 5:
                // Statistics
                break;

            case 6:
                // Student Search
                break;

            case 7:
                printf("Logging out...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
}

// Function to display the student menu
void studentMenu(Student* students, int numStudents) {
    int choice;

    do {
        printf("\nStudent Menu\n");
        printf("1. View Grades\n");
        printf("2. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // Implement student features here

            case 1:
                // View Grades
                break;

            case 2:
                printf("Logging out...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);
}



// hello 