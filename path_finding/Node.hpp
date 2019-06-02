#include <string>
#include <iostream>
#include <cstdlib>

class Node{
        int position_x;
        int position_y;

        int heuristic_value;

    public:
            Node(int position_x, int position_y, int heuristic_value);
            Node(int position_x, int position_y);
            void determine_heuristic(int px, int py);
};


Node::Node(int p_x, int p_y, int val){
    this->position_x = p_x;
    this->position_y = p_y;
    this->heuristic_value = val;
}

Node::Node(int p_x, int p_y){
    this->position_x = p_x;
    this->position_y = p_y;
}

void Node::determine_heuristic(int px, int py){
    //px and py are the goal state's position
    this->heuristic_value = abs(px - this->position_x) + abs(py - this->position_y);    
}

