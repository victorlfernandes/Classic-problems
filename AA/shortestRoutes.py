import sys

def dijkstra(graph, nCities, source):

    distances = [sys.maxsize] * nCities
    visited = [False] * nCities
    distances[source] = 0

    for i in range(nCities - 1):

        minDistanceCity = 0 
        aux = sys.maxsize
        
        for j in range(nCities):
            
            if not visited[j] and distances[j] <= aux:
                minDistanceCity = j
                aux = distances[j]

        visited[minDistanceCity] = True

        for j in range(nCities):

            if not visited[j] and \
               graph[minDistanceCity][j] and \
               distances[minDistanceCity] != sys.maxsize and \
               distances[minDistanceCity] + graph[minDistanceCity][j] < distances[j]:

                distances[j] = distances[minDistanceCity] + graph[minDistanceCity][j]

    return distances

def main():

    aux = [int(i) for i in input().split()]
    nCities  = aux[0]
    nRoads   = aux[1]
    nQueries = aux[2]   

    graph = [[0] * nCities for i in range(nCities)]

    for i in range(nRoads):
        aux = [int(i) for i in input().split()]
        city1 = aux[0]
        city2 = aux[1]
        distance = aux[2]
        graph[city1 - 1][city2 - 1] = distance
        graph[city2 - 1][city1 - 1] = distance

    for i in range(nQueries):
        aux = [int(i) for i in input().split()]
        a = aux[0]
        b = aux[1]
        d = dijkstra(graph, nCities, a - 1)
        if d[b - 1] == sys.maxsize: 
            print(-1) 
        else: 
            print(d[b - 1])

if __name__ == '__main__':
    main()