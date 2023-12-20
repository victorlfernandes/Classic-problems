def main():

    setCounter = 1
    while True:

        try:
            set = [int(i) for i in input().split()]
        except EOFError:
            break

        amtChambers = set[0]
        amtSpecimens = set[1]
        masses = [int(i) for i in input().split()]

        for i in range(2 * amtChambers - amtSpecimens):
            masses.insert(0, 0)

        masses.sort()
        avgMass = sum(masses) / amtChambers

        print('Set #{}'.format(setCounter))

        imbalance = 0
        for i in range(amtChambers):
            print(' {}: '.format(i), end='')
            if masses[i] == 0 and masses[-(i + 1)] == 0:
                print()
            else:
                if masses[i] > 0:
                    print('{} '.format(masses[i]),end='')
                if masses[-(i + 1)] > 0:
                    print('{}'.format(masses[-(i + 1)]))
            chamberMass = masses[i] + masses[-(i + 1)]
            imbalance += abs(chamberMass - avgMass)
        print('IMBALANCE = {:.5f}'.format(imbalance))                

        setCounter += 1
        print()

if __name__ == '__main__':
    main()