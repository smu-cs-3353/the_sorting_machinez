#ifndef TIMSORT_H__
#define TIMSORT_H__

#include "Sort.h"

class Timsort : public Sort
{

    public:
    Timsort(string);
    void timsorter();
    void insertion();
};
#endif