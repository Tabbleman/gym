/*

*/
#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

const int N = 110;

struct Tree {
  typedef std::shared_ptr<struct Tree> TreePtr;
  int weight;
  TreePtr l, r;
};
typedef std::shared_ptr<struct Tree> TreePtr;
TreePtr construct(std::vector<int> in, std::vector<int> post, int inL, int inR,
                  int postL, int postR) {
  if (inL == inR && postL == postR) {
    return nullptr;
  }

  int idx, val;
  TreePtr tmp = std::make_shared<struct Tree>(),
          left = std::make_shared<struct Tree>(),
          right = std::make_shared<struct Tree>();

  val = post[postR - 1];

  for (int i = inL; i < inR; i++) {
    if(val == in[i]){
      idx = val;
      break;
    }
  }
  // a b c
  //  ^
  
  //div post;
  


  left = construct(in, post, inL, idx, postL, postR - 1);
  right = construct(in, post, idx + 1, inR, postL, postR);

}
void RestuctTree(std::vector<int> vin, std::vector<int> vpost) {
  TreePtr root;
  root = construct(vin, vpost, 0, vin.size(), 0, vpost.size());
}

int main() {
  std::vector<int> vin, vpost;
  std::string in, post;
  std::getline(std::cin, in);
  std::getline(std::cin, in);

  int x;
  std::stringstream ss;
  ss << in;
  while (ss >> x)
    vin.push_back(x);
  ss << post;
  while (ss >> x)
    vpost.push_back(x);

  RestuctTree(vin, vpost);

  return 0;
}