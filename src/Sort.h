#ifndef SORT_H__
#define SORT_H__
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h> //rand()
#include <math.h> //log()
#include <algorithm> //make_heap

using namespace std;

class Sort
{
protected:
    vector<int> input_vector;
    // vector<string> input_vector;

public:
    /*
    base class constructor: process file input -> input_vector
    */
    Sort(string directory)
    {
        ifstream filee(directory);

        if (!filee.is_open())
            cout << "input file can't open" << endl;

        int temp;

        while (!filee.eof())
        {
            filee >> temp;
            input_vector.push_back(temp);
        }
    
    }

    // virtual void sort(string directory)
};

#endif