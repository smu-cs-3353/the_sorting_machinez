#include "Shellsort.h"
// referenced geeksforgeeks: https://www.geeksforgeeks.org/shellsort/

Shellsort::Shellsort(string directory) : Sort(directory)
{
    cout << "-----shellsort!-----" << endl;
    for (int s : input_vector) // test print
        cout << s << endl;

    shellsorter();

    cout << "-----shellsort done-----" << endl;
    for (int s : input_vector) // test print
        cout << s << endl;
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