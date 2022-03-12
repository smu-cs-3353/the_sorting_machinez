#include "Shellsort.h"
// referenced geeksforgeeks: https://www.geeksforgeeks.org/shellsort/

Shellsort::Shellsort(string directory) : Sort(directory)
{

    shellsorter();

}

void Shellsort::shellsorter()
{

    int size = input_vector.size();

    for (int gap = size / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < size; i ++)
        {
            int j = i;

            while (j >= gap && input_vector.at(j) < input_vector.at(j - 1))
            {
                swap(input_vector.at(j), input_vector.at(j - gap));
                j -= gap;
            }
        }
    }
}