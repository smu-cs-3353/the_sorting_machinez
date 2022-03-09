import random 

arr = set()

size = 100

while len(arr) < size:
    arr.add(random.randint(1, 1000000))

arr = list(arr)
# arr.sort()

amount_to_sort = int(0.6 * size)

list1 = arr[:amount_to_sort]
list2 = arr[amount_to_sort:]

list1.sort()

arr = list1 + list2

file = open("integer_data.txt", "w")

for num in list1:
    file.writelines(str(num) + "\n")

file.writelines("\n\n")

for num in list2:
    file.writelines(str(num) + "\n")

####


dupes = []

dupe_percentage = 0.2

num_dupes = int(size * dupe_percentage)

dupe_number = random.randint(1, 1000000)

for i in range(num_dupes):
    dupes.append(dupe_number)

num_remaining = int(size * (1 - dupe_percentage))

non_dupes = set()

for i in range(num_remaining):
    non_dupes.add(random.randint(1, 1000000))

non_dupes = list(non_dupes)

final_list = non_dupes + dupes

random.shuffle(final_list)

file2 = open("integer_duplicates.txt", "w")

for num in final_list:
    file2.writelines(str(num) + "\n")


    
