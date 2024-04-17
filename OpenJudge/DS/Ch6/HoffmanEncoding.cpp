/*

*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

const int N = 110;


typedef struct HoffmanTreeNode {
  int weight;
  typedef std::shared_ptr<struct HoffmanTreeNode> HoffmanTreePtr;
  HoffmanTreePtr lChild, rChild;
} HoffmanTreeNode;
typedef std::shared_ptr<HoffmanTreeNode> HoffmanTreePtr;


HoffmanTreePtr createHoffmanTree(std::vector<int> v) {
  std::vector<HoffmanTreePtr> forest(v.size());
  std::shared_ptr<HoffmanTreeNode> root = nullptr;
  for (int i = 0; i < v.size(); i++) {
    HoffmanTreePtr node = std::make_shared<HoffmanTreeNode>();
    node->weight = v[i];
    node->lChild = node->rChild = nullptr;
    forest[i] = node;
  }
  for (int i = 1; i < v.size(); i++) {
    int min1 = -1, min2;
    for (int j = 0; j < v.size(); j++) {
      if (forest[j] != nullptr && min1 == -1) {
        min1 = j;
        continue;
      }
      if (forest[j] != nullptr) {
        min2 = j;
        break;
      }
    }

    for (int j = min2; j < v.size(); j++) {
      if (forest[j] != nullptr && forest[j]->weight < forest[min1]->weight) {
        min2 = min1;
        min1 = j;
      } else if (forest[j] != nullptr &&
                 forest[j]->weight < forest[min2]->weight) {
        min2 = j;
      }
    }

    root = std::make_shared<HoffmanTreeNode>();
    root->weight = forest[min1]->weight + forest[min2]->weight;
    root->lChild = forest[min1];
    root->rChild = forest[min2];

    forest[min1] = root;
    forest[min2] = nullptr;
  }
  return root;
}

int getWPL(HoffmanTreePtr tree, int depth) {
  if (tree == nullptr)
    return 0;

  if (tree->lChild == nullptr && tree->rChild == nullptr)
    return tree->weight * depth;
  else{
    int l = getWPL(tree->lChild, depth + 1);
    int r = getWPL(tree->rChild, depth + 1);
    return l + r;
  }
}

void printHuffmanTree(HoffmanTreePtr root, int depth = 0, char prefix = '-') {
  if (root == nullptr)
    return;

  // 输出当前节点的信息
  for (int i = 0; i < depth; ++i)
    std::cout << "  ";
  std::cout << prefix << " Weight: " << root->weight << std::endl;

  // 递归打印左子树和右子树
  printHuffmanTree(root->lChild, depth + 1, 'L');
  printHuffmanTree(root->rChild, depth + 1, 'R');
}

int main(){
  int t;
  std::cin >> t;
  while(t--){
    int n;
    std::vector<int> v;
    std::cin >> n;
    for(int i = 0; i < n; i ++){
      int x;
      std::cin >> x;
      v.push_back(x);

    }
    HoffmanTreePtr root = createHoffmanTree(v);
    // printHuffmanTree(root);
    std::cout << getWPL(root, 0) << std::endl;
    
  }

  return 0;
}