#ifndef MERGE_H__
#define MERGE_H__

#include "Sort.h"

class Merge : public Sort
{

public:
    //constructor, merge_sort, and merge function
    Merge(string);
    void merger(int, int);
    void merge(int, int, int);
}

#endif