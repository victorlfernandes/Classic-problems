from ast import Break
from math import sqrt

def main():

    while True:
            
        # reading amount of sprinkles and dimensions of the grass
        try:
            data = [int(i) for i in input().split()]
            print(data)
            print()
        except EOFError:
            break

        # checking if we ran all test cases
        if len(data) != 3:
            exit()

        n = data[0]
        l = data[1]
        w = data[2]

        # calculating the minimum radius to cover all wide
        minimumRadius = w * sqrt(2) / 4

        # reading data of each sprinkle
        sprinkles = list()
        for i in range(n):
            sprinkle = [int(j) for j in input().split()]
            print(sprinkle)
            print()
            position = sprinkle[0]
            radius   = sprinkle[1]
            if position >= 0 and position <= l and radius >= minimumRadius:
                sprinkles.append(sprinkle)

        # creating a list of unreached spots
        unreachedSpots = list()
        for i in range(l):
            unreachedSpots.append(i + 1)

        # sorting sprinkles by radius
        i = 1
        while i < len(sprinkles):
            key = sprinkles[i][1]
            aux = sprinkles[i]
            j = i - 1
            while j >= 0 and key > sprinkles[j][1]:
                sprinkles[j + 1] = sprinkles[j]
                j -= 1
            sprinkles[j + 1] = aux
            i += 1

        # checking use of each sprinkle
        amtUsefulSprinkles = 0
        for sprinkle in sprinkles:
            usefulSprinkle = False
            # reaching center
            index = sprinkle[0] - 1
            if unreachedSpots[index] != -1:
                usefulSprinkle = True
                unreachedSpots[index] = -1
            # reaching right spots
            counter = 0
            while counter < sprinkle[1]:
                if index < l and unreachedSpots[index] != -1:
                    usefulSprinkle = True
                    unreachedSpots[index] = -1
                index += 1
                counter += 1
            # reaching left spots
            index = sprinkle[0] - 1
            counter = 0
            while counter < sprinkle[1]:
                if index >= 0 and unreachedSpots[index] != -1:
                    usefulSprinkle = True
                    unreachedSpots[index] = -1
                index -= 1
                counter += 1
            if usefulSprinkle:
                amtUsefulSprinkles += 1

        print()
        print()
        # printing result
        aux = 0
        for i in unreachedSpots:
            aux += i
        if aux == -len(unreachedSpots):
            print(amtUsefulSprinkles)
        else:
            print(-1)
        
        print()
        print()

if __name__ == '__main__':
    main()