#include "Insertion.h"

Insertion::Insertion(string directory) : Sort(directory)
{
	insertioner();

}

/*
insertion sort: first element is already sorted
in place; sort subsequent elements by moving them into the right index
all elements that are larger than the current element
	will shift to the right by one index
*/
void Insertion::insertioner()
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
