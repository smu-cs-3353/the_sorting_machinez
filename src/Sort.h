#ifndef SORT_H__
#define SORT_H__
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h> //rand()

using namespace std;

class Sort
{
protected:
    vector<string> input_vector;

public:
    /*
    base class constructor: process file input -> input_vector
    */
    Sort(string directory)
    {
        cout << "--------called base class----------" << endl;

        ifstream filee(directory);

        if (!filee.is_open())
            cout << "input file can't open" << endl;

        string temp;

        while (!filee.eof())
        {
            filee >> temp;
            input_vector.push_back(temp);
        }
    }

    // virtual void sort(string directory)
};

#endif