A = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

B = [
    [7,4,1],
    [8,5,2],
    [9,6,3],
]

C = [
    [0,0,0],
    [0,0,0],
    [0,0,0],
]

def Addition():
    for i in range(len(A)):
        for j in range(len(A)):
            C[i][j] = A[i][j] + B[i][j]

    print("The Addition of Matrices A And B is")
    for i in range(len(C)):
        print(C[i])


def Subtraction():
    for i in range(len(A)):
        for j in range(len(B)):
            C[i][j] = A[i][j] - B[i][j]

    print("The Subtraction of Matrices A & B is : ")
    for i in range(len(C)):
        print(C[i])


def Multiplication():
    for i in range(len(A)):
        for j in range(len(A)):
            for k in range(len(A)):
                C[i][j] = A[i][k] * B[k][j]
    
    print("The Multiplictaion of matrices A and B is : ")
    for i in range(len(C)):
        print(C[i])


def TransposeA():
    for i in range(len(A)):
        for j in range(len(A)):
            C[i][j] = A[j][i]

    print("The transpose of Matrix A is :")
    for i in range(len(C)):
        print(C[i])


def TransposeB():
    for i in range(len(A)):
        for j in range(len(A)):
            C[i][j] = B[j][i]

    print("The transpose of Matrix b is:")
    for i in range(len(C)):
        print(C[i])

Addition()
Subtraction()
Multiplication()
TransposeA()
TransposeB()