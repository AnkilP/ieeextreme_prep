#include <string>
#include "search.hpp" 
#include <queue>
#include <algorithm>
#include <vector>

class breadth_first_search: public search {
    std::queue<std::pair<int, int>> tree_expansion;
    std::vector<std::pair<int, int>> points; //24 * 24
    int numExpansions = 0;
    std::pair<int, int> goal_state;
    std::pair<int, int> start_state;
    public:
        breadth_first_search(int map[][24], std::pair<int, int> & g, std::pair<int, int> s): search(map, g, s){
            goal_state = g;
            start_state = s;
        } 
        void bfs_search();
        void expand_node();
};
          
void breadth_first_search::bfs_search(){
    //queue structure 
   // std::cout << start_state.first;
    tree_expansion.push(this->start_state);                                         
    //std::cout << goal_state.first << goal_state.second << std::endl;
    while(!tree_expansion.empty()){        
//        std::cout << tree_expansion.size();
        if(tree_expansion.front() == this->goal_state){
            std::cout << "Found the path in " << numExpansions << " moves" << std::endl; 
            break;
        }
        this->expand_node();
        tree_expansion.pop();
    }
    std::cout << "Goal State is not reachable" << std::endl;
}

void breadth_first_search::expand_node(){
    //start at bottom and work counter-clockwise
    std::pair<int, int> point(this->tree_expansion.front());    
    this->points.push_back(point);

    if(point.second < 23 && this->map[point.first][point.second +1] != 1 && points.end() == std::find(points.begin(), points.end(), std::make_pair(point.first, point.second + 1))){
        this->tree_expansion.emplace(std::make_pair(point.first, point.second + 1));
        numExpansions++;
        this->points.push_back(std::make_pair(point.first, point.second + 1));
      //  std::cout << "down" << std::endl;
    }
    if(point.first < 23 && this->map[point.first + 1][point.second ] != 1 && points.end() == std::find(points.begin(), points.end(), std::make_pair(point.first, point.second + 1))){
        this->tree_expansion.emplace(std::make_pair(point.first + 1, point.second));
        numExpansions++;
        this->points.push_back(std::make_pair(point.first + 1, point.second));
    //    std::cout << "right" << std::endl;
    }
    if(point.second > 0 && this->map[point.first][point.second -1] != 1 && points.end() == std::find(points.begin(), points.end(), std::make_pair(point.first, point.second + 1))){ 
        this->tree_expansion.emplace(std::make_pair(point.first, point.second - 1));
        numExpansions++;
        this->points.push_back(std::make_pair(point.first, point.second - 1));
  //      std::cout << "up" << std::endl;
    }
    if(point.first > 0 && this->map[point.first - 1][point.second] != 1 && points.end() == std::find(points.begin(), points.end(), std::make_pair(point.first, point.second + 1))){
        this->tree_expansion.emplace(std::make_pair(point.first - 1, point.second));
        numExpansions++;
        this->points.push_back(std::make_pair(point.first - 1, point.second));
//        std::cout << "left" << std::endl;
    }
}    
