#include <iostream>
#include <Eigen/Dense>
#include <utility>
#include <stdlib.h> 
#include <time.h> 
#include <memory>


class visualizer{
    Eigen::MatrixXd map = Eigen::MatrixXd::Zero(24,24);
    std::pair<int, int> goal_state;
    std::pair<int, int> start_state;
    public:
            visualizer(int seed1, int seed2);
            void draw_to_console();
                
};

visualizer::visualizer(int seed1, int seed2){
    this->start_state = std::make_pair<int, int>(seed1 % 24, seed2 % 12);
    this->goal_state = std::make_pair<int, int>(seed2 % 24, (seed1 % 12) + 12);

    this->map(this->start_state.first, this->start_state.second) = 1;
    this->map(this->goal_state.first, this->goal_state.second) = 1;
    int x,y;
    srand(time(NULL));
    for(int i = 0; i < (24*24); ++i){
        x = rand() % 24 + 1;
        y = rand() % 24 + 1;
        if(x != this->goal_state.first && x != this->start_state.first && y != this->goal_state.second && y != this->start_state.second){ 
        if(rand() % 2){
                this->map(x,y) = 0;
        }
        else{
            this->map(x,y) = 1;
        }
                        }
    }
}

void visualizer::draw_to_console(){
    std::cout << this->map << std::endl;
}

