#include "Merge.h"

Merge::Merge(string directory) : Sort(directory)
{

    int left = 0;
    int right = input_vector.size() - 1;
    merger(left, right);
}

/*
merge_sort: divide input vector by half recursively
    until there is just one element remaining; then merge
*/
void Merge::merger(int left, int right)
{

    if (left < right)
    {
        int middle = left + (right - left) / 2;
        merger(left, middle);
        merger(middle + 1, right);
        merge(left, middle, right);
    }
}

/*
merge: divides input vector into two separate arrays by index;
populates those arrays with same content as input vector;
then, merge those two arrays back into input vector in sorted order
*/
void Merge::merge(int left, int middle, int right)
{

    int a_length = middle - left + 1;
    int b_length = right - middle;

    int arr_a[a_length];
    int arr_b[b_length];

    for (int i = 0; i < a_length; i++)
        arr_a[i] = input_vector.at(left + i);

    for (int i = 0; i < b_length; i++)
        arr_b[i] = input_vector.at(middle + 1 + i);

    // a is count for arr_a, b for arr_b, result for input_vector
    int a = 0, b = 0, result = left;

    while (a < a_length && b < b_length)
    {
        if (arr_a[a] <= arr_b[b])
            input_vector.at(result++) = arr_a[a++];
        else
            input_vector.at(result++) = arr_b[b++];
    }
    while (a < a_length)
        input_vector.at(result++) = arr_a[a++];

    while (b < b_length)
        input_vector.at(result++) = arr_b[b++];
}