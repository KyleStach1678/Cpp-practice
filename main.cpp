#include <iostream>

#include "NodePath.h"
#include "Node.h"
#include "Tree.h"
#include "TreeBuilder.h"

int main(int argc, char** argv) {
  TreeBuilder tb;
  TreeSearcher search;
  Tree* tree;
  std::tie(tree, search) = tb.parse(std::string(argv[1]));
  std::cout << search.FindPath().ToString() << std::endl;
  std::cout << tree->ToString() << std::endl;
  return 0;
}