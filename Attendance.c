#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to store student details
struct Student {
    int roll;
    char name[50];
    int attendance; // number of days present
    int totalDays;  // total working days
};

int main() {
    struct Student s[MAX];
    int choice, i, n = 0;

    while (1) {
        printf("\n=== College Attendance Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. View Attendance Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add Student
            printf("Enter student roll number: ");
            scanf("%d", &s[n].roll);
            printf("Enter student name: ");
            scanf("%s", s[n].name);

            s[n].attendance = 0;
            s[n].totalDays = 0;

            printf("Student added successfully!\n");
            n++;
        }

        else if (choice == 2) {
            // Mark Attendance
            int roll, found = -1;
            printf("Enter roll number to mark attendance: ");
            scanf("%d", &roll);

            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                printf("Student not found!\n");
            } else {
                char status;
                printf("\nMark Present (P) or Absent (A): ");
                scanf(" %c", &status);  // space before %c avoids input issues

                s[found].totalDays++;

                if (status == 'P' || status == 'p') {
                    s[found].attendance++;
                    printf("Attendance marked as Present.\n");
                } else {
                    printf("Attendance marked as Absent.\n");
                }
            }
        }

        else if (choice == 3) {
            // Attendance Report
            printf("\n--- Attendance Report ---\n");
            printf("Roll\tName\tPresent\tTotal\tPercentage\n");

            for (i = 0; i < n; i++) {
                float percentage = 0;
                if (s[i].totalDays > 0) {
                    percentage = (s[i].attendance * 100.0) / s[i].totalDays;
                }

                printf("%d\t%s\t%d\t%d\t%.2f%%\n",
                       s[i].roll, s[i].name,
                       s[i].attendance, s[i].totalDays,
                       percentage);
            }
        }

        else if (choice == 4) {
            printf("Exiting program...\n");
            break;
        }

        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
