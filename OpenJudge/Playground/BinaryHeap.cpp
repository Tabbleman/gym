/*

*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
const int N = 110;

typedef struct TreeNode{
  typedef std::shared_ptr<struct TreeNode> TreeNodePtr;
  TreeNodePtr parent, lChild, rChild;
  int weight;
} TreeNode;
using TreeNodePtr = std::shared_ptr<TreeNode> ;



int main(){
  
  return 0;
}