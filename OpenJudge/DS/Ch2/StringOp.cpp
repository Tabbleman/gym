#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
const int N = 110;
void solve(std::string s){
  std::size_t iter = s.find(' ');
  std::string base, insert;
  base = s.substr(0, iter), insert = s.substr(iter + 1, s.size() - iter - 1);
  int idx;
  char maxChar = 0;
  for(int i = 0; i < base.size(); i ++){
    if(base[i] > maxChar){
      idx = i;
      maxChar = base[i];
    }
  }
  base.insert(idx + 1, insert);
  std::cout << base << std::endl;
}
int main(){ 
  std::string s;
  while(std::getline(std::cin, s)){
    solve(s);
  }  

  return 0;
}