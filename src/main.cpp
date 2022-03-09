#include "Insertion.h"
#include "Quicksort.h"

int main(int argc, char** argv){
	
	// Insertion i(argv[1]);
	
	Sort *quicksort = new Quicksort();
	quicksort->sort(argv[1]);
	delete quicksort;

	return 0;

}
