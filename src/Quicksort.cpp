#include "Quicksort.h"

Quicksort::Quicksort(string directory) : Sort(directory){

    cout << "-----------called quicksort---------" << endl;
    cout << left << " blablabla" << right << endl;

    string left = 0;
    string right = input_vector.size() - 1;
    cout << left << " blablabla" << right << endl;
    quicksorter1(left, right);
}

/*
quicksorter1:
chooses random pivot, then swaps pivot with the rightmost element
maintain a window of elements that are < pivot element; 
    increment window
*/
void Quicksort::quicksorter1(string left, string right){
    
    if(left < right){
        int pivot = partition1(left, right);
        quicksorter(left, pivot - 1);
        quicksorter(pivot + 1, right);
    }
}

int Quicksort::partition1(string left, string right){
    
    int random = left + (rand() % (right - left + 1));
    cout << random << endl;
    swap(input_vector.at(random), input_vector.at(right));

    int i = left - 1;
    for(int j = left; j <= right - 1; j++){

    }
    return 5;
}


