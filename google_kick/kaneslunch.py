import numpy as np

class kaneslunch:

    def __init__(self, calorieCounts, totalCalorieLimit):
        self.calorieCounts = calorieCounts
        self.totalCalorieLimit = totalCalorieLimit
        self.hash_table = [0] * self.totalCalorieLimit
        for i in range(len(self.calorieCounts)):
            self.hash_table[self.calorieCounts[i]] = [i]

    def calculateCalories(self, index):
        for calorieIndex in range(len(self.calorieCounts)):
            if(calorieIndex not in self.hash_table[index] and self.hash_table[index] is not 0):
                    



    def returnCalorie(self):
        if(self.hash_table[self.totalCalorieLimit] is not 0):
            return True
        else:
            return False
