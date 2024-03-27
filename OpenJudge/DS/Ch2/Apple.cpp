/*
描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
输入
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
输出
对输入的每组数据M和N，用一行输出相应的K。
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
const int N = 110;
static int cnt = 0;
int solve(int appleLeft, int plateLeft){
  if(appleLeft == 0 || plateLeft == 1) 
    return 1;
  if(plateLeft > appleLeft)
    return solve(appleLeft, appleLeft );
  return solve(appleLeft, plateLeft - 1) + solve(appleLeft - plateLeft, plateLeft);
}
int main(){
  int T;
  std::cin >> T;
  while(T--){
    int appleNumber, plateNumber;
    std::cin >> appleNumber >> plateNumber;
    std::cout << solve(appleNumber, plateNumber) << std::endl;;    
  }

  return 0;
}