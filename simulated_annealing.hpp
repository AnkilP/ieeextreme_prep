#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stdlib.h>
#include <memory>

template <class T>
class node{

    std::vector<std::unique_ptr<node<T>>> neighbour;
    T state;
    bool goal_state;

    public:

        node() = default;

        node(std::vector<std::unique_ptr<node<T>>>  & neig, T & state, bool goal_state=false){
            neighbour = neig;
            state = state;
            goal_state = goal_state;
        }
};

class sim_annealing
{
    int depot;
    std::vector<int> initial_state;
    float probability(float cost_difference, float temperature);
    int num_iter;
    int ini_temp;
    int fin_temp;
    std::function<void (float &)> func;
    int num_neighbours;

    public:
        sim_annealing(std::vector<int> & ,int, int number_of_iterations, int initial_temp, int final_temp, std::function<void (float &)> temperature_decrement_rule);
        void update();
};