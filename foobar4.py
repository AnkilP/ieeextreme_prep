from fractions import gcd

#uses conservation of bananas (cons)
def deadlock(x, y):
    cons = int((x + y)/gcd(x,y))
    return bool(cons & (cons - 1 ))

def create_graph(banana_list):
    graph = [[0 for j in range(len(banana_list))] for i in range(len(banana_list))]
    for i in range(len(banana_list)):
        for j in range(len(banana_list)):
            if deadlock(banana_list[i], banana_list[j]):
                graph[i][j] = 1
                graph[j][i] = 1
    return graph

def bpm(u, matchR, seen, graph, banana_list):
    for v in range(len(banana_list)):
        if graph[u][v] and seen[v] == False:
            seen[v] = True # Mark v as visited
            if matchR[v] == -1 or bpm(matchR[v], matchR, seen, graph, banana_list):
                matchR[v] = u
                return True
    return False

def maxGaurdPair(graph, banana_list):
    matchR = [-1] * len(banana_list)
    result = 0 # Count of graud match
    for i in range(len(banana_list)):
        seen = [False] * len(banana_list)
        if bpm(i, matchR, seen, graph, banana_list):
            result += 1
    return len(banana_list)- 2*(result/2)

def solution(banana_list):
    graph = create_graph(banana_list)
    distracted_guards = maxGaurdPair(graph, banana_list)
    return distracted_guards

if __name__ == "__main__":
    banana_list = [1, 7, 3, 21, 13, 19]
    print(solution(banana_list))