n = int(input("Enter the number of students : "))
marks = []

for i in range(n):
    mark = int(input(f"Enter the mark for students {i +1} (-1 if absent) :"))
    marks.append(mark)


valid_marks = [mark for mark in marks if mark !=-1]
average_score = sum(valid_marks)/len( valid_marks) if valid_marks else 0

if valid_marks:
    highest_score = max(valid_marks)
    lowest_score = min(valid_marks)
else:
    highest_score = None
    lowest_score = None

absent_count = marks.count(-1)

mark_frequency = {}
for mark in marks:
    if mark !=1:
        if mark in mark_frequency:
            mark_frequency[mark] += 1
        else:
            mark_frequency[mark] = 1

if mark_frequency:
    frequent_mark = max(mark_frequency, key = mark_frequency.get)
else:
    frequent_mark = None


print(f"The average score is : {average_score}")
print(f"The higest score is : {highest_score}")
print(f"The lowest score is : {lowest_score}")
print(f"The absent count is : {absent_count}")
print(f"The frequent mark is : {frequent_mark}")