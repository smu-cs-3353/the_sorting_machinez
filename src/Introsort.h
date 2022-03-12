#ifndef INTROSORT_H__
#define INTROSORT_H__

#include "Sort.h"

class Introsort : public Sort
{

public:
    Introsort(string);
    void introsorter();
    void intro_recurring(int, int, int);

    void insertioner(int, int); //insertion_sort if size < 16

    void heap_sort(int, int); //heap sort if recur call stack > 2logn
    void build_heap(int, int);
    void heaper(int, int);

    void quick_sort(int, int);
    int partition(int, int);



};
#endif