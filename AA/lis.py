def lis(array):
    n = len(array)
    l = n * [1]
    for i in range(1, n):
        for j in range(i):
            if array[i] > array[j] and l[i] < l[j] + 1:
                l[i] = l[j] + 1
    return max(l)

def main():
    arraySize = int(input())
    array = [int(i) for i in input().split()]
    print(lis(array))

if __name__ == '__main__':
    main()
