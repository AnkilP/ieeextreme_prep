#include "genetic_algorithm.hpp"

genetic_algorithm::genetic_algorithm(const int population){

}

int main(){
    std::srand(std::time(NULL));
    int tabu_tenure = rand() % 10 + 300;
    std::cout << "Tabu Tenure: " << std::to_string(tabu_tenure) << std::endl;
    genetic_algorithm ts(tabu_tenure);
    ts.solve();
}