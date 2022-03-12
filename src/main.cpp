#include "Insertion.h"
#include "Quicksort.h"
#include "Merge.h"
#include "Shellsort.h"
#include "Timsort.h"
#include "Introsort.h"
#include <chrono>

// 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

int main(int argc, char **argv)
{
	typedef chrono::steady_clock my_clock;
	my_clock::time_point start;
	my_clock::time_point end;
	chrono::duration<double> time{};

	string file = argv[1];

	/*
	quicksort timing
	*/
	start = my_clock::now();

	Sort *quicksorter = new Quicksort(file);
	delete quicksorter;

	end = my_clock::now();
	time = end - start;
	cout << "quicksort time: " << time.count() << endl;
	/*
	insertionsort timing
	*/
	start = my_clock::now();

	Sort *insertioner = new Insertion(file);
	delete insertioner;

	end = my_clock::now();
	time = end - start;
	cout << "insertion time: " << time.count() << endl;

	/*
	mergesort timing
	*/
	start = my_clock::now();

	Sort *merger = new Merge(file);
	delete merger;

	end = my_clock::now();
	time = end - start;
	cout << "merge time: " << time.count() << endl;

	/*
	shellsort timing
	*/
	start = my_clock::now();

	Sort *shellsorter = new Shellsort(file);
	delete shellsorter;

	end = my_clock::now();

	time = end - start;
	cout << "shell time: " << time.count() << endl;

	/*
	timsort timing
	*/
	// start = my_clock::now();

	// Sort *timsorter = new Timsort(file);
	// delete timsorter;

	// end = my_clock::now();
	// time = end - start;
	// cout << "tim time: " << time.count() << endl;

	/*
	introsort timing
	*/

	start = my_clock::now();

	Sort *introsorter = new Introsort(file);
	delete introsorter;

	end = my_clock::now();
	time = end - start;
	cout << "intro time: " << time.count() << endl;

	return 0;
}
