#include <iostream>

#include "NodePath.h"
#include "Node.h"
#include "Tree.h"
#include "TreeBuilder.h"

int main(int argc, char** argv) {
  TreeBuilder tb;
  TreeSearcher search;
  Tree* tree;
  if (argc < 2) {
  	std::cout << "No arguments given. Exiting." << std::endl;
  	exit(0);
  }
  std::tie(tree, search) = tb.parse(std::string(argv[1]));
  std::cout << search.FindPath().ToString() << std::endl;
  return 0;
}