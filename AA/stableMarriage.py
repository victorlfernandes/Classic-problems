def main():

    # reading the number of test cases
    amtTestCases = int(input())

    # executing the algorithm 'amtTestCases' times
    for i in range(amtTestCases):

        # reading the number of marriages to find
        amtMarriages = int(input())
        # reading womens preferences
        womensPreferences = list()
        for j in range(amtMarriages):
            womensPreferences.append(list())
            womensPreferences[j] = [int(i) for i in input().split()]
            womensPreferences[j].remove(j + 1)
        # reading mens preferences
        mensPreferences = list()
        for j in range(amtMarriages):
            mensPreferences.append(list())
            mensPreferences[j] = [int(i) for i in input().split()]
            mensPreferences[j].remove(j + 1)

        # creating lists for single men e women
        singleMen = list()
        singleWomen = list()
        for j in range(1, amtMarriages + 1):
            singleMen.append(j)
            singleWomen.append(j)

        # creting lists of wifes and husbands
        wife = amtMarriages * [0]
        husband = amtMarriages * [0]

        # looping for proposals while there are single men
        counter = 0
        while singleMen and counter < amtMarriages * amtMarriages:

            # obtaining the single men
            currentMen = singleMen.pop(0)

            # obtaining the first preference of him
            currentWomen = mensPreferences[currentMen - 1].pop(0)

            # checking if his preference is single
            if currentWomen in singleWomen:
                # engaging them
                wife[currentMen - 1] = currentWomen
                husband[currentWomen - 1] = currentMen
                singleWomen.remove(currentWomen)
            
            else:
                
                # obtaining women's current husband
                husbandOfCurrentWomen = husband[currentWomen - 1]

                # checking women's order of preference
                p1 = womensPreferences[currentWomen - 1].index(currentMen)
                p2 = womensPreferences[currentWomen - 1].index(husbandOfCurrentWomen)
                if p2 < p1: # currentMen remains single
                    singleMen.insert(0, currentMen)

                else: # women exchange her current husband for current men
                    wife[currentMen - 1] = currentWomen
                    husband[currentWomen - 1] = currentMen
                    singleMen.insert(0, husbandOfCurrentWomen)

            counter += 1

        for i in range(amtMarriages):
            print('{} {}'.format(i + 1, wife[i]))


if __name__ == '__main__':
    main()