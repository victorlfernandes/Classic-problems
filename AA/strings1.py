def kmp(pat, txt):
    M = len(pat)
    N = len(txt)
 
    lps = [0] * M
    j = 0 
 
    preProcess(pat, M, lps)

    results = list()
    i = 0

    while (N - i) >= (M - j):
        if pat[j] == txt[i]:
            i += 1
            j += 1
 
        if j == M:
            results.append(i - j + 1)
            j = lps[j-1]
 
        elif i < N and pat[j] != txt[i]:

            if j != 0:
                j = lps[j-1]
            else:
                i += 1
    
    return results
 
def preProcess(pat, M, lps):

    len = 0
 
    lps[0] 
    i = 1
 
    while i < M:

        if pat[i] == pat[len]:
            len += 1
            lps[i] = len
            i += 1
        else:
            if len != 0:
                len = lps[len-1]
 
            else:
                lps[i] = 0
                i += 1
 
def main():

    nTests = int(input())

    for _ in range(nTests):

        a = list(map(str, input().split()))

        b = kmp(a[1], a[0])

        if len(b) == 0:
            print('Not Found')
            print()

        else:
            print(len(b))
            for i in range(len(b)):
                print('{} '.format(b[i]), end='')
            print('\n')

if __name__ == '__main__':
    main()
