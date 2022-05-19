TableSize = int(input("Enter size of Hash Table: "))


# Functions for linear probing
def line_insert():
    get_name = input("Enter name: ")
    get_num = input("Enter number: ")
    hash_row = get_name + ":" + get_num
    position = int(get_num) % TableSize

    if (hashTable[position] == None):
        hashTable[position] = hash_row
    else:
        print("Collision occured for {}.".format(get_name))
        while hashTable[position] != None:
            position += 1
            if position >= TableSize:
                position = 0
        hashTable[position] = hash_row


def line_search():
    t_list = [range(len(hashTable))]
    get_name = input("Enter name: ")
    get_num = input("Enter number: ")
    count = 0
    for i in range(len(hashTable)):
        count += 1
        if hashTable[i] is not None:
            t_list = hashTable[i].split(":")
            if t_list[0] == get_name and t_list[1] == get_num:
                print("{} found at position {}, in {} comparisions".format(get_name, i, count - 1))
                return

            else:
                print("No such record found!")




def line_display():
    print("\nName:Number")
    for i in range(len(hashTable)):
        if hashTable[i] == None:
            print("None : None")
        else:
            print(hashTable[i])


# functions for chain probing
def chain_insert(hashTable):
    get_name = input("Enter name: ")
    get_num = input("Enter number: ")
    hash_row = get_name + ':' + get_num
    hash_key = hashing(int(get_num))
    hashTable[hash_key].append(hash_row)


def chain_search(hashTable):
    count = 0
    t_list = [range(len(hashTable))]
    get_name = input("Enter name: ")
    get_num = input("Enter number: ")
    for i in range(len(hashTable)):
        for j in hashTable[i]:
            count += 1
            if j == None:
                count += 1
            elif j != None:
                t_list = j.split(":")
                if t_list[0] == get_name and t_list[1] == get_num:
                    print("{} found at position {}, in {} comparisions".format(get_name, i, count - 1))

        count += 1


def chain_display(hashTable):
    for i in range(len(hashTable)):
        print(i, end=" : ")
        for j in hashTable[i]:
            print(j)
        print()


# Main Function
exit = 0
while (exit != 1):
    chc1 = int(input("\n1=Linear Probing\n2=Chain Probing\n3=Exit\nEnter Choice: "))
    if chc1 == 1:
        hashTable = list(None for i in range(TableSize))
        exit2 = 0
        while exit2 != 1:
            chc2 = int(input("\n1=Insert\n2=Search\n3=Display\n4=Return\nEnter Choice: "))
            if chc2 == 1:
                line_insert()
            elif chc2 == 2:
                line_search()
            elif chc2 == 3:
                line_display()
            elif chc2 == 4:
                print("Returning...")
                exit2 += 1
            else:
                print("Invalid Choice!")

    elif chc1 == 2:
        hashTable = [[] for i in range(TableSize)]
        exit2 = 0


        def hashing(key):
            return key % len(hashTable)


        while exit2 != 1:
            chc2 = int(input("\n1=Insert\n2=Search\n3=Display\n4=Return\nEnter Choice: "))
            if chc2 == 1:
                chain_insert(hashTable)
            elif chc2 == 2:
                chain_search(hashTable)
            elif chc2 == 3:
                chain_display(hashTable)
            elif chc2 == 4:
                print("Returning...")
                exit2 += 1
            else:
                print("Invalid Choice!")

    elif chc1 == 3:
        print("Exiting...")
        exit += 1

    else:
        print("Invalid Choice")
