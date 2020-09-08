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

class luckyflip:

    def __init__(self):
        self.num_bets = get_number()
        self.bets = [""] * self.num_bets
        self.tally_bets = []
        self.reutrn = -1
        for i in range(self.num_bets):
            self.bets[i] = get_word()
            self.tally_bets.append(0)

        if self.num_bets == 1:
            self.num_bets

    def distX(self, bet, pot):
        return sum([int(bet[i:i+1] != pot[i:i+1]) for i in range(len(bet))])

    def distance(self, bet, pot):
        return [int(bet[i:i+1] != pot[i:i+1]) for i in range(len(bet))]

    def createStrList(self):
        lengthStr = len(self.bets[0])
        strList = []
        for i in range(pow(2, lengthStr)):
            number = [(i >> bit) & 1 for bit in range(lengthStr - 1, -1, -1)]
            strList.append("".join(str(j) for j in number))
        return strList

    def iterate_over_strList(self):
        strList = self.createStrList()
        # print(strList)
        for i in strList:
            minVal = np.zeros(self.num_bets)
            iter = 0
            for j in self.bets:
                minVal[iter] = self.distX(j, i)
                iter += 1
            setized, counts = np.unique(minVal, return_counts=True)
            duplicates = setized[counts > 1]
            if(minVal[np.argmin(minVal)] not in duplicates):
                self.tally_bets[np.argmin(minVal)] += 1

    def find_smallest_tally(self):
        # print(self.tally_bets)
        return np.min(np.asarray(self.tally_bets))

if __name__ == '__main__':
    lf = luckyflip()
    lf.iterate_over_strList()
    print(lf.find_smallest_tally())
