#include "tabu_search.hpp"

tabu_search::tabu_search(const int & tabu_list){
    // std::cout << "starting schtuff" << std::endl;

    // first = true;
    numIter = 0;

    best_score = 1000000;
    current_state_score = 10000000;

    for(int i = 0; i < 20; ++i){
        this->state.at(i) = i + 1;
    }

    // this->state = {5, 11, 12, 16, 15, 17, 18, 2, 7, 10, 4, 8, 20, 3, 1, 13, 6, 19, 14, 9};

    std::random_shuffle(this->state.begin(), this->state.end());

    print_matrix(this->state);

    flowRead.get(flowMatrix);
    // print_matrix(flowMatrix);
    distanceRead.get(DistanceMatrix);
    // print_matrix(DistanceMatrix);

    this->tabu_list_size = tabu_list;

    this->recency_frequency_matrix[this->state] = this->tabu_list_size;
    this->frequency_matrix[state] = 1;

    // std::cout << "ending schtuff" << std::endl;
}

int tabu_search::find_cost(){
    int cost = 0;

    for(int i = 0; i < 20; i++){ // TODO: could improve runtime if I tracked which nodes were disturbed
        for(int j = i+1; j < 20; j++){
            if (i == j){
                continue;
            }
            int c = this->state.at(i);
            int f = this->state.at(j);

            cost += this->flowMatrix.at(c-1).at(f-1) *
             this->DistanceMatrix.at(i).at(j);

        }
    }

    best_score = std::min(cost, best_score);
    return cost;

}

int tabu_search::find_cost(const std::vector<int> & state){
    int cost = 0;

    for(int i = 0; i < 20; i++){ // TODO: could improve runtime if I tracked which nodes were disturbed
        for(int j = i+1; j < 20; j++){
            if (i == j){
                continue;
            }
            int c = state.at(i);
            int f = state.at(j);

            cost += this->flowMatrix.at(c-1).at(f-1) *
             this->DistanceMatrix.at(i).at(j);

        }
    }

    best_score = std::min(cost, best_score);
    // std::cout << cost << std::endl;
    return cost;
}

void tabu_search::print_matrix(const std::vector<std::vector<int>>& matrix){
    for(auto & row: matrix){
        // std::cout << "whats up3" << std::endl;
        for(auto &col: row){
            // std::cout << "whats up4" << std::endl;
            std::cout << col << ", ";
        }
        std::cout << std::endl;
    }
}

void tabu_search::print_matrix(const std::vector<int> & matrix){
        for(auto it = matrix.begin(); it != matrix.end(); ++it){
            std::cout << *it << ", ";
        }
        std::cout << std::endl;
}

void tabu_search::swap(std::vector<int> & state, const int & index1, const int & index2){
    int temp = state.at(index1);
    state.at(index1) = state.at(index2);
    state.at(index2) = temp;
}

void tabu_search::print_recency_matrix(){
    std::cout << "Recency Matrix" << std::endl;
    for(auto &i: this->recency_frequency_matrix){
        print_matrix(i.first);
        std::cout << "::::: " << i.second << std::endl;
    }
}

bool tabu_search::try_add(const std::vector<int> & state){

    if(this->recency_frequency_matrix.find(state) == this->recency_frequency_matrix.end()){
        this->recency_frequency_matrix[state] = this->tabu_list_size + 1;
        for(auto &i: this->recency_frequency_matrix){
            i.second = i.second - 1;
        }
        return true;
    }
    else{
        if(this->recency_frequency_matrix[state] <= 0 && this->frequency_matrix[state] <= 3){
            // was previously in tabu list but outlasted its tenure
            this->recency_frequency_matrix[state] = this->tabu_list_size + 1;
            this->frequency_matrix[state]++;
            for(auto &i: this->recency_frequency_matrix){
                i.second = i.second - 1;
            }
            return true;
        }
        else{
            // print_recency_matrix();
            // if(first){ //if best among immediate neighbours available
            //     this->recency_frequency_matrix[state] = this->tabu_list_size + 1;
            //     for(auto &i: this->recency_frequency_matrix){
            //         i.second = i.second - 1;
            //     }
            //     return true;
            // }
            return false;
        }
    }
}

void tabu_search::move(){
    
    std::vector<int> state_copy = this->state;
    //std::cout << "Initial State:" << std::endl;
    //print_matrix(this->state);
    //std::cout << this->best_score << std::endl;
    
    std::priority_queue<neighbour, std::vector<neighbour>, compareNeighbours> pq;

    // determine neighbours
    for(int i = 0; i < 20; ++i){
        for(int j = i+1; j < 20; ++j){

            if(i == j){
                continue;
            }

            this->swap(state_copy, i, j);

            pq.emplace(neighbour(i,j,find_cost(state_copy)));

            this->swap(state_copy, j, i);
            
        }
    }
    // first = true;
    bool cancellation_token = false;
    while(!cancellation_token){
        neighbour x = pq.top();
        // std::cout << x.getIndex1() << std::endl;
        // std::cout << x.getIndex2() << std::endl;
        this->swap(state_copy, x.getIndex1(), x.getIndex2());
        // print_matrix(state_copy);
        if(!try_add(state_copy)){
            this->swap(state_copy, x.getIndex1(), x.getIndex2());
            pq.pop();
            // first = false;
        }
        else{
            this->state = state_copy; // move to new state
            // this->current_state_score = x.getCost();
            // std::cout << "COST" << std::to_string(x.getCost()) << std::endl;
            pq.pop();
            cancellation_token = true;
        }
    }
    //std::cout << "Moved to new state:" << std::endl;
    //print_matrix(this->state);  
    // std::cout << this->current_state_score << std::endl;
}

void tabu_search::solve(){
    while(this->find_cost() > 1286){
        move();
        // test_cases();
        numIter++;
    }
    std::cout << "Final state:" << std::endl;
    print_matrix(this->state);
    test_cases(); 
    std::cout << "Number of Iterations: " << std::to_string(numIter) << std::endl;
}

void tabu_search::test_cases(){
    std::cout << "Final Cost: " << std::to_string(this->find_cost()) << std::endl;
}

int main(){
    std::srand(std::time(NULL));
    int tabu_tenure = rand() % 10 + 300;
    std::cout << "Tabu Tenure: " << std::to_string(tabu_tenure) << std::endl;
    tabu_search ts(tabu_tenure);
    ts.solve();
}