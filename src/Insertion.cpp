#include "Insertion.h"

Insertion::Insertion(string int_directory){
	
		ifstream filee(directory);
		
		if(!filee.is_open())
			cout << "input file can't open" << endl;

		
		//get number_lines in input file
		int num_lines = std::count(istreambuf_iterator<int>(filee), istreambuf_iterator<int>());
		num_lines += 2;
		cout << (num_lines + 2) << endl;
		int int_array[num_lines ];
				
		
		/*
		for(int i = 0; i < num_lines; i++){
			int temp;
			filee >> temp;
			cout << temp << endl;
			
		}
		*/
		
		/*
		int number = 0;
		int temp = 0;
		while(filee >> temp){
			number++;			
		}
		cout << number << endl;
		
		*/
		
		/*
		for(int i : int_array)
			cout << i << endl;
		*/
}
/*
start from index = 0; then insert each subsequent index in the right location
*/
Insertion::int_insertion(int[] int_array, int size){
	
	for(int i = 1; i < size; i++){
		
		int current = int_array[i];
		
		while(i >= 0 && int_array[i - 1] > current){
			int_array[i - 1] = current;
			current = int_array[i - 1];		
			i--;
		}	
	}	
}