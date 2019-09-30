#include <vector>
#include <iostream>
#include <algorithm>

void print_matrix(const std::vector<std::vector<int>>& matrix){
    for(auto & row: matrix){
        for(auto &col: row){
            std::cout << col << ", ";
        }
        std::cout << std::endl;
    }
}

void print_matrix(const std::vector<int> & matrix){
        for(auto it = matrix.begin(); it != matrix.end(); ++it){
            std::cout << *it << ", ";
        }
        std::cout << std::endl;
}

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {

    print_matrix(matrix);

    int total_size = (int)matrix.size() * (int)matrix.at(0).size();
    std::vector<int> results(total_size, 0);
    
    int mini = 0;
    int minj = 0;
    int maxi = matrix.size();
    int maxj = matrix[0].size();
    int count = 0;
    int i = mini;
    int j = minj;

    while(count < total_size){
        while(j < maxj){
            results[count++] = matrix.at(i).at(j++);
        }
        // j = maxj - 1, i = mini
        i++;
        j--;
        while(i < maxi){
            results[count++] = matrix.at(i++).at(j);
        }
        // j = maxj - 1, i = maxi - 1
        i--;
        maxj--;
        j--;
        while(j >= minj){
            results[count++] = matrix.at(i).at(j--);
        }
        j++;
        // j = minj, i = maxi - 1
        maxi--;
        i--;
        while(i > mini){
            results[count++] = matrix.at(i--).at(j);
        }
        i++;
        // j = minj, i = mini + 1
        minj++;
        j++;
        mini++;
    }

    return results;
}

void fill_row(std::vector<int> & row)
{
    std::generate(row.begin(), row.end(), [](){ return rand() % 100; }); 
}

void fill_matrix(std::vector<std::vector<int>> & mat)
{
    std::for_each(mat.begin(), mat.end(), fill_row);
}

int main(){
    
    std::vector<std::vector<int> > test1 = {{9, 13, 16}, {11, 2, 17}, {1, 17, 3}, {8, 2, 4}, {4, 10, 1}};//(4, std::vector<int>(3,0));
    // fill_matrix(test1);

    print_matrix(spiralOrder(test1));

    return 0;
}