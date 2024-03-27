/**
 * 描述
    给出N个范围在[0, 65535]的整数，编程支持以下的操作：


（1）修改操作：C d，所有的数都增加d。如果超过65535，把结果模65536。 0 <= d <= 65535
（2）查询操作：Q i，统计在N个正整数中有多少个整数其对应的二进制形式的第i位二进制位为非0。0 <= i <= 15。并且最低位i为0。


　　最后，输出所有查询操作的统计值。

输入
输入的第一行为两个正整数N,M,其中N为操作的整数的个数，而M为具体有多少个操作。
输入的第二行为N个正整数，为进行操作的N个正整数。
下面有M行，分别表示M个操作。

N<=100000,M<=200000
输出
输出所有查询操作Q的统计值，每一个查询操作统计结果输出为一行。
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
const int N = 100010;
void Q(std::vector<int>&v, int vSize, int opNum){
  int cnt = 0;
  for(int i = 0; i < vSize; i ++){
    if(v[i] & (1 << opNum)) cnt++;
  }
  std::cout << cnt << std::endl;
} 
void C(std::vector<int>&v, int vSize, int opNum){
  for(int i = 0; i < vSize; i ++){
    v[i] += opNum;
  }
}
int main(){
  int n, m;
  std::cin >> n >> m;
  std::vector<int> v(N);
  for(int i = 0; i < n; i ++){
    std::cin >> v[i];
  }  
  while(m --){
    char op;
    int opNum;
    std::cin >> op >> opNum;
    switch (op)
    {
    case 'C':
      C(v, n, opNum);
      break;
    case 'Q':
      Q(v, n, opNum);

      break;
    }
    
  }
  return 0;
}