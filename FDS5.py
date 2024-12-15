n = int(input("Enter the Number of students : "))
percentage = []

for i in range(n):
    x=float(input(f"Enter the Second Year Percentage of Student no {i+1} : "))
    percentage.append(x)

def insertion_sort(arr):
    A = len(arr)
    for i in range(1, A):
        key = arr[i]
        j = i-1

        while j>=0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr


print("\nSorting using Insertion Sort...")
sorted_insertion = percentage.copy()
sorted_insertion = insertion_sort(sorted_insertion)
print("Top five scores (Insertion Sort):", sorted_insertion[-5:])