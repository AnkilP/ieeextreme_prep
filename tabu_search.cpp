#include "tabu_search.hpp"

tabu_search::tabu_search(const int & tabu_list){
    best_score = 1000000;

    for(int i = 0; i < 20; ++i){
        this->state->at(i) = i + 1;
    }

    flowRead->get(flowMatrix);
    distanceRead->get(DistanceMatrix);
}

int tabu_search::find_cost(){
    int cost = 0;

    for(auto &c: *state){ // TODO: could improve runtime if I tracked which nodes were disturbed
        for(auto &f: *state){
            if (c == f){
                continue;
            }

            cost += this->flowMatrix->at(c-1).at(f-1) * this->DistanceMatrix->at(c-1).at(f-1);

        }
    }

    best_score = std::min(cost, best_score);
    return cost;

}

template <typename T>
void tabu_search::print_matrix(const T& matrix){
    if(std::is_same<T, std::unique_ptr<std::vector<std::vector<int>>>>::value){
        for(auto &c: matrix){
            for(auto &f: c){
                std::cout << f << ", ";
            }
            std::cout << std::endl;
        }
    }
    else if(std::is_same<T, std::unique_ptr<std::vector<int>>>::value){
        for(auto &c: matrix){
            std::cout << c << ", ";
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "Type unrecognized" << std::endl;
    }
}