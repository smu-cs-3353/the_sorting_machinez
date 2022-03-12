#include "Timsort.h"

/*
file input to input_vector done in base class 'Sort'
*/
Timsort::Timsort(string directory) : Sort(directory)
{
    cout << "-----timsort!-----" << endl;
    for (int s : input_vector) // test print
        cout << s << endl;

    timsorter();

    cout << "-----timsort done-----" << endl;
    for (int s : input_vector) // test print
        cout << s << endl;
}

/*
a combination of insertion sort and merge sort; divide input_array
    into many smaller subarrays, and insertion sort each subarray
after each subarray is sorted, merge subarrays
*/
void Timsort::timsorter()
{
    int sub_size = 5; // subarray size
    int size = input_vector.size();

    for (int i = 0; i < size; i += sub_size)
    {
        int left = i;
        int right = i + sub_size;
        insertion(left, right);
    }

    while (sub_size < size)
    {
        cout << "HERE" << endl;
        for (int i = 0; i < size; i += 2 * sub_size)
        {

            int left = i;
            int right = i + sub_size;
            int middle = left + (right - left) / 2;
            merge(left, middle, right);
        }
        sub_size *= 2;
    }
}
/*
first element is sorted; go to next element and place in right position
in sorted part of array
*/
void Timsort::insertion(int left, int right)
{
    int size = right - left + 1;
    for (int i = left + 1; i < size; i++)
    {
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

void Timsort::merge(int left, int middle, int right)
{

    int size_a = middle - left + 1;
    int size_b = right - middle;
    int arr_a[size_a];
    int arr_b[size_b];

    // populate arr_a and arr_b with contents of input_vector range
    for (int i = 0; i < size_a; i++)
        arr_a[i] = input_vector.at(left + i);
    for (int i = 0; i < size_b; i++)
        arr_b[i] = input_vector.at(middle + 1 + i);

    // merge arr_a and arr_b, in ascending order
    int a = 0, b = 0, result = left;

    while (a < size_a && b < size_b)
    {
        if (arr_a[a] <= arr_b[b])
            input_vector.at(result++) = arr_a[a++];
        else
            input_vector.at(result++) = arr_b[b++];
    }
    // either arr_a or arr_b is finished first;
    while (a < size_a)
        input_vector.at(result++) = arr_a[a++];
    while (b < size_b)
        input_vector.at(result++) = arr_b[b++];
}