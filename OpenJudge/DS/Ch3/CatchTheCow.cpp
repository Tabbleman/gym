/*
描述
农夫知道一头牛的位置，想要抓住它。农夫和牛都位于数轴上，农夫起始位于点N(0<=N<=100000)，牛位于点K(0<=K<=100000)。农夫有两种移动方式：

1、从X移动到X-1或X+1，每次移动花费一分钟
2、从X移动到2*X，每次移动花费一分钟

假设牛没有意识到农夫的行动，站在原地不动。农夫最少要花多少时间才能抓住牛？


输入
两个整数，N和K
输出
一个整数，农夫抓到牛所要花费的最小分钟数
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
const int N = 100010;
int solve(int n, int k)
{
  /**
   * q location, time
   */
  std::queue<std::pair<int, int>> q;
  std::vector<int> dist(N, -1);

  q.push({n, 0});
  dist[n] = 0;
  while (q.size())
  {
    auto u = q.front();
    q.pop();

    if (u.first == k)
    {
      return u.second;
    }
    if (u.first + 1 <= 100000 && dist[u.first + 1] == -1)
      q.push(std::make_pair(u.first + 1, u.second + 1)), dist[u.first + 1] = dist[u.first] + 1;
    if (u.first - 1 >= 0 && dist[u.first - 1] == -1)
      q.push(std::make_pair(u.first - 1, u.second + 1)), dist[u.first - 1] = dist[u.first] + 1;
    if (u.first * 2 <= 100000 && dist[u.first * 2] == -1)
      q.push(std::make_pair(u.first * 2, u.second + 1)), dist[u.first * 2] = dist[u.first] + 1;
  }
}
int main()
{
  int n, k;
  std::cin >> n >> k;
  std::cout << solve(n, k);
  return 0;
}