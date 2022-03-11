#dataset sizes: 10, 100, 1000, 10 000, 100 000, 1 000 000
#1. no duplicates, ascending order
#2. no duplicates, 60% ascending order
#3. 20% duplicates
#4. 40% duplocates

import random 

# arr = []

def no_dupes(s, type):
    arr = set() #create set so there is no duplicates

    if (type == 'integer'):
        while len(arr) < s: #generate random numbers between 1 and 100000, put into set
            arr.add(random.randint(1, 1000000))
    
    if (type == 'string'):
        while len(arr) < s:
            string = ''
            for c in range(3):
                string += chr(random.randint(65, 90))
            arr.add(string)

    arr = list(arr)
    return arr

def no_dupes_ascending(s, type):
    arr = no_dupes(s, type)
    arr.sort()
    return arr

def no_dupes_60ascending(s, type):
        
    amount_to_sort = int(0.6 * s)
        
    arr = no_dupes_ascending(s, type)

    list1 = arr[:amount_to_sort]
    list2 = arr[amount_to_sort:]

    list1.sort()

    arr = list1 + list2
    return arr

def duplicate(s, dupe_percentage, type):
    dupes = []

    num_dupes = int(s * dupe_percentage)

    if (type == 'integer'):
        dupe_number = random.randint(1, 10000000)

        for i in range(num_dupes):
            dupes.append(dupe_number)
    
    if (type == 'string'):
        dupe_string = ''
        for c in range(3):
            dupe_string += chr(random.randint(65, 90))
        
        for i in range(num_dupes):
            dupes.append(dupe_string)

    num_remaining = int(s * (1 - dupe_percentage))

    non_dupes = set()

    if (type == 'integer'):
        while len(non_dupes) < num_remaining:
            non_dupes.add(random.randint(1, 10000000))

    if (type == 'string'):
        while len(non_dupes) < num_remaining:
            non_dupe_string = ''
            for c in range(3):
                non_dupe_string += chr(random.randint(65, 90))
            non_dupes.add(non_dupe_string)

    non_dupes = list(non_dupes)

    final_list = non_dupes + dupes

    random.shuffle(final_list)

    return final_list

def write_to_file(arr, file_name):
    file = open(file_name, "w")

    for num in arr:
        file.writelines(str(num) + "\n")
#main
sizes = {10, 100, 500, 1000, 5000, 10000}

for s in sizes:

    arr = []

    type = "string"
    #type = "integer"

    arr = no_dupes(s, type)
    write_to_file(arr, type + "_data/no_dupes_" + str(s) + "_.txt")

    print("no dupes \n")
    arr = no_dupes_ascending(s, type)
    write_to_file(arr, type + "_data/no_dupes_ascending" + str(s) + "_.txt")

    print("ascending\n")
    arr = no_dupes_60ascending(s, type)
    write_to_file(arr, type + "_data/no_dupes_60ascending" + str(s) + "_.txt")

    print("ascending 60 \n")
    arr = duplicate(s, 0.2, type)
    write_to_file(arr, type + "_data/dupes_20_" + str(s) + "_.txt")

    print("duplicate 20 \n")
    arr = duplicate(s, 0.4, type)
    write_to_file(arr, type + "_data/dupes_40_" + str(s) + "_.txt")

    print("duplicate 40 \n")

    print("Size", s, "done")
    ####
