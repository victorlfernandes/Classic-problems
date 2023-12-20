import sys

def main():

    s = list()

    for x in sys.stdin:

        a = list(x)

        if a[-1] == '\n':
            a.pop()

        s += a

        if a[-1] == '#':

            n = len(s) - 1
            count = 0
            cc = 1

            for i in range(n):

                if s[n - i - 1] == '1':
                    count = (count + cc) % 131071

                cc = (cc * 2) % 131071

            s = list()
            print(('NO', 'YES')[count == 0])


if __name__ == '__main__':
    main()