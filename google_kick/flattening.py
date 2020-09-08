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

class merchant_association:

    def __init__(self):
        self.num_towns = get_number()
        self.town_prices = np.zeros(self.num_towns)
        for i in range(num_towns):
            self.town_prices[i] = get_number()

        self.adj_matrix = np.zeros(shape=(self.num_towns, self.num_towns))
        for i in range(num_towns -1):
            x = get_number()
            y = get_number()
            self.adj_matrix[x-1][y-1] = 1
            self.adj_matrix[y-1][x-1] = 1

        self.k = get_number()
        self.merchants = np.zeros(k)
        for i in range(k):
            self.merchants[i] = get_number() - 1

    def conflict_search(self):
        aggregate_merchant_info()
        self.merchant_sets = np.asarray(self.merchant_sets)
        for i in self.merchant_sets:
            for j in self.merchant_sets:
                if i != j:
                    self.merchantz.append(list(set(i).intersection(j)))

    def det_profit(self):
        self.merchants_profits = np.zeros(self.k)
        for i in range(self.k):
            self.merchants_profits[i] = sum([x for x in self.town_prices if x in traverse(i, )])

    def aggregate_merchant_info(self):
        self.merchant_sets = [[]] * self.k
        index = 0
        for i in self.merchants:
            self.merchant_sets[index] = self.traversal(i)
            index += 1

    def neighbours(self, index):
        x = []
        for i in range(self.num_towns):
            if(self.adj_matrix[index][i] == 1):
                x.append(i)
        return x

    def traverse(self, index, final):
        visited = {index}
        queue = [index]
        while queue:
            curr, path = queue.popleft()
            visited.add(curr)
            for i in neighbours(index):
                if i == final:
                    return path + [curr, i]
                if(i in visited):
                    continue
                queue.append(i, path + [curr])
                visited.add(i)
        return None

    def traversal(self, index):
        visited = [False] * (len(self.k))
        queue = []
        queue.append(index)
        visited[index] = True
        while queue:
            index = queue.pop(0)
            for i in neighbours(index):
                if visited[index] == False:
                    queue.append(index)
                    visited[index] = True
