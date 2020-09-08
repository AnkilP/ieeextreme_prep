#include <vector>
#include <iostream>
#include <map>
#include <queue>

class goodTuples{

  std::vector<int> v;
  std::unordered_map<int,int> x;
  std::queue<int> q;

public:
  goodTuples(std::vector<int>& v);
  int solve();
  void pop_queue();
};

goodTuples::goodTuples(std::vector<int>& v){
  this.v = v;
}

void goodTuples::pop_queue(){
  int dqw = a.front();
  x[dqw]--;
  if(x[dqw] == 0){
    x.erase(dqw);
  }
  q.pop();

}

int goodTuples::solve(){
  int count = 0;
  for(int i = 0; i < 3; ++i){
    x[v[i]]++;
    q.emplace(v[i]);
  }
  if(x.size() == 2){
    count++;
  }

  for(int i = 3; i < v.size(); ++i){
    pop_queue();
    q.emplace(v[i]);
    x[v[i]]++;
    if(x.size() == 2){
      count++;
    }
  }
  return count;
}

int main(){
  std::vector<int> x = {1,1,2,1,5,3,2,3};
  goodTuples y(x);
  std:: cout << y.solve() << std::endl;
}
