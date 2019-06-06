#include <string>
#include "visualizer.hpp"

class search{
    public:
     int map[24][24];
     int heuristics_map[24][24];
     std::pair<int, int> goal_state;
     std::pair<int, int> start_state;
    
     search(int [][24] , std::pair<int, int> &, std::pair<int, int> &);
     void update_map();
};

search::search(int map[][24], std::pair<int, int> & goal_state, std::pair<int,int> & start_state){
    map = map;
    goal_state = goal_state;
    start_state = start_state;
}


