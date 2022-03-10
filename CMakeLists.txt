cmake_minimum_required(VERSION 3.16)
project(the_sorting_machinez)

add_executable(the_sorting_machinez src/main.cpp src/Sort.h 
    src/Quicksort.h src/Quicksort.cpp src/Insertion.cpp src/Insertion.h
    src/Merge.h src/Merge.cpp src/Shellsort.h src/Shellsort.cpp)

