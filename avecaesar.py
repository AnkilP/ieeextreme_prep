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

class caesar:

    def __init__(self):
        self.strings = get_number()
        self.string_casket = []
        for i in range(self.strings):
            self.string_casket.append(get_word())
        self.answer = ""

    def isValid(self, string):
        if(len(string) == 1):
            return True
        elif len(string) > 1:
            twostrings = []
            for i in range(len(string[:-1])):
                if(string[i] > string[i+1]):
                    twostrings.append(string[:i+1])
                    twostrings.append(string[i+1:])
                    break
            if(twostrings):
                return self.lexico(twostrings[0], twostrings[1])
            else:
                return True
        else:
            return False

    def lexico(self, string1, string2):
        return string1 <= string2

    def iterate_over_strings(self):
        for i in self.string_casket:
            if(self.isValid(i)):
                self.answer = self.answer + "1"
            else:
                self.answer = self.answer + "0"
        return self.answer

if __name__ == '__main__':
    lf = caesar()
    print(lf.iterate_over_strings())
