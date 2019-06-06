#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h> 
#include <time.h> 
#include <memory>


class visualizer{
//    Eigen::MatrixXd map;
    public:
    int map[24][24];
    std::pair<int, int> goal_state;
    std::pair<int, int> start_state;
            visualizer(int seed1, int seed2);
            void draw_to_console();
                
};

visualizer::visualizer(int seed1, int seed2){
    this->start_state = std::make_pair<int, int>(seed1 % 24, seed2 % 12);
    this->goal_state = std::make_pair<int, int>(seed2 % 24, (seed1 % 12) + 12);

    //this->map(this->start_state.first, this->start_state.second) = 1;
    //this->map(this->goal_state.first, this->goal_state.second) = 1;
    int x,y;
    srand(time(NULL));
    for(int i = 0; i < (24*24); ++i){
        x = rand() % 24;
        y = rand() % 24;
       if(rand() % 2){
            this->map[x][y] = 1; // blocks
        }
       else{
            this->map[x][y] = 0;
       }                                
                        
    }
   this->map[this->goal_state.first][this->goal_state.second] = -1;
   this->map[this->start_state.first][this->start_state.second] = 2;
//   this->map.finished();
 
}

void visualizer::draw_to_console(){
    for(int i = 0; i < 24; ++i){
        for(int j = 0; j < 24; ++j){
            std::cout << this->map[i][j];
        }
        std::cout << '\n';
    }
}

