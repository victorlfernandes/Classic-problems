from operator import xor

def test(nPiles, stones):

    xorResult = xor(stones[0], stones[1])

    for i in range(2, nPiles):

        xorResult = xor(xorResult, stones[i])

    return xorResult

def main():

    nTestCases = int(input())

    for _ in range(nTestCases):

        nPiles = int(input())

        stones = list(map(int, input().split()))

        xorResult = test(nPiles, stones)

        if (xorResult != 0):
            print(0)
        else:
            print(1)

if __name__ == '__main__':
    main()