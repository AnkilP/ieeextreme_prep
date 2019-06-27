#include "simulated_annealing.hpp"

sim_annealing::sim_annealing(std::vector<int> & initial_state, int num_neighbours, int number_of_iterations, int initial_temp, int final_temp, std::function<void (float &)> temperature_decrement_rule){
    num_iter = number_of_iterations;
    ini_temp = initial_temp;
    fin_temp = final_temp;
    initial_state = initial_state;
    func = temperature_decrement_rule;
    std::vector<std::unique_ptr<node<std::vector<int>>>> neighbours(num_neighbours); // this is an optimization for my computer
    for(int i = 0; i < num_neighbours; ++i){
        
        neighbours[i] = std::make_unique()
    }
    node<std::vector<int>> root_node(neighbours, initial_state, false);

}