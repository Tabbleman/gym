/**
 * 描述
求两个不超过200位的非负整数的积。

输入
有两行，每行是一个不超过200位的非负整数，没有多余的前导0。
输出
一行，即相乘后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int N = 510;
void mul(std::string a, std::string b){
  std::vector<int > va(N), vb(N);
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  for(int i = 0; i < a.size(); i ++){
    va[i] = a[i] - '0';
  }
  for(int i = 0; i < b.size(); i ++){
    vb[i] = b[i] - '0';
  }

  std::vector<int> c(N);
  for(int i = 0; i < N; i ++){
    for(int j = 0; j <= i; j ++) c[i] += va[j] * vb[i - j];
    if(c[i] >= 10){
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
  std::reverse(c.begin(), c.end());
  int i = 0;
  while(c[i] == 0)i++;
  if(i == N){
    std::cout << 0 << std::endl;
    return;
  }
  for(;i < N;i ++){
    std::cout << c[i] ;
  }
}
int main(){
  std::string a, b;
  std::cin >> a >> b;
  mul(a, b);
  return 0;
}