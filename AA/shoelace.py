import numpy as np

def shoelace(p):

    ans = 0
    n = len(p)

    i = 0
    j = n - 1
    while i < n: 

        ans += np.cross(p[i], p[j])

        j = i
        i += 1

    return np.abs(ans)

def main():

    nVertices = int(input())
    p = [] 

    for _ in range(nVertices):

        x = list(map(int, input().split()))
        p.append([x[0], x[1]])

    print(shoelace(p))

if __name__ == '__main__':
    main()