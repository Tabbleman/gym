/*
描述
给定一个长度为n（n<=10^6）的数组。有一个大小为k的滑动窗口从数组的最左端移动到最右端。你可以看到窗口中的k个数字。窗口每次向右滑动一个数字的距离。
下面是一个例子：
数组是 [1 3 -1 -3 5 3 6 7]， k = 3。

窗口位置	最小值	最大值
[1  3  -1] -3  5  3  6  7 	-1	3
 1 [3  -1  -3] 5  3  6  7 	-3	3
 1  3 [-1  -3  5] 3  6  7 	-3	5
 1  3  -1 [-3  5  3] 6  7 	-3	5
 1  3  -1  -3 [5  3  6] 7 	3	6
 1  3  -1  -3  5 [3  6  7]	3	7


你的任务是得到滑动窗口在每个位置时的最大值和最小值。


输入
输入包括两行。
第一行包括n和k，分别表示数组的长度和窗口的大小。
第二行包括n个数字。
输出
输出包括两行。
第一行包括窗口从左至右移动的每个位置的最小值。
第二行包括窗口从左至右移动的每个位置的最大值
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>

const int N = 1000010;
void min(std::vector<int> v, int vSize, int windowSize)
{
  std::deque<int> q;
  for (int i = 0; i < windowSize; i++)
  {
    while (q.size() && v[q.back()] >= v[i])
      q.pop_back();
    q.push_back(i);
  }
  for(int i = windowSize - 1; i < vSize; i ++){
    
    while(q.size() && v[q.back()] >= v[i]) q.pop_back();
    
    q.push_back(i);
    while(q.size() && i - q.front() >= windowSize) q.pop_front();
    std::cout << v[q.front()] << ' ';
  }
  std::cout << std::endl;
}
void max(std::vector<int> v, int vSize, int windowSize)
{
  std::deque<int> dq;
  for(int i = 0; i < windowSize; i ++){
    while(dq.size() && v[dq.back()] <= v[i]) dq.pop_back();
    dq.push_back(i);
  }
  for(int i = windowSize - 1; i < vSize; i ++){
    while(dq.size() && v[dq.back()] <= v[i]) dq.pop_back();
    dq.push_back(i);
    while(dq.size() && i - dq.front() >= windowSize) dq.pop_front();
    std::cout << v[dq.front()] << ' ';
  }
}

int main()
{
  int vSize, windowSize;
  std::cin >> vSize >> windowSize;
  std::vector<int> v(N);
  for (int i = 0; i < vSize; i++)
  {
    std::cin >> v[i];
  }
  min(v, vSize, windowSize);
  max(v, vSize, windowSize);

  return 0;
}