#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    queue<pair<int,int>> bfs_q;

    void traverse_graph(vector<vector<int>>& A, vector<vector<int>>& visited, int index1, int index2){
        if(index1 + 1 < A.size()){
            if(A[index1 + 1][index2] == 1 && visited[index1 + 1][index2] == 0){
                visited[index1+1][index2] = 1;
                traverse_graph(A, visited, index1 + 1, index2);
            }
            else if(A[index1 + 1][index2] == 0 && visited[index1 + 1][index2] == 0){
                bfs_q.emplace(index1+1, index2);
            }
        }
        if(index1 - 1 >= 0){
            if(A[index1 - 1][index2] == 1 && visited[index1 - 1][index2] == 0){
                visited[index1-1][index2] = 1;
                traverse_graph(A, visited, index1 - 1, index2);
            }
            else if(A[index1 - 1][index2] == 0 && visited[index1 - 1][index2] == 0){
                bfs_q.emplace(index1-1, index2);
            }
        }
        if(index2 + 1 < A[0].size()){
            if(A[index1][index2+1] == 1 && visited[index1][index2+1] == 0){
                visited[index1][index2+1] = 1;
                traverse_graph(A, visited, index1, index2+1);
            }
            else if(A[index1][index2+1] == 0 && visited[index1][index2+1] == 0){
                bfs_q.emplace(index1, index2+1);
            }
        }
        if(index2 - 1 >= 0){
            if(A[index1][index2-1] == 1 && visited[index1][index2-1] == 0){
                visited[index1][index2-1] = 1;
                traverse_graph(A, visited, index1, index2-1);
            }
            else if(A[index1][index2-1] == 0 && visited[index1][index2-1] == 0){
                bfs_q.emplace(index1, index2-1);
            }
        }
    }

    void printVec(const vector<vector<int>> &A){
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    void find_firstIsland(vector<vector<int>>& A, vector<vector<int>>& visited, int & index1, int & index2){
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < A[0].size(); ++j){
                if(A[i][j] == 1 && visited[i][j] == 0){
                    visited[i][j] = 1;
                    traverse_graph(A, visited, i, j);
                    index1 = i;
                    index2 = j;
                    return;
                }
            }
        }
    }

    int traverse_BFS(vector<vector<int>>& A, vector<vector<int>>& visited){
        int bridgeLength = 0;
        while(!bfs_q.empty()){
            auto size = bfs_q.size();
            while(size--){
              int x = bfs_q.front().first;
              int y = bfs_q.front().second;
              bfs_q.pop();
              if(A[x][y] == 1 && visited[x][y] == 0){
                  return bridgeLength;
              }
              else{
                  visited[x][y] = 2;
                  if(x + 1 < A.size() && visited[x+1][y] == 0){
                      bfs_q.emplace(x+1, y);
                  }
                  if(x - 1 >= 0 && visited[x-1][y] == 0){
                      bfs_q.emplace(x-1, y);
                  }
                  if(y + 1 < A[0].size() && visited[x][y+1] == 0){
                      bfs_q.emplace(x, y+1);
                  }
                  if(y -1 >= 0 && visited[x][y-1] == 0){
                      bfs_q.emplace(x, y-1);
                  }
              }
            }
            bridgeLength++;
        }
        return -1;

    }

    int shortestBridge(vector<vector<int>>& A) {
        vector<vector<int> > visited(A.size(), vector<int> (A[0].size(), 0));
        int idx1, idx2;
        find_firstIsland(A, visited, idx1, idx2);
        return traverse_BFS(A,visited);
    }
};

int main(){
  Solution x = Solution();
  vector<vector<int> > A = {{0,1},{1,0}};
  vector<vector<int> > B = {{0,1,0},{0,0,0},{0,0,1}};
  cout << x.shortestBridge(B) << endl;
}
