#ifndef QUICKSORT_H__
#define QUICKSORT_H__

#include <iostream>
#include <string>
#include <stdlib.h> //rand()
#include <algorithm> //swap()

#include "Sort.h"

using namespace std;

class Quicksort : public Sort
{


public:
	Quicksort(string); 	
	void quicksorter1(int, int);
	int partition1(int, int);


};

#endif