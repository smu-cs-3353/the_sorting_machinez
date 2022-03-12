#include "Introsort.h"
#include "Insertion.h"
#include <algorithm>

Introsort::Introsort(string directory) : Sort(directory)
{
    cout << "-----introsort!-----" << endl;
    for (int s : input_vector) // test print
        cout << s << endl;

    introsorter();

    cout << "-----introsort done!-----" << endl;
    for (int s : input_vector) // test print
        cout << s << endl;
}
/*
introsort: hybrid of quicksort, heapsort, insertion sort
reference: https://www.geeksforgeeks.org/know-your-sorting-algorithm-set-2-introsort-cs-sorting-weapon/
1. create partition
2.
    1) if partition results in recursion call stack depth > 2log(n),
        do heap sort
    2) if partition size < 16, do insertion sort
    3) otherwise, do quicksort
*/
void Introsort::introsorter(){
    int size = input_vector.size();

    if(size < 16){
        insertioner();
    }

}

void Introsort::insertioner()
{
	int size = input_vector.size();

	for (int i = 1; i < size; i++)
	{
		// current element = element that will be shifted into right position
		int current = input_vector.at(i);
		int j = i - 1;

		while (j >= 0 && input_vector.at(j) > current)
		{

			input_vector.at(j + 1) = input_vector.at(j);
			j--;
		}
		input_vector.at(j + 1) = current;
	}
}
