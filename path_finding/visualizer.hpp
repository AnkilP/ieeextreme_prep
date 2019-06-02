#include <iostream>
#include <Eigen/Dense>
#include <utility>

class visualizer{
    Eigen::Matrix3D map(24,24);
    std::pair<int, int> goal_state;
    std::pair<int, int> start_state;
        public:
            visualizer(int seed1, int seed2, int percentage);
            draw_to_console();
                
};

visualizer::visualizer(int seed1, int seed2, int percentage){
    this->start_state = std::make_pair<int, int>(seed1 % 24, seed2 % 12);
    this->goal_state = std::make_pair<int, int>(seed2 % 24, (seed1 % 12) + 12);

    map(this->start_state.first, this->start_state.second) = 1;
    map(this->goal_state.first, this->goal_state.second) = 1;

    for(int i = 0; i < seed1 % (12*12); ++i){
        
    }
}

visualizer::draw_to_console(){
    std::cout << this->map << std::endl;
}

