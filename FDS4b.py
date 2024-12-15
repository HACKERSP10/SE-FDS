n = int(input("Enter the number of students : "))
studentList = []

for i in range(n):
    x = float(input(f"Enter the First Year percentage of Student {i+1} : "))
    studentList.append(x)

print("Student list before sorting", studentList)
for i in range(n):
    for j in range(n-1):
        if(studentList[j]>studentList[j+1]):
            temp = studentList[j]
            studentList[j] = studentList[j+1]
            studentList[j+1] = temp

print("List after Sorting is :\n ", studentList)
print("Top five scorers are : ")
for i in range(n-1, n-6, -1):
    print(studentList[i])