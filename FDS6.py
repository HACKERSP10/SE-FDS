def quickSort(arr):
    if len(arr)<=1:
        return arr
    
    pivot = arr[len(arr)//2]

    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quickSort(left) + middle + quickSort(right)


def getTopScores(scores, n=5):
    if len(scores) < n:
        print("Not enough scores to display in top 5")
        return scores
    
    return scores[-n:]

students = int(input("Enter Number of students : "))
scores = []

for i in range(students):
    x = float(input("Enter the Second Year Percentage of students : "))
    scores.append(x)

sortedScores = quickSort(scores)
print("\n Sorted Scores are :")
print(sortedScores)

topScores = getTopScores(scores)
print("\n Top Five scores are : ")
print(topScores)
