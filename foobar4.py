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

def dfs(u, globalVisited, visited, graph, banana_list):
    # print(globalVisited)
    for v in range(len(banana_list)):
        if graph[u][v] and visited[v] == False:
            visited[v] = True # Mark v as visited
            if globalVisited[v] == -1 or dfs(globalVisited[v], globalVisited, visited, graph, banana_list):
                globalVisited[v] = u
                return True
    return False

def maximalMatching(graph, banana_list):
    globalVisited = [-1] * len(banana_list)
    result = 0
    for i in range(len(banana_list)):
        visited = [False] * len(banana_list)
        if dfs(i, globalVisited, visited, graph, banana_list):
            result += 1
    return len(banana_list)- 2*(result/2)

def solution(banana_list):
    graph = create_graph(banana_list)
    distracted_guards = maximalMatching(graph, banana_list)
    return distracted_guards

if __name__ == "__main__":
    banana_list = [1, 7, 3, 21, 13, 19]
    print(solution(banana_list))
    assert solution(banana_list) == 0
    print(solution([1,1]))
    assert solution([1,1]) == 2