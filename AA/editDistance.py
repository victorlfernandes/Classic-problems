def minOp(str1, str2):

    m = len(str1)
    n = len(str2)

    pd = [[0] * (n + 1) for i in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):

            if i == 0:
                pd[i][j] = j

            elif j == 0:
                pd[i][j] = i

            elif str1[i - 1] == str2[j - 1]:
                pd[i][j] = pd[i - 1][j - 1]

            else:
                pd[i][j] = min(pd[i][j - 1], pd[i - 1][j], pd[i - 1][j - 1]) + 1

    return pd[m][n]     

def main():

    nTestCases = int(input())

    for i in range(nTestCases):

        str1 = input()
        str2 = input()

        print(minOp(str1, str2))


if __name__ == '__main__':
    main()
