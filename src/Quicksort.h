#ifndef QUICKSORT_H__
#define QUICKSORT_H__

#include <iostream>
#include <string>

#include "Sort.h"

class Quicksort : public Sort
{
public:
	/*
	Quicksort constructor:
	base class(Sort) constructor is called to process input file,
	*/
	Quicksort(string);
	void quicksorter(int, int);
	int partition(int, int);
};

#endif