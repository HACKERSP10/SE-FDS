n = int(input("Enter the number of students : "))
percentage = []

for i in range(n):
    x = float(input(f"Enter Second year percentage of Student no {i+1} : "))
    percentage.append(x)

def shell_sort(arr):
    A = len(arr)
    gap = A//2
    while gap > 0:
        for i in range(gap, A):
            temp = arr[i]
            j = i

            while j>= gap and arr[j-gap]>temp:
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap//=2
    return arr


print("\nSorting using Shell Sort...")
sorted_shell = percentage.copy()
sorted_shell = shell_sort(sorted_shell)
print("Top five scores (Shell Sort):", sorted_shell[-5:])