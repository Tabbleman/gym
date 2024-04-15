/*

*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
const int N = 110;
void handleNext(std::vector<int> &pi, std::string pattern) {
  int n = pattern.size();
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && pattern[i] != pattern[j])
      j = pi[j - 1];
    if (pattern[i] == pattern[j]) {
      j++;
      pi[i] = j;
    }
  }
}
void kmp(std::string str, std::string pattern, std::vector<int> pi) {
  int n = str.size(), m = pattern.size();
  int j = 0;
  for (int i = 0; i < n; i++) {
    // std::cout << i << ' ' << j << std::endl;
    while (j > 0 && str[i] != pattern[j])
      j = pi[j - 1];
    if (pattern[j] == str[i])
      j++;
    if (j == m) {
      std::cout << i - m + 1 << std::endl;
      j = pi[j - 1];
    }
  }
}
int main() {
  std::string str, pattern;
  std::cin >> str >> pattern;
  std::vector<int> pi(N, 0);
  handleNext(pi, pattern);
  for(int i = 0; i < pattern.size(); i ++)
    std::cout << pi[i] << ' ';

  // kmp(str, pattern, pi);
  return 0;
}