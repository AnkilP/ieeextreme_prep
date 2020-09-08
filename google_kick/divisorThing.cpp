#include <vector>

std::vector<int> getDigits(int n){
  std::vector<int> digits;
  while(n){
    digits.emplace_back(n % 10);
    n /= 10;
  }
  return std::reverse(digits.begin(), digits.end());
}

int divisorSubStrings(int n, int k){
  std::vector<int> v = getDigits(n);
  
}
