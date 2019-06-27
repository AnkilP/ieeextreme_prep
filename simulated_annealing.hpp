#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
class node{

    node * left = NULL;
    node * right = NULL;
    T state;
    bool goal_state = false;

    public:

        node() = default;

        node(node * left, node * right, T state, bool goal_state=false){
            left = left;
            right = right;
            state = state;
            goal_state = goal_state;
        }
};

class sim_annealing
{
    int depot;
    std::vector<int> initial_state;
    node<std::vector<int> > * root_node;
    float probability(float cost_difference, float temperature);
    

    public:
        sim_annealing(node<std::vector<int> > * root, int number_of_iterations, );
};