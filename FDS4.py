n = int(input("Enter the number of students : "))
list =[]

for i in range(n):
    x=float(input(f"Enter the marks of student {i+1} : "))
    list.append(x)

print("Student score befor Sorting : ", list)

for i in range(n):
    for j in range(i +1, n - 1):
        if(list[i]>list[j]):
            temp = list[i]
            list[i] = list[j]
            list[j] = temp

print("Students score after sorting : ", list)