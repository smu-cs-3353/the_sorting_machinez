#include "Insertion.h"
#include "Quicksort.h"
#include "Merge.h"

// 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

int main(int argc, char **argv)
{

	string file = argv[1];

	// Sort *quicksorter = new Quicksort(file);
	// delete quicksorter;

	// Sort *insertioner = new Insertion(file);
	// delete insertioner;

	Sort *merger = new Merge(file);
	delete merger;

	return 0;
}
