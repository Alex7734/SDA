#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_GRADES 3

typedef struct _student {
    char *firstName;
    char *lastName;
    unsigned char age;
    int *grades;
    float average;
} Student;

char* readString() {
    int size = 8;
    char* str = (char *) malloc(size);
    char c;
    int i = 0;


    while ((c = (char)getchar()) != '\n') {
        if (i==size){
            str = (char *) realloc(str, size*2);
        }
        if (str == NULL) {
            perror("realloc");
            exit(1);
        }

        str[i++] = c;
    }

    str[i] = '\0';
    return str;
}

STATUS createStudent(FILE *fin, Student **student) {
    // Create Student
    Student* stud = (Student *)malloc(sizeof(Student));

    if (stud == nullptr) {
        return STATUS_ERROR_MEMORY;
    }

    // Realized there may be padding here too, must be a way to not allow padding to create
    memset(stud, 0, sizeof(Student));

    // Add lastName
    char* lastName = readString();

    stud->lastName = (char *) malloc(strlen(lastName));
    if (stud->lastName == nullptr) {
        return STATUS_ERROR_MEMORY;
    }

    memcpy(stud->lastName, lastName, strlen(lastName) + 1);
    stud->lastName[strlen(stud->lastName)] = '\0';

    // Add firstName
    char* firstName = readString();

    stud->firstName = (char *) malloc(strlen(firstName));
    if (stud->firstName == nullptr) {
        return STATUS_ERROR_MEMORY;
    }

    memcpy(stud->firstName, firstName, strlen(firstName) + 1);
    stud->firstName[strlen(stud->firstName)] = '\0';

    // Add age
    unsigned age = 0;
    if (fscanf(fin, "%d", &age)){
        stud->age = (char) age;
    } else {
        return STATUS_ERROR;
    }

    // Add Grades
    stud->grades = (int *) malloc(sizeof(int) * NO_GRADES);
    if (stud->grades == nullptr) {
        return STATUS_ERROR_MEMORY;
    }

    int sum = 0;
    for (int i = 0; i < NO_GRADES; i++) {
        fscanf(fin, "%d", &stud->grades[i]);
        sum += stud->grades[i];
    }

    // Calculate averege
    stud->average = (float) sum / NO_GRADES;

    // Return student
    *student = stud;
    return STATUS_SUCCESS;
}

// I have to be honest the next two fucntions I just left like this from the source file I recived :)

// prints the student to stdout
void printStudent(Student *student) {
    printf("Name: %s %s\nAge: %d\nAverage: %f\n", student->firstName, student->lastName, student->age, student->average);
}

// prints the averege to stdout
void printAverage(Student *student) {
    printf("%s %s %f\n", student->firstName, student->lastName, student->average);
}


// last point, incrementing each student by one
STATUS incGrades(Student *student) {
    int sum = 0;

    for (int i = 0; i < NO_GRADES; i++) {
        if (student->grades[i] < 10) {
            student->grades[i]++;
        }

        sum += student->grades[i];
    }

    student->average = (float) sum / NO_GRADES;
    return STATUS_SUCCESS;
};