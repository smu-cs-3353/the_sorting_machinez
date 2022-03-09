#include "Insertion.h"

Insertion::Insertion(string directory){
	
	ifstream filee(directory);
		
	if(!filee.is_open())
		cout << "input file can't open" << endl;
	
	vector<string> input_vector;
	string temp;
	
	while(!filee.eof()){
		filee >> temp;
		input_vector.push_back(temp);
	}
	
	
		
		
}


