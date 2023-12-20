def recursion(q, i, j, queenCounter):

    if i < 0 or i >= 8 or j < 0 or j >= 8:
        return False

    # creating a copy of the queens position
    copy = list()
    for k in range(8):
        copy.append(8 * [True])
        for l in range(8):
            copy[k][l] = q[k][l]
    
    if q[i][j] == False:
        return False

    # marking current square as queen
    q[i][j] = 'q'
    queenCounter += 1

    for k in range(8):
        print(q[k])  
    print()  

    # print(queenCounter)
    if j == 8 - 2:
        # print(queenCounter)
        if queenCounter >= 8:
            # print('oi')
            return True
        # else:
            # return False

    # blocking line
    for k in range(j + 1, 8):
        q[i][k] = False

    # blocking column
    # for k in range(i + 1, 8):
    #     q[k][j] = False

    # blocking diagonals
    k = i + 1
    l = j + 1
    while k < 8 and l < 8:
        q[k][l] = False
        k += 1
        l += 1
    k = i - 1
    l = j + 1
    while k >= 0 and l < 8:
        q[k][l] = False
        k -= 1
        l += 1

    # recursive calls
    for k in range(8):
        # if not q[0][j] and not q[1][j] and not q[2][j] and not q[3][j]:
        flag = True
        for l in range(8):
            if q[l][j]:
                flag = False
        if flag:
            for m in range(8):
                q[i] = copy[i]
            k += 1
        if recursion(q, k, j + 1, queenCounter):
            # if queenCounter == 8:
                print('difer')
                return True
            # else:
                # return False

def queens(board):

    for i in range(8):
        q = list()
        for j in range(8):
            q.append([True] * 8)
        if recursion(q, i, 0, 0):
            print('x')
            for i in range(8):
                print(q[i])
            result = 0
            for i in range(8):
                if 'q' in q[i]:
                    result += board[i][q[i].index('q')]
            print(result)
            # break

def main():

    nBoards = int(input())
    for i in range(nBoards):

        board = list()
        for i in range(8):
            board.append(list())
            board[i] = [int(j) for j in input().split()]
        
        queens(board)


if __name__ == '__main__':
    main()