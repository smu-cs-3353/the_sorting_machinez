#include "Insertion.h"
#include "Quicksort.h"

//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

int main(int argc, char** argv){
	
	string file = argv[1];

	Sort *quicksort = new Quicksort(file);
	//quicksort->sort(argv[1]);

	delete quicksort;

	return 0;

}
