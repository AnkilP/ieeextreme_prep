# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

# numpy and scipy are available for use
import numpy as np
import scipy
import sys

def print_sol_array(sol_array):
    for i in range(2):
        for j in range(num_nodes):
            k = j + 1
            while(k < num_nodes):
                print("Dist %d, i %d j %d solution %d" %(i+1, j+1, k+1, solArray[j][k][i]))
                k += 1

def get_min_gen(adjList, solArray, startIndex, targetIndex, dist, num_nodes, swap):
    #print("Swap", swap)
    minVal = solArray[startIndex][targetIndex][int(swap)]
    # if dist == 2 and startIndex == 1 and targetIndex == 2:
    #     print("Test sol array")
    #     print_sol_array(solArray)
    #     print("minVal")
    #print("MINVAL Base", minVal, swap)
    if minVal == 0:
        solArray[startIndex][targetIndex][int(not swap)] = 0
        return
    for i in range(num_nodes):
        newCost = max(adjList[startIndex][i], solArray[i][targetIndex][int(swap)])
        # if dist == 2 and startIndex == 1 and targetIndex == 2:
        #     print("Stat 1 - i %d cost1 %d cost2 %d" %(i, adjList[startIndex][i], solArray[i][targetIndex][0]))
        #     print("newCost")
        #     print(newCost)
        #print("new cost %d min val %d" %(newCost, minVal))
        minVal = min(minVal, newCost)
    solArray[startIndex][targetIndex][int(not swap)] = minVal
    solArray[targetIndex][startIndex][int(not swap)] = minVal

num_nodes = get_number()
max_path = (10**9) * (num_nodes-1)
# adjList = [[max_path for i in range(num_nodes)] for j in range(num_nodes)]

# solArray = [[[max_path for i in range(2)] for j in range(num_nodes)] for k in range(num_nodes)]
adjList = np.full(shape=(num_nodes, num_nodes), fill_value=max_path) # NEW
solArray = np.full(shape=(num_nodes, num_nodes, 2), fill_value=max_path) # NEW
for i in range(num_nodes-1):
    node1_val = get_number()
    node2_val = get_number()
    weight = get_number()
    adjList[node1_val-1][node2_val-1] = weight;
    adjList[node2_val-1][node1_val-1] = weight;
#Base-case: distance 1
initList = [0,1]
for i in range(num_nodes):
    for j in range(num_nodes):
        if i == j:
            adjList[i-1][j-1] = 0
        solArray[i-1][j-1][0] = adjList[i-1][j-1]
        solArray[j-1][i-1][0] = adjList[i-1][j-1]

# print("Sol after base")
# print_sol_array(solArray)

distRange = list(range(2, num_nodes-1))
swap = 0
#print(distRange)
#General case - dist. from 2 to n-1
for i in distRange:
    for j in range(num_nodes):
        k = j + 1
        while(k < num_nodes):
            get_min_gen(adjList, solArray, j, k, i, num_nodes, swap)
            k += 1
    # print("Sol array for dist %d" %(i))
    # print_sol_array(solArray)
    swap = not swap
# print("Sol after end")
# print_sol_array(solArray)
sum = 0
for i in range(num_nodes):
    j = i+1
    while(j < num_nodes):
        sum += solArray[i][j][int( swap)]
        j += 1
print(sum)
