#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "students.csv"

struct Student {
    int roll;
    char name[50];
    int age;
    char course[50];
    char department[50];
};

// Function prototypes
int rollExists(int roll);
int isValidName(char *name);
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Database Manager =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Check if roll number already exists in file
int rollExists(int roll) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return 0;

    struct Student s;
    while (fscanf(fp, "%d,%[^,],%d,%[^,],%[^\n]\n",
                  &s.roll, s.name, &s.age, s.course, s.department) == 5) {
        if (s.roll == roll) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Check if name contains only alphabets
int isValidName(char *name) {
    for (int i = 0; name[i]; i++) {
        if (!isalpha(name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}

void addStudent() {
    struct Student s;

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    if (rollExists(s.roll)) {
        printf("Error: Roll Number already exists!\n");
        return;
    }

    printf("Enter Name: ");
    getchar();
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    if (!isValidName(s.name)) {
        printf("Error: Name must contain only alphabets!\n");
        return;
    }

    printf("Enter Age: ");
    scanf("%d", &s.age);

    if (s.age < 10 || s.age > 100) {
        printf("Error: Age is not valid!\n");
        return;
    }

    printf("Enter Course: ");
    getchar();
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(s.department, sizeof(s.department), stdin);
    s.department[strcspn(s.department, "\n")] = '\0';

    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%d,%s,%d,%s,%s\n", s.roll, s.name, s.age, s.course, s.department);
    fclose(fp);

    printf("Student added successfully!\n");
}

void viewStudents() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No data available.\n");
        return;
    }

    struct Student s;

    printf("\n%-10s %-20s %-5s %-15s %-15s\n", "Roll", "Name", "Age", "Course", "Department");
    printf("--------------------------------------------------------------------------\n");

    while (fscanf(fp, "%d,%[^,],%d,%[^,],%[^\n]\n",
                  &s.roll, s.name, &s.age, s.course, s.department) == 5) {
        printf("%-10d %-20s %-5d %-15s %-15s\n",
               s.roll, s.name, s.age, s.course, s.department);
    }

    fclose(fp);
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No data available.\n");
        return;
    }

    struct Student s;
    int found = 0;

    while (fscanf(fp, "%d,%[^,],%d,%[^,],%[^\n]\n",
                  &s.roll, s.name, &s.age, s.course, s.department) == 5) {
        if (s.roll == roll) {
            printf("\nRecord Found:\n");
            printf("Roll: %d\nName: %s\nAge: %d\nCourse: %s\nDepartment: %s\n",
                   s.roll, s.name, s.age, s.course, s.department);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }

    fclose(fp);
}

void updateStudent() {
    int roll;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No data available.\n");
        return;
    }

    FILE *temp = fopen("temp.csv", "w");
    struct Student s;
    int found = 0;

    while (fscanf(fp, "%d,%[^,],%d,%[^,],%[^\n]\n",
                  &s.roll, s.name, &s.age, s.course, s.department) == 5) {
        if (s.roll == roll) {
            found = 1;

            printf("Enter new Name (press enter to skip): ");
            getchar();
            char newName[50];
            fgets(newName, 50, stdin);
            if (newName[0] != '\n') {
                newName[strcspn(newName, "\n")] = '\0';
                strcpy(s.name, newName);
            }

            printf("Enter new Age (0 to skip): ");
            int newAge;
            scanf("%d", &newAge);
            if (newAge != 0) s.age = newAge;

            printf("Enter new Course (press enter to skip): ");
            getchar();
            char newCourse[50];
            fgets(newCourse, 50, stdin);
            if (newCourse[0] != '\n') {
                newCourse[strcspn(newCourse, "\n")] = '\0';
                strcpy(s.course, newCourse);
            }

            printf("Enter new Department (press enter to skip): ");
            char newDept[50];
            fgets(newDept, 50, stdin);
            if (newDept[0] != '\n') {
                newDept[strcspn(newDept, "\n")] = '\0';
                strcpy(s.department, newDept);
            }
        }

        fprintf(temp, "%d,%s,%d,%s,%s\n",
                s.roll, s.name, s.age, s.course, s.department);
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        printf("Student not found!\n");
        remove("temp.csv");
    } else {
        remove(FILE_NAME);
        rename("temp.csv", FILE_NAME);
        printf("Record updated successfully!\n");
    }
}

void deleteStudent() {
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No data available.\n");
        return;
    }

    FILE *temp = fopen("temp.csv", "w");
    struct Student s;
    int found = 0;

    while (fscanf(fp, "%d,%[^,],%d,%[^,],%[^\n]\n",
                  &s.roll, s.name, &s.age, s.course, s.department) == 5) {
        if (s.roll == roll) {
            found = 1;
            continue; // Skip copying the record → delete
        }

        fprintf(temp, "%d,%s,%d,%s,%s\n",
                s.roll, s.name, s.age, s.course, s.department);
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        printf("Student not found!\n");
        remove("temp.csv");
    } else {
        remove(FILE_NAME);
        rename("temp.csv", FILE_NAME);
        printf("Record deleted successfully!\n");
    }
}