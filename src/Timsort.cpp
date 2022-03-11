#include "Timsort.h"

Timsort::Timsort(string directory) : Sort(directory){

    timsorter();
}

void Timsort::timsorter(){

    int RUN = 5;
    int size = input_vector.size();

    for(int i = 0; i < size; i += RUN){

        int left = i;
        int right = 0;
        //insertion();
    }
}