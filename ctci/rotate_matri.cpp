#include <vector>
#include <iostream>

#define SIZE 4

template <typename T>
void print_matrix(const T& matrix){
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){

    int matrx[SIZE][SIZE] = {{1,0,1,0},{1,0,1,9},{1,0,1,0}};

    print_matrix(matrx);

    for(int layer = 0; layer < SIZE/2; ++layer){
        int first = layer;
        int last = SIZE - 1 - first;
        for(int i = first; i < last; ++i){
            int offset = i - first;
            int top = matrx[first][i];
            matrx[first][i] = matrx[last - offset][first];
            matrx[last-offset][first] = matrx[last][last-offset];
            matrx[last][last-offset] = matrx[i][last];
            matrx[i][last] = top;
        }
    }

    print_matrix(matrx);

    return 0;

}