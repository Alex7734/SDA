#ifndef LAB1_STUDENT_H
#define LAB1_STUDENT_H
#include <stdio.h>

typedef enum{
    STATUS_ERROR_MEMORY = -1,
    STATUS_SUCCESS = 0,
    STATUS_ERROR = 1
} STATUS;

typedef struct _student student;

STATUS createStudent(FILE*, student);


#endif
