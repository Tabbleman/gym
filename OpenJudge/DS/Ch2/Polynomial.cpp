/**
 * 描述
    我们经常遇到两多项式相加的情况，在这里，我们就需要用程序来模拟实现把两个多项式相加到一起。首先，我们会有两个多项式，每个多项式是独立的一行，每个多项式由系数、幂数这样的多个整数对来表示。

如多项式2x20- x17+ 5x9- 7x7+ 16x5+ 10x4 + 22x2- 15

对应的表达式为：2 20 -1 17 5 9 - 7 7 16 5 10 4 22 2 -15 0。  

为了标记每行多项式的结束，在表达式后面加上了一个幂数为负数的整数对。

同时输入表达式的幂数大小顺序是随机的。

我们需要做的就是把所给的两个多项式加起来。

输入
输入包括多行。
第一行整数n,表示有多少组的多项式需要求和。(1 < n < 100)
下面为2n行整数，每一行都是一个多项式的表达式。表示n组需要相加的多项式。
每行长度小于300。
输出
输出包括n行，每行为1组多项式相加的结果。
在每一行的输出结果中，多项式的每一项用“[x y]”形式的字符串表示，x是该项的系数、y 是该项的幂数。要求按照每一项的幂从高到低排列，即先输出幂数高的项、再输出幂数低的项。
系数为零的项不要输出。
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
const int N = 110;
std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>> v)
{
  std::vector<std::pair<int, int>> res;

  for (int i = 0; i < v.size(); i++)
  {
    int n = v[i].first, m = v[i].second;
    int j = i + 1;
    while (j < v.size() && v[j].second == m)
    {
      n += v[j].first;
      j++;
    }
    res.push_back({n, m});
    i = j - 1;
  }
  return res;
}
void solve(std::vector<std::pair<int, int>> &a, std::vector<std::pair<int, int>> &b)
{
  std::sort(a.begin(), a.end(), [](const std::pair<int, int> &pii1, const std::pair<int, int> &pii2)
            { return pii1.second > pii2.second; });
  std::sort(b.begin(), b.end(), [](const std::pair<int, int> &pii1, const std::pair<int, int> &pii2)
            { return pii1.second > pii2.second; });
  std::vector<std::pair<int, int>> ca = merge(a), cb = merge(b);
  std::vector<std::pair<int, int>> c;

  // return ;
  int i, j;
  for (i = 0, j = 0; i < ca.size() && j < cb.size();)
  {
    if (ca[i].second > cb[j].second)
    {
      c.push_back(ca[i]);
      i++;
    }
    else if (ca[i].second < cb[j].second)
    {
      c.push_back(cb[j]);
      j++;
    }
    else
    {
      if (ca[i].first + cb[j].first)
        c.push_back(std::make_pair(ca[i].first + cb[j].first, ca[i].second));
      i++, j++;
    }
  }
  while (i < ca.size())
  {
    c.push_back(ca[i]);
    i++;
  }
  while (j < cb.size())
  {
    c.push_back(cb[j]);
    j++;
  }
  for (auto p : c)
  {
    std::cout << "[ " << p.first << " " << p.second << " ] ";
  }
  std::cout << std::endl;
}
int main()
{
  int t;
  std::cin >> t;
  while (t--)
  {
    // input a;
    int v, e;
    std::map<int, int> result;
    while (std::cin >> v >> e && e >= 0)
    {
      if (result.find(e) != result.end())
      {
        result[e] += v;
      }
      else
      {
        result.insert({e, v});
      }
    }
    while (std::cin >> v >> e && e >= 0)
    {
      if (result.find(e) != result.end())
      {
        result[e] += v;
      }
      else
      {
        result.insert({e, v});
      }
    }
    for (std::map<int, int>::reverse_iterator u = result.rbegin(); u != result.rend(); u++)
    {
      if (u->second)
        std::cout << "[ " << u->second << " " << u->first << " ] ";
    }
    std::cout << std::endl;
  }
  return 0;
}