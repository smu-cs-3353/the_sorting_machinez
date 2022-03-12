#include "Introsort.h"
#include "Insertion.h"
#include <algorithm>

Introsort::Introsort(string directory) : Sort(directory)
{
    introsorter();

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
void Introsort::introsorter()
{

    int size = input_vector.size();
    int limit = 2 * log(size);

    int left = 0, right = size - 1;
    intro_recurring(left, right, limit);
}

void Introsort::intro_recurring(int left, int right, int limit)
{

    int size = right - left + 1;

    if (size < 16)
    {
        insertioner(left, right);
    }
    else if (limit == 0)
    {
        heap_sort(left, right);
    }
    else
    {
        int pivot = partition(left, right);
        intro_recurring(left, pivot - 1, limit - 1);
        intro_recurring(pivot + 1, right, limit - 1);
    }
}

/*
insertion sort if size < 16
*/
void Introsort::insertioner(int left, int right)
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

/*
heap sort if recur call stack > 2logn
*/
void Introsort::heap_sort(int left, int right)
{
    int size = right - left + 1;
    build_heap(left, right);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(input_vector.at(0), input_vector.at(i));
        heaper(i, 0);
    }
}

void Introsort::build_heap(int left, int right)
{
    int size = right - left + 1;

    for (int i = (size - 2) / 2; i >= 0; i--)
        heaper(size, i);
}

void Introsort::heaper(int size, int i)
{
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (input_vector.at(left) > input_vector.at(largest) && left < size)
    {
        largest = left;
    }

    if (input_vector.at(right) > input_vector.at(largest) && right < size)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(input_vector.at(i), input_vector.at(largest));
        heaper(size, largest);
    }
}

/*
quicksort implementation
*/
int Introsort::partition(int left, int right)
{
    // generate random pivot, then swap it with last element
    int random = left + (rand() % (right - left + 1));
    swap(input_vector.at(random), input_vector.at(right));

    // pivot element = rightmost element
    int pivot = input_vector[right];

    // maintain window of elements < pivot element
    int i = left - 1;

    /*
    loop thru all elements, if an element that is < pivot is found,
        increment the window, and swap that element into the window
    */
    for (int j = left; j <= right - 1; j++)
    {
        if (input_vector.at(j) < pivot)
        {
            i++;
            swap(input_vector.at(j), input_vector.at(i));
        }
    }

    // swap pivot element into right position,
    swap(input_vector.at(i + 1), input_vector.at(right));
    // return pivot element
    return (i + 1);
}
