#include "Quicksort.h"

Quicksort::Quicksort(string directory) : Sort(directory)
{
    cout << "-----quicksort!-----" << endl;
    for (int s : input_vector) //test print
        cout << s << endl;

    int left = 0;
    int right = input_vector.size() - 1;

    quicksorter(left, right);

    cout << "-----quicksort done-----" << endl;
    for (int s : input_vector)  //test print
        cout << s << endl;
}

/*
quicksorter:
chooses random pivot, then swaps pivot with the rightmost element
maintain a window of elements that consists of elements < pivot element;
partition left and right recursively until left index crosses the right index
*/
void Quicksort::quicksorter(int left, int right)
{
    if (left < right)
    {
        int pivot = partition(left, right);
        quicksorter(left, pivot - 1);
        quicksorter(pivot + 1, right);
    }
}

int Quicksort::partition(int left, int right)
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
