#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'findHighPoints' function below.
 *
 * The function is expected to return a 2D_BOOLEAN_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY elevations as parameter.
 */

bool neighbour(vector<vector<int>> & elevations, int index1, int index2){
    for(int i = index1 - 1; i <= index1 + 1; ++i){
        for(int j = index2 - 1; j <= index2 + 1; ++j){
            if(i == 0 && j == 0){
                continue;
            }
            if(i < 0 || j < 0 || i >= elevations.size() || j >= elevations[0].size()){
                continue;
            }

            if(elevations[i][j] >= elevations[index1][index2]){
                return false;
            }
        }
    }
    return true;
}

vector<vector<bool>> findHighPoints(vector<vector<int>> elevations) {
    vector<vector<bool>> x(elevations.size(), vector<bool> (elevations[0].size()));

    for(int i = 0; i < elevations.size(); ++i){
        for(int j = 0; j < elevations[0].size(); ++j){
            x[i][j] = neighbour(elevations, i, j);
        }
    }
    return x;
}
int main(){

}
