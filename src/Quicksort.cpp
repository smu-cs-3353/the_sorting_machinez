#include "Quicksort.h"

Quicksort::Quicksort(string directory) : Sort(directory)
{

    int left = 0;
    int right = input_vector.size() - 1;

    for (string s : input_vector)
        cout << s << endl;

    quicksorter1(left, right);

    cout << "done" << endl;
    for (string s : input_vector)
        cout << s << endl;
}

/*
quicksorter1:
chooses random pivot, then swaps pivot with the rightmost element
maintain a window of elements that consists of elements < pivot element;
*/
void Quicksort::quicksorter1(int left, int right)
{
    if (left < right)
    {
        int pivot = partition1(left, right);
        quicksorter1(left, pivot - 1);
        quicksorter1(pivot + 1, right);
    }
}

int Quicksort::partition1(int left, int right)
{
    // generate random pivot, then swap it with last element
    int random = left + (rand() % (right - left + 1));
    swap(input_vector.at(random), input_vector.at(right));

    // pivot element = rightmost element
    string pivot = input_vector[right];

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
