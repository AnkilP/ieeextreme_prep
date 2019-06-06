#include "bfs.hpp"

int main(int argc, char * argv[]){
    std::unique_ptr<visualizer> viz = std::make_unique<visualizer>(123, 1244);
    viz->draw_to_console();
//    std::cout << viz->start_state.first;
    breadth_first_search bfs = breadth_first_search((viz->map), viz->goal_state, viz->start_state);
    bfs.bfs_search();

    return 0;
}
