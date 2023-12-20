import sys

def floydWarshall(graph, nNodes):

    distances = [[0] * (nNodes + 1) for i in range(nNodes + 1)]

    for i in range(nNodes):
        for j in range(nNodes):
            distances[i][j] = graph[i][j]

    for i in range(nNodes):
        for j in range(nNodes):
            for k in range(nNodes):
                if distances[j][i] + distances[i][k] < distances[j][k]:
                    distances[j][k] = distances[j][i] + distances[i][k]

    for i in range(nNodes):
        if distances[i][i] < 0:
            return True
    
    return False

def main():

    aux = [int(i) for i in input().split()]
    nNodes = aux[0]
    nEdges = aux[1]

    graph = [[sys.maxsize] * nNodes for i in range(nNodes)]

    for i in range(nEdges):
        aux = [int(i) for i in input().split()]
        a = aux[0]
        b = aux[1]
        distance = aux[2]
        graph[a - 1][b - 1] = distance
        graph[b - 1][a - 1] = distance

    if floydWarshall(graph, nNodes):
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()