#ifndef SORT_H__
#define SORT_H__
#include <vector>
#include <fstream>

using namespace std;

class Sort
{
protected:
    vector<string> input_vector;
    
public:
    virtual void sort(string directory)
    {
        ifstream filee(directory);

        if (!filee.is_open())
            cout << "input file can't open" << endl;

        string temp;

        cout << "hi" << endl;

        while (!filee.eof())
        {
            filee >> temp;
            input_vector.push_back(temp);
        }

        for (string s : input_vector)
            cout << s << endl;
    }

    vector<string> get_input(){
        return input_vector;
    }
};

#endif