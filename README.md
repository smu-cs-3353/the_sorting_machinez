# The Sorting Machinez

## Project Statement
Implement six sorting algorithms, and generate data to test its performance. The sorting algorithms are as follows:
- insertion sort
- randomized quicksort
- merge sort
- shellsort
- introsort
- timsort

## Data
I generated five categories of data, and each category is done in six dataset sizes. The categories are as follows:
- randomized dataset without duplicates
- dataset without duplicates in ascending order
- dataset without duplicates, 60% data is in ascending order
- randomized dataset with 20% duplicates
- randomized dataset with 40% duplicates

For datasets without duplicates, a random number generator was used to create a set, and the numbers varied between one and a million. datasets were created in ascending order by using the sort() function. Datasets that were partly sorted were created by appending a sorted sublist to an unsorted sublist. Randomized datasets with a percentage of duplicates were created by forming a list of duplicates, then joining that list to a set of nonduplicates(by casting set to list), then performing the shuffle() operation for randomized order.

String data had little difference, only that the randomly generated numbers varied between 65 and 90: the ASCii representation of uppercase alphabets. The randomly generated numbers were cast to characters using the chr() method.

The python data generation script is located in the data folder of the repository.

## Implementation, Build, Input/Output
Data file input is read in through a command line argument, then the file directory is passed to the base class ```sort```, where file input is processed into an input vector. All subclasses(the different sorting algorithms) inherit from the ```sort``` class and have protected access to the input vector.

### How to Build
Clone the repository, then navigate to the project build folder and build cmake. After the executable is created, run the executable.
```
project/build$ cmake ..
project/build$ cmake --build .
project/build$ ./project ../input_file.txt
```
### Sample Output
![image](https://user-images.githubusercontent.com/89363825/158005586-6f18b716-171f-41a5-82fb-e76bb27ed5b9.png) | =100x100)

Output will contain time taken for each sorting algorithm.

### Sample Input


