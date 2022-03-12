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
```
quicksort time: 0.00022143
insertion time: 0.000155453
merge time: 8.529e-05
shell time: 0.000230311
tim time: 9.7e-08
intro time: 0.000127488
```

Output will contain time taken for each sorting algorithm.

### Sample Input
```
123435
234546
345456
456678
234456
```
Sample of input text file.

## Analysis of Sorting Algorithms
```
Insertion Sort:
insertion sort is an in place and stable sorting algorithm, meaning that it doesn't use extra space in the sorting process, and original order is retained if there are two equivalent elements. Insertion sort is popular for small arrays; python's Timsort is a hybrid sorting algorithm that uses insertion sort for small arrays; Introsort is another hybrid algorithm that uses insertion sort for small subarrays. 
Insertion sort is implemented by running through each element in ascending order, placing each element in the right place in the sorted portion of the array. In the process, elements that are out of order are shifted forward by one; that way, the current element can be inserted to its right place. In the best case, insertion sort has a time complexity of O(n). No exchange of elements would be needed if the array was already in ascending order. The worst case of O(n^2) happens when the array is in reverse order, since a maximum number of exchanges would be required for each element.
```
```
Merge Sort:
merge sort is a divide and conquer algorithm, recursively implemented by calling the left and right subtree until the there is just one element remaining; then, the merge function is called and the array becomes sorted. Merge Sort has a time complexity of O(nlogn), and requires O(n) extra space in the merge function. In general, merge sort is outperformed by quicksort, however, merge sort's worst possible time complexity is O(nlogn) while quicksort can have a worse time complexity if the pivot is poorly chosen.
```
```
Quicksort:
quicksort is a divide and conquer algorithm, recursively implemented by selecting a pivot and partitioning. Quicksort only requires extra space for the recursion call stack, and is used in Introsort, a hybrid sorting algorithm. Unless the worst case happens and the recursion call stack is maximized to result in a time complexity of O(n^2), quicksort is considered faster than merge sort.
```
```
Shellsort:
shellsort is an optimization of insertion sort. in insertion sort, the worse case can become O(n^2) when the minimum elements are at the way end of the array.
```
```
Timsort:
timsort is a hybrid of insertion sort and merge sort. Insertion sort works really well for small dataset sizes, but becomes less efficient as dataset size grows since it if a small element was at the end of the array, then all elements before it would need to moved forward by one index. In order to avoid that inefficiency, timsort does recursively does insertion sort on smaller subarrays, then merges those subarrays. Timsort does recursive sorting in a tree-like recursive structure, and has a O(nlogn) time complexity.
```
```
Introsort:
a hybrid of quicksort, insertion sort, and heap sort. Introsort is implemented by partitioning recursively, and each subarray is sorted according to size. If the subarray is small, then insertion sort is chosen. If the subarray will result in a long recursion call stack(and therefore be inefficiently O(n^2) with quicksort), then heap sort is used. Otherwise, quicksort is implemented.
The heap sort that is used in introsort is like a variation of selection sort using the heap data structure. To use heap sort, first the dataset must be put into heap structure, then the sorting process becomes an O(nlogn) operation.
```



