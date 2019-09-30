#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <memory>
#include <map>
#include <set>

class pirates{

    int Q;
    int rows;
    int columns;

    std::vector<std::vector<int> > test_cases;
    std::vector<std::vector<std::string> > islands;
    std::vector<std::vector<int> > island_compressed;
    std::string line;

    std::vector<int> superNode;
    std::vector<int> rank;
    std::vector<std::set<int> > edges;
    std::set<int> unique_nodes;

    int neighbour(const std::string & unit_string, int row, int column);
    int flattened_number(int row, int column);
    void set_union(int row, int column, int in_x, int in_y);
    void edge_add(int row, int column, int in_x, int in_y);
    int find(int index);
    void convert_to_adj_matrix();
    int clear_matrix(std::vector<std::vector<int> > & island);

    public:
        pirates();
        void ingestor();
        void path_finder(int source, int sink);
        void disjoint_sets();
};

pirates::pirates(){
    ingestor();
    superNode.resize(rows*columns);
    std::iota (std::begin(superNode), std::end(superNode), 0);
    rank.resize(rows*columns);
    edges.resize(rows*columns);
}

void pirates::ingestor(){
    std::cin >> rows >> columns >> Q;
    for(int i = 0; i < rows; ++i) {
        std::getline(std::cin, line);
        std::istringstream ss(line);
        islands.emplace_back(std::istream_iterator<int>{ss}, std::istream_iterator<int>{});
    }
    for(int i = 0; i < Q; ++i){
        std::getline(std::cin, line);
        std::istringstream ss(line);
        test_cases.emplace_back(std::istream_iterator<int>{ss}, std::istream_iterator<int>{}); 
    }
}


void pirates::convert_to_adj_matrix(){
    island_compressed.resize(unique_nodes.size());
    for(int i = 0; i < unique_nodes.size(); ++i){
        island_compressed[i].resize(unique_nodes.size());
    }
    std::set<int>::iterator it;
    int iter = 0;
    for(it = unique_nodes.begin(); it != unique_nodes.end(); ++it){
        island_compressed[iter][]
    }

}

void pirates::path_finder(int source, int sink){

}

int pirates::flattened_number(int row, int column){ // assuming row-major ordering
    return ((row - 1) >= 0 ? (row - 1) : 0) * this->columns + column;
}

int pirates::find(int index){    { 
    if (superNode[index] != index){ 
        return find(superNode[index]); 
    }
    return index; 
} 

void pirates::set_union(int row, int column, int increment_x, int increment_y){
    int flat = flattened_number(row, column);
    int curr_parent = find(superNode[flat]);
    int next = find(superNode[flattened_number(row + increment_x, column + increment_y)]);
    if(curr_parent == next){
        return;
    }
    else{
        if (rank[curr_parent] < rank[next]) 
            superNode[curr_parent] = next; 
        else if (rank[next] < rank[curr_parent]) 
            superNode[next] = curr_parent; 
        else
        { 
            superNode[next] = curr_parent;   
            rank[curr_parent] = rank[curr_parent] + 1; 
        } 
    }
}

void pirates::edge_add(int row, int column, int increment_x, int increment_y){
    int flat = flattened_number(row, column);
    int curr_parent = find(superNode[flat]);
    int next = find(superNode[flattened_number(row + increment_x, column + increment_y)]);
    edges[curr_parent].insert(next); // will have to go over this list again after all the sets have been joined
    // parent of current is root but next is not necessarily root
}

int pirates::neighbour(const std::string & unit_string, int row, int column){
    int flat = flattened_number(row, column);
    for(int i = -1; i <= 1; ++i){ // check neighbourhood
        for(int j = -1; j <= 1; ++j){ // check neighbourhood
            if( i == 0 && j == 0){ // no point in unioning yourself
                continue;
            }
            if((row + i) < this->rows && (row + i) >= 0){ // checking for out of bound
                if((column + j) < this->columns && (column + j) >= 0){ // checking for out of bound
                    if(islands[row + i][column + j] == unit_string){ // checking for same unit string
                        set_union(row, column, i, j);
                    }
                    else{ // bipartite graph distinction
                        edge_add(row, column, i, j);
                    }
                }
            }
        }
    }
    return flattened_number(row, column);
}

void pirates::disjoint_sets(){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            if(i == 0 && j == 0){ // ignore the first element
                continue;
            }
            superNode[flattened_number(i,j)] = neighbour(islands[i][j], i, j);
        }
    }
    std::set<int>::iterator it;
    for(int i = 0; i < edges.size(); ++i){ // joining edges
        int root = find(superNode[i]);
        unique_nodes.insert(root);
        auto s = edges[i];
        for(it = s.begin(); it != s.end(); ++it){
            int node = *it;
            s.erase(it);
            edges[root].insert(find(node));
        }
    }
}

int main(){
    pirates blackBeard();
}