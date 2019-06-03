#include "visualizer.hpp"

int main(int argc, char * argv[]){
    std::unique_ptr<visualizer> viz = std::make_unique<visualizer>(123, 1244);
    viz->draw_to_console();
    return 0;
}
