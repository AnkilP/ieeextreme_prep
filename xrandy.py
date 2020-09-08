import numpy as np

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

class xrandy:

    def __init__(self):
        self.num_nodes = get_number()
        self.tree = np.zeros(shape=(self.num_nodes, self.num_nodes), dtype=int)
        for _ in range(self.num_nodes - 1):
            a = get_number() - 1
            b = get_number() - 1
            w = int(get_number())
            self.tree[a][b] = w
        print(self.tree)
        self.stack = [0]

    # def dfs(self, root):
    #     original_root = root
    #     queue = [root]
    #     while queue:
    #         t_root = queue.pop(0)
    #         neighs = self.neighbours(t_root)
    #         # print("t_root")
    #         # print(t_root)
    #         # print("neighs")
    #         # print(neighs)
    #         if(len(neighs) == 0):
    #             if(self.tree[root][t_root] == self.stack[-1]):
    #                 print("popping stack")
    #                 print(self.stack.pop(-1))
    #                 if not queue:
    #                     break
    #         # elif(len(neighs) > 0):
    #         #     print("Neighs")
    #         #     print(neighs)
    #         #     for node in neighs:
    #         #         queue.insert(0,node) # no cycle protection
    #         else:
    #             for node in neighs:
    #                 queue.insert(0,node) # no cycle protection
    #         # print("tree at queue 0")
    #         # print(queue)
    #         if(self.tree[t_root][queue[0]] >= self.stack[-1]):
    #             self.stack.append(self.tree[t_root][queue[0]])
    #             # print("stack at -1")
    #             # print(self.stack[-1])
    #             self.tree[original_root][queue[0]] = max(self.stack[-1], self.tree[original_root][queue[0]])
    #         else:
    #             self.tree[original_root][queue[0]] = max(self.stack[-1], self.tree[original_root][queue[0]])
    #         root = t_root

    def dfs(self, node, original_root):
        parent_node = node
        went_in = False
        for n in self.neighbours(node):
            went_in = True
            if(self.tree[parent_node][n] >= self.stack[-1]):
                self.stack.append(self.tree[parent_node][n])
                # print("stack at -1")
                # print(self.stack[-1])
                self.tree[original_root][n] = max(self.stack[-1], self.tree[original_root][n])
            else:
                self.tree[original_root][n] = max(self.stack[-1], self.tree[original_root][n])
        if(not went_in):
            if(self.tree[parent_node][t_root] == self.stack[-1]):
                print("popping stack")
                self.stack.pop(-1)
            dfs(graph,n, original_root)

    def neighbours(self, index):
        neighs = []
        for i in range(self.num_nodes):
            if(self.tree[index][i] != 0):
                neighs.append(int(i))
        return neighs

    def run(self):
        for i in range(self.num_nodes):
            self.dfs(i, i)

    def add_weights(self):
        for i in range(self.num_nodes):
            for j in range(self.num_nodes):
                self.sum += self.tree[i][j]
        return self.sum

if __name__ == '__main__':
    x = xrandy()
    x.run()
    print(add_weights())
