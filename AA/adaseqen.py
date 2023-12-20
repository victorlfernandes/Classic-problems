import string

# def lcs(str1, str2, n, m, pd, prices):

#     for i in range(n + 1):
#         for j in range(m + 1):

#             if i == 0 or j == 0:
#                 pd[i][j] = 0

#             elif str1[i - 1] == str2[j - 1]:
#                 pd[i][j] = prices[string.ascii_letters.index(str1[n - 1])] + lcs(str1, str2, n - 1, m - 1, pd, prices)

#             else:
#                 pd[i][j] = max(pd[i - 1][j], pd[i][j - 1])

#     return pd[n][m]


def lcs(str1, str2, n, m, pd, prices):

    if n == 0 or m == 0:
        return 0

    if pd[n][m] != -1:
        return pd[n][m]

    if str1[n - 1] == str2[m - 1]:
        pd[n][m] = prices[string.ascii_letters.index(str1[n - 1])] + lcs(str1, str2, n - 1, m - 1, pd, prices)
        return pd[n][m]

    pd[n][m] = max(lcs(str1, str2, n, m - 1, pd, prices), lcs(str1, str2, n - 1, m, pd, prices))

    return pd[n][m]

def main():

    i = input()
    n = int(i[0])
    m = int(i[2])

    prices = [int(i) for i in input().split()]

    str1 = input()
    str2 = input()

    pd = [[-1] * (m + 1) for i in range(n + 1)]

    print(lcs(str1, str2, n, m, pd, prices))

if __name__ == '__main__':
    main()
