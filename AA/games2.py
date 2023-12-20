import string

def game(s):
    
    finalStr = []

    for i in range(len(s)):

        if i % 2 == 0:
            if s[i] == 'a':
                finalStr.append('b')
            else:
                finalStr.append('a')
        else:
            if s[i] == 'z':
                finalStr.append('y')
            else:
                finalStr.append('z')

    return finalStr

def main():
    
    nTests = int(input())

    for _ in range(nTests):

        s = input()
        r = game(s)
        for i in range(len(r)):
            print(r[i], end = '')
        print()

if __name__ == '__main__':
    main()