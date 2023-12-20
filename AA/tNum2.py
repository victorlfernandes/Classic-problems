from math import gcd

def main():

    while True:

        a = list(map(int, input().split()))

        if a[-1] != 0:
            continue
        else:
            a.remove(0)

        if len(a) == 0: 
            break

        if len(a) == 1:
            print(a[1])

        a.sort()

        resp = a[1] - a[0]
        for i in range(1, len(a)):
            resp = gcd(resp, a[i] - a[i - 1])

        print(resp)

if __name__ == '__main__':
    main()
    