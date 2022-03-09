#include "Quicksort.h"

void Quicksort::sort(string string_directory){
    Sort.sort();
    vector<string> input_vector = get_input();

    cout << "inside quicksort" << input_vector.size() << endl;


    for(string s : input_vector)
        cout << s << endl;

}
