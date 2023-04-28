cmake_minimum_required(VERSION 3.24)
project(lab9 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab9 int_stack.c int_stack.h stack.c stack.h single_linked_list.c single_linked_list.h double_linked_list.c double_linked_list.h doneAtLab.c graph.c graph.h queue.c queue.h int_queue.c int_queue.h main.c)
