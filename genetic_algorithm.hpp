#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <type_traits>
#include <map>
#include <queue>
#include <ctime>
#include <stdlib.h> 

class neighbour{

    int index1;
    int index2;
    int spcost;

    public:
        neighbour(int i, int j, int cost){
            index1 = i;
            spcost = cost;
            index2 = j;
        }

        neighbour() = default;

        int getCost() const {
            return this->spcost;
        }

        int getIndex1(){
            return this->index1;
        }

        int getIndex2(){
            return this->index2;
        }
};

class compareNeighbours{
    public: 
        int operator() (const neighbour& p1, const neighbour& p2) 
        { 
            return p1.getCost() > p2.getCost(); 
        } 
};

class genetic_algorithm{

    int find_cost();
    int find_cost(const std::vector<int> &);
    void swap(std::vector<int> & state, const int & index1, const int & index2);
    bool try_add(const std::vector<int> &);
    void print_recency_matrix();

    public:
        genetic_algorithm(const int population);
        void move();
        void solve();
        void print_matrix(const std::vector<std::vector<int>> & matrix);
        void print_matrix(const std::vector<int> & matrix);

        void test_cases();
};