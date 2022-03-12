#include "Insertion.h"
#include "Quicksort.h"
#include "Merge.h"
#include "Shellsort.h"
#include "Timsort.h"
#include "Introsort.h"

// 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

int main(int argc, char **argv)
{

	string file = argv[1];

	Sort *quicksorter = new Quicksort(file);
	delete quicksorter;

	Sort *insertioner = new Insertion(file);
	delete insertioner;

	Sort *merger = new Merge(file);
	delete merger;

	Sort *shellsorter = new Shellsort(file);
	delete shellsorter;

	// Sort *timsorter = new Timsort(file);
	// delete timsorter;

	Sort *introsorter = new Introsort(file);
	delete introsorter;

	return 0;
}
