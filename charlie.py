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

class knaps:

    def __init__(self):
        self.testcases = get_number()

    def ingestorX(self):
        self.budget = get_number()
        num_components = get_number()
        components_types = []

        for i in range(num_components):
            components_types.append(get_number())

        self.all_options = []
        for i in range(num_components):
            one_option = []
            for j in range(components_types[i]):
                one_option.append(get_number())
            self.all_options.append(sorted(one_option, reverse=True))
        return self.budget, np.array(self.all_options)

    def run(self):
        for i in range(self.testcases):
            budget, all_options = self.ingestorX()
            print(self.knapSackz(budget, all_options))

    def knapSackz(self, totalBudget, all_options):
        self.bags = np.zeros(shape=(all_options.shape[0] + 1,totalBudget + 1), dtype=int)
        for i in range(all_options.shape[0]):
            # print(i)
            for w in range(totalBudget+1):
                if i == 0 or w == 0:
                    # print(i)
                    self.bags[i][w] = 0
                elif min(all_options[i]) <= w:
                    # print("device")
                    # print(i)
                    for device in all_options[i]:
                        # print("bags")
                        if(device <= w):
                            self.bags[i][w] = max(device + self.bags[i-1][w-device], self.bags[i-1][w])
                else:
                    # print("else")
                    # print(i)
                    self.bags[i][w] = self.bags[i-1][w]
        return self.bags[all_options.shape[0]][totalBudget]


if __name__ == "__main__":
    k = knaps()
    k.run()
